//FormAI DATASET v1.0 Category: Data structures visualization ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct LinkedList{
    Node* head;
}LinkedList;

void init(LinkedList* list){
    list->head = NULL;
}

void append(LinkedList* list, int data){
    Node* temp = (Node*) malloc (sizeof(Node));
    temp->data = data;
    temp->next = NULL;

    if(list->head == NULL){
        list->head = temp;
    }
    else{
        Node* p = list->head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
}

void printList(LinkedList* list){
    Node* p = list->head;
    while(p != NULL){
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL");
}

int main(){
    LinkedList list;
    init(&list);
    append(&list, 10);
    append(&list, 20);
    append(&list, 30);
    append(&list, 40);
    append(&list, 50);
    printList(&list);
    return 0;
}