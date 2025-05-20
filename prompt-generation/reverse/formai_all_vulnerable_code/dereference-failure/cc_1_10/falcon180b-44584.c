//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct node {
    char data[MAX_SIZE];
    int size;
    struct node *next;
};

struct node *head = NULL;

void insert_node(char *data, int size) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    strcpy(new_node->data, data);
    new_node->size = size;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        return;
    }

    struct node *temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void search_node(char *data, int size) {
    struct node *temp = head;
    while (temp!= NULL) {
        if (temp->size == size && strcmp(temp->data, data) == 0) {
            printf("Data found!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Data not found.\n");
}

int main() {
    // Insert nodes
    insert_node("Linus Torvalds", 16);
    insert_node("Linux", 5);
    insert_node("Git", 4);

    // Search nodes
    search_node("Linus Torvalds", 16);
    search_node("Linux", 5);
    search_node("Git", 4);
    search_node("Github", 7);

    return 0;
}