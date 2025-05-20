//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    char data;
    struct node* next;
} Node;

typedef struct linked_list {
    Node* head;
    Node* tail;
    int size;
} LinkedList;

LinkedList* create_linked_list() {
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void add_node(LinkedList* list, char data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
    list->size++;
}

void print_linked_list(LinkedList* list) {
    Node* current_node = list->head;
    printf("Linked List: ");
    while (current_node!= NULL) {
        printf("%c ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

void delete_node(LinkedList* list, char data) {
    Node* current_node = list->head;
    Node* previous_node = NULL;
    while (current_node!= NULL && current_node->data!= data) {
        previous_node = current_node;
        current_node = current_node->next;
    }
    if (current_node == NULL) {
        printf("Node not found.\n");
    } else if (previous_node == NULL) {
        list->head = current_node->next;
        if (list->head == NULL) {
            list->tail = NULL;
        }
        free(current_node);
    } else {
        previous_node->next = current_node->next;
        if (current_node->next == NULL) {
            list->tail = previous_node;
        }
        free(current_node);
    }
    list->size--;
}

int main() {
    LinkedList* linked_list = create_linked_list();
    add_node(linked_list, 'A');
    add_node(linked_list, 'B');
    add_node(linked_list, 'C');
    add_node(linked_list, 'D');
    print_linked_list(linked_list); // A B C D
    delete_node(linked_list, 'C');
    print_linked_list(linked_list); // A B D
    return 0;
}