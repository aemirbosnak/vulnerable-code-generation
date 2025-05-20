//FormAI DATASET v1.0 Category: Linked list operations ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>

// Structure for each node of the linked list
struct node {
    int data;
    struct node *next;
};

// Function to create a new node
struct node *createNode(int data) {
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the list
void insertAtBeginning(struct node **head, int data) {
    struct node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a new node at the end of the list
void insertAtEnd(struct node **head, int data) {
    struct node *newNode = createNode(data);
    struct node *temp = *head;
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to insert a new node at a specific position in the list
void insertAtPosition(struct node **head, int data, int position) {
    if (position == 1) {
        insertAtBeginning(head, data);
    }
    else if (position == -1) {
        insertAtEnd(head, data);
    }
    else {
        struct node *newNode = createNode(data);
        struct node *temp = *head;
        int i;
        for (i = 1; i < position-1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Cannot insert at position %d\n", position);
        }
        else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

// Function to delete the first node
void deleteFirstNode(struct node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
    }
    else {
        struct node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

// Function to delete the last node
void deleteLastNode(struct node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
    }
    else if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    }
    else {
        struct node *temp1 = *head, *temp2;
        while (temp1->next != NULL) {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        temp2->next = NULL;
        free(temp1);
    }
}

// Function to delete a node from a specific position in the list
void deleteFromPosition(struct node **head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
    }
    else {
        struct node *temp1 = *head, *temp2;
        int i;
        for (i = 1; i < position && temp1 != NULL; i++) {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        if (temp1 == NULL) {
            printf("Cannot delete at position %d\n", position);
        }
        else {
            temp2->next = temp1->next;
            free(temp1);
        }
    }
}

// Function to display the contents of the list
void display(struct node *head) {
    if (head == NULL) {
        printf("List is empty\n");
    }
    else {
        struct node *temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    struct node *head = NULL;
    int choice, data, position;

    while (1) {
        printf("1.Insert at beginning\n2.Insert at end\n3.Insert at position\n4.Delete first node\n5.Delete last node\n6.Delete from position\n7.Display\n8.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 4:
                deleteFirstNode(&head);
                break;
            case 5:
                deleteLastNode(&head);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteFromPosition(&head, position);
                break;
            case 7:
                display(head);
                break;
            case 8:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}