//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

//Node structure for linked list
struct Node{
    int data;
    struct Node* next;
};

//Function to create a new node
struct Node* newNode(int data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

//Function to insert a node at the end of the list
void insertNode(struct Node** head_ref, int data){
    struct Node* new_node = newNode(data);
    struct Node* last = *head_ref;

    if(*head_ref == NULL){
        new_node->next = NULL;
        *head_ref = new_node;
        return;
    }

    while(last->next!= NULL){
        last = last->next;
    }

    last->next = new_node;
    return;
}

//Function to search for a node in the linked list
struct Node* searchNode(struct Node* head, int data){
    struct Node* current = head;

    while(current!= NULL){
        if(current->data == data){
            return current;
        }
        current = current->next;
    }
    return NULL;
}

//Function to print the linked list
void printList(struct Node* node){
    while(node!= NULL){
        printf("%d ", node->data);
        node = node->next;
    }
}

int main(){
    struct Node* head = NULL;

    //Inserting nodes
    insertNode(&head, 5);
    insertNode(&head, 10);
    insertNode(&head, 15);
    insertNode(&head, 20);
    insertNode(&head, 25);

    //Printing the linked list
    printf("Linked List: ");
    printList(head);

    //Searching for a node
    struct Node* search_result = searchNode(head, 15);

    if(search_result!= NULL){
        printf("Node found with value %d", search_result->data);
    }else{
        printf("Node not found");
    }

    return 0;
}