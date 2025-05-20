//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50

typedef struct {
    char name[MAX_LEN];
    int quantity;
    struct node *next;
} Node;

Node *head = NULL;

void add_resource(char *name, int quantity) {
    Node *new_node = (Node *)malloc(sizeof(Node));

    strcpy(new_node->name, name);
    new_node->quantity = quantity;

    if (head == NULL) {
        head = new_node;
        return;
    }

    Node *current = head;

    while (current->next != NULL) {
        if (strcmp(current->name, name) > 0) {
            new_node->next = current;
            current->next = new_node;
            return;
        }
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
}

void display_resources() {
    Node *current = head;

    printf("\nResources:\n");
    while (current != NULL) {
        printf("%s: %d\n", current->name, current->quantity);
        current = current->next;
    }
}

int main() {
    add_resource("Water", 10);
    add_resource("Canned Food", 5);
    add_resource("Ammunition", 20);
    add_resource("Water", 5);
    add_resource("Canned Food", 3);

    display_resources();

    return 0;
}