//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int key;
    char *name;
    struct Node *next;
} Node;

Node *head = NULL;

void create_node(int k, char *n) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->key = k;
    new_node->name = strdup(n);
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        Node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void display_list() {
    Node *current = head;
    while (current != NULL) {
        printf("Key: %d, Name: %s, Next: %p\n", current->key, current->name, current->next);
        current = current->next;
    }
}

void delete_node(int key) {
    Node *current = head;
    Node *previous = NULL;

    if (head != NULL && head->key == key) {
        head = head->next;
        free(current);
        return;
    }

    while (current != NULL && current->key != key) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with key %d not found.\n", key);
        return;
    }

    previous->next = current->next;
    free(current);
}

int main() {
    int i;
    char names[10][20] = {"Apple", "Banana", "Cherry", "Date", "Fig", "Grape", "Kiwi", "Mango", "Orange", "Pineapple"};

    for (i = 0; i < 11; i++) {
        create_node(i, names[i]);
    }

    display_list();

    printf("\nDeleting node with key 6\n");
    delete_node(6);
    display_list();

    printf("\nDeleting node with key 0\n");
    delete_node(0);
    display_list();

    return 0;
}