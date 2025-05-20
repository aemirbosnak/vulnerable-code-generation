//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Defining the struct for a node
typedef struct Node {
    char* name;
    char* value;
    struct Node* next;
} Node;

// Function to initialize a node
Node* initNode(char* name, char* value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->name = strdup(name);
    node->value = strdup(value);
    node->next = NULL;
    return node;
}

// Function to add a node at the end of the linked list
void addNode(Node** head, char* name, char* value) {
    Node* node = initNode(name, value);
    if (*head == NULL) {
        *head = node;
    } else {
        Node* temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
}

// Function to delete a node from the linked list
void deleteNode(Node** head, char* name) {
    Node* temp = *head;
    if (*head!= NULL) {
        if ((*head)->name == strdup(name)) {
            *head = (*head)->next;
            free(*head);
        } else {
            while (temp->next!= NULL) {
                if (temp->next->name == strdup(name)) {
                    temp->next = temp->next->next;
                    free(temp->next->name);
                    free(temp->next->value);
                    free(temp->next);
                    break;
                }
                temp = temp->next;
            }
        }
    }
}

// Function to print the linked list
void printList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    while (temp!= NULL) {
        printf("%s: %s\n", temp->name, temp->value);
        temp = temp->next;
    }
}

int main() {
    Node* head = NULL;
    addNode(&head, "John", "Python");
    addNode(&head, "Jane", "Java");
    addNode(&head, "Mark", "C++");
    printList(head);
    deleteNode(&head, "Jane");
    printList(head);
    return 0;
}