//Falcon-180B DATASET v1.0 Category: Memory management ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int size;
    char *data;
} DynamicArray;

DynamicArray *createArray(int size) {
    DynamicArray *array = (DynamicArray *)malloc(sizeof(DynamicArray));
    if (array == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    array->size = size;
    array->data = (char *)malloc(size * sizeof(char));
    if (array->data == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    memset(array->data, '\0', size);
    return array;
}

void destroyArray(DynamicArray *array) {
    free(array->data);
    free(array);
}

void resizeArray(DynamicArray *array, int newSize) {
    char *newData = (char *)realloc(array->data, newSize * sizeof(char));
    if (newData == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    array->data = newData;
    array->size = newSize;
}

void append(DynamicArray *array, char *string) {
    int length = strlen(string);
    if (array->size - array->data[array->size - 1] < length) {
        resizeArray(array, array->size + length);
    }
    strcat(array->data, string);
}

int main() {
    DynamicArray *array = createArray(MAX_SIZE);
    char *string1 = "Hello, world!";
    char *string2 = "This is a test.";
    char *string3 = "Another string to append.";

    append(array, string1);
    append(array, string2);
    append(array, string3);

    printf("Array contents:\n%s\n", array->data);

    destroyArray(array);

    return 0;
}