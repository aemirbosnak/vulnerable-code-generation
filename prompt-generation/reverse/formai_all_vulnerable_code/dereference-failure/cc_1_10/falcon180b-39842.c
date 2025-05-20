//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void push(Node** head_ref, int new_data) {
    Node* new_node = create_node(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void print_list(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    Node* head = NULL;

    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);

    printf("Created Linked List: ");
    print_list(head);

    Node* temp = head;
    while (temp!= NULL) {
        if (temp->data == 3) {
            Node* prev_node = head;
            while (prev_node->next!= temp) {
                prev_node = prev_node->next;
            }
            prev_node->next = temp->next;
            free(temp);
            temp = head;
        } else {
            temp = temp->next;
        }
    }

    printf("\nLinked List after deleting 3: ");
    print_list(head);

    return 0;
}