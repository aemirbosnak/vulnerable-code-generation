//FormAI DATASET v1.0 Category: Linked list operations ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// define the structure of each node in the linked list
struct node {
    int data;
    struct node *next;
};

// function to create and add a new node to the linked list
void add_node(struct node **head, int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
    } else {
        struct node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// function to print all the nodes in the linked list
void print_nodes(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// function to count the number of nodes in the linked list
int count_nodes(struct node *head) {
    int count = 0;
    struct node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// function to delete a node from the linked list
void delete_node(struct node **head, int data) {
    struct node *temp = *head;
    struct node *prev = NULL;
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    } else if (prev == NULL) {
        *head = (*head)->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
}

// function to reverse the linked list
void reverse_list(struct node **head) {
    struct node *prev = NULL;
    struct node *current = *head;
    struct node *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

int main() {
    struct node *head = NULL;

    // add some nodes to the list
    add_node(&head, 3);
    add_node(&head, 7);
    add_node(&head, 9);
    add_node(&head, 2);
    add_node(&head, 5);

    // print the initial list
    printf("Initial List: ");
    print_nodes(head);

    // count the number of nodes
    printf("Number of Nodes: %d\n", count_nodes(head));

    // delete a node
    int num_to_delete = 9;
    delete_node(&head, num_to_delete);
    printf("After Deleting %d: ", num_to_delete);
    print_nodes(head);

    // reverse the list
    reverse_list(&head);
    printf("After Reversing: ");
    print_nodes(head);

    return 0;
}