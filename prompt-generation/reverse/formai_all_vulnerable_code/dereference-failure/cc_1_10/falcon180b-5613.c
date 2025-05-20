//Falcon-180B DATASET v1.0 Category: Sorting ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

void printList(Node *head) {
    Node *temp = head;
    while (temp!= NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void merge(Node **head, Node *a, Node *b) {
    Node *temp = *head;
    if (temp == NULL) {
        *head = a;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = a;
}

void mergeSort(Node **head) {
    Node *a, *b;
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
    a = *head;
    b = (*head)->next;
    (*head) = NULL;
    mergeSort(&a);
    mergeSort(&b);
    merge(head, a, b);
}

int main() {
    Node *head = NULL;
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        Node *newnode = (Node*)malloc(sizeof(Node));
        newnode->data = x;
        newnode->next = NULL;
        if (head == NULL) {
            head = newnode;
        }
        else {
            Node *temp = head;
            while (temp->next!= NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
    printf("Unsorted list:\n");
    printList(head);
    mergeSort(&head);
    printf("Sorted list:\n");
    printList(head);
    return 0;
}