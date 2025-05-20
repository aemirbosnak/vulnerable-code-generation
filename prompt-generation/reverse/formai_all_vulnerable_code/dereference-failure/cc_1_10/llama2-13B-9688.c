//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 20

struct node {
    char *name;
    int age;
    struct node *next;
};

// Function to allocate memory for a node
struct node* create_node(char *name, int age) {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->name = name;
    node->age = age;
    node->next = NULL;
    return node;
}

// Function to print all nodes in a linked list
void print_list(struct node *head) {
    while (head != NULL) {
        printf("%s %d\n", head->name, head->age);
        head = head->next;
    }
}

int main() {
    struct node *head = NULL;

    // Create a list of names and ages
    head = create_node("Alice", 25);
    head = create_node("Bob", 30);
    head = create_node("Charlie", 35);
    head = create_node("David", 20);

    // Print the list
    print_list(head);

    // Free the memory of the list
    struct node *current = head;
    while (current != NULL) {
        struct node *temp = current;
        free(current);
        current = temp->next;
    }

    return 0;
}