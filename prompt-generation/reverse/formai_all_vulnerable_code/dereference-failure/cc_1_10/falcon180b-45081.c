//Falcon-180B DATASET v1.0 Category: Recursive ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

void printLinkedList(Node *head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void deleteLinkedList(Node *head) {
    while (head!= NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}

void mergeLinkedList(Node *list1, Node *list2) {
    Node *head1 = list1;
    Node *head2 = list2;
    Node *result = NULL;
    Node *temp = NULL;

    if (head1 == NULL) {
        result = head2;
    } else if (head2 == NULL) {
        result = head1;
    } else if (head1->data <= head2->data) {
        result = head1;
        temp = head1;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = head2;
    } else {
        result = head2;
        temp = head2;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = head1;
    }

    printf("Result: ");
    printLinkedList(result);
}

int main() {
    Node *list1 = NULL;
    Node *list2 = NULL;

    list1 = (Node *)malloc(sizeof(Node));
    list1->data = 1;
    list1->next = NULL;

    list2 = (Node *)malloc(sizeof(Node));
    list2->data = 2;
    list2->next = NULL;

    printf("List 1: ");
    printLinkedList(list1);

    printf("List 2: ");
    printLinkedList(list2);

    mergeLinkedList(list1, list2);

    deleteLinkedList(list1);
    deleteLinkedList(list2);

    return 0;
}