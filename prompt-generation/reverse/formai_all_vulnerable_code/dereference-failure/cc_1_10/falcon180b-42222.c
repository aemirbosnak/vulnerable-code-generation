//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct node {
    char data[MAX_SIZE];
    int size;
    struct node *next;
};

typedef struct node Node;

Node *create_node(char *data, int size) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->data, data);
    new_node->size = size;
    new_node->next = NULL;
    return new_node;
}

void add_node(Node **head, char *data, int size) {
    Node *new_node = create_node(data, size);
    if (*head == NULL) {
        *head = new_node;
    } else {
        Node *temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void print_list(Node *head) {
    while (head!= NULL) {
        printf("%s\n", head->data);
        head = head->next;
    }
}

int main() {
    Node *head = NULL;
    char input[MAX_SIZE];
    while (1) {
        printf("Enter a string to add to the list: ");
        scanf("%s", input);
        add_node(&head, input, strlen(input));
    }
    return 0;
}