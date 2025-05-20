//FormAI DATASET v1.0 Category: Data structures visualization ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

struct node {                           // defining node structure
    int data;
    struct node* next;
};

struct list {                           // defining list structure
    struct node* head;
};

void create_list(struct list* l) {      // function to create a new linked list
    l->head = NULL;
}

void print_list(struct list* l) {       // function to print list
    struct node* temp = l->head;
    while(temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insert_node(struct list* l, int data) {   // function to insert node at the end of list
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if(l->head == NULL) {                     // if list is empty
        l->head = new_node;
    } else {
        struct node* temp = l->head;
        while(temp->next) {                   // traverse till the end of list
            temp = temp->next;
        }
        temp->next = new_node;                 // insert node at the end
    }
}

int main() {
    struct list l1;
    create_list(&l1);                          // creating linked list

    insert_node(&l1, 1);                       // inserting nodes
    insert_node(&l1, 2);
    insert_node(&l1, 3);
    insert_node(&l1, 4);
    insert_node(&l1, 5);

    printf("Linked List Visualization:\n");
    printf("\n");
    printf("     +------+     +------+     +------+     +------+     +------+ \n");
    printf("     |  %d | --> |  %d | --> |  %d | --> |  %d | --> |  %d | \n", l1.head->data, l1.head->next->data, l1.head->next->next->data, l1.head->next->next->next->data, l1.head->next->next->next->next->data);
    printf("     +------+     +------+     +------+     +------+     +------+ \n");
    printf("       |                                                 | \n");
    printf("       V                                                 V \n");
    printf("     NULL                                              NULL \n"); 

    printf("\n");
    printf("Linked List Values:\n");
    print_list(&l1);                            // printing linked list values
    printf("\n");

    return 0;
}