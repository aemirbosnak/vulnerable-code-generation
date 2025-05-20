//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createLinkedList(int size) {
    Node* head = NULL;
    Node* tail = NULL;
    int i;
    for (i = 0; i < size; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = rand() % MAX_SIZE;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

void printLinkedList(Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void bucketSort(Node* head) {
    Node* tempHead = head;
    int max = 0;
    int i;
    while (tempHead!= NULL) {
        if (tempHead->data > max) {
            max = tempHead->data;
        }
        tempHead = tempHead->next;
    }
    int bucketSize = max / MAX_SIZE;
    Node* buckets[MAX_SIZE];
    for (i = 0; i < MAX_SIZE; i++) {
        buckets[i] = NULL;
    }
    tempHead = head;
    while (tempHead!= NULL) {
        int bucketIndex = tempHead->data / bucketSize;
        Node* curBucket = buckets[bucketIndex];
        if (curBucket == NULL) {
            curBucket = tempHead;
        }
        else {
            curBucket->next = tempHead;
        }
        buckets[bucketIndex] = curBucket;
        tempHead = tempHead->next;
    }
    head = NULL;
    for (i = 0; i < MAX_SIZE; i++) {
        Node* curBucket = buckets[i];
        if (curBucket!= NULL) {
            while (curBucket->next!= NULL) {
                curBucket = curBucket->next;
            }
            curBucket->next = head;
            head = buckets[i];
        }
    }
}

int main() {
    int size = 50;
    Node* linkedList = createLinkedList(size);
    printLinkedList(linkedList);
    bucketSort(linkedList);
    printf("Sorted Linked List:\n");
    printLinkedList(linkedList);
    return 0;
}