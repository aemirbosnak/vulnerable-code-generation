//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

#define MAX_SIZE 1000

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *create_list(int size) {
    Node *head = NULL;
    Node *tail = NULL;
    int i;

    srand(time(NULL));

    for (i = 0; i < size; i++) {
        Node *new_node = (Node *) malloc(sizeof(Node));
        new_node->data = rand() % 100;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    return head;
}

void print_list(Node *head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void reverse_list(Node **head_ref) {
    Node *prev = NULL;
    Node *next = NULL;

    while (*head_ref!= NULL) {
        next = (*head_ref)->next;
        (*head_ref)->next = prev;
        prev = (*head_ref);
        (*head_ref) = next;
    }

    *head_ref = prev;
}

void sort_list(Node *head) {
    Node *temp;
    int swapped;

    do {
        swapped = FALSE;
        temp = head;
        while (temp->next!= NULL) {
            if (temp->data > temp->next->data) {
                int temp_data = temp->data;
                temp->data = temp->next->data;
                temp->next->data = temp_data;
                swapped = TRUE;
            }
            temp = temp->next;
        }
    } while (swapped);
}

int main() {
    Node *head = create_list(10);
    print_list(head);
    reverse_list(&head);
    print_list(head);
    sort_list(head);
    print_list(head);

    return 0;
}