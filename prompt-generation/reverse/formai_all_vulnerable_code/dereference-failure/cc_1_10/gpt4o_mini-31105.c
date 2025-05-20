//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 5
#define BUFFER_SIZE 100

// Function prototypes
char** createList(int capacity);
void addItem(char*** list, int* size, int* capacity, const char* item);
void removeItem(char** list, int* size, const char* item);
void listItems(char** list, int size);
void freeList(char** list, int size);
void clearBuffer();

int main() {
    char** itemList = createList(INITIAL_CAPACITY);
    int size = 0;
    int capacity = INITIAL_CAPACITY;

    char choice[10];
    char item[BUFFER_SIZE];

    do {
        printf("\nMenu:\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. List Items\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        fgets(choice, sizeof(choice), stdin);
        
        switch (choice[0]) {
            case '1':
                printf("Enter item to add: ");
                fgets(item, sizeof(item), stdin);
                item[strcspn(item, "\n")] = 0; // Remove trailing newline
                addItem(&itemList, &size, &capacity, item);
                break;
            case '2':
                printf("Enter item to remove: ");
                fgets(item, sizeof(item), stdin);
                item[strcspn(item, "\n")] = 0; // Remove trailing newline
                removeItem(itemList, &size, item);
                break;
            case '3':
                listItems(itemList, size);
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice[0] != '4');

    freeList(itemList, size);
    return 0;
}

char** createList(int capacity) {
    char** list = malloc(capacity * sizeof(char*));
    if (!list) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return list;
}

void addItem(char*** list, int* size, int* capacity, const char* item) {
    if (*size >= *capacity) {
        *capacity *= 2;
        char** newList = realloc(*list, *capacity * sizeof(char*));
        if (!newList) {
            fprintf(stderr, "Memory reallocation failed!\n");
            exit(EXIT_FAILURE);
        }
        *list = newList;
    }
    (*list)[*size] = malloc((strlen(item) + 1) * sizeof(char));
    if (!(*list)[*size]) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    strcpy((*list)[*size], item);
    (*size)++;
    printf("Added item: %s\n", item);
}

void removeItem(char** list, int* size, const char* item) {
    for (int i = 0; i < *size; i++) {
        if (strcmp(list[i], item) == 0) {
            free(list[i]);
            for (int j = i; j < *size - 1; j++) {
                list[j] = list[j + 1]; // Shift remaining items
            }
            (*size)--;
            printf("Removed item: %s\n", item);
            return;
        }
    }
    printf("Item not found: %s\n", item);
}

void listItems(char** list, int size) {
    if (size == 0) {
        printf("No items in the list.\n");
        return;
    }
    printf("Items in the list:\n");
    for (int i = 0; i < size; i++) {
        printf("%d: %s\n", i + 1, list[i]);
    }
}

void freeList(char** list, int size) {
    for (int i = 0; i < size; i++) {
        free(list[i]);
    }
    free(list);
}