//FormAI DATASET v1.0 Category: Linked list operations ; Style: curious
#include<stdio.h>
#include<stdlib.h>

// defining the node structure
struct node {
    int data;
    struct node* next;
};

// function to add new node to the list
void addNode(struct node** head, int val) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        struct node* temp = *head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("New node with value %d has been added to the list.\n", val);
}

// function to print the list
void displayList(struct node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
    }
    else {
        printf("The list contains: ");
        while (head != NULL) {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
}

// function to delete a node from the list
void deleteNode(struct node** head, int val) {
    if (*head == NULL) {
        printf("The list is empty. Cannot delete any node.\n");
    }
    else {
        struct node* temp = *head;
        struct node* prev = NULL;
        while (temp != NULL && temp->data != val) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Node with value %d is not present in the list.\n", val);
        }
        else {
            if (prev == NULL) {
                *head = temp->next;
            }
            else {
                prev->next = temp->next;
            }
            printf("Node with value %d has been deleted from the list.\n", val);
            free(temp);
        }
    }
}

int main() {
    struct node* head = NULL;
    int choice, val;
    do {
        printf("Enter your choice:\n1. Add a node\n2. Delete a node\n3. Display the list\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                printf("Enter the value to be added: ");
                scanf("%d", &val);
                addNode(&head, val);
                break;
            case 2: 
                printf("Enter the value to be deleted: ");
                scanf("%d", &val);
                deleteNode(&head, val);
                break;
            case 3: 
                displayList(head);
                break;
            case 4: 
                printf("Exiting the program. Thank you!\n");
                exit(0);
            default: 
                printf("Invalid choice. Please try again!\n");
        }
    } while(choice != 4);

    return 0;
}