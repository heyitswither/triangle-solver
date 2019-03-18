// id.c: identify different cases for solving triangles

#include "common.h"

int basic_right_id(double **opts, char mask) {
    return (*opts[A] == 90) || (*opts[B] == 90) || (*opts[C] == 90);
}
