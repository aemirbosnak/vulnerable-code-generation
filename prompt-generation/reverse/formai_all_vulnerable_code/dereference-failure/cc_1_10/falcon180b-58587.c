//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Node structure definition
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add a node at the end of the list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = newNode(new_data);
    struct Node* last = *head_ref;

    if (*head_ref == NULL) {
        new_node->next = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next!= NULL)
        last = last->next;

    last->next = new_node;
    return;
}

// Function to search for an element in the linked list
int search(struct Node* head, int x) {
    struct Node* current = head;

    while (current!= NULL) {
        if (current->data == x)
            return 1;
        current = current->next;
    }

    return 0;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    int n, x, pos, c;
    struct Node* head = NULL;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (c = 0; c < n; c++) {
        scanf("%d", &x);
        push(&head, x);
    }

    printf("Enter the element to search: ");
    scanf("%d", &x);

    if (search(head, x))
        printf("%d found!\n", x);
    else
        printf("%d not found!\n", x);

    return 0;
}