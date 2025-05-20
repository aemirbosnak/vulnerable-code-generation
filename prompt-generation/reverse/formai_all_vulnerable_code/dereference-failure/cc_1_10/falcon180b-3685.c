//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} node;

node* createLinkedList() {
    node* head = NULL;
    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        node* newNode = (node*) malloc(sizeof(node));
        if (newNode == NULL) {
            printf("Memory error\n");
            exit(0);
        }
        newNode->data = i;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
        }
        else {
            node* temp = head;
            while (temp->next!= NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    return head;
}

void displayLinkedList(node* head) {
    node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void bucketSort(node* head) {
    node* temp = head;
    int i, j, bucket[MAX_SIZE];
    while (temp!= NULL) {
        i = temp->data;
        temp = temp->next;
        bucket[i]++;
    }
    temp = head;
    while (temp!= NULL) {
        i = temp->data;
        j = bucket[i] - 1;
        while (j >= 0) {
            printf("%d ", temp->data);
            temp = temp->next;
            j--;
        }
        bucket[i] = 0;
    }
}

int main() {
    node* head = createLinkedList();
    printf("Original Linked List: ");
    displayLinkedList(head);
    printf("\n");
    bucketSort(head);
    return 0;
}