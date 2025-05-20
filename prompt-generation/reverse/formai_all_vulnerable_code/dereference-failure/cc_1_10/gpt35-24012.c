//FormAI DATASET v1.0 Category: Linked list operations ; Style: random
#include <stdio.h>
#include <stdlib.h>

// Node Structure
struct Node {
    int data;
    struct Node* next;
};

// Method to create a new node
struct Node* create_node(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Method to add a node to the beginning of the list
void add_first(struct Node** head_ref, int data) {
    struct Node* new_node = create_node(data);
    if(*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
}

// Method to add a node to the end of the list
void add_last(struct Node** head_ref, int data) {
    struct Node* new_node = create_node(data);
    if(*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        struct Node* temp = *head_ref;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Method to add a node after a given node
void add_after(struct Node* prev_node, int data) {
    if(prev_node == NULL) {
        printf("Previous node cannot be null");
        return;
    }
    struct Node* new_node = create_node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Method to delete a node from the list
void delete_node(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;
    if(temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("Node with data %d not found", key);
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Method to display the list
void display_list(struct Node* head_ref) {
    struct Node* temp = head_ref;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    add_first(&head, 5);
    add_last(&head, 10);
    add_after(head->next, 7);
    delete_node(&head, 5);
    delete_node(&head, 20);
    display_list(head);
    return 0;
}