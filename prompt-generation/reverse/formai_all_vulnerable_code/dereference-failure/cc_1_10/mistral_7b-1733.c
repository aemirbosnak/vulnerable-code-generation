//MISTRAL-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TABLE_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int hashFunction(int key) {
    return (key % TABLE_SIZE + TABLE_SIZE) % TABLE_SIZE;
}

void insertNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL && current->next->data < data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void bucketSort(int arr[], int size) {
    Node** buckets = (Node**)calloc(TABLE_SIZE, sizeof(Node*));
    for (int i = 0; i < TABLE_SIZE; i++) {
        buckets[i] = NULL;
    }

    for (int i = 0; i < size; i++) {
        int bucketIndex = hashFunction(arr[i]);
        insertNode(&buckets[bucketIndex], arr[i]);
    }

    int index = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Bucket %d: ", i);
        printList(buckets[i]);
        Node* temp = buckets[i];
        while (temp != NULL) {
            arr[index++] = temp->data;
            Node* nextNode = temp->next;
            free(temp);
            temp = nextNode;
        }
    }

    free(buckets);
}

int main() {
    int arr[] = {34, 7, 45, 66, 23, 12, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Before sorting: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, size);

    printf("After sorting: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}