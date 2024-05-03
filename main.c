#include <stdio.h>
#include<string.h>
#include "mymalloc.h"

int main(int argc, char *argv[]){
    int *p1 = (int*)MyMalloc(sizeof(int));
    if(p1 == NULL){
        printf("Can not allocate memory size %lu \n", sizeof(int));
    }
    else{
        *p1 = 10;
        printf("Allocated memory: %d\n", *p1);
    }

    char *p2 = (char*)MyMalloc(sizeof(char) * 100);
    if(p2 == NULL){
        printf("Can not allocate memory size %lu \n", sizeof(char) * 100);
    }
    else{
        strcpy(p2, "Allocated memory for 100 characters");
        printf("%s\n", p2);
    }

    MyFree(p1);
    MyFree(p2);


    return 0;
}
