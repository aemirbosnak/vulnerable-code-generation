//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct Node {
    int key;
    struct Node* next;
} Node;

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

Node* createList(int arr[], int size) {
    Node* head = NULL;
    for (int i = 0; i < size; i++) {
        if (head == NULL) {
            head = createNode(arr[i]);
        } else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = createNode(arr[i]);
        }
    }
    return head;
}

int search(Node* head, int key) {
    Node* current = head;
    while (current != NULL) {
        if (current->key == key) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->key);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int size = sizeof(arr) / sizeof(arr[0]);
    Node* list = createList(arr, size);

    int target = 11;
    int result = search(list, target);

    printf("List: ");
    printList(list);

    if (result) {
        printf("%d found in the list.\n", target);
    } else {
        printf("%d not found in the list.\n", target);
    }

    return 0;
}