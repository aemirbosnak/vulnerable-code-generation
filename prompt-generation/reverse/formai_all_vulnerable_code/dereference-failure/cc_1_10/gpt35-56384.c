//FormAI DATASET v1.0 Category: Data structures visualization ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct linkedlist{
    struct node* head;
    int size;
};

void init(struct linkedlist* lst){
    lst->head = NULL;
    lst->size = 0;
}

void add_node(struct linkedlist* lst, int val){
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    if(lst->head == NULL){
        lst->head = newNode;
    }
    else{
        struct node* temp = lst->head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }

    lst->size++;
}

void print_list(struct linkedlist* lst){
    struct node* temp = lst->head;

    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main(){
    struct linkedlist myList;

    init(&myList);

    add_node(&myList, 4);
    add_node(&myList, 8);
    add_node(&myList, 2);

    printf("My linked list contains: ");
    print_list(&myList);

    return 0;
}