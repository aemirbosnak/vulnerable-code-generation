//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 5
#define INCREMENT_SIZE 5

typedef struct {
    char **data;
    size_t size;
    size_t capacity;
} StringList;

// Function to initialize the StringList
void initStringList(StringList *list) {
    list->size = 0;
    list->capacity = INITIAL_SIZE;
    list->data = (char **)malloc(list->capacity * sizeof(char *));
    if (list->data == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
}

// Function to resize the StringList
void resizeStringList(StringList *list) {
    list->capacity += INCREMENT_SIZE;
    list->data = (char **)realloc(list->data, list->capacity * sizeof(char *));
    if (list->data == NULL) {
        fprintf(stderr, "Memory reallocation failed!\n");
        exit(EXIT_FAILURE);
    }
}

// Function to add a string to the list
void addString(StringList *list, const char *str) {
    if (list->size >= list->capacity) {
        resizeStringList(list);
    }
    list->data[list->size] = (char *)malloc((strlen(str) + 1) * sizeof(char));
    if (list->data[list->size] == NULL) {
        fprintf(stderr, "Memory allocation for string failed!\n");
        exit(EXIT_FAILURE);
    }
    strcpy(list->data[list->size], str);
    list->size++;
}

// Function to free the StringList
void freeStringList(StringList *list) {
    for (size_t i = 0; i < list->size; i++) {
        free(list->data[i]);
    }
    free(list->data);
    list->size = 0;
    list->capacity = 0;
}

// Function to print the StringList
void printStringList(const StringList *list) {
    printf("StringList contents (%zu elements):\n", list->size);
    for (size_t i = 0; i < list->size; i++) {
        printf("  [%zu]: %s\n", i, list->data[i]);
    }
}

// Main function to demonstrate the usage of StringList
int main() {
    StringList list;
    initStringList(&list);

    addString(&list, "Hello");
    addString(&list, "World");
    addString(&list, "This");
    addString(&list, "is");
    addString(&list, "a");
    addString(&list, "dynamic");
    addString(&list, "string");
    addString(&list, "management");
    addString(&list, "example!");

    printStringList(&list);

    freeStringList(&list);
    return 0;
}