/**
 * @file test.c
 * Dumb test program for Reed-Solomon codec.
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#include "reed-solomon.h"

/**
 * Main program function.
 */
int32_t
main(void)
{
    int32_t i, len, err;
    uint8_t buf[N];

    rs_init();
    srandom((uint32_t) time(NULL));

    while(!0)
    {
        len = sprintf((char *) buf, "%u", (uint32_t) random());
        rs_encode(buf, len, &buf[K]);
        /* Introduce an error in a random location. */
        buf[random() % len] = 'x';
        err = rs_decode(buf);
/*
        printf("Data:");
        for(i = 0; i < len; i++)
        {
            if(i % 16 == 0)
            {
                printf("\n  %03x:", i);
            }
            printf(" %02x", buf[i]);
        }
        printf("\n");
        printf("Buffer had %d bytes with %d errors.\n", len, err);
*/
        if(!err) {
            printf("Buffer decoded successfully.\n");
        } else if(err > 0) {
            printf("Buffer corrected %d errors.\n", err);
        } else {
            printf("Buffer was not decoded successfully.\n");
        }
    }

    return 0;
}