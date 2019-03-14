#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define IN_MASK(m, o) (m & (int)pow(2, o))

#define INPUT_SIZE 16
#define NUM_OPTS 6
#define OPTS_STR "A", "a", "B", "b", "C", "c"

enum opts{A, a, B, b, C, c};

int main(void) {
    // TODO: maybe use a struct for this so I don't do weird stuff with NULL
    double *vals[NUM_OPTS];
    const char *opts_str[NUM_OPTS] = {OPTS_STR};
    int opts_mask = 0;
    char input[INPUT_SIZE];

    for (int i = 0; i < NUM_OPTS; i++) {
        vals[i] = malloc(sizeof(double));
        *vals[i] = 0;
        if (!vals[i]) {
            fprintf(stderr, "allocation error\n");
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < NUM_OPTS; i++) {
        printf("%s: ", opts_str[i]);
        fgets(input, INPUT_SIZE, stdin);
        if (sscanf(input, " %lf", vals[i]) > 0) {
            opts_mask |= (int)pow(2, i);
        }
        printf("\n");
    }

    printf("mask: %x\nA: %lf, a: %lf, B: %lf, b: %lf, C: %lf, c: %lf\n", opts_mask, *vals[A], *vals[a], *vals[B], *vals[b], *vals[C], *vals[c]);
    printf("A: %s, a: %s, B: %s, b: %s, C: %s, c: %s\n", IN_MASK(opts_mask, A) ? "yeek":"nope", IN_MASK(opts_mask, a) ? "yeek":"nope", IN_MASK(opts_mask, B) ? "yeek":"nope", IN_MASK(opts_mask, b) ? "yeek":"nope", IN_MASK(opts_mask, C) ? "yeek":"nope", IN_MASK(opts_mask, c) ? "yeek":"nope");

    return EXIT_SUCCESS;
}
