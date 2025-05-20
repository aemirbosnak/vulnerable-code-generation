//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: scalable
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_NAME_LENGTH 256
#define MAX_PHONE_NUMBER_LENGTH 64
#define MAX_ADDRESS_LENGTH 256

struct phone_book {
    char *name;
    char *phone_number;
    char *address;
    struct phone_book *next;
};

struct phone_book *root = NULL;

void insert(char *name, char *phone_number, char *address) {
    struct phone_book *new_node = (struct phone_book *) malloc(sizeof(struct phone_book));
    new_node->name = name;
    new_node->phone_number = phone_number;
    new_node->address = address;
    new_node->next = NULL;

    if (root == NULL) {
        root = new_node;
    } else {
        struct phone_book *current = root;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void search(char *name) {
    struct phone_book *current = root;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("Found phone number: %s\n", current->phone_number);
            printf("Found address: %s\n", current->address);
            return;
        }
        current = current->next;
    }
    printf("Not found\n");
}

void delete(char *name) {
    struct phone_book *current = root;
    struct phone_book *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                root = current->next;
            } else {
                prev->next = current->next;
            }
            free(current->name);
            free(current->phone_number);
            free(current->address);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Not found\n");
}

int main() {
    insert("John Doe", "555-1234", "123 Main St");
    insert("Jane Doe", "555-5678", "456 Elm St");
    insert("Bob Smith", "555-9012", "789 Oak St");

    search("John Doe");
    search("Jane Doe");
    search("Bob Smith");

    delete("John Doe");

    search("John Doe");

    return 0;
}