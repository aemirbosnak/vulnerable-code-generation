//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
struct node {
    int data;
    struct node *next;
};

// Linked list head
struct node *head = NULL;

// Function to add a new entry to the index
void addEntry(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

// Function to delete an entry from the index
void deleteEntry(int data) {
    struct node *temp = head;
    struct node *prev = NULL;

    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp!= NULL) {
        if (prev == NULL) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }
        free(temp);
    }
}

// Function to search for an entry in the index
int searchEntry(int data) {
    struct node *temp = head;
    while (temp!= NULL) {
        if (temp->data == data) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    addEntry(5);
    addEntry(10);
    addEntry(15);
    printf("%d\n", searchEntry(5));
    printf("%d\n", searchEntry(20));

    deleteEntry(10);
    printf("%d\n", searchEntry(10));

    return 0;
}