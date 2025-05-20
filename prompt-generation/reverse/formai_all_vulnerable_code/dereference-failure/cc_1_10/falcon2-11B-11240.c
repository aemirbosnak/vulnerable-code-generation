//Falcon2-11B DATASET v1.0 Category: Greedy Algorithms ; Style: futuristic
// Futuristic Greedy Algorithms

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* create_node(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void insert(struct Node** head_ref, int data) {
    struct Node* new_node = create_node(data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    struct Node* current = *head_ref;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void display(struct Node* head) {
    struct Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 1);
    display(head); // Output: 1 2 3

    insert(&head, 4);
    display(head); // Output: 1 2 4 3

    insert(&head, 5);
    display(head); // Output: 1 2 5 4 3

    insert(&head, 6);
    display(head); // Output: 1 2 6 5 4 3

    insert(&head, 7);
    display(head); // Output: 1 2 7 6 5 4 3

    insert(&head, 8);
    display(head); // Output: 1 2 8 7 6 5 4 3

    insert(&head, 9);
    display(head); // Output: 1 2 9 8 7 6 5 4 3

    return 0;
}