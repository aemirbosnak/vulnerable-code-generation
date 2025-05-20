//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function prototypes
void addNode(Node** head, int data);
void printList(Node* head);
int countNodes(Node* head);

// Main function
int main() {
    Node* head = NULL;
    int choice, data;

    // Loop until user chooses to exit
    while(1) {
        printf("1. Add node\n2. Print list\n3. Count nodes\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                addNode(&head, data);
                break;
            case 2:
                printList(head);
                break;
            case 3:
                printf("Number of nodes: %d\n", countNodes(head));
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

// Function to add a node to the end of the list
void addNode(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if(*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while(temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print the list
void printList(Node* head) {
    if(head == NULL) {
        printf("List is empty.\n");
    } else {
        printf("List: ");
        while(head!= NULL) {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
}

// Function to count the number of nodes in the list
int countNodes(Node* head) {
    int count = 0;
    while(head!= NULL) {
        count++;
        head = head->next;
    }
    return count;
}