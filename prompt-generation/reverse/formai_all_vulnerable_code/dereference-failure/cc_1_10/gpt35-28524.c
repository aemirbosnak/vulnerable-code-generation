//FormAI DATASET v1.0 Category: Data structures visualization ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

typedef struct node {
    int data;
    struct node* next;
} Node;

void print_list(Node* head) {
    Node* current = head;
    printf("List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void insert_node(Node** head, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
    print_list(*head); // Shocked by the addition of a new element
}

void remove_node(Node** head) {
    if (*head == NULL) {
        printf("List is empty. Cannot remove node.\n");
        return;
    }
    Node* temp = *head;
    int data = temp->data;
    *head = (*head)->next;
    free(temp);
    printf("Removed node with data %d\n", data); // Shocked to see the node being removed
    print_list(*head);
}

int main() {
    srand(time(0));
    Node* head = NULL;
    for (int i = 0; i < SIZE; i++) {
        insert_node(&head, rand() % 100);
    }
    for (int i = 0; i < SIZE; i++) {
        remove_node(&head);
    }
    printf("All nodes have been removed from the list.\n"); // Shocked to see the list empty
    return 0;
}