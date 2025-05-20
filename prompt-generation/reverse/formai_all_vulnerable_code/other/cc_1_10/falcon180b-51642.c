//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define MAX_SIZE 1000000

// Node structure for linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Linked list structure
typedef struct list {
    Node* head;
    int size;
} List;

// Function prototypes
void init_list(List* list);
void add_node(List* list, int data);
void print_list(List* list);
void free_list(List* list);

int main() {
    List list;
    init_list(&list);

    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        add_node(&list, i);
    }

    printf("List created with %d nodes:\n", list.size);
    print_list(&list);

    free_list(&list);
    return 0;
}

void init_list(List* list) {
    list->head = NULL;
    list->size = 0;
}

void add_node(List* list, int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    assert(node!= NULL);

    node->data = data;
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
    } else {
        Node* temp = list->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }

    list->size++;
}

void print_list(List* list) {
    Node* node = list->head;
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void free_list(List* list) {
    Node* node = list->head;
    while (node!= NULL) {
        Node* temp = node;
        node = node->next;
        free(temp);
    }
}