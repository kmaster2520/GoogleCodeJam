#include "list.h"

typedef struct htable {
    int size;
    int width;
    float loadf;
    llist_t** hash;
} htable_t;