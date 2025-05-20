//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for linked list
struct node {
    char name[50];
    int num;
    struct node* next;
};

// Function to create a new node
struct node* create_node(char* name, int num) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    strcpy(new_node->name, name);
    new_node->num = num;
    new_node->next = NULL;
    return new_node;
}

// Function to add a node to the end of the list
void add_node(struct node** head, char* name, int num) {
    struct node* new_node = create_node(name, num);
    struct node* temp = *head;

    if (*head == NULL) {
        new_node->next = NULL;
        *head = new_node;
        return;
    }

    while (temp->next!= NULL)
        temp = temp->next;

    temp->next = new_node;
    new_node->next = NULL;
}

// Function to delete a node from the list
void delete_node(struct node** head, char* name) {
    struct node* temp = *head;
    struct node* prev = NULL;

    if (temp!= NULL && strcmp(temp->name, name) == 0) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && strcmp(temp->name, name)!= 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

// Function to search for a node in the list
struct node* search_node(struct node* head, char* name) {
    struct node* temp = head;

    while (temp!= NULL) {
        if (strcmp(temp->name, name) == 0)
            return temp;
        temp = temp->next;
    }

    return NULL;
}

// Function to print the list
void print_list(struct node* head) {
    struct node* temp = head;

    while (temp!= NULL) {
        printf("%s %d\n", temp->name, temp->num);
        temp = temp->next;
    }
}

int main() {
    struct node* head = NULL;

    add_node(&head, "Alice", 25);
    add_node(&head, "Bob", 30);
    add_node(&head, "Charlie", 35);

    print_list(head);

    delete_node(&head, "Bob");

    print_list(head);

    struct node* found_node = search_node(head, "Charlie");

    if (found_node!= NULL)
        printf("Found node: %s %d\n", found_node->name, found_node->num);
    else
        printf("Node not found.\n");

    return 0;
}