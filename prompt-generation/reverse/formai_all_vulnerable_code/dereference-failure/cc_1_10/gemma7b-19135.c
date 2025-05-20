//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define DELAY 150

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void initialize_list(Node** head) {
    *head = NULL;
}

void insert_at_tail(Node** head, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void print_list(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    initialize_list(&head);

    // Insert data into the list
    insert_at_tail(&head, 10);
    insert_at_tail(&head, 20);
    insert_at_tail(&head, 30);
    insert_at_tail(&head, 40);

    // Print the list
    print_list(head);

    // Sleep for a while
    sleep(DELAY);

    // Delete data from the list
    insert_at_tail(&head, 50);
    print_list(head);

    return 0;
}