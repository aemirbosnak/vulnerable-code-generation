//Falcon-180B DATASET v1.0 Category: Educational ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int next;
} Node;

Node *create_node(int data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_at_end(Node **head, int data) {
    Node *new_node = create_node(data);
    Node *temp = *head;

    if (*head == NULL) {
        new_node->next = NULL;
        *head = new_node;
        return;
    }

    while (temp->next!= NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
    new_node->next = NULL;
}

void delete_node(Node **head, int data) {
    Node *temp = *head;

    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= data) {
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    Node *prev_node = temp->next;
    temp->next = prev_node->next;
    free(prev_node);
}

void traverse_list(Node *head) {
    Node *temp = head;

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    srand(time(NULL));

    Node *head = NULL;

    for (int i = 0; i < MAX_SIZE; i++) {
        int data = rand() % 100;
        insert_at_end(&head, data);
    }

    printf("Initial list:\n");
    traverse_list(head);

    int search_data = rand() % 100;
    delete_node(&head, search_data);

    printf("\nAfter deleting %d:\n", search_data);
    traverse_list(head);

    return 0;
}