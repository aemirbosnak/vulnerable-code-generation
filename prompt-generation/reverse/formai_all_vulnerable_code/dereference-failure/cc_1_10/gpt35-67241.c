//FormAI DATASET v1.0 Category: Linked list operations ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

/* Define the node structure */
struct Node {
    int data;
    struct Node* next;
};

/* Function to add a new node to the list */
void addNode(struct Node** headRef, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = (*headRef);
    (*headRef) = newNode;
}

/* Function to print all the elements in the list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Function to delete a node with a specified value from the list */
void deleteNode(struct Node** headRef, int key) {
    struct Node* temp = *headRef, *prev;
    if (temp != NULL && temp->data == key) {
        *headRef = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

/* Function to reverse the order of the nodes in the list */
void reverseList(struct Node** headRef) {
    struct Node* prev = NULL;
    struct Node* current = (*headRef);
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    (*headRef) = prev;
}

/* Main function to test the linked list operations */
int main() {
    struct Node* head = NULL;
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);

    printf("Original list: ");
    printList(head);

    deleteNode(&head, 3);
    printf("List after deleting node with value 3: ");
    printList(head);

    reverseList(&head);
    printf("List after reversing: ");
    printList(head);

    return 0;
}