//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

typedef struct node{
    char data[MAX_SIZE];
    struct node* next;
}node;

node* createNode(char data[]){
    node* newNode = (node*)malloc(sizeof(node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

node* insertNode(node* head, char data[]){
    node* newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        return head;
    }
    node* temp = head;
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

node* searchNode(node* head, char data[]){
    node* temp = head;
    while(temp!= NULL){
        if(strcmp(temp->data, data) == 0){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void deleteNode(node* head, char data[]){
    node* temp = head;
    while(temp!= NULL){
        if(strcmp(temp->data, data) == 0){
            node* prev = temp;
            temp = temp->next;
            free(prev);
            prev = NULL;
        }
        else{
            temp = temp->next;
        }
    }
}

void displayList(node* head){
    node* temp = head;
    while(temp!= NULL){
        printf("%s -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    node* head = NULL;
    char data[MAX_SIZE];
    while(1){
        printf("Enter the data to be inserted into the list: ");
        scanf("%s", data);
        head = insertNode(head, data);
        printf("Enter 1 to search for a node, 2 to delete a node, 3 to display the list, and 0 to exit.\n");
        int choice = scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the data to be searched for: ");
                scanf("%s", data);
                node* result = searchNode(head, data);
                if(result!= NULL){
                    printf("The node containing %s has been found.\n", data);
                }
                else{
                    printf("The node containing %s has not been found.\n", data);
                }
                break;
            case 2:
                printf("Enter the data to be deleted from the list: ");
                scanf("%s", data);
                deleteNode(head, data);
                printf("The node containing %s has been deleted.\n", data);
                break;
            case 3:
                displayList(head);
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}