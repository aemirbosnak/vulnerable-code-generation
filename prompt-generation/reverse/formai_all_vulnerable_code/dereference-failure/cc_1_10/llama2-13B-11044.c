//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 20

struct phone_book {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
    struct phone_book *next;
};

struct phone_book *root = NULL;

void insert(char *name, char *phone_number) {
    struct phone_book *new_node = (struct phone_book *)malloc(sizeof(struct phone_book));
    strcpy(new_node->name, name);
    strcpy(new_node->phone_number, phone_number);
    new_node->next = root;
    root = new_node;
}

void search(char *name) {
    struct phone_book *current = root;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("%s %s\n", current->name, current->phone_number);
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
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Not found\n");
}

int main() {
    srand(time(NULL));

    insert("Alice", "555-1234");
    insert("Bob", "555-5678");
    insert("Charlie", "555-9012");
    insert("David", "555-1111");

    search("Alice");
    search("Bob");
    search("Charlie");
    search("David");

    delete("Alice");

    search("Alice");

    return 0;
}