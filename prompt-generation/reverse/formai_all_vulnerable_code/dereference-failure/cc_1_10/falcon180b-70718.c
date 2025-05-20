//Falcon-180B DATASET v1.0 Category: Educational ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node *next;
} Node;

Node *createList(int n) {
    Node *head = NULL;
    int i;

    for (i = 0; i < n; i++) {
        Node *newNode = (Node *) malloc(sizeof(Node));
        newNode->data = i;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node *temp = head;

            while (temp->next!= NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    return head;
}

void printList(Node *head) {
    Node *temp = head;

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void reverseList(Node *head) {
    Node *prev = NULL;
    Node *curr = head;

    while (curr!= NULL) {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    Node *head = createList(n);
    printf("Original list: ");
    printList(head);
    reverseList(head);
    printf("\nReversed list: ");
    printList(head);

    return 0;
}