#ifndef MYMALLOC_H

#include <stddef.h>
#include <stdbool.h>

extern char heap[25000];

typedef struct block {
    bool isFree;
    int size;
    struct block *next;
} block;

extern block *head;

void *MyMalloc(int size);
void MyFree(void *ptr);

#endif
