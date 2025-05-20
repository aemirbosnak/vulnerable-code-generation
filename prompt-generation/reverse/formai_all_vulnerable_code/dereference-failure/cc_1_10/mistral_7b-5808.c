//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    char *name;
    float price;
    struct Node *next;
} Node;

Node *createNode(int data, const char *name, float price) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    size_t len = strlen(name) + 1;
    newNode->name = (char *)malloc(len * sizeof(char));
    strcpy(newNode->name, name);
    newNode->price = price;
    newNode->next = NULL;
    return newNode;
}

void append(Node **head, int data, const char *name, float price) {
    Node *newNode = createNode(data, name, price);
    Node *last = *head;

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
}

void displayList(Node *head) {
    Node *current = head;

    while (current != NULL) {
        printf("Data: %d, Name: %s, Price: %.2f\n", current->data, current->name, current->price);
        current = current->next;
    }
}

bool isEmpty(Node *head) {
    return head == NULL;
}

int main() {
    Node *head = NULL;

    append(&head, 1, "Apple", 0.50);
    append(&head, 2, "Banana", 0.35);
    append(&head, 3, "Orange", 0.65);

    printf("Linked List:\n");
    displayList(head);

    if (isEmpty(head)) {
        printf("\nThe list is empty.\n");
    } else {
        Node *temp = head;

        while (temp != NULL) {
            if (temp->data > 1) {
                Node *toRemove = temp;
                temp = temp->next;
                free(toRemove->name);
                free(toRemove);
                append(head, temp->data, temp->name, temp->price);
            }
            temp = temp->next;
        }

        printf("\nModified List:\n");
        displayList(head);
    }

    return 0;
}