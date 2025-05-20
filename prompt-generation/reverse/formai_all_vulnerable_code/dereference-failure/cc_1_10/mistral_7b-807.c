//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: retro
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Node* create_linked_list(int* arr, int size) {
    Node* head = NULL;
    Node* new_node = NULL;

    for(int i = 0; i < size; i++) {
        if(head == NULL) {
            head = create_node(arr[i]);
            new_node = head;
        } else {
            new_node->next = create_node(arr[i]);
            new_node = new_node->next;
        }
    }

    return head;
}

void print_linked_list(Node* head) {
    Node* current = head;

    printf("Linked List: ");

    while(current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

void free_linked_list(Node* head) {
    Node* current = head;
    Node* next;

    while(current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    Node* head = create_linked_list(arr, size);
    print_linked_list(head);

    free_linked_list(head);

    printf("Memory freed.\n");

    return 0;
}