//FormAI DATASET v1.0 Category: Linked list operations ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

/* define the node structure */
struct node{
    int data;
    struct node *next;
};

/* function to display the list */
void display(struct node *head){
    /* traverse through the list */
    while(head != NULL){
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

/* function to insert a node at the beginning of the list */
void insertAtBeginning(struct node **head, int data){
    /* create a new node */
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = *head;

    /* update the head pointer */
    *head = newNode;
}

/* function to insert a node at the end of the list */
void insertAtEnd(struct node **head, int data){
    /* create a new node */
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    /* if the list is empty */
    if(*head == NULL){
        *head = newNode;
        return;
    }

    /* traverse till the end of the list */
    struct node *temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    /* update the next pointer */
    temp->next = newNode;
}

/* function to delete a node from the list */
void deleteNode(struct node **head, int data){
    /* if the list is empty */
    if(*head == NULL){
        return;
    }

    /* if the first node is to be deleted */
    if((*head)->data == data){
        /* update the head pointer */
        *head = (*head)->next;
        return;
    }

    /* traverse till the node to be deleted is found */
    struct node *temp = *head;
    while(temp->next != NULL && temp->next->data != data){
        temp = temp->next;
    }

    /* if the node to be deleted is not found */
    if(temp->next == NULL){
        return;
    }

    /* update the next pointer */
    temp->next = temp->next->next;
}

/* function to reverse the list */
void reverseList(struct node **head){
    struct node* current = *head; 
    struct node *prev = NULL, *next = NULL; 

    while (current != NULL) { 
        next = current->next; /* store the next pointer */
        current->next = prev; /* update the next pointer */
        prev = current; /* make the current node the previous node */
        current = next; /* move to the next node */
    } 

    /* update the head pointer */
    *head = prev;
}

int main(){
    struct node *head = NULL;
    int choice, data;

    do{
        /* display the options */
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete a node\n");
        printf("4. Reverse the list\n");
        printf("5. Display the list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: /* insert at beginning */
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2: /* insert at end */
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3: /* delete a node */
                printf("Enter data to be deleted: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 4: /* reverse the list */
                reverseList(&head);
                printf("List reversed\n");
                break;
            case 5: /* display the list */
                display(head);
                break;
            case 6: /* exit */
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(choice != 6);

    return 0;
}