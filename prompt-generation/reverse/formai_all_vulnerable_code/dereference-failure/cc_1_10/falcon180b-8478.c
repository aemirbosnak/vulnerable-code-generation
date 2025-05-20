//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* create_list(int size) {
    Node* head = NULL;
    for (int i = 0; i < size; i++) {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = rand() % 100;
        new_node->next = NULL;
        if (head == NULL) {
            head = new_node;
        } else {
            Node* temp = head;
            while (temp->next!= NULL) {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }
    return head;
}

void display_list(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void add_node(Node** head_ref, int new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void delete_node(Node **head_ref, int key) {
    Node* temp = *head_ref;
    Node* prev = NULL;

    if (temp!= NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

void reverse_list(Node** head_ref) {
    Node* prev = NULL;
    Node* next = NULL;
    Node* current = *head_ref;

    while (current!= NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head_ref = prev;
}

int main() {
    srand(time(NULL));
    Node* head = create_list(MAX_SIZE);
    display_list(head);
    add_node(&head, 42);
    display_list(head);
    delete_node(&head, 13);
    display_list(head);
    reverse_list(&head);
    display_list(head);
    return 0;
}