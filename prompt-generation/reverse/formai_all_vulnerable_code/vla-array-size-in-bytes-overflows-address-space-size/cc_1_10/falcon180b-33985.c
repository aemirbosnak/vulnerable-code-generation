//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void deleteNode(Node* node) {
    while (node!= NULL) {
        Node* temp = node;
        node = node->next;
        free(temp);
    }
}

void printLinkedList(Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

void bucketSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int bucketSize = max / n;
    Node** buckets = (Node**)malloc(n * sizeof(Node*));
    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        Node* node = createNode(arr[i]);
        int bucketIndex = arr[i] / bucketSize;
        node->next = buckets[bucketIndex];
        buckets[bucketIndex] = node;
    }

    int index = 0;
    for (int i = 0; i < n; i++) {
        Node* head = buckets[i];
        while (head!= NULL) {
            arr[index++] = head->data;
            head = head->next;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array: ");
    printLinkedList(arr);

    return 0;
}