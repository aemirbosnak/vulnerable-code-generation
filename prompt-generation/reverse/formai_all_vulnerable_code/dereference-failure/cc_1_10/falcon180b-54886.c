//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: active
#include<stdio.h>
#include<stdlib.h>

// Node structure for linked list
struct Node{
    int data;
    struct Node* next;
};

// Function prototypes
void createLinkedList(struct Node** head);
void insertNode(struct Node** head, int data);
void displayLinkedList(struct Node* head);
void deleteNode(struct Node** head, int data);

// Main function
int main(){
    struct Node* head = NULL;

    // Creating linked list
    createLinkedList(&head);

    // Displaying linked list
    printf("Linked List: ");
    displayLinkedList(head);

    // Inserting node
    insertNode(&head, 7);

    // Displaying linked list after insertion
    printf("\nLinked List after insertion: ");
    displayLinkedList(head);

    // Deleting node
    deleteNode(&head, 7);

    // Displaying linked list after deletion
    printf("\nLinked List after deletion: ");
    displayLinkedList(head);

    return 0;
}

// Function to create linked list
void createLinkedList(struct Node** head){
    int choice;
    struct Node* newNode = NULL;

    // Taking input from user to create linked list
    do{
        printf("\nEnter 1 to add node or 0 to exit: ");
        scanf("%d", &choice);

        if(choice == 1){
            printf("Enter data for node: ");
            scanf("%d", &newNode->data);
            newNode->next = NULL;

            if(*head == NULL){
                *head = newNode;
            }
            else{
                struct Node* temp = *head;
                while(temp->next!= NULL){
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }
    }while(choice == 1);
}

// Function to insert node
void insertNode(struct Node** head, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if(*head == NULL){
        newNode->next = NULL;
        *head = newNode;
    }
    else{
        struct Node* temp = *head;
        while(temp->next!= NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display linked list
void displayLinkedList(struct Node* head){
    if(head == NULL){
        printf("Linked list is empty.\n");
    }
    else{
        printf("Linked List: ");
        struct Node* temp = head;
        while(temp!= NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to delete node
void deleteNode(struct Node** head, int data){
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if(temp!= NULL && temp->data == data){
        *head = temp->next;
        free(temp);
        return;
    }

    while(temp!= NULL && temp->data!= data){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        return;
    }

    prev->next = temp->next;
    free(temp);
}