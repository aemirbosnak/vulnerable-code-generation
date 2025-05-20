//Falcon-180B DATASET v1.0 Category: Sorting ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in our linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the structure for a linked list
typedef struct linked_list {
    Node* head;
    int size;
} LinkedList;

// Create a new node
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

// Create a new linked list
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

// Add a node to the end of the linked list
void add_node(LinkedList* list, int data) {
    Node* new_node = create_node(data);
    Node* curr_node = list->head;
    if (curr_node == NULL) {
        list->head = new_node;
    } else {
        while (curr_node->next!= NULL) {
            curr_node = curr_node->next;
        }
        curr_node->next = new_node;
    }
    list->size++;
}

// Sort the linked list in ascending order
void sort_linked_list(LinkedList* list) {
    Node* curr_node = list->head;
    Node* prev_node = NULL;
    while (curr_node!= NULL) {
        int curr_data = curr_node->data;
        while (prev_node!= NULL && prev_node->data > curr_data) {
            int temp_data = prev_node->data;
            prev_node->data = curr_data;
            curr_node->data = temp_data;
            curr_node = prev_node;
            prev_node = curr_node->next;
        }
        curr_node = curr_node->next;
    }
}

// Print the linked list
void print_linked_list(LinkedList* list) {
    Node* curr_node = list->head;
    while (curr_node!= NULL) {
        printf("%d ", curr_node->data);
        curr_node = curr_node->next;
    }
    printf("\n");
}

// Main function
int main() {
    LinkedList* list = create_linked_list();
    add_node(list, 5);
    add_node(list, 2);
    add_node(list, 8);
    add_node(list, 1);
    add_node(list, 3);
    add_node(list, 6);
    add_node(list, 4);
    add_node(list, 7);
    printf("Unsorted list:\n");
    print_linked_list(list);
    sort_linked_list(list);
    printf("Sorted list:\n");
    print_linked_list(list);
    return 0;
}