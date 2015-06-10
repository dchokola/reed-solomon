/**
 * @file utils.h
 * Some utility functions & macros.
 */

#ifndef UTILS_H
#define UTILS_H

#ifdef MIN
#undef MIN
#endif /* MIN */
#define MIN(a,b) \
    ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
       _a < _b ? _a : _b; })

#ifdef MAX
#undef MAX
#endif /* MAX */
#define MAX(a,b) \
    ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
       _a > _b ? _a : _b; })

#endif /* UTILS_H */
