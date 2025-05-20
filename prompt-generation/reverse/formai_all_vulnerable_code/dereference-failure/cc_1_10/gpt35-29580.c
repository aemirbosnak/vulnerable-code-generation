//FormAI DATASET v1.0 Category: Linked list operations ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
typedef struct node {
    int data;
    struct node *next;
} Node;

// Initialization of the first node as NULL
Node *head = NULL;

// Create a new node
Node *createNode(int data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert a node at the beginning of the linked list
void insertBeginning(int data) {
    Node *newNode = createNode(data);
    if (head == NULL) {
        head = newNode; // If the list is empty, set the new nod as head
    } else {
        newNode->next = head; // Otherwise, set the new node's next to the current head
        head = newNode; // Then set the head to the new node
    }
}

// Insert a node at the end of the linked list
void insertEnd(int data) {
    Node *newNode = createNode(data);
    if (head == NULL) {
        head = newNode; // If the list is empty, set the new nod as head
    } else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next; // Traverse to the last node
        }
        temp->next = newNode; // Set the new node as the next of the last node
    }
}

// Insert a node at a specified position in the linked list
void insertAtPosition(int data, int position) {
    if (position == 1) {
        insertBeginning(data); // If the position is the beginning, just insert the node there
        return;
    }
    Node *newNode = createNode(data);
    Node *temp = head;
    for (int i = 1; i < position - 1; i++) {
        if (temp == NULL) {
            printf("Invalid position\n");
            return;
        }
        temp = temp->next; // Traverse to the node just before the specified position
    }
    newNode->next = temp->next; // Set the new node's next to the current node at the position
    temp->next = newNode; // Set the current node's next to the new node
}

// Delete the node at the beginning of the linked list
void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node *temp = head;
    head = head->next; // Set the second node as the new head
    free(temp); // Free the memory of the first node
}

// Delete the node at the end of the linked list
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node *temp1 = head;
    Node *temp2 = NULL;
    while (temp1->next != NULL) {
        temp2 = temp1;
        temp1 = temp1->next; // Traverse to the last node
    }
    if (temp2 == NULL) {
        head = NULL; // If there's only one node, free it
    } else {
        temp2->next = NULL; // Set the second last node's next as NULL
    }
    free(temp1); // Free the memory of the last node
}

// Delete the node at a specified position in the linked list
void deleteAtPosition(int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (position == 1) {
        deleteBeginning(); // If the position is the beginning, just delete the first node
        return;
    }
    Node *temp1 = head;
    Node *temp2 = NULL;
    for (int i = 1; i < position; i++) {
        if (temp1 == NULL) {
            printf("Invalid position\n");
            return;
        }
        temp2 = temp1; // Traverse to the node just before the specified position
        temp1 = temp1->next;
    }
    if (temp2 == NULL) {
        head = temp1->next; // If the first node is to be deleted, set the second node as the new head
    } else {
        temp2->next = temp1->next; // Set the current node's previous node's next to the current node's next
    }
    free(temp1); // Free the memory of the deleted node
}

// Traverse the linked list and print all the node's data
void traverse() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Linked list: ");
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next; // Traverse to the next node
    }
    printf("\n");
}

int main() {
    int choice, data, position;
    while (1) {
        printf("1. Insert at beginning   ");
        printf("2. Insert at end   ");
        printf("3. Insert at position   ");
        printf("4. Delete from beginning   ");
        printf("5. Delete from end   ");
        printf("6. Delete at position   ");
        printf("7. Traverse   8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertBeginning(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertEnd(data);
                break;
            case 3:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &position);
                insertAtPosition(data, position);
                break;
            case 4:
                deleteBeginning();
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            case 7:
                traverse();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}