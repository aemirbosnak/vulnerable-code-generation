//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>

// Define node structure
struct Node{
    int data;
    struct Node* next;
};

// Function to create a new node with given data
struct Node* newNode(int data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add a node at the beginning of the list
void push(struct Node** head_ref, int new_data){
    struct Node* new_node = newNode(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to add a node at the end of the list
void append(struct Node** head_ref, int new_data){
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
}

// Function to add a node after a given position in the list
void insertAfter(struct Node* prev_node, int new_data){
    if(prev_node == NULL){
        printf("The given previous node cannot be NULL");
        return;
    }
    struct Node* new_node = newNode(new_data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Function to delete a node with given data
void deleteNode(struct Node** head_ref, int key){
    struct Node* temp = *head_ref;
    struct Node* prev;
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
}

// Function to search for a node with given data
struct Node* search(struct Node* head, int x){
    struct Node* current = head;
    while(current!= NULL){
        if(current->data == x){
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to print the list
void printList(struct Node* node){
    while(node!= NULL){
        printf("%d ", node->data);
        node = node->next;
    }
}

// Driver program to test above functions
int main(){
    struct Node* head = NULL;
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    append(&head, 2);
    append(&head, 4);
    append(&head, 5);
    append(&head, 6);
    printList(head);
    printf("\n");
    insertAfter(search(head, 2), 8);
    printList(head);
    printf("\n");
    deleteNode(&head, 1);
    printList(head);
    printf("\n");
    deleteNode(&head, 6);
    printList(head);
    return 0;
}