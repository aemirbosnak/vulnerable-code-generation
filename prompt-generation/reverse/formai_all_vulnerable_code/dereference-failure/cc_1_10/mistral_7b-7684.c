//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node *next;
} Node;

Node* create_node(int data) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_at_beginning(Node **head, int data) {
    Node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

void print_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int linear_search_invasive(Node *head, int target, int *index) {
    Node *current = head;
    int pos = 0;

    while (current != NULL) {
        if (current->data == target) {
            *index = pos;
            return 1;
        }
        pos++;
        current = current->next;
    }

    *index = -1;
    return 0;
}

int main() {
    Node *head = NULL;
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int i, target, index;

    for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        insert_at_beginning(&head, arr[i]);
    }

    printf("Linked List: ");
    print_list(head);

    printf("Enter the number to search: ");
    scanf("%d", &target);

    if (linear_search_invasive(head, target, &index) == 1) {
        printf("Number found at position %d.\n", index + 1);
    } else {
        printf("Number not found.\n");
    }

    return 0;
}