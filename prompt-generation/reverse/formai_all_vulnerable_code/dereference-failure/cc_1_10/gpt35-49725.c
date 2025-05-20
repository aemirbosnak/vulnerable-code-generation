//FormAI DATASET v1.0 Category: Linked list operations ; Style: systematic
#include<stdio.h>
#include<stdlib.h>

/*Structure of a node*/
struct Node {
    int data;
    struct Node* next;
};

/*Function for creating a new node*/
struct Node* createNode(){
    struct Node* temp = malloc(sizeof(struct Node));
    printf("Enter data:");
    scanf("%d",&temp->data);
    temp->next = NULL;
    return temp;
}

/*Function for inserting a node at the beginning of the list*/
void insertAtBeginning(struct Node** head){
    struct Node* newNode = createNode();
    newNode->next = *head;
    *head = newNode;
}

/*Function for inserting a node at the end of the list*/
void insertAtEnd(struct Node** head){
    struct Node* temp = *head;
    if(temp == NULL){
        *head = createNode();
        return;
    }
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = createNode();
}

/*Function for displaying the list*/
void displayList(struct Node* head){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    printf("List: ");
    while(head != NULL){
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
}

/*Function for deleting the first node of the list*/
void deleteAtBeginning(struct Node** head){
    if(*head == NULL){
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

/*Function for deleting the last node of the list*/
void deleteAtEnd(struct Node** head){
    if(*head == NULL){
        printf("List is empty\n");
        return;
    }
    if((*head)->next == NULL){
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* temp = *head;
    while(temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

/*Function to free up memory*/
void deleteList(struct Node** head){
    struct Node* temp = *head;
    while(temp != NULL){
        *head = (*head)->next;
        free(temp);
        temp = *head;
    }
}

int main(){
    struct Node* head = NULL;
    int ch = -1;

    /*Menu-driven program*/
    while(ch != 0){
        printf("***LINKED LIST OPERATIONS***\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete from beginning\n");
        printf("4. Delete from end\n");
        printf("5. Display the list\n");
        printf("0. Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1: insertAtBeginning(&head);
                    break;
            case 2: insertAtEnd(&head);
                    break;
            case 3: deleteAtBeginning(&head);
                    break;
            case 4: deleteAtEnd(&head);
                    break;
            case 5: displayList(head);
                    break;
            case 0: deleteList(&head);
                    break;          
            default: printf("Invalid choice\n");
        }
    }

    printf("Exiting program\n");
    return 0;
}