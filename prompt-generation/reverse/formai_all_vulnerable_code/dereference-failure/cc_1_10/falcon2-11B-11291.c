//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    struct Node* next;
};

struct Node* root = NULL;

void add_to_phone_book(char* name) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    strcpy(new_node->name, name);
    new_node->next = NULL;
    if (root == NULL) {
        root = new_node;
    } else {
        struct Node* current = root;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void print_phone_book() {
    struct Node* current = root;
    while (current!= NULL) {
        printf("%s\n", current->name);
        current = current->next;
    }
}

void search_phone_book(char* name) {
    struct Node* current = root;
    while (current!= NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("Found: %s\n", name);
            return;
        }
        current = current->next;
    }
    printf("Not found: %s\n", name);
}

void delete_from_phone_book(char* name) {
    struct Node* current = root;
    while (current!= NULL) {
        if (strcmp(current->name, name) == 0) {
            struct Node* temp = current->next;
            free(current);
            current = temp;
        } else {
            current = current->next;
        }
    }
}

int main() {
    char* name;
    while (scanf("%s", &name)!= EOF) {
        if (strcmp(name, "quit") == 0) {
            break;
        }
        if (strcmp(name, "print") == 0) {
            print_phone_book();
        } else if (strcmp(name, "search") == 0) {
            search_phone_book(name);
        } else if (strcmp(name, "add") == 0) {
            add_to_phone_book(name);
        } else if (strcmp(name, "delete") == 0) {
            delete_from_phone_book(name);
        } else {
            printf("Invalid command\n");
        }
    }
    return 0;
}