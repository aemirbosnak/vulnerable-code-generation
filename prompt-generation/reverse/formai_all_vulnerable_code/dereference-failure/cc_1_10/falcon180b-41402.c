//Falcon-180B DATASET v1.0 Category: Memory management ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char *data;
    struct node *next;
};

// Function to create a new node
struct node* create_node(char *data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = strdup(data);
    new_node->next = NULL;
    return new_node;
}

// Function to add a node at the end of the list
void add_node(struct node **head, char *data) {
    struct node *new_node = create_node(data);
    struct node *temp = *head;
    if (*head == NULL) {
        new_node->next = NULL;
        *head = new_node;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = NULL;
}

// Function to delete a node from the list
void delete_node(struct node **head, char *data) {
    struct node *temp = *head;
    if (temp!= NULL && strcmp(temp->data, data) == 0) {
        *head = temp->next;
        free(temp->data);
        free(temp);
        return;
    }
    while (temp!= NULL && strcmp(temp->data, data)!= 0) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node not found\n");
        return;
    }
    temp->next = temp->next->next;
    free(temp->data);
    free(temp);
}

// Function to print the list
void print_list(struct node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    while (temp!= NULL) {
        printf("%s ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct node *head = NULL;
    add_node(&head, "apple");
    add_node(&head, "banana");
    add_node(&head, "cherry");
    print_list(head);
    delete_node(&head, "banana");
    print_list(head);
    delete_node(&head, "apple");
    print_list(head);
    delete_node(&head, "cherry");
    print_list(head);
    return 0;
}