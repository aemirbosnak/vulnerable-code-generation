//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define INITIAL_CAPACITY 5

typedef struct {
    char **names;
    int count;
    int capacity;
} NameList;

// Function prototypes
NameList *createNameList();
void addName(NameList *list, const char *name);
void deleteNameList(NameList *list);
void displayNames(NameList *list);
void resizeNameList(NameList *list);

int main() {
    NameList *nameList = createNameList();
    char name[MAX_NAME_LENGTH];

    printf("Enter names (type 'exit' to finish):\n");

    while (1) {
        printf("Name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = 0; // Remove newline character

        if (strcmp(name, "exit") == 0) {
            break;
        }
        addName(nameList, name);
    }

    displayNames(nameList);
    deleteNameList(nameList);

    return 0;
}

NameList *createNameList() {
    NameList *list = (NameList *)malloc(sizeof(NameList));
    if (!list) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    list->names = (char **)malloc(INITIAL_CAPACITY * sizeof(char *));
    if (!list->names) {
        free(list);
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    list->count = 0;
    list->capacity = INITIAL_CAPACITY;
    return list;
}

void addName(NameList *list, const char *name) {
    if (list->count >= list->capacity) {
        resizeNameList(list);
    }
    list->names[list->count] = (char *)malloc((strlen(name) + 1) * sizeof(char));
    if (!list->names[list->count]) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    strcpy(list->names[list->count], name);
    list->count++;
}

void resizeNameList(NameList *list) {
    list->capacity *= 2;
    list->names = (char **)realloc(list->names, list->capacity * sizeof(char *));
    if (!list->names) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
}

void displayNames(NameList *list) {
    printf("\nYou entered the following names:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%s\n", list->names[i]);
    }
}

void deleteNameList(NameList *list) {
    for (int i = 0; i < list->count; i++) {
        free(list->names[i]);
    }
    free(list->names);
    free(list);
}