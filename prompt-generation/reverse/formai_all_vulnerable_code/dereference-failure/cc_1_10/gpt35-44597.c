//FormAI DATASET v1.0 Category: Data structures visualization ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct {
    struct node *head;
    int size;
} linked_list;

linked_list * create_list() {

    linked_list *list = (linked_list *) malloc(sizeof(linked_list));
    list -> head = NULL;
    list -> size = 0;

    return list;
}

void add_to_list(linked_list *list, int data) {

    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node -> data = data;
    new_node -> next = NULL;

    if(list -> head == NULL) {
        list -> head = new_node;
    } else {
        struct node *temp = list -> head;

        while(temp -> next != NULL) {
            temp = temp -> next;
        }

        temp -> next = new_node;
    }

    list -> size++;
}

void print_list(linked_list *list) {

    struct node *temp = list -> head;

    while(temp != NULL) {
        printf("%d\n", temp -> data);
        temp = temp -> next;
    }
}

int main() {
    linked_list *list = create_list();

    add_to_list(list, 5);
    add_to_list(list, 10);
    add_to_list(list, 15);
    add_to_list(list, 20);
    add_to_list(list, 25);

    print_list(list);

    return 0;
}