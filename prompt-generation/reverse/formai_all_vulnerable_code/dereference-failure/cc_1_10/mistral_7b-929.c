//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    char name[50];
    struct Node *next;
} Node;

Node *createNode(int data, const char *name) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node *insertAtHead(Node *head, int data, const char *name) {
    Node *newNode = createNode(data, name);
    newNode->next = head;
    head = newNode;
    return head;
}

Node *insertAtTail(Node *head, int data, const char *name) {
    Node *newNode = createNode(data, name);
    Node *current = head;

    if (head == NULL) {
        head = newNode;
        return head;
    }

    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

Node *searchByName(Node *head, const char *name) {
    Node *current = head;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

Node *deleteNodeByName(Node *head, const char *name) {
    Node *current = head;
    Node *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
    return head;
}

Node *reverseList(Node *head) {
    Node *current = head;
    Node *previous = NULL;
    Node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    return previous;
}

void printList(Node *head) {
    Node *current = head;

    while (current != NULL) {
        printf("(%d, %s) -> ", current->data, current->name);
        current = current->next;
    }

    printf("NULL\n");
}

int main() {
    Node *head = NULL;

    head = insertAtHead(head, 1, "Apple");
    head = insertAtTail(head, 2, "Banana");
    head = insertAtTail(head, 3, "Cherry");
    head = insertAtHead(head, 0, "Orange");

    printList(head);

    Node *search = searchByName(head, "Banana");
    if (search != NULL) {
        printf("Found node with name Banana: (%d, %s)\n", search->data, search->name);
    } else {
        printf("Node with name Banana not found.\n");
    }

    head = deleteNodeByName(head, "Cherry");
    printList(head);

    head = reverseList(head);
    printList(head);

    return 0;
}