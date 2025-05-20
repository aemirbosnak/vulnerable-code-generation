//FormAI DATASET v1.0 Category: Data structures visualization ; Style: shocked
#include <stdio.h>

/* Define the struct for a node in a linked list */
typedef struct ListNode {
    int data;
    struct ListNode *next;
} ListNode;

/* Function to add a new node to the end of a linked list */
void add_node(ListNode **head, int data) {
    ListNode *new_node = malloc(sizeof(ListNode));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        ListNode *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

/* Function to print the contents of a linked list */
void print_list(ListNode *head) {
    ListNode *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    ListNode *list = NULL;

    /* Add some nodes to the linked list */
    add_node(&list, 1);
    add_node(&list, 4);
    add_node(&list, 5);
    add_node(&list, 3);

    /* Visualize the linked list */
    printf("Here's what the linked list looks like:\n");
    print_list(list);

    /* Add some more nodes */
    add_node(&list, 2);
    add_node(&list, 6);

    /* Visualize the updated linked list */
    printf("\nAnd here's what the linked list looks like now:\n");
    print_list(list);

    return 0;
}