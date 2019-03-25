// id.c: identify different cases for solving triangles

#include "common.h"

int basic_right_id(double **opts, char mask) {
    return ((*opts[A] == 90) || (*opts[B] == 90) || (*opts[C] == 90)) ? SUCCESS : ENOID;
}

int single_missing_angle_id(double **opts, char mask) {
    return (__builtin_popcount(MASK_ANGLES) == 2) ? SUCCESS : ENOID;
}

int sss_id(double **opts, char mask) {
    return ((MASK_SIDES > 0) && (MASK_ANGLES == 0) && IS_RIGHT(opts)) ? SUCCESS : ENOID;
}
