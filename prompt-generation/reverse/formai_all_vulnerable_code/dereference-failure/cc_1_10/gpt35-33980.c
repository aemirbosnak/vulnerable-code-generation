//FormAI DATASET v1.0 Category: Linked list operations ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the shape-shifting linked list node
struct node {
    int data;
    struct node* next;
    struct node* prev;
    char shape;
};

// Function to randomly generate a shape for a node
char shape_shift() {
    int r = rand() % 4;
    if (r == 0) {
        return 'o';
    } else if (r == 1) {
        return '*';
    } else if (r == 2) {
        return '-';
    } else {
        return '|';
    }
}

// Function to create a new node with shape-shifting abilities
struct node* newNode(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->shape = shape_shift();
    return new_node;
}

// Function to add a node to the end of the linked list
void append(struct node** head_ref, int new_data) {
    struct node* new_node = newNode(new_data);
    struct node* last = *head_ref;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
    new_node->prev = last;
}

// Function to delete a node from the linked list
void delete_node(struct node** head_ref, struct node* del) {
    if (*head_ref == NULL || del == NULL) {
        return;
    }
    if (*head_ref == del) {
        *head_ref = del->next;
    }
    if (del->next != NULL) {
        del->next->prev = del->prev;
    }
    if (del->prev != NULL) {
        del->prev->next = del->next;
    }
    free(del);
}

// Function to display the linked list
void display(struct node* node) {
    while (node != NULL) {
        printf("%c%d%c ", node->shape, node->data, node->shape);
        node = node->next;
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    struct node* head = NULL;

    // Append some nodes to the linked list
    printf("Appending 5 nodes to the linked list...\n");
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);
    append(&head, 50);
    display(head);

    // Delete a node from the linked list
    printf("Deleting the third node from the linked list...\n");
    delete_node(&head, head->next->next);
    display(head);

    return 0;
}