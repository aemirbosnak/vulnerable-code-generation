//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createLinkedList(int arr[], int size) {
    Node* head = NULL;
    for (int i = 0; i < size; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = arr[i];
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next!= NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    return head;
}

int search(Node* head, int key) {
    Node* temp = head;
    while (temp!= NULL) {
        if (temp->data == key) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    int arr[MAX_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node* head = createLinkedList(arr, sizeof(arr)/sizeof(arr[0]));
    int key = 5;
    if (search(head, key)) {
        printf("Element found\n");
    } else {
        printf("Element not found\n");
    }
    return 0;
}