//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: random
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
    Node* current = NULL;
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        int data = rand() % MAX_SIZE;
        current = (Node*) malloc(sizeof(Node));
        current->data = data;
        current->next = NULL;
        if (head == NULL) {
            head = current;
        } else {
            Node* temp = head;
            while (temp->next!= NULL) {
                temp = temp->next;
            }
            temp->next = current;
        }
    }
    return head;
}

void print_list(Node* head) {
    Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void reverse_list(Node** head) {
    Node* prev = NULL;
    Node* current = *head;
    while (current!= NULL) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

int main() {
    Node* head = create_list(10);
    printf("Original list:\n");
    print_list(head);
    reverse_list(&head);
    printf("Reversed list:\n");
    print_list(head);
    return 0;
}