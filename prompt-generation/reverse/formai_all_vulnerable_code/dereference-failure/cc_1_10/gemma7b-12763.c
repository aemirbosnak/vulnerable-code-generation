//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int main() {
    Node* head = NULL;
    head = malloc(sizeof(Node));
    head->data = 1;
    head->next = NULL;

    Node* second = malloc(sizeof(Node));
    second->data = 2;
    second->next = NULL;

    head->next = second;

    Node* third = malloc(sizeof(Node));
    third->data = 3;
    third->next = NULL;

    second->next = third;

    Node* fourth = malloc(sizeof(Node));
    fourth->data = 4;
    fourth->next = NULL;

    third->next = fourth;

    Node* fifth = malloc(sizeof(Node));
    fifth->data = 5;
    fifth->next = NULL;

    fourth->next = fifth;

    Node* sixth = malloc(sizeof(Node));
    sixth->data = 6;
    sixth->next = NULL;

    fifth->next = sixth;

    Node* seventh = malloc(sizeof(Node));
    seventh->data = 7;
    seventh->next = NULL;

    sixth->next = seventh;

    Node* eighth = malloc(sizeof(Node));
    eighth->data = 8;
    eighth->next = NULL;

    seventh->next = eighth;

    Node* ninth = malloc(sizeof(Node));
    ninth->data = 9;
    ninth->next = NULL;

    eighth->next = ninth;

    Node* tenth = malloc(sizeof(Node));
    tenth->data = 10;
    tenth->next = NULL;

    ninth->next = tenth;

    printf("The data in the linked list is:");
    for (Node* current = head; current; current = current->next) {
        printf(" %d", current->data);
    }

    return 0;
}