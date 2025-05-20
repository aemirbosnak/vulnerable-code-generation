//Falcon2-11B DATASET v1.0 Category: Memory management ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct node {
    char data[MAX_SIZE];
    struct node *next;
} node;

node *head = NULL;

node* create_node(char data[]) {
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    strcpy(new_node->data, data);
    new_node->next = NULL;
    return new_node;
}

void insert_node(char data[], node *head) {
    node *new_node = create_node(data);
    if (new_node == NULL) {
        return;
    }
    if (head == NULL) {
        head = new_node;
        return;
    }
    new_node->next = head;
    head = new_node;
}

void display_list(node *head) {
    node *temp = head;
    while (temp!= NULL) {
        printf("%s ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    node *head = NULL;

    insert_node("Hello, ", head);
    insert_node("world!", head);
    insert_node("Welcome to", head);
    insert_node("the cyberpunk world!", head);
    insert_node("where the memory is managed", head);

    display_list(head);

    return 0;
}