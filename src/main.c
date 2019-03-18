#ifndef __GNUC__
#error "GCC (with extensions) is required to compile"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <strings.h>

#include "common.h"
#include "id.h"
#include "verify.h"
#include "solve.h"

#define INPUT_SIZE 16

// id, verify, solve, verify

int main(int argc, char *argv[]) {
    // TODO: maybe use a struct for this so I don't do weird stuff with NULL
    //       or maybe not, mask works just fine
    double *vals[NUM_OPTS];
    const char opts_str[NUM_OPTS] = OPTS_STR;
    char opts_mask = 0;
    char input[INPUT_SIZE];
    int use_stdin = (argc != 7);

    if (((argc > 1) && ((!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")))) || (argc > 7)) {
        printf("usage: %s [%s]\n"
               "\tif no args are given, take input interactively.\n"
               "\tuse an x to denote a missing value\n",
               argv[0], OPTS_STR_PRINTABLE);
        return EXIT_FAILURE;
    }

#undef MASK
#define MASK opts_mask

    for (int i = 0; i < NUM_OPTS; i++) {
        vals[i] = malloc(sizeof(double));
        if (!vals[i]) {
            LOG("%s\n", "allocation error");
            return EXIT_FAILURE;
        }
        *vals[i] = 0;
    }

    for (int i = 0; i < NUM_OPTS; i++) {
        if (use_stdin) {
            fprintf(stderr, "%c: ", opts_str[i]);
            fgets(input, INPUT_SIZE, stdin);
        } else {
            strlcpy(input, argv[i + 1], INPUT_SIZE);
        }
        if (sscanf(input, " %lf", vals[i]) > 0) {
            opts_mask |= (int)pow(2, i);
        }
    }

    if (__builtin_popcount(opts_mask) < 3) {
        fprintf(stderr, "At least 3 values needed, only %d given\n", __builtin_popcount(opts_mask));
        return EXIT_FAILURE;
    }

    LOG("bits set: %d, angles: %d, sides: %d\n", __builtin_popcount(opts_mask), __builtin_popcount(MASK_ANGLES), __builtin_popcount(MASK_SIDES));
    LOG("mask: %x\n", opts_mask);

    if (__builtin_popcount(MASK_ANGLES) == 2) {
        single_missing_angle(vals, opts_mask);
    }

    if (basic_right_id(vals, opts_mask)) {
        if (basic_right_verify(vals, opts_mask)) {
            basic_right_solve(vals, opts_mask);
        }
    }

    printf("A: %lf\nB: %lf\nC: %lf\na: %lf\nb: %lf\nc: %lf\n", *vals[A], *vals[B], *vals[C], *vals[a], *vals[b], *vals[c]);

    return EXIT_SUCCESS;
}
