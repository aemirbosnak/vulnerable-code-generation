//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct node {
    int data;
    struct node* next;
} node;

node* insert(node* head, int data) {
    node* newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void print_list(node* head) {
    node* current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    node* head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);

    print_list(head);

    // Maze Route Finder Algorithm
    node* current = head;
    node* target = head->next->next->next;
    int distance = 0;

    while (current != target) {
        current = current->next;
        distance++;
    }

    printf("Distance to target: %d\n", distance);

    return 0;
}