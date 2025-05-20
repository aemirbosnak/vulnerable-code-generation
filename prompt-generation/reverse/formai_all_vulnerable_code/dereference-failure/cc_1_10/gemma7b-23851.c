//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

struct Node {
    char name[20];
    int hour;
    struct Node* next;
};

void schedule(struct Node* head) {
    if (head) {
        printf("%s at %d: ", head->name, head->hour);
        schedule(head->next);
    }
}

int main() {
    struct Node* head = NULL;
    struct Node* newNode = NULL;

    // Create a new node
    newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, "John Doe");
    newNode->hour = 10;
    newNode->next = NULL;

    // Add the new node to the head
    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
        head = newNode;
    }

    // Create another new node
    newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, "Jane Doe");
    newNode->hour = 12;
    newNode->next = NULL;

    // Add the new node to the head
    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
        head = newNode;
    }

    // Schedule the nodes
    schedule(head);

    return 0;
}