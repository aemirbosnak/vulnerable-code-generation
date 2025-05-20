//Falcon-180B DATASET v1.0 Category: Memory management ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    char *data;
    struct node *next;
} Node;

Node *head = NULL;

void insert(char *data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(0);
    }
    new_node->data = (char *)malloc(strlen(data) + 1);
    if (new_node->data == NULL) {
        printf("Memory allocation failed\n");
        exit(0);
    }
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

void delete(char *data) {
    Node *temp = head;
    Node *prev = NULL;
    while (temp!= NULL && strcmp(temp->data, data)!= 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element not found\n");
        return;
    }
    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp->data);
    free(temp);
}

void search(char *data) {
    Node *temp = head;
    while (temp!= NULL && strcmp(temp->data, data)!= 0) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element not found\n");
    } else {
        printf("Element found\n");
    }
}

void display() {
    Node *temp = head;
    while (temp!= NULL) {
        printf("%s ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insert("apple");
    insert("banana");
    insert("orange");
    display();
    search("banana");
    delete("banana");
    display();
    return 0;
}