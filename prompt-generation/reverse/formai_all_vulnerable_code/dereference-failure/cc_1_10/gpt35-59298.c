//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>

// Define a struct for a node in the list
struct node{
    int data;
    struct node* next;
};

// Function to insert a node at the end of the list
void insert(struct node** head, int value){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;
    if(*head == NULL){
        *head = new_node;
        return;
    }
    struct node* current = *head;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = new_node;
}

// Function to delete a node from the list
void delete(struct node** head, int value){
    if(*head == NULL){
        return;
    }
    struct node* current = *head;
    struct node* prev = NULL;
    if(current->data == value){
        *head = current->next;
        free(current);
        return;
    }
    while(current->data != value && current != NULL){
        prev = current;
        current = current->next;
    }
    if(current == NULL){
        printf("%d not found in list.\n", value);
        return;
    }
    prev->next = current->next;
    free(current);
}

// Function to display the list
void display(struct node* head){
    if(head == NULL){
        printf("List is empty.\n");
        return;
    }
    struct node* current = head;
    printf("List: ");
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function to test the above functions
int main(){
    struct node* head = NULL; // Initially, the list is empty
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    display(head); // Should output "List: 1 2 3 4"
    delete(&head, 3);
    display(head); // Should output "List: 1 2 4"
    delete(&head, 5); // Should output "5 not found in list."
    return 0;
}