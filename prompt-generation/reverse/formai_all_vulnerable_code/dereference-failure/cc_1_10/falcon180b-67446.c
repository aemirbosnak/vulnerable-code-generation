//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

// Define the node structure
typedef struct node {
    int data;
    struct node *next;
} Node;

Node *head = NULL; // Define the head of the linked list

void add_node(int data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        Node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void search_node(int data) {
    Node *temp = head;
    int found = FALSE;
    while (temp!= NULL) {
        if (temp->data == data) {
            found = TRUE;
            break;
        }
        temp = temp->next;
    }
    if (found == TRUE) {
        printf("Node found\n");
    } else {
        printf("Node not found\n");
    }
}

int main() {
    add_node(5);
    add_node(10);
    add_node(15);
    add_node(20);

    search_node(10);
    search_node(25);

    return 0;
}