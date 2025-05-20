//FormAI DATASET v1.0 Category: Data structures visualization ; Style: immersive
#include<stdio.h>
#include<stdlib.h>

//node structure for linked list
struct node{
    int data;
    struct node *next;
};

//function to create new node
struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//function to create linked list
struct node* createLinkedList(int arr[], int size){
    if(size==0)
        return NULL;
    struct node* head = createNode(arr[0]);
    struct node* temp = head;
    for(int i=1; i<size; i++){
        temp->next = createNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

//function to print linked list
void printLinkedList(struct node* head){
    while(head != NULL){
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main(){
    //array to create linked list
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;
    
    //creating and printing linked list
    struct node* head = createLinkedList(arr, size);
    printLinkedList(head);
    
    //deleting linked list
    while(head != NULL){
        struct node* temp = head;
        head = head->next;
        free(temp);
    }
    
    printf("Linked List Deleted Successfully!\n");
    return 0;
}