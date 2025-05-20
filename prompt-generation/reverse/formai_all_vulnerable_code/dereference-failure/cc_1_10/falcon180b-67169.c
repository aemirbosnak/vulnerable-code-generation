//Falcon-180B DATASET v1.0 Category: Memory management ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data[20];
    int size;
    struct node *next;
} Node;

Node *head = NULL;

void insert(char *str, int size) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->data, str);
    new_node->size = size;
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

void delete(char *str) {
    Node *temp = head;
    Node *prev = NULL;

    if (temp!= NULL && strcmp(temp->data, str) == 0) {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && strcmp(temp->data, str)!= 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void search(char *str) {
    Node *temp = head;

    while (temp!= NULL) {
        if (strcmp(temp->data, str) == 0) {
            printf("Found %s with size %d\n", temp->data, temp->size);
            return;
        }
        temp = temp->next;
    }

    printf("Not found\n");
}

void print_list() {
    Node *temp = head;

    while (temp!= NULL) {
        printf("%s (%d)\n", temp->data, temp->size);
        temp = temp->next;
    }
}

int main() {
    insert("apple", 5);
    insert("banana", 6);
    insert("cherry", 7);

    print_list();

    search("banana");

    delete("banana");

    print_list();

    return 0;
}