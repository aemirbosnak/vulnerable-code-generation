//FormAI DATASET v1.0 Category: Linked list operations ; Style: introspective
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* createNode(int value){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtBegin(struct node** head, int value){
    struct node* newNode = createNode(value);
    if (*head == NULL){
        *head = newNode;
        return;
    }
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct node** head, int value){
    struct node* newNode = createNode(value);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    struct node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteAtBegin(struct node** head){
    if(*head == NULL){
        printf("Linked List is empty\n");
        return;
    }
    struct node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteAtEnd(struct node** head){
    if(*head == NULL){
        printf("Linked List is empty\n");
        return;
    }
    if((*head)->next == NULL){
        free(*head);
        *head = NULL;
        return;
    }
    struct node* temp = *head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void display(struct node* head){
    if(head == NULL){
        printf("Linked List is empty\n");
        return;
    }
    struct node* temp = head;
    printf("Linked List: ");
    while(temp != NULL){
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct node* head = NULL;
    int choice, value;
    while(1){
        printf("1. Insert at begin\n");
        printf("2. Insert at end\n");
        printf("3. Delete from begin\n");
        printf("4. Delete from end\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                insertAtBegin(&head, value);
                break;
            case 2: 
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 3: 
                deleteAtBegin(&head);
                break;
            case 4: 
                deleteAtEnd(&head);
                break;
            case 5: 
                display(head);
                break;
            case 6: 
                exit(0);
            default: 
                printf("Invalid choice, please try again!\n");
        }
    }
    return 0;
}