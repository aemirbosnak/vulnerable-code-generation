//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: automated
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

typedef struct linked_list{
    Node *head;
}LinkedList;

LinkedList* createLinkedList(){
    LinkedList *llist = (LinkedList*)malloc(sizeof(LinkedList));
    if (llist == NULL){
        printf("Malloc failed\n");
        exit(0);
    }
    llist->head = NULL;
    return llist;
}

void insertNode(LinkedList *list, int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL){
        printf("Malloc failed\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (list->head == NULL){
        list->head = newNode;
    }
    else{
        Node *ptr = list->head;
        while (ptr->next!= NULL){
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
}

void printList(LinkedList *list){
    Node *ptr = list->head;
    while (ptr!= NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main(){
    LinkedList *llist = createLinkedList();
    insertNode(llist, 1);
    insertNode(llist, 2);
    insertNode(llist, 3);
    printList(llist);
    return 0;
}