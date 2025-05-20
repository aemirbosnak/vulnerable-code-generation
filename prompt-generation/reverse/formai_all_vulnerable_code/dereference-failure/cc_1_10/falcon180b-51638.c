//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 // maximum size of the array
#define MAX_STRING 1000 // maximum length of a string

typedef struct {
    char *strings[MAX_SIZE]; // array of strings
    int size; // size of the array
} StringArray;

StringArray *createArray() {
    StringArray *array = (StringArray*) malloc(sizeof(StringArray));
    array->size = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        array->strings[i] = (char*) malloc(MAX_STRING);
        strcpy(array->strings[i], "");
    }
    return array;
}

void addString(StringArray *array, char *string) {
    if (array->size >= MAX_SIZE) {
        printf("Error: array is full\n");
        return;
    }
    strcpy(array->strings[array->size], string);
    array->size++;
}

int searchArray(StringArray *array, char *searchString) {
    for (int i = 0; i < array->size; i++) {
        if (strcmp(array->strings[i], searchString) == 0) {
            return i;
        }
    }
    return -1; // string not found
}

int main() {
    StringArray *array = createArray();
    char string[MAX_STRING];
    int choice, index;
    while (1) {
        printf("1. Add string\n");
        printf("2. Search string\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter string: ");
                scanf("%s", string);
                addString(array, string);
                break;
            case 2:
                printf("Enter string to search: ");
                scanf("%s", string);
                index = searchArray(array, string);
                if (index!= -1) {
                    printf("String found at index %d\n", index);
                } else {
                    printf("String not found\n");
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}