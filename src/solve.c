// solve.c: actually solve the triangle

#include <math.h>
#include <stdio.h>

#include "common.h"

static const char opts_str[NUM_OPTS] = {OPTS_STR};

int basic_right_solve(double **opts, char mask) {
    ERROR("%s\n", "not implemented");
    return ESTUB;
}

int single_missing_angle_solve(double **opts, char mask) {
    int missing = log2(MASK_ANGLES ^ __extension__ 0b111);
    LOG("missing: %c\n", opts_str[missing]);
    *opts[missing] = 180 - *opts[(missing == A) ? B : A] - *opts[(missing == C) ? B : C];
    return SUCCESS;
}

int sss_solve(double **opts, char mask) {
    fprintf(stderr, "SSS case found, unable to solve\n");
    return EINVAL;
}
