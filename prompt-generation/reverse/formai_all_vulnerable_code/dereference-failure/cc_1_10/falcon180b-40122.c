//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Node structure for linked list
struct node {
    char *data;
    struct node *next;
};

// Function to create a new node with given data
struct node* new_node(char *data) {
    struct node *node = (struct node*) malloc(sizeof(struct node));
    node->data = strdup(data);
    node->next = NULL;
    return node;
}

// Function to search for a word in the linked list
int search_word(struct node *head, char *word) {
    struct node *current = head;
    while (current!= NULL) {
        if (strcmp(current->data, word) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

// Function to print the linked list
void print_list(struct node *head) {
    struct node *current = head;
    while (current!= NULL) {
        printf("%s -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    // Create a linked list with sample data
    struct node *head = NULL;
    head = new_node("The");
    head->next = new_node("quick");
    head->next->next = new_node("brown");
    head->next->next->next = new_node("fox");
    head->next->next->next->next = new_node("jumps");
    head->next->next->next->next->next = new_node("over");
    head->next->next->next->next->next->next = new_node("the");
    head->next->next->next->next->next->next->next = new_node("lazy");
    head->next->next->next->next->next->next->next->next = new_node("dog");

    // Print the linked list
    printf("Original List:\n");
    print_list(head);

    // Search for a word in the linked list
    char *word = "fox";
    if (search_word(head, word)) {
        printf("\n%s found in the list!\n", word);
    } else {
        printf("\n%s not found in the list.\n", word);
    }

    // Free memory allocated for the linked list
    struct node *temp = head;
    while (temp!= NULL) {
        free(temp->data);
        temp = temp->next;
        free(temp);
    }

    return 0;
}