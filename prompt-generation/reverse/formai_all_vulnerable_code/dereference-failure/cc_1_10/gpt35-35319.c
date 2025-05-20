//FormAI DATASET v1.0 Category: Memory management ; Style: artistic
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

void addToList(int val) {
    Node* temp = malloc(sizeof(Node));
    temp->data = val;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        Node* curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = temp;
    }
}

void removeFromList(int val) {
    if (head == NULL) {
        return;
    }

    if (head->data == val) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }

    Node* curr = head;
    while (curr->next != NULL && curr->next->data != val) {
        curr = curr->next;
    }

    if (curr->next == NULL) {
        return;
    }

    Node* temp = curr->next;
    curr->next = curr->next->next;
    free(temp);
}

int main() {
    addToList(5);
    addToList(3);
    addToList(9);
    addToList(1);

    removeFromList(3);

    Node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");

    return 0;
}