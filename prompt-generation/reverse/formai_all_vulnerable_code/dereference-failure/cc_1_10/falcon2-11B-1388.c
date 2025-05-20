//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

void insert_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        struct node* current = head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void delete_node(int data) {
    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    struct node* current = head;
    struct node* prev = NULL;
    struct node* next;

    while (current!= NULL) {
        if (current->data == data) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Node with data %d not found\n", data);
}

void display_linked_list() {
    struct node* current = head;
    while (current!= NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    insert_node(5);
    insert_node(10);
    insert_node(15);

    display_linked_list();

    delete_node(5);

    display_linked_list();

    return 0;
}