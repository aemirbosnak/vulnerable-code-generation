//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50

typedef struct Node {
    char data[MAX_LEN];
    int len;
    struct Node *next;
} Node;

Node *head = NULL;

void init() {
    head = NULL;
}

void insert(char *str) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    int len = strlen(str);

    if (len > MAX_LEN) {
        printf("Error: String too long\n");
        free(new_node);
        return;
    }

    strcpy(new_node->data, str);
    new_node->len = len;
    new_node->next = head;
    head = new_node;
}

void delete(char *str) {
    Node *current = head, *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->data, str) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("Error: Element not found\n");
}

Node *search(char *str) {
    Node *current = head;

    while (current != NULL) {
        if (strcmp(current->data, str) == 0) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

void display() {
    Node *current = head;

    while (current != NULL) {
        printf("%s (%d)\n", current->data, current->len);
        current = current->next;
    }
}

int main() {
    init();

    insert("Hello");
    insert("World");
    insert("Linked");
    insert("List");

    display();

    Node *found = search("Linked");
    if (found != NULL) {
        printf("Found: %s (%d)\n", found->data, found->len);
    }

    delete("World");

    display();

    return 0;
}