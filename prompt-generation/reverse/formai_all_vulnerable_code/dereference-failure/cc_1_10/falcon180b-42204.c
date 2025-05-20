//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the linked list structure
typedef struct linked_list {
    Node* head;
    int size;
} LinkedList;

// Function to create a new node with given data
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to create a new empty linked list
LinkedList* create_linked_list() {
    LinkedList* new_list = (LinkedList*)malloc(sizeof(LinkedList));
    if (new_list == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_list->head = NULL;
    new_list->size = 0;
    return new_list;
}

// Function to add a node at the end of the linked list
void add_node(LinkedList* list, int data) {
    Node* new_node = create_node(data);
    Node* temp = list->head;
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    list->size++;
}

// Function to print the linked list
void print_linked_list(LinkedList* list) {
    Node* temp = list->head;
    printf("Linked List: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to reverse the linked list
void reverse_linked_list(LinkedList* list) {
    Node* prev = NULL;
    Node* curr = list->head;
    while (curr!= NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    list->head = prev;
}

int main() {
    LinkedList* list = create_linked_list();
    add_node(list, 5);
    add_node(list, 10);
    add_node(list, 15);
    printf("Original Linked List: ");
    print_linked_list(list);
    reverse_linked_list(list);
    printf("Reversed Linked List: ");
    print_linked_list(list);
    return 0;
}