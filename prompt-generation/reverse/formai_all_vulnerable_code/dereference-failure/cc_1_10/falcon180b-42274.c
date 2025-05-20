//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the database indexing system
struct node {
    char *key;
    int value;
    struct node *next;
};

// Function to create a new node
struct node *create_node(char *key, int value) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->key = strdup(key);
    newnode->value = value;
    newnode->next = NULL;
    return newnode;
}

// Function to insert a new node into the database
void insert_node(struct node *head, char *key, int value) {
    struct node *newnode = create_node(key, value);
    if (head == NULL) {
        head = newnode;
    } else {
        struct node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

// Function to search for a node in the database
struct node *search_node(struct node *head, char *key) {
    struct node *temp = head;
    while (temp!= NULL) {
        if (strcmp(temp->key, key) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to delete a node from the database
void delete_node(struct node *head, char *key) {
    struct node *temp = search_node(head, key);
    if (temp!= NULL) {
        struct node *prev = head;
        while (prev->next!= temp) {
            prev = prev->next;
        }
        prev->next = temp->next;
        free(temp->key);
        free(temp);
    }
}

// Function to display the database
void display_database(struct node *head) {
    struct node *temp = head;
    while (temp!= NULL) {
        printf("%s -> %d\n", temp->key, temp->value);
        temp = temp->next;
    }
}

int main() {
    // Initialize the database
    struct node *head = NULL;
    insert_node(head, "apple", 10);
    insert_node(head, "banana", 20);
    insert_node(head, "cherry", 30);

    // Display the database
    printf("Initial database:\n");
    display_database(head);

    // Search for a node
    struct node *node = search_node(head, "banana");
    if (node!= NULL) {
        printf("Node found: %s -> %d\n", node->key, node->value);
    } else {
        printf("Node not found\n");
    }

    // Delete a node
    delete_node(head, "banana");

    // Display the updated database
    printf("Updated database:\n");
    display_database(head);

    return 0;
}