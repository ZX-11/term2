#include "extdlib.h"
void *malloc_s(size_t size) {
    void *t = malloc(size);
    check(t != NULL, "Memory allocation failed!");
    return t;
}