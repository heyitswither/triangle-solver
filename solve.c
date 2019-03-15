// solve.c: actually solve the triangle

#include <math.h>
#include <stdio.h>

#include "common.h"

static const char opts_str[NUM_OPTS] = {OPTS_STR};

int single_missing_angle(double **opts, char mask) {
    int missing = log2(MASK_ANGLES ^ 0b111);
    LOG("missing: %c\n", opts_str[missing]);
    *opts[missing] = 180 - *opts[(missing == A) ? B : A] - *opts[(missing == C) ? B : C];
    return TRUE;
}

int basic_right_solve(double **opts, char mask) {
    return TRUE;
}
