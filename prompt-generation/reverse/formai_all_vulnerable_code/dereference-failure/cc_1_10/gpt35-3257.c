//FormAI DATASET v1.0 Category: Data structures visualization ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

typedef struct node {  // Define a node struct that will be used in the data structure
    int data;
    struct node* next;
} Node;

typedef struct linked_list {  // Define a linked list struct that will use the nodes
    int size;  // Keep track of the size of the linked list
    Node* head;  // Head of the linked list
} LinkedList;

void add_element(LinkedList* list, int data) {  // Add a new element to the linked list
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
}

void remove_element(LinkedList* list, int data) {  // Remove an element from the linked list
    Node* current_node = list->head;
    Node* previous_node = NULL;
    while (current_node != NULL) {
        if (current_node->data == data) {
            if (previous_node == NULL) {
                list->head = current_node->next;
            } else {
                previous_node->next = current_node->next;
            }
            free(current_node);
            list->size--;
            return;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }
}

void print(LinkedList* list) {  // Print out the linked list
    Node* current_node = list->head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

int main() {
    LinkedList list;
    list.size = 0;
    list.head = NULL;

    add_element(&list, 1);
    add_element(&list, 2);
    add_element(&list, 3);
    add_element(&list, 4);
    add_element(&list, 5);

    printf("Linked List: ");
    print(&list);

    remove_element(&list, 3);

    printf("Linked List after removing element 3: ");
    print(&list);

    return 0;
}