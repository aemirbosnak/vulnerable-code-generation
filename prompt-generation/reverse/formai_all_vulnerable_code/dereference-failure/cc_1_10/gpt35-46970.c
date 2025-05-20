//FormAI DATASET v1.0 Category: Linked list operations ; Style: systematic
#include<stdio.h>
#include<stdlib.h>

//Define a linked list structure
struct node {
    int data; //Data of the node
    struct node* next; //Pointer to the next node
};

//Function to print linked list
void print_list(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

//Function to add node at the beginning of the linked list
void add_node_at_beginning(struct node** head_ref, int new_data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

//Function to add node at the end of the linked list
void add_node_at_end(struct node** head_ref, int new_data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    struct node* last_node = *head_ref;
    while (last_node->next != NULL)
        last_node = last_node->next;

    last_node->next = new_node;
    return;
}

//Function to add node at any position of the linked list
void add_node_at_position(struct node** head_ref, int new_data, int position) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;

    if (position == 1) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }

    struct node* prev_node = *head_ref;
    for (int i = 1; i < position - 1 && prev_node != NULL; i++)
        prev_node = prev_node->next;

    if (prev_node == NULL) {
        printf("Invalid position!\n");
        free(new_node);
        return;
    }

    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

//Function to delete node at any position of the linked list
void delete_node_at_position(struct node** head_ref, int position) {
    if (*head_ref == NULL)
        return;

    struct node* temp_node = *head_ref;

    if (position == 1) {
        *head_ref = temp_node->next;
        free(temp_node);
        return;
    }

    for (int i = 1; i < position - 1 && temp_node != NULL; i++)
        temp_node = temp_node->next;

    if (temp_node == NULL || temp_node->next == NULL) {
        printf("Invalid position!\n");
        return;
    }

    struct node* next_node = temp_node->next->next;
    free(temp_node->next);
    temp_node->next = next_node;
}

int main() {
    //Initialize linked list
    struct node* head = NULL;

    //Add nodes to the linked list
    add_node_at_beginning(&head, 3);
    add_node_at_beginning(&head, 1);
    add_node_at_end(&head, 5);
    add_node_at_position(&head, 2, 2);
    add_node_at_position(&head, 4, 4);

    //Print linked list
    printf("Linked list: ");
    print_list(head);

    //Delete nodes from the linked list
    delete_node_at_position(&head, 3);
    delete_node_at_position(&head, 5);

    //Print updated linked list
    printf("Updated linked list: ");
    print_list(head);

    return 0;
}