//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* node) {
    if (node == NULL) {
        printf("The list is empty\n");
        return;
    }
    printf("List elements are: ");
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = NULL;

    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    second->data = 2;
    second->next = NULL;

    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    third->data = 3;
    third->next = NULL;

    struct Node* fourth = (struct Node*)malloc(sizeof(struct Node));
    fourth->data = 4;
    fourth->next = NULL;

    struct Node* fifth = (struct Node*)malloc(sizeof(struct Node));
    fifth->data = 5;
    fifth->next = NULL;

    struct Node* sixth = (struct Node*)malloc(sizeof(struct Node));
    sixth->data = 6;
    sixth->next = NULL;

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    printList(head);
    return 0;
}