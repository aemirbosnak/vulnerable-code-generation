//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: invasive
#include<stdio.h>
#include<stdlib.h>

//Define the node structure
struct node {
    int data;
    struct node *next;
};

//Function to create a new node
struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

//Function to insert a node at the beginning of the linked list
struct node* insert_at_beginning(struct node** head_ref, int data) {
    struct node* new_node = create_node(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
    return new_node;
}

//Function to insert a node at the end of the linked list
struct node* insert_at_end(struct node** head_ref, int data) {
    struct node* new_node = create_node(data);
    struct node* current = *head_ref;
    while(current->next!= NULL)
        current = current->next;
    current->next = new_node;
    return new_node;
}

//Function to delete a node from the linked list
void delete_node(struct node** head_ref, int data) {
    struct node* current = *head_ref;
    struct node* prev = NULL;
    while(current!= NULL && current->data!= data) {
        prev = current;
        current = current->next;
    }
    if(current == NULL) {
        printf("Data not found in the list\n");
        return;
    }
    if(prev == NULL) {
        *head_ref = current->next;
        free(current);
        return;
    }
    prev->next = current->next;
    free(current);
}

//Function to print the linked list
void print_list(struct node* head) {
    struct node* current = head;
    while(current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

//Driver program to test above functions
int main() {
    struct node* head = NULL;
    insert_at_beginning(&head, 1);
    insert_at_beginning(&head, 2);
    insert_at_beginning(&head, 3);
    print_list(head);
    printf("Linked list elements: ");
    printf("%d, ", head->data);
    printf("%d, ", head->next->data);
    printf("%d\n", head->next->next->data);
    delete_node(&head, 2);
    print_list(head);
    return 0;
}