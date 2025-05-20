//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

//Node structure for linked list
struct Node{
    int data;
    struct Node* next;
};

//Function to create a new node with given data
struct Node* newNode(int data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

//Function to add a node at the end of the list
void push(struct Node** head_ref, int new_data){
    struct Node* new_node = newNode(new_data);
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

//Function to search for an element in the list
int search(struct Node* head, int x){
    struct Node* current = head;

    while(current!= NULL){
        if(current->data == x){
            return 1;
        }
        current = current->next;
    }

    return 0;
}

//Function to delete a node with given data
void deleteNode(struct Node **head_ref, int key){
    struct Node* temp = *head_ref, *prev;

    if(temp!= NULL && temp->data == key){
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while(temp!= NULL && temp->data!= key){
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

//Function to print the list
void printList(struct Node* node){
    while(node!= NULL){
        printf("%d ", node->data);
        node = node->next;
    }
}

int main(){
    struct Node* head = NULL;

    push(&head, 12);
    push(&head, 22);
    push(&head, 32);
    push(&head, 42);
    push(&head, 52);

    printf("List after insertion: ");
    printList(head);

    int key = 32;
    search(head, key)? printf("\nElement found! "): printf("\nElement not found. ");

    deleteNode(&head, key);

    printf("\nList after deletion: ");
    printList(head);

    return 0;
}