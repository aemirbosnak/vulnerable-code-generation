//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX_SIZE 100000

typedef struct node{
    int data;
    struct node* next;
}LinkedList;

LinkedList* createLinkedList(){
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->data = -1;
    list->next = NULL;
    return list;
}

void addNode(LinkedList* list, int data){
    LinkedList* newNode = (LinkedList*)malloc(sizeof(LinkedList));
    newNode->data = data;
    newNode->next = NULL;

    if(list->data == -1){
        list->data = data;
        list->next = newNode;
    }else{
        LinkedList* temp = list;
        while(temp->next!= NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteNode(LinkedList* list, int data){
    if(list->data == data){
        list->data = -1;
        list->next = NULL;
    }else{
        LinkedList* temp = list;
        while(temp->next!= NULL){
            if(temp->next->data == data){
                temp->next = temp->next->next;
                free(temp->next);
                break;
            }
            temp = temp->next;
        }
    }
}

void printList(LinkedList* list){
    LinkedList* temp = list;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    int choice, data;
    LinkedList* list = createLinkedList();

    while(1){
        printf("Enter your choice:\n1. Add node\n2. Delete node\n3. Print list\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:{
                printf("Enter data:\n");
                scanf("%d", &data);
                addNode(list, data);
                break;
            }
            case 2:{
                printf("Enter data:\n");
                scanf("%d", &data);
                deleteNode(list, data);
                break;
            }
            case 3:{
                printList(list);
                break;
            }
            case 4:{
                exit(0);
            }
            default:{
                printf("Invalid choice!\n");
            }
        }
    }

    return 0;
}