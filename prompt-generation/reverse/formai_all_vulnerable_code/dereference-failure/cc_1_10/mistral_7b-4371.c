//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50

typedef struct Node {
    int data;
    char name[SIZE];
    struct Node* next;
} Node;

void printList(Node* head) {
    Node* current = head;
    int i = 1;

    printf("Linked List:\n");
    while (current != NULL) {
        printf("Node %d:\n", i);
        printf("Data: %d\n", current->data);
        printf("Name: %s\n", current->name);
        current = current->next;
        i++;
    }

    printf("\nASCII Art:\n");
    for (int j = 1; j <= i; j++) {
        if (j == 1) {
            printf("+-----------------+");
        } else if (j == i) {
            printf("+-----------------+");
        } else {
            printf("+-----------------+");
            printf("|                 |");
        }
        printf("\n| %2d | %-15s | %-15s |", j, current->name, current->data > 0 ? "Positive" : "Negative");
        printf("|                 |");
        printf("\n+-----------------+");
    }
}

int main() {
    Node* head = NULL;
    Node* newNode1 = (Node*)malloc(sizeof(Node));
    Node* newNode2 = (Node*)malloc(sizeof(Node));
    Node* newNode3 = (Node*)malloc(sizeof(Node));

    head = newNode1;

    strcpy(newNode1->name, "John");
    newNode1->data = 5;

    newNode2 = (Node*)malloc(sizeof(Node));
    head->next = newNode2;

    strcpy(newNode2->name, "Mike");
    newNode2->data = -3;

    newNode3 = (Node*)malloc(sizeof(Node));
    newNode2->next = newNode3;

    strcpy(newNode3->name, "Sara");
    newNode3->data = 8;

    printList(head);

    free(newNode1);
    free(newNode2);
    free(newNode3);
    free(head);

    return 0;
}