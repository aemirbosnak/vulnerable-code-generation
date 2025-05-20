//FormAI DATASET v1.0 Category: Linked list operations ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

/* Define node struct */
typedef struct node {
    int data;
    struct node *next;
} Node;

/* Create the head node */
Node *head = NULL;

/* Add node to the beginning of the list */
void add_node_beginning(int n) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = n;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        new_node->next = head;
        head = new_node;
    }
    printf("\nNode with data %d added at the beginning!\n", n);
}

/* Add node to the end of the list */
void add_node_end(int n) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = n;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        Node *curr_node = head;
        while (curr_node->next != NULL) {
            curr_node = curr_node->next;
        }
        curr_node->next = new_node;
    }
    printf("\nNode with data %d added at the end!\n", n);
}

/* Delete a node from the list */
void delete_node(int n) {
    if (head == NULL) {
        printf("\nList is empty! Cannot delete node.\n");
    } else if (head->data == n) {
        Node *temp = head;
        head = head->next;
        free(temp);
        printf("\nNode with data %d deleted!\n", n);
    } else {
        Node *curr_node = head;
        Node *prev_node = NULL;
        while (curr_node != NULL && curr_node->data != n) {
            prev_node = curr_node;
            curr_node = curr_node->next;
        }
        if (curr_node == NULL) {
            printf("\nNode with data %d not found in list! Cannot delete node.\n", n);
        } else {
            prev_node->next = curr_node->next;
            free(curr_node);
            printf("\nNode with data %d deleted!\n", n);
        }
    }
}

/* Display the list */
void display() {
    if (head == NULL) {
        printf("\nList is empty!\n");
    } else {
        printf("\nList elements:\n");
        Node *curr_node = head;
        while (curr_node != NULL) {
            printf("%d -> ", curr_node->data);
            curr_node = curr_node->next;
        }
        printf("NULL\n");
    }
}

int main() {
    /* Add nodes to the list */
    add_node_end(10);
    add_node_end(20);
    add_node_beginning(5);
    add_node_end(30);
    add_node_beginning(2);
    add_node_end(40);

    /* Display the list */
    display();

    /* Delete a node from the list */
    delete_node(20);

    /* Display the list again */
    display();

    return 0;
}