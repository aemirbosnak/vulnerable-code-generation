//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>
#include<time.h>

struct node{
    int data;
    struct node* next;
};

struct list{
    struct node* head;
    struct node* tail;
    int length;
};

void addNode(struct list* list, int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if(list->head == NULL){
        list->head = newNode;
        list->tail = newNode;
        list->length = 1;
        return;
    }
    list->tail->next = newNode;
    list->tail = newNode;
    list->length++;
}

void printList(struct list* list){
    struct node* temp = list->head;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct list* list = (struct list*)malloc(sizeof(struct list));
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    addNode(list, 1);
    addNode(list, 2);
    addNode(list, 3);
    addNode(list, 4);
    addNode(list, 5);
    printList(list);
    return 0;
}