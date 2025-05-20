//FormAI DATASET v1.0 Category: Linked list operations ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// Node definition
struct node {
    int data;
    struct node* next;
};

// Function to create new node
struct node* create_node(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to insert new node at the end of the list
void insert_end(struct node** head_ref, int data) {
    struct node* new_node = create_node(data);
    struct node* current = *head_ref;

    // If list is empty
    if(*head_ref == NULL) {
        *head_ref = new_node;
    }
    else {
        // Traverse to the end of the list
        while(current->next != NULL) {
            current = current->next;
        }

        current->next = new_node;
    }
}

// Function to delete node at a given position
void delete_node(struct node** head_ref, int position) {
    struct node* current = *head_ref, *prev = NULL;

    // If list is empty
    if(*head_ref == NULL) {
        printf("List is empty!\n");
        return;
    }

    // If head node needs to be deleted
    if(position == 0) {
        *head_ref = current->next;
        free(current);
        return;
    }

    // Traverse to the position of node to be deleted
    for(int i = 0; i < position; i++) {
        prev = current;
        current = current->next;

        // If position is out of range
        if(current == NULL) {
            printf("Position out of range\n");
            return;
        }
    }

    // Delete the node at given position
    prev->next = current->next;
    free(current);
}

// Function to print the contents of the list
void print_list(struct node* head) {
    printf("List contents: ");

    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");
}

int main() {
    struct node* head = NULL;

    insert_end(&head, 10);
    insert_end(&head, 20);
    insert_end(&head, 30);
    insert_end(&head, 40);
    insert_end(&head, 50);

    print_list(head);

    delete_node(&head, 3);

    print_list(head);

    delete_node(&head, 6);

    print_list(head);

    return 0;
}