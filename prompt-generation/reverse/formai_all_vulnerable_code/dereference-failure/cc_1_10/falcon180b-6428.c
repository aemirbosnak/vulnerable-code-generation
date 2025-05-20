//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure definition
struct Node {
    int data;
    struct Node* next;
};

void addNodeAtBeginning(struct Node** start_ref, int data);
void addNodeAtEnd(struct Node** start_ref, int data);
void deleteNode(struct Node** start_ref, int data);
void display(struct Node* node);

int main() {
    struct Node* start = NULL;

    // Adding nodes
    addNodeAtBeginning(&start, 10);
    addNodeAtEnd(&start, 20);
    addNodeAtBeginning(&start, 5);
    addNodeAtEnd(&start, 30);

    // Displaying list
    printf("List after adding nodes: ");
    display(start);

    // Deleting nodes
    deleteNode(&start, 5);
    deleteNode(&start, 30);

    // Displaying list after deleting nodes
    printf("\nList after deleting nodes: ");
    display(start);

    return 0;
}

void addNodeAtBeginning(struct Node** start_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = (*start_ref);
    (*start_ref) = new_node;
}

void addNodeAtEnd(struct Node** start_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*start_ref == NULL) {
        new_node->next = NULL;
        (*start_ref) = new_node;
    }
    else {
        struct Node* last = *start_ref;

        while (last->next!= NULL)
            last = last->next;

        last->next = new_node;
    }
}

void deleteNode(struct Node** start_ref, int data) {
    struct Node* temp = *start_ref;

    if (temp!= NULL && temp->data == data) {
        temp = temp->next;
        (*start_ref) = temp;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= data) {
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    struct Node* prev = temp->next;
    temp->next = NULL;
    free(temp);
    temp = prev;
}

void display(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}