/**
 * @file reed-solomon.h
 */

#ifndef REED_SOLOMON_H
#define REED_SOLOMON_H

#include <stdint.h>

/* Define the characteristics of the Reed-Solomon codec. */
#define M 8     /* symbol size */
#define E 16    /* number of errors that can be corrected */

/* Do not change below this line. */
#define Q 2                /* code is over a binary field */
#define N ((1 << M) - 1)   /* length of codeword (bytes) */
#define D (E * 2)          /* number of parity symbols */
#define K (N - D)          /* length of message (K < N) */
#define A0 N               /* field.log[A0] = 0 */

typedef struct rs_field {
    uint8_t exp[N+1];   /* alpha ^ n */
    uint8_t log[N+1];   /* log(alpha ^ n) */
} rs_field_t;

/* Primitive polynomial for generating the finite field. */
#define PRIMPOLY 0x171

void rs_init(void);
int32_t rs_encode(const uint8_t msg[], uint32_t len, uint8_t parity[D]);
int32_t rs_decode(uint8_t msg[N]);

#endif /* REED_SOLOMON_H */