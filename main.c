#ifndef __GNUC__
#error "GCC (with extensions) is required to compile"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "common.h"
#include "id.h"
#include "verify.h"
#include "solve.h"

#define INPUT_SIZE 16

// id, verify, solve, verify

int main(void) {
    // TODO: maybe use a struct for this so I don't do weird stuff with NULL
    //       or maybe not, mask works just fine
    double *vals[NUM_OPTS];
    const char opts_str[NUM_OPTS] = {OPTS_STR};
    char opts_mask = 0;
    char input[INPUT_SIZE];

#undef MASK
#define MASK opts_mask

    for (int i = 0; i < NUM_OPTS; i++) {
        vals[i] = malloc(sizeof(double));
        *vals[i] = 0;
        if (!vals[i]) {
            LOG("%s\n", "allocation error");
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < NUM_OPTS; i++) {
        printf("%c: ", opts_str[i]);
        fgets(input, INPUT_SIZE, stdin);
        if (sscanf(input, " %lf", vals[i]) > 0) {
            // TODO radians support
            opts_mask |= (int)pow(2, i);
        }
    }

    LOG("bits set: %d, angles: %d, sides: %d\n", __builtin_popcount(opts_mask), __builtin_popcount(MASK_ANGLES), __builtin_popcount(MASK_SIDES)); // bits set must be >=3
    LOG("mask: %x\n", opts_mask);

    // TODO: solve any single missing angle

    if (basic_right_id(vals, opts_mask)) {
        if (basic_right_verify(vals, opts_mask)) {
            basic_right_solve(vals, opts_mask);
        } else {
            LOG("%s\n", "no verify");
        }
    } else {
        LOG("%s\n", "no id");
    }

    printf("A: %lf\nB: %lf\nC: %lf\na: %lf\nb: %lf\nc: %lf\n", *vals[A], *vals[B], *vals[C], *vals[a], *vals[b], *vals[c]);

    return EXIT_SUCCESS;
}
