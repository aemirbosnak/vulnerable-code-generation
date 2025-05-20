//FormAI DATASET v1.0 Category: Linked list operations ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *create_list(int n);
Node *insert_node(Node *head, int data, int position);
Node *delete_node(Node *head, int position);
void display_list(Node *head);

int main() {
    int n = 0;
    int position = 0;
    int data = 0;
    Node *head = NULL;

    printf("How many nodes do you want to create?\n");
    scanf("%d", &n);

    head = create_list(n);

    printf("Enter the data value of the node to insert:\n");
    scanf("%d", &data);

    printf("Enter the position (starting from 1) where you want to insert the node:\n");
    scanf("%d", &position);

    head = insert_node(head, data, position);

    printf("Enter the position (starting from 1) of the node you want to delete:\n");
    scanf("%d", &position);

    head = delete_node(head, position);

    printf("The final linked list is:\n");
    display_list(head);

    return 0;
}

Node *create_list(int n) {
    int i = 0;
    Node *head = NULL;
    Node *temp = NULL;

    for (i = 0; i < n; i++) {
        temp = (Node*) malloc(sizeof(Node));
        printf("Enter the data value for node %d:\n", i+1);
        scanf("%d", &temp->data);
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
        } else {
            Node *current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = temp;
        }
    }

    return head;
}

Node *insert_node(Node *head, int data, int position) {
    Node *temp = (Node*) malloc(sizeof(Node));
    Node *current = head;
    int i = 0;

    temp->data = data;
    temp->next = NULL;

    if (position == 1) {
        temp->next = head;
        head = temp;
        return head;
    }

    for (i = 1; i < position-1; i++) {
        current = current->next;
    }

    temp->next = current->next;
    current->next = temp;

    return head;
}

Node *delete_node(Node *head, int position) {
    Node *temp = NULL;
    Node *current = head;
    int i = 0;

    if (position == 1) {
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    for (i = 1; i < position-1; i++) {
        current = current->next;
    }

    temp = current->next;
    current->next = temp->next;
    free(temp);

    return head;
}

void display_list(Node *head) {
    Node *current = head;

    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}