//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

// Function to create a new node
struct node* createNode(int data){
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the linked list
struct node* insertAtBegin(struct node* head, int data){
    struct node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    return head;
}

// Function to delete the first node from the linked list.
struct node* deleteAtBegin(struct node* head){
    if(head == NULL){
        printf("List is empty\n");
        return head;
    }
    struct node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to display the linked list
void display(struct node* head){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    printf("Linked List:\n");
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main function
int main(){
    struct node* head = NULL;
    int choice, data;
    do{
        printf("\n--Menu--\n");
        printf("1. Insert at beginning\n");
        printf("2. Delete at beginning\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                head = insertAtBegin(head, data);
                break;
            case 2:
                head = deleteAtBegin(head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }

    }while(choice != 4);

    return 0;
}