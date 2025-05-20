//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data[50];
    struct node *next;
} Node;

Node *head = NULL;

void add_node(char *data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->data, data);
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        Node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void delete_node(char *data) {
    Node *temp = head;

    if (head!= NULL && strcmp(head->data, data) == 0) {
        head = head->next;
        free(temp);
        return;
    }

    while (temp!= NULL && strcmp(temp->data, data)!= 0) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node not found.\n");
        return;
    }

    Node *prev = temp->next;
    free(temp);
    prev->next = temp->next;
}

void search_node(char *data) {
    Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp!= NULL) {
        if (strcmp(temp->data, data) == 0) {
            printf("Node found.\n");
            return;
        }
        temp = temp->next;
    }

    printf("Node not found.\n");
}

void print_list() {
    Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("List:\n");
    while (temp!= NULL) {
        printf("%s\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    add_node("John");
    add_node("Jane");
    add_node("Bob");

    print_list();

    delete_node("Bob");

    print_list();

    search_node("John");
    search_node("Dave");

    return 0;
}