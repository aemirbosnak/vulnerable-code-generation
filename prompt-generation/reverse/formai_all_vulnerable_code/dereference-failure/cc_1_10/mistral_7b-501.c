//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

    // Define the node structure
    struct Node {
        int data;
        char name[20];
        struct Node* next;
    };

    // Initialize the linked list
    struct Node* initList() {
        struct Node* head = NULL;
        return head;
    }

    // Insert node at the beginning of the list
    void insertAtBeginning(struct Node** head, int data, const char* name) {
        struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
        newNode->data = data;
        strcpy(newNode->name, name);
        newNode->next = *head;
        *head = newNode;
    }

    // Insert node at the end of the list
    void insertAtEnd(struct Node** head, int data, const char* name) {
        struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
        struct Node* current = *head;

        if (*head == NULL) {
            newNode->data = data;
            strcpy(newNode->name, name);
            *head = newNode;
            return;
        }

        while (current->next != NULL) {
            current = current->next;
        }

        newNode->data = data;
        strcpy(newNode->name, name);
        current->next = newNode;
    }

    // Print the linked list
    void printList(struct Node* head) {
        struct Node* current = head;

        while (current != NULL) {
            printf("Data: %d, Name: %s -> ", current->data, current->name);
            current = current->next;
        }

        printf("NULL\n");
    }

#ifdef __cplusplus
}
#endif

int main() {
    struct Node* head = initList();

    insertAtBeginning(&head, 5, "Five");
    insertAtBeginning(&head, 10, "Ten");
    insertAtEnd(head, 15, "Fifteen");
    insertAtEnd(head, 20, "Twenty");

    printList(head);

    return 0;
}