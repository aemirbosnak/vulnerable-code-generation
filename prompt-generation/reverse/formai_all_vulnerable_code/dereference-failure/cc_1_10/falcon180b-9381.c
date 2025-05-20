//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Node {
    int data;
    struct Node* next;
};

struct Node* createLinkedList(int arr[], int size) {
    struct Node* head = NULL;
    struct Node* temp = NULL;

    for (int i = 0; i < size; i++) {
        temp = (struct Node*) malloc(sizeof(struct Node));
        temp->data = arr[i];
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
        }
        else {
            struct Node* current = head;
            while (current->next!= NULL) {
                current = current->next;
            }
            current->next = temp;
        }
    }

    return head;
}

void printLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current!= NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

struct Node* linearSearch(struct Node* head, int key) {
    struct Node* current = head;
    while (current!= NULL) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    struct Node* head = createLinkedList(arr, size);
    printf("Linked List: ");
    printLinkedList(head);

    int key = 4;
    struct Node* result = linearSearch(head, key);
    if (result!= NULL) {
        printf("Element %d found in the linked list.\n", key);
    }
    else {
        printf("Element %d not found in the linked list.\n", key);
    }

    return 0;
}