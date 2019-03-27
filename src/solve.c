// solve.c: actually solve the triangle

#include <stdio.h>

#include "common.h"

static const char opts_str[NUM_OPTS] = {OPTS_STR};

int basic_right_solve(double **opts, char mask) {
    ERROR("%s\n", "not implemented");
    return ESTUB;
}

int single_missing_angle_solve(double **opts, char mask) {
    int missing = log2(MASK_ANGLES ^ 0b111);
    LOG("missing: %c\n", opts_str[missing]);
    *opts[missing] = 180 - *opts[(missing == A) ? B : A] - *opts[(missing == C) ? B : C];
    return SUCCESS;
}

int sss_solve(double **opts, char mask) {
    fprintf(stderr, "SSS case found, unable to solve\n");
    return EINVAL;
}

int right_ss_solve(double **opts, char mask) {
    double m1 = MISSING1;
    double m2 = MISSING2;

    return SUCCESS;
}
