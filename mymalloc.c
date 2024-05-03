#include <stdio.h>
#include <string.h>
#include "mymalloc.h"

char heap[25000];
block *head = NULL;

void* MyMalloc(int size){
    if (head == NULL){
        head = (block*) &heap[0];
        head->size = 25000 - sizeof(block);
        head->isFree = true;
        head->next = NULL;
    }

    block *current = head;
    block *prev = NULL;

    while (current != NULL && !(current->isFree && current->size >= size)){
        prev = current;
        current = current->next;
    }

    if (current != NULL){
        current->isFree = false;

        if (current->size > size + sizeof(block)){
            block *newBlock = (block*)((char*)current + size + sizeof(block));
            newBlock->size = current->size - size - sizeof(block);
            newBlock->isFree = true;
            current->size = size;
            newBlock->next = current->next;
            current->next = newBlock;
        }
        return (void*)current + sizeof(block);
    }
    return NULL;
}

void MyFree(void *ptr){
    if (ptr == NULL){
        return;
    }

    block *current = head;
    block *prev = NULL;

    while (current != NULL && (char*)current + sizeof(block) != ptr){
        prev = current;
        current = current->next;
    }

    if (current != NULL){
        current->isFree = true;

        if (prev != NULL && prev->isFree){
            prev->size += current->size + sizeof(block);
            prev->next = current->next;
            current = prev;
        }

        if (current->next != NULL && current->next->isFree){
            current->size += current->next->size + sizeof(block);
            current->next = current->next->next;
        }
    }
    else{
        printf("Memory block already freed\n");
    }
}
