//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: medieval
#include <stdlib.h>
#include <stddef.h>

#define LIST_MAX_SIZE 100
#define LIST_EMPTY 0
#define LIST_NOT_EMPTY 1

// Structure to represent a node in the linked list
struct node {
    int data;
    struct node* next;
};

// Function to create an empty linked list
struct node* list_create(void) {
    struct node* head = NULL;
    return head;
}

// Function to insert an element into the linked list
struct node* list_insert(struct node** head_ref, int data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
    return new_node;
}

// Function to search for an element in the linked list
struct node* list_search(struct node* head, int data) {
    while (head != NULL && head->data != data) {
        head = head->next;
    }
    return head;
}

// Function to remove the first occurrence of an element in the linked list
struct node* list_remove(struct node** head_ref, int data) {
    struct node* current = *head_ref;
    struct node* previous = NULL;

    while (current != NULL && current->data != data) {
        previous = current;
        current = current->next;
    }

    if (current != NULL) {
        if (previous == NULL) {
            *head_ref = current->next;
        } else {
            previous->next = current->next;
        }
        free(current);
        return current;
    }

    return NULL;
}

// Function to traverse the linked list
void list_traverse(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main(void) {
    struct node* head = list_create();

    // Insert some elements into the linked list
    list_insert(&head, 1);
    list_insert(&head, 2);
    list_insert(&head, 3);
    list_insert(&head, 4);
    list_insert(&head, 5);

    // Search for an element in the linked list
    struct node* node = list_search(head, 3);
    if (node != NULL) {
        printf("Element found at index %d\n", node->data);
    } else {
        printf("Element not found\n");
    }

    // Remove the first occurrence of an element in the linked list
    struct node* removed_node = list_remove(&head, 3);
    if (removed_node != NULL) {
        printf("Removed element at index %d\n", removed_node->data);
    } else {
        printf("Element not found\n");
    }

    // Traverse the linked list
    list_traverse(head);

    return 0;
}