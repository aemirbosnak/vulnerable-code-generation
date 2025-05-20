//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int main() {
    Node* head = NULL;
    head = malloc(sizeof(Node));
    head->data = 10;
    head->next = NULL;

    Node* second = malloc(sizeof(Node));
    second->data = 20;
    second->next = NULL;

    head->next = second;

    Node* third = malloc(sizeof(Node));
    third->data = 30;
    third->next = NULL;

    second->next = third;

    // Visualization
    printf("Here is your linked list:\n");
    Node* current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // Traversal
    printf("Traversing the list:\n");
    current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // Searching for data
    printf("Searching for data 20:\n");
    current = head;
    while (current) {
        if (current->data == 20) {
            printf("Data found!\n");
            break;
        }
        current = current->next;
    }
    if (current == NULL) {
        printf("Data not found.\n");
    }

    // Insertion at the end
    printf("Inserting data 40 at the end:\n");
    Node* fourth = malloc(sizeof(Node));
    fourth->data = 40;
    fourth->next = NULL;

    current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = fourth;

    // Print the updated list
    printf("Here is the updated list:\n");
    current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}