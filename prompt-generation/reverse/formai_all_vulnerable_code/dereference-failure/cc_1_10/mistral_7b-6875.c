//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data[100];
    struct Node *next;
} Node;

Node *createNode(const char *data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

Node *insertAtBeginning(Node *head, const char *data) {
    Node *newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    return head;
}

Node *insertAtEnd(Node *head, const char *data) {
    Node *newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        return head;
    }

    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

Node *deleteAtBeginning(Node *head) {
    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node *deleteAtEnd(Node *head) {
    Node *current = head;
    Node *previous = NULL;

    if (head == NULL) {
        printf("List is empty, cannot delete from end.\n");
        return head;
    }

    while (current != NULL) {
        if (current->next == NULL) {
            if (previous == NULL) {
                head = NULL;
            } else {
                previous->next = NULL;
            }
            free(current);
            break;
        } else {
            previous = current;
            current = current->next;
        }
    }

    return head;
}

void displayList(Node *head) {
    Node *current = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("List: ");
    while (current != NULL) {
        printf("%s -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;

    head = insertAtBeginning(head, "Apple");
    head = insertAtEnd(head, "Banana");
    head = insertAtEnd(head, "Cherry");
    head = insertAtBeginning(head, "Orange");
    head = insertAtEnd(head, "Durian");

    displayList(head);

    head = deleteAtBeginning(head);
    head = deleteAtEnd(head);

    displayList(head);

    return 0;
}