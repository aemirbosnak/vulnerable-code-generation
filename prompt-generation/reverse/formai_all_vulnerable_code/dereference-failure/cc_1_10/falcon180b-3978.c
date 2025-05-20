//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX_SIZE 1000

typedef struct{
    int *data;
    int size;
    int capacity;
}DynamicArray;

DynamicArray* createDynamicArray(){
    DynamicArray* arr = (DynamicArray*)malloc(sizeof(DynamicArray));
    if(arr == NULL){
        printf("Memory Error\n");
        exit(0);
    }
    arr->data = (int*)malloc(sizeof(int)*MAX_SIZE);
    if(arr->data == NULL){
        printf("Memory Error\n");
        exit(0);
    }
    arr->size = 0;
    arr->capacity = MAX_SIZE;
    return arr;
}

void destroyDynamicArray(DynamicArray* arr){
    free(arr->data);
    free(arr);
}

void resizeDynamicArray(DynamicArray* arr){
    int* tempData = (int*)malloc(sizeof(int)*arr->capacity*2);
    if(tempData == NULL){
        printf("Memory Error\n");
        exit(0);
    }
    memcpy(tempData, arr->data, sizeof(int)*arr->size);
    free(arr->data);
    arr->data = tempData;
    arr->capacity *= 2;
}

void pushDynamicArray(DynamicArray* arr, int value){
    if(arr->size == arr->capacity){
        resizeDynamicArray(arr);
    }
    arr->data[arr->size++] = value;
}

int popDynamicArray(DynamicArray* arr){
    if(arr->size == 0){
        printf("Array is Empty\n");
        exit(0);
    }
    return arr->data[--arr->size];
}

int main(){
    DynamicArray* arr = createDynamicArray();
    pushDynamicArray(arr, 10);
    pushDynamicArray(arr, 20);
    pushDynamicArray(arr, 30);
    pushDynamicArray(arr, 40);
    pushDynamicArray(arr, 50);
    printf("%d popped from the array\n", popDynamicArray(arr));
    printf("%d popped from the array\n", popDynamicArray(arr));
    destroyDynamicArray(arr);
    return 0;
}