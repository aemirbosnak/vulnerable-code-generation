//FormAI DATASET v1.0 Category: Linked list operations ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int data) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;
    if (head == NULL) {
        head = new_node;
        head->next = NULL;
    } else {
        struct node *temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = NULL;
    }
}

void print(struct node *current) {
    if (current == NULL) {
        printf("\n");
        return;
    }
    printf("%d -> ", current->data);
    print(current->next);
}

void delete(int key) {
    if (head == NULL) {
        return;
    }
    if (head->data == key) {
        head = head->next;
    } else {
        struct node *temp = head;
        while(temp->next != NULL) {
            if (temp->next->data == key) {
                temp->next = temp->next->next;
                return;
            }
            temp = temp->next;
        }
    }
}

int main() {
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    print(head);
    delete(3);
    print(head);
    return 0;
}