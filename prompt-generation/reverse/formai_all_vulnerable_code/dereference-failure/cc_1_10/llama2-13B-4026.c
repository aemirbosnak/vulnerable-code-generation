//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Knight {
    int gold;
    struct Knight *prev;
    struct Knight *next;
};

// Function to create a new node with the given gold amount
struct Knight *newKnight(int gold) {
    struct Knight *newNode = (struct Knight *) malloc(sizeof(struct Knight));
    newNode->gold = gold;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node to the beginning of the list
void enlist(struct Knight **head_ref, int gold) {
    struct Knight *newNode = newKnight(gold);
    newNode->prev = NULL;
    newNode->next = *head_ref;
    if (*head_ref != NULL) {
        (*head_ref)->prev = newNode;
    }
    *head_ref = newNode;
}

// Function to add a node to the end of the list
void enlist_tail(struct Knight **head_ref, int gold) {
    struct Knight *newNode = newKnight(gold);
    struct Knight *current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    newNode->next = NULL;
}

// Function to remove the node with the given gold amount
void dismiss(struct Knight **head_ref, int gold) {
    struct Knight *current = *head_ref;
    struct Knight *prev = NULL;
    while (current != NULL && current->gold != gold) {
        prev = current;
        current = current->next;
    }
    if (current != NULL) {
        if (prev == NULL) {
            *head_ref = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
    }
}

// Function to print the list of knights
void printList(struct Knight *head) {
    while (head != NULL) {
        printf("%d gold\n", head->gold);
        head = head->next;
    }
}

int main() {
    struct Knight *head = NULL;
    enlist(&head, 100);
    enlist(&head, 50);
    enlist_tail(&head, 200);
    dismiss(&head, 50);
    printList(head);
    return 0;
}