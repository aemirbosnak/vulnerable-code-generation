//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data; // element data
    struct node* next; // pointer to next element
};

typedef struct node* list; // list is a pointer to the first node

void print_list(list L) {
    // prints the elements of the list
    printf("[");
    while (L != NULL) {
        printf("%d", L->data);
        if (L->next != NULL) {
            printf(", ");
        }
        L = L->next;
    }
    printf("]\n");
}

void push_front(list* L, int data) {
    // adds an element to the front of the list
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *L;
    *L = new_node;
}

void push_back(list* L, int data) {
    // adds an element to the back of the list
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (*L == NULL) {
        *L = new_node;
    } else {
        struct node* last = *L;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = new_node;
    }
}

int main() {
    list L = NULL; // initialize an empty list
    printf("Initial list: ");
    print_list(L); // []

    push_front(&L, 1);
    printf("After push_front(1): ");
    print_list(L); // [1]

    push_front(&L, 2);
    printf("After push_front(2): ");
    print_list(L); // [2, 1]

    push_back(&L, 3);
    printf("After push_back(3): ");
    print_list(L); // [2, 1, 3]

    return 0;
}