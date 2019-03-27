#ifndef _COMMON_H
#define _COMMON_H

#include <math.h>

#ifdef DEBUG
#define _DEBUG 1
#else
#define _DEBUG 0
#endif

enum errors{SUCCESS, ESTUB, EIMPOS, EINVAL, ENOID, ENOVFY};

#define LOG(fmt, ...) \
            do { if (_DEBUG) fprintf(stderr, "[DEBUG] %s:%d:%s(): " fmt, \
                                     __FILE__, __LINE__, __func__, \
                                     __VA_ARGS__); \
            } while (0)

#define ERROR(fmt, ...) \
              do { fprintf(stderr, "[ERROR] %s:%d:%s(): " fmt, __FILE__, \
                           __LINE__, __func__, __VA_ARGS__); } while (0)

#define IS_RIGHT(o) ((*o[A] == 90) || (*o[B] == 90) || \
                     (*o[C] == 90))

#define DEG2RAD(r) (r * (180.0 / M_PI))

#define MASK mask
#define MISSING1 (log2((MASK & 1) ?: (MASK >> 1)))
#define MISSING2 (log2((MASK & 0b100) ?: (MASK & 0b10)))
#define IN_MASK(o) (MASK & (int)pow(2, o))
#define MASK_ANGLES (MASK & 0b111)
#define MASK_SIDES (MASK & 0b111000)

#define NUM_OPTS 6
#define OPTS_STR "ABCabc"
#define OPTS_STR_PRINTABLE "A B C a b c"

enum opts{A, B, C, a, b, c};

#endif
