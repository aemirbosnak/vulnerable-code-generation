//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *name;
    char *phone;
    struct Node *next;
} Node;

Node *head = NULL;

void insert(char *name, char *phone) {
    Node *new_node = malloc(sizeof(Node));
    new_node->name = strdup(name);
    new_node->phone = strdup(phone);
    new_node->next = head;
    head = new_node;
}

void print() {
    Node *current = head;
    while (current != NULL) {
        printf("%s %s\n", current->name, current->phone);
        current = current->next;
    }
}

void search(char *name) {
    Node *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("%s %s\n", current->name, current->phone);
            return;
        }
        current = current->next;
    }
    printf("Name not found.\n");
}

void delete(char *name) {
    Node *current = head;
    Node *prev = NULL;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current->name);
            free(current->phone);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Name not found.\n");
}

int main() {
    insert("John Doe", "555-1234");
    insert("Jane Doe", "555-1235");
    insert("John Smith", "555-1236");
    insert("Jane Smith", "555-1237");

    print();

    search("John Doe");
    search("Jane Smith");
    search("Bob Jones");

    delete("John Doe");
    delete("Bob Jones");

    print();

    return 0;
}