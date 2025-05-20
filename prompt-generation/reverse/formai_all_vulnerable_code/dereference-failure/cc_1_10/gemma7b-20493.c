//Gemma-7B DATASET v1.0 Category: Sorting ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertAtTail(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void sortList(Node** head) {
    Node* current = *head;
    Node* previous = NULL;
    int i = 0;

    while (current) {
        int currentData = current->data;
        int j = i;

        for (Node* comparison = current->next; comparison; comparison) {
            if (currentData > comparison->data) {
                int temp = currentData;
                currentData = comparison->data;
                comparison->data = temp;

                if (previous) {
                    previous->next = comparison;
                } else {
                    *head = comparison;
                }
            }
            j++;
        }

        i = j;
        previous = current;
        current = current->next;
    }
}

int main() {
    Node* head = NULL;
    insertAtTail(&head, 4);
    insertAtTail(&head, 2);
    insertAtTail(&head, 8);
    insertAtTail(&head, 6);
    insertAtTail(&head, 3);

    sortList(&head);

    for (Node* current = head; current; current = current->next) {
        printf("%d ", current->data);
    }

    printf("\n");

    return 0;
}