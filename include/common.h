#ifndef _COMMON_H
#define _COMMON_H

#define MASK mask
#define IN_MASK(o) (MASK & (int)pow(2, o))
#define MASK_ANGLES (MASK & 0b111)
#define MASK_SIDES (MASK & 0b111000)

#define NUM_OPTS 6
#define OPTS_STR 'A', 'B', 'C', 'a', 'b', 'c'

#define TRUE 1
#define FALSE 0

enum opts{A, B, C, a, b, c};

#endif
