// solve.c: actually solve the triangle

#include <math.h>
#include <stdio.h>

#include "common.h"

int basic_right_solve(double **opts, char mask) {
    int missing = log2(MASK_ANGLES ^ 0b111);
    const char opts_str[NUM_OPTS] = {OPTS_STR};
    // TODO: only print debug messages with -DDEBUG
    printf("log: miss: %c, pop: %d\n", opts_str[missing], __builtin_popcount(MASK_ANGLES));
    if (__builtin_popcount(MASK_ANGLES) == 2) {
        // find which angle is missing, then subtract the others from 180
        // TODO: maybe don't repeat code
        if (missing == A) {
            *opts[A] = 180 - *opts[B] - *opts[C];
        } else if (missing == B) {
            *opts[B] = 180 - *opts[A] - *opts[C];
        } else if (missing == C) {
            *opts[C] = 180 - *opts[A] - *opts[B];
        }
    }
    return TRUE;
}
