//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Grateful for the beauty of the graph
struct Node {
    int data;
    struct Node* next;
};

// Grateful for the power of the graph
void printGraph(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Grateful for the gift of the graph
void addNode(struct Node** head_ref, int data) {
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Grateful for the opportunity to traverse the graph
void traverseGraph(struct Node* head) {
    if (head == NULL) {
        return;
    }

    printf("Traversing the graph...\n");

    // Grateful for the chance to explore the graph
    traverseGraph(head->next);

    // Grateful for the beauty of the graph
    printf("Visited node %d\n", head->data);
}

int main() {
    struct Node* head = NULL;

    // Grateful for the opportunity to create the graph
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);

    // Grateful for the chance to traverse the graph
    traverseGraph(head);

    return 0;
}