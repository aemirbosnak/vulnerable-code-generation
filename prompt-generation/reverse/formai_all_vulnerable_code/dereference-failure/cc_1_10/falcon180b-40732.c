//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    char data[MAX_SIZE];
    struct node *next;
} Node;

Node *create_node(char *data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory error\n");
        exit(1);
    }
    strcpy(new_node->data, data);
    new_node->next = NULL;
    return new_node;
}

void add_node(Node **head, char *data) {
    Node *new_node = create_node(data);
    Node *temp = *head;
    if (*head == NULL) {
        new_node->next = NULL;
        *head = new_node;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void search_node(Node *head, char *data) {
    Node *temp = head;
    while (temp!= NULL) {
        if (strcmp(temp->data, data) == 0) {
            printf("Data found\n");
            return;
        }
        temp = temp->next;
    }
    printf("Data not found\n");
}

int main() {
    Node *head = NULL;
    char data[MAX_SIZE];

    printf("Enter data to add (enter 'done' to stop):\n");
    fgets(data, MAX_SIZE, stdin);

    while (strncmp(data, "done", 4)!= 0) {
        add_node(&head, data);
        printf("Enter data to add (enter 'done' to stop):\n");
        fgets(data, MAX_SIZE, stdin);
    }

    printf("Enter data to search:\n");
    fgets(data, MAX_SIZE, stdin);
    search_node(head, data);

    return 0;
}