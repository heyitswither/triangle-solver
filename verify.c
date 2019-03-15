// verify.c: verify that the case identified is possible

#include "common.h"

int basic_right_verify(double **opts, char mask) {
    if (__builtin_popcount(MASK_ANGLES) == 3) {
        return (*opts[A] + *opts[B] + *opts[C]) == 180;
    } else {
        return TRUE;
    }
}
