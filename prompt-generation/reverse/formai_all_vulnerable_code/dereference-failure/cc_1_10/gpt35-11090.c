//FormAI DATASET v1.0 Category: Linked list operations ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

/* Define a struct representing a single node of the linked list */
struct node {
    int data;           // integer data stored in the node
    struct node *next;  // pointer to the next node in the list
};

/* Function to create a new node and initialize its data and next fields */
struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

/* Function to insert a new node at the beginning of the list */
void insert_at_begin(struct node** head_ref, int data) {
    struct node* new_node = create_node(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

/* Function to insert a new node at the end of the list */
void insert_at_end(struct node** head_ref, int data) {
    struct node* new_node = create_node(data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        struct node* ptr = *head_ref;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
}

/* Function to delete the first node of the list */
void delete_at_begin(struct node** head_ref) {
    if (*head_ref == NULL) {
        printf("The list is empty.\n");
    } else {
        struct node* temp = *head_ref;
        *head_ref = temp->next;
        free(temp);
    }
}

/* Function to delete the last node of the list */
void delete_at_end(struct node** head_ref) {
    if (*head_ref == NULL) {
        printf("The list is empty.\n");
    } else if ((*head_ref)->next == NULL) {
        free(*head_ref);
        *head_ref = NULL;
    } else {
        struct node* ptr = *head_ref;
        while (ptr->next->next != NULL) {
            ptr = ptr->next;
        }
        free(ptr->next);
        ptr->next = NULL;
    }
}

/* Function to print the contents of the linked list */
void print_list(struct node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
    } else {
        printf("Elements of the list are:\n");
        struct node* ptr = head;
        while (ptr != NULL) {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

/* Main function to test the linked list operations */
int main() {
    struct node* head = NULL;
    insert_at_begin(&head, 1);
    insert_at_begin(&head, 2);
    insert_at_begin(&head, 3);
    insert_at_end(&head, 4);
    insert_at_end(&head, 5);
    print_list(head);
    delete_at_begin(&head);
    delete_at_end(&head);
    delete_at_end(&head);
    print_list(head);
    return 0;
}