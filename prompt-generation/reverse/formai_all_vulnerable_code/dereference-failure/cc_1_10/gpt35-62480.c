//FormAI DATASET v1.0 Category: Linked list operations ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

/* Declare a node structure */
struct Node {
    int value;
    struct Node* next;
};

/* Function declarations */
void insertAtHead(struct Node** headPtr, int value);
void insertAtIndex(struct Node** headPtr, int value, int index);
void insertAtEnd(struct Node** headPtr, int value);
void deleteNode(struct Node** headPtr, int index);
void searchNode(struct Node** headPtr, int value);
void displayList(struct Node* head);

/* Main function */
int main() {
    struct Node* head = NULL;
    int option = 0, value = 0, index = 0;

    do {
        printf("\nChoose an option:\n");
        printf("1. Insert at head\n");
        printf("2. Insert at index\n");
        printf("3. Insert at end\n");
        printf("4. Delete node at index\n");
        printf("5. Search for a node\n");
        printf("6. Display the list\n");
        printf("7. Exit\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\nEnter a value to insert at head: ");
                scanf("%d", &value);
                insertAtHead(&head, value);
                break;

            case 2:
                printf("\nEnter a value to insert: ");
                scanf("%d", &value);
                printf("Enter an index: ");
                scanf("%d", &index);
                insertAtIndex(&head, value, index);
                break;

            case 3:
                printf("\nEnter a value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;

            case 4:
                printf("\nEnter an index to delete: ");
                scanf("%d", &index);
                deleteNode(&head, index);
                break;

            case 5:
                printf("\nEnter a value to search for: ");
                scanf("%d", &value);
                searchNode(&head, value);
                break;

            case 6:
                displayList(head);
                break;

            case 7:
                printf("\nExiting...\n");
                break;

            default:
                printf("\nInvalid option!\n");
                break;
        }
    } while (option != 7);

    return 0;
}

/* Function to insert a node at the head */
void insertAtHead(struct Node** headPtr, int value) {
    /* Create and allocate memory for a new node */
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    /* Initialize the node's value and next pointer */
    newNode->value = value;
    newNode->next = *headPtr;

    /* Set the head pointer to the new node */
    *headPtr = newNode;

    printf("\nNode added to the head.\n");
}

/* Function to insert a node at a specified index */
void insertAtIndex(struct Node** headPtr, int value, int index) {
    /* Check if the index is valid */
    if (index < 0) {
        printf("\nInvalid index!\n");
        return;
    }

    /* Create and allocate memory for a new node */
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* current = *headPtr;
    int i;

    /* Initialize the node's value */
    newNode->value = value;

    /* Insert the node at the head if the index is 0 */
    if (index == 0) {
        newNode->next = *headPtr;
        *headPtr = newNode;
        printf("\nNode added to the head.\n");
        return;
    }

    /* Traverse the list to find the index */
    for (i = 1; i < index && current != NULL; i++) {
        current = current->next;
    }

    /* Check if the index is valid */
    if (current == NULL) {
        printf("\nInvalid index!\n");
        return;
    }

    /* Insert the node at the specified index */
    newNode->next = current->next;
    current->next = newNode;

    printf("\nNode added at index %d.\n", index);
}

/* Function to insert a node at the end */
void insertAtEnd(struct Node** headPtr, int value) {
    /* Create and allocate memory for a new node */
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* current = *headPtr;

    /* Initialize the node's value and next pointer */
    newNode->value = value;
    newNode->next = NULL;

    /* Insert the node at the head if the list is empty */
    if (current == NULL) {
        *headPtr = newNode;
        printf("\nNode added to the head.\n");
        return;
    }

    /* Traverse the list to find the end */
    while (current->next != NULL) {
        current = current->next;
    }

    /* Insert the node at the end */
    current->next = newNode;

    printf("\nNode added to the end.\n");
}

/* Function to delete a node at a specified index */
void deleteNode(struct Node** headPtr, int index) {
    /* Check if the list is empty */
    if (*headPtr == NULL) {
        printf("\nThe list is empty!\n");
        return;
    }

    struct Node* temp = *headPtr;
    int i;

    /* Delete the head node */
    if (index == 0) {
        *headPtr = temp->next;
        free(temp);
        printf("\nNode deleted from the head.\n");
        return;
    }

    /* Traverse the list to find the index */
    for (i = 1; i < index && temp != NULL; i++) {
        temp = temp->next;
    }

    /* Check if the index is valid */
    if (temp == NULL) {
        printf("\nInvalid index!\n");
        return;
    }

    /* Delete the node at the specified index */
    struct Node* next = temp->next;
    temp->next = next->next;
    free(next);

    printf("\nNode deleted at index %d.\n", index);
}

/* Function to search for a node with a specified value */
void searchNode(struct Node** headPtr, int value) {
    /* Check if the list is empty */
    if (*headPtr == NULL) {
        printf("\nThe list is empty!\n");
        return;
    }

    struct Node* temp = *headPtr;
    int index = 0;
    int found = 0;

    /* Traverse the list to find the node with the specified value */
    while (temp != NULL) {
        if (temp->value == value) {
            printf("\nNode found at index %d.\n", index);
            found = 1;
            break;
        }
        temp = temp->next;
        index++;
    }

    /* Print a message if the node is not found */
    if (!found) {
        printf("\nNode with value %d not found.\n", value);
    }
}

/* Function to display the list */
void displayList(struct Node* head) {
    /* Check if the list is empty */
    if (head == NULL) {
        printf("\nThe list is empty!\n");
        return;
    }

    struct Node* temp = head;
    int index = 0;

    /* Traverse the list and print the nodes */
    while (temp != NULL) {
        printf("\nIndex: %d, Value: %d", index, temp->value);
        temp = temp->next;
        index++;
    }
    printf("\n");
}