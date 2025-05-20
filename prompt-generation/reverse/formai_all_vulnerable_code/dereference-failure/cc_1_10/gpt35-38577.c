//FormAI DATASET v1.0 Category: Data structures visualization ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

/*
 * This program demonstrates a unique visualization of a linked list data structure.
 * The program creates nodes with random integer values and links them to form a list.
 * The visual representation of the list is shown by printing the list elements as a horizontal bar. Each node is represented
 * by a dot on the bar and its value is shown above it.
 */

typedef struct node {
    int val;
    struct node* next;
} Node;

void insert(Node** head, int val) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(Node* head) {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d |", temp->val);
        for (int i = 0; i < temp->val; i++) { // print a dot for each node value
            printf(".");
        }
        printf("\n");
        temp = temp->next;
    }
}

int main() {
    Node* head = NULL;

    // create a list of nodes with random values
    insert(&head, 3);
    insert(&head, 7);
    insert(&head, 2);
    insert(&head, 5);
    insert(&head, 9);

    // print the bar chart representation of the list
    printList(head);

    // free allocated memory
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}