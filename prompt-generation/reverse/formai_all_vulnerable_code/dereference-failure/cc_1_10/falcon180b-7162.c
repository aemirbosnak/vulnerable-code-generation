//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TRUE 1
#define FALSE 0

//Structure for a single node
struct node{
    int data;
    struct node* next;
};

//Function for creating a new node
struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//Function for inserting a node at the end of the list
void insertNode(struct node** head, int data){
    struct node* newNode = createNode(data);
    struct node* temp = *head;
    if(*head == NULL){
        newNode->next = NULL;
        *head = newNode;
        return;
    }
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return;
}

//Function for deleting a node from the list
void deleteNode(struct node** head, int data){
    struct node* temp = *head;
    struct node* prev = NULL;
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
    return;
}

//Function for searching a node in the list
struct node* searchNode(struct node* head, int data){
    struct node* temp = head;
    while(temp!= NULL){
        if(temp->data == data){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

//Function for printing the list
void printList(struct node* head){
    struct node* temp = head;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

//Main function
int main(){
    srand(time(NULL));
    int choice, data;
    struct node* head = NULL;
    while(1){
        printf("\n1.Insert\n2.Delete\n3.Search\n4.Print\n5.Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertNode(&head, data);
                break;
            case 2:
                printf("Enter the data to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 3:
                printf("Enter the data to search: ");
                scanf("%d", &data);
                struct node* result = searchNode(head, data);
                if(result!= NULL){
                    printf("Data found!\n");
                }
                else{
                    printf("Data not found!\n");
                }
                break;
            case 4:
                printList(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}