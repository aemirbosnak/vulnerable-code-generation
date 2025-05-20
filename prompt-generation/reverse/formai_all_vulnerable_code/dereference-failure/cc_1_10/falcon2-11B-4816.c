//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node {
    char data;
    struct node* next;
} Node;

Node* create_node(char data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Node* create_linked_list(char* arr, int size) {
    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < size; i++) {
        Node* new_node = create_node(arr[i]);

        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = tail->next;
        }
    }

    return head;
}

void print_linked_list(Node* head) {
    Node* current = head;

    while (current!= NULL) {
        printf("%c ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    char arr[] = "ABCD";
    int size = strlen(arr);

    Node* head = create_linked_list(arr, size);
    print_linked_list(head);

    return 0;
}