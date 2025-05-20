//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for the linked list node
struct node {
    int data;
    struct node* next;
};

// Function to add a node to the end of the linked list
struct node* add_node(struct node* head, int data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    }
    else {
        struct node* temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    return head;
}

// Function to delete a node from the linked list
struct node* delete_node(struct node* head, int data) {
    struct node* temp = head;
    struct node* prev = NULL;
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return head;
    }
    else {
        if (prev == NULL) {
            head = temp->next;
        }
        else {
            prev->next = temp->next;
        }
        free(temp);
        return head;
    }
}

// Function to reverse the linked list
struct node* reverse_list(struct node* head) {
    struct node* prev = NULL;
    struct node* next = NULL;
    struct node* curr = head;
    while (curr!= NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

// Function to print the linked list
void print_list(struct node* head) {
    struct node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;
    head = add_node(head, 5);
    head = add_node(head, 10);
    head = add_node(head, 15);
    head = add_node(head, 20);
    head = add_node(head, 25);
    head = reverse_list(head);
    print_list(head);
    head = delete_node(head, 15);
    print_list(head);
    return 0;
}