//FormAI DATASET v1.0 Category: Linked list operations ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void createList(struct node **start) {
    int num;
    struct node *temp;
    printf("Enter the data for the new node: ");
    scanf("%d", &num);
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    temp->next = *start;
    *start = temp;
    printf("\nNew node created successfully!\n\n");
}

void displayList(struct node *start) {
    struct node *temp;
    temp = start;
    if(temp == NULL) {
        printf("\nList is empty!\n\n");
    }
    else {
        printf("\nList Elements:\n");
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n\n");
    }
}

void insertAtBeginning(struct node **start) {
    int num;
    struct node *temp;
    printf("Enter the data to insert at the beginning: ");
    scanf("%d", &num);
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    temp->next = *start;
    *start = temp;
    printf("\nData inserted successfully at the beginning!\n\n");
}

void insertAtEnd(struct node **start) {
    int num;
    struct node *temp, *newNode;
    printf("Enter the data to insert at the end: ");
    scanf("%d", &num);
    temp = *start;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = num;
    newNode->next = NULL;
    if(temp == NULL) {
        *start = newNode;
    }
    else {
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("\nData inserted successfully at the end!\n\n");
}

void deleteNode(struct node **start) {
    int num;
    struct node *temp, *prevNode;
    printf("Enter the data value of the node to delete: ");
    scanf("%d", &num);
    temp = *start;
    if(temp != NULL && temp->data == num) {
        *start = temp->next;
        free(temp);
        printf("\nNode deleted successfully!\n\n");
        return;
    }
    while(temp != NULL && temp->data != num) {
        prevNode = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("\nNode not found!\n\n");
        return;
    }
    prevNode->next = temp->next;
    free(temp);
    printf("\nNode deleted successfully!\n\n");
}

int main() {
    struct node *start = NULL;
    int choice;

    while(1) {
        printf("--------------------\n");
        printf("Linked List Operations\n");
        printf("--------------------\n");
        printf("1. Create a new node.\n");
        printf("2. Display the list.\n");
        printf("3. Insert a new node at the beginning.\n");
        printf("4. Insert a new node at the end.\n");
        printf("5. Delete a node.\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                createList(&start);
                break;
            case 2:
                displayList(start);
                break;
            case 3:
                insertAtBeginning(&start);
                break;
            case 4:
                insertAtEnd(&start);
                break;
            case 5:
                deleteNode(&start);
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid choice. Please try again!\n\n");
        }
    }

    return 0;
}