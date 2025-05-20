//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: careful
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *head;

void add_item(int data) {
    node *new_node = (node *) malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        node *current = head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void search_item(int data) {
    node *current = head;
    while (current!= NULL) {
        if (current->data == data) {
            printf("Item found: %d\n", data);
        }
        current = current->next;
    }
}

void display_inventory() {
    node *current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    add_item(10);
    add_item(20);
    add_item(30);
    search_item(10);
    search_item(25);
    display_inventory();
    return 0;
}