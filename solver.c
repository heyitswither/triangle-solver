#include <stdio.h>
#include <stdlib.h>

#define NUM_OPTS 6
#define OPTS_STR "A", "a", "B", "b", "C", "c"

enum opts{A, a, B, b, C, c};

int main(void) {
    double *vals[NUM_OPTS];
    const char *opts_str[NUM_OPTS] = {OPTS_STR};

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
        scanf("%lf", vals[i]);
        printf("\n");
    }

    printf("A: %lf, a: %lf, B: %lf, b: %lf, C: %lf, c: %lf\n", *vals[A], *vals[a], *vals[B], *vals[b], *vals[C], *vals[c]);

    return EXIT_SUCCESS;
}
