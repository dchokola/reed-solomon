/**
 * @file galois.c
 * Generate a Galois field with the given parameters.
 */

#include <stdint.h>

#include "galois.h"
#include "utils.h"

/**
 * Main program function.
 * Generate the finite field GF(2^r) in a pair of lookup tables. */
int32_t
gf_generate_field(gf_t *gf, uint8_t r, uint32_t poly)
{
    uint32_t i;
    uint32_t tmp;

    if(!gf) {
        return -1;
    }

    /* Make sure we are working with a field that isn't trivially small or
     * too big to fit in our lookup tables. */
    gf->len = 1 << r;
    if(gf->len < 1 || gf->len > GF_MAX) {
        return -1;
    }

    /* The (r-1)th bit of poly should be set if it is the same order as the
     * field. If the rth bit or higher is set, the order is too high. */
    if(!(poly >> (r - 1)) || poly >> 1) {
        return -1;
    }

    /* Assign an exponent to the zero element. Use an unused value. */
    gf->exp[gf->len - 1] = 0; /* exp(gf->len - 1) = 0 */
    gf->log[0] = gf->len - 1; /* log(0) = gf->len - 1 */
    gf->exp[0] = 1;           /* exp(0) = 1 */
    gf->log[1] = 0;           /* log(1) = 0 */
    for(i = 2; i < gf->len; i++)
    {
        tmp = (uint32_t) gf->exp[i - 1] << 1;
        if(tmp & (1 << r))
        {
            /* subtract (addition and subtraction are both XOR) the generator
             * polynomial to generate a field modulo poly */
            tmp ^= poly;
        }
        gf->exp[i] = tmp;
        gf->log[tmp] = i;
    }

    return 0;
}
