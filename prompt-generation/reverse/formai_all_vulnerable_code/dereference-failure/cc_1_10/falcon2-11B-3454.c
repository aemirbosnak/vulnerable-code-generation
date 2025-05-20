//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    int value;
    struct node *next;
};

struct node *head = NULL;

void create_node(int key, int value) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->key = key;
    new_node->value = value;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        struct node *curr = head;
        while (curr->next!= NULL) {
            curr = curr->next;
        }
        curr->next = new_node;
    }
}

void insert_node(int key, int value) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->key = key;
    new_node->value = value;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        struct node *curr = head;
        while (curr->next!= NULL) {
            curr = curr->next;
        }
        curr->next = new_node;
    }
}

void print_list() {
    struct node *curr = head;
    while (curr!= NULL) {
        printf("%d %d\n", curr->key, curr->value);
        curr = curr->next;
    }
}

int main() {
    create_node(1, 100);
    create_node(2, 200);
    create_node(3, 300);
    print_list();
    insert_node(4, 400);
    print_list();
    return 0;
}