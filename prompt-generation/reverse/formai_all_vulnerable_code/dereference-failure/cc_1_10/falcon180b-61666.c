//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Define structure for a linked list
struct LinkedList {
    struct Node* head;
};

// Function to create a new node
struct Node* create_node(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to create an empty linked list
struct LinkedList* create_linked_list() {
    struct LinkedList* new_list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    if (new_list == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    new_list->head = NULL;
    return new_list;
}

// Function to add a node to the end of the linked list
void add_node(struct LinkedList* list, int data) {
    struct Node* new_node = create_node(data);
    if (list->head == NULL) {
        list->head = new_node;
    }
    else {
        struct Node* temp = list->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Function to display the linked list
void display_linked_list(struct LinkedList* list) {
    struct Node* temp = list->head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to reverse the linked list
void reverse_linked_list(struct LinkedList* list) {
    struct Node* prev = NULL;
    struct Node* curr = list->head;
    while (curr!= NULL) {
        struct Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    list->head = prev;
}

int main() {
    struct LinkedList* list = create_linked_list();
    add_node(list, 5);
    add_node(list, 10);
    add_node(list, 15);
    printf("Original linked list:\n");
    display_linked_list(list);
    reverse_linked_list(list);
    printf("Reversed linked list:\n");
    display_linked_list(list);
    return 0;
}