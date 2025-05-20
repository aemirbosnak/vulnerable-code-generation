//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Node* create_list(int size) {
    Node* head = NULL;
    int i;
    for (i = 0; i < size; i++) {
        head = create_node(rand() % 100);
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

void sort_list(Node* head) {
    Node* current = head;
    while (current!= NULL && current->next!= NULL) {
        if (current->data > current->next->data) {
            int temp_data = current->data;
            current->data = current->next->data;
            current->next->data = temp_data;
        }
        current = current->next;
    }
}

void reverse_list(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    while (current!= NULL) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void delete_node(Node* head, int data) {
    Node* current = head;
    while (current!= NULL && current->data!= data) {
        current = current->next;
    }
    if (current!= NULL) {
        Node* temp = current->next;
        free(current);
        current = temp;
    }
}

int main() {
    srand(time(NULL));
    Node* list = create_list(MAX_SIZE);
    printf("Original list:\n");
    print_list(list);
    sort_list(list);
    printf("Sorted list:\n");
    print_list(list);
    reverse_list(list);
    printf("Reversed list:\n");
    print_list(list);
    delete_node(list, 50);
    printf("List after deleting node with data 50:\n");
    print_list(list);
    return 0;
}