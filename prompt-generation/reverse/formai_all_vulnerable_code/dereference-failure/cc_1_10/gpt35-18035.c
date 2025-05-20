//FormAI DATASET v1.0 Category: Data structures visualization ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int* data;
    int maxSize;
    int size;
} Array;

Array* newArray(int maxSize){
    Array* arr = (Array*)malloc(sizeof(Array));
    arr->data = (int*)malloc(sizeof(int) * maxSize);
    arr->maxSize = maxSize;
    arr->size = 0;

    return arr;
}

void append(Array* arr, int value){
    if(arr->size == arr->maxSize){
        printf("Error: Array is full.\n");
        return;
    }

    arr->data[arr->size++] = value;
}

void insert(Array* arr, int index, int value){
    if(arr->size == arr->maxSize){
        printf("Error: Array is full.\n");
        return;
    }

    if(index < 0 || index >= arr->size){
        printf("Error: Invalid index.\n");
        return;
    }

    for(int i = arr->size - 1; i >= index; i--){
        arr->data[i+1] = arr->data[i];
    }

    arr->data[index] = value;
    arr->size++;
}

void delete(Array* arr, int index){
    if(index < 0 || index >= arr->size){
        printf("Error: Invalid index.\n");
        return;
    }

    for(int i = index; i < arr->size - 1; i++){
        arr->data[i] = arr->data[i+1];
    }

    arr->size--;
}

void print(Array* arr){
    for(int i = 0; i < arr->size; i++){
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

int main(){
    Array* arr = newArray(10);

    // Initial array contents: []
    append(arr, 5); // [5]
    append(arr, 7); // [5, 7]
    append(arr, 10); // [5, 7, 10]
    insert(arr, 0, 2); // [2, 5, 7, 10]
    insert(arr, 1, 3); // [2, 3, 5, 7, 10]
    insert(arr, 3, 8); // [2, 3, 5, 8, 7, 10]
    delete(arr, 4); // [2, 3, 5, 8, 10]

    print(arr);

    free(arr->data);
    free(arr);
    return 0;
}