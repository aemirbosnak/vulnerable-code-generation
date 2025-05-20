//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: artistic
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void addNode(struct Node** head, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if(*head == NULL){
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return;
}

void deleteNode(struct Node** head, int data){
    struct Node* temp = *head;
    if(temp!= NULL && temp->data == data){
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp!= NULL && temp->data!= data){
        temp = temp->next;
    }
    if(temp == NULL){
        return;
    }
    struct Node* prev = temp->next;
    temp->next = prev->next;
    free(prev);
    return;
}

void searchNode(struct Node* head, int data){
    struct Node* temp = head;
    while(temp!= NULL){
        if(temp->data == data){
            printf("Node found!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Node not found.\n");
    return;
}

void printList(struct Node* head){
    struct Node* temp = head;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return;
}

int main(){
    struct Node* head = NULL;
    int choice, data;
    while(1){
        printf("Enter your choice:\n1. Add node\n2. Delete node\n3. Search node\n4. Print list\n5. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter data to be added:\n");
                scanf("%d", &data);
                addNode(&head, data);
                break;
            case 2:
                printf("Enter data to be deleted:\n");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 3:
                printf("Enter data to be searched:\n");
                scanf("%d", &data);
                searchNode(head, data);
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