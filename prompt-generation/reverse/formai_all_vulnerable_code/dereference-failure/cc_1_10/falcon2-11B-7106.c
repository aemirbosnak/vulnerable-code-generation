//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 1000
#define MAX_COLUMNS 10

struct node {
    char *name;
    int value;
    struct node *next;
};

struct node *head = NULL;

void add_node(char *name, int value) {
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    strcpy(new_node->name, name);
    new_node->value = value;
    new_node->next = head;
    head = new_node;
}

void delete_node(char *name) {
    struct node *current = head;
    while (current!= NULL && strcmp(current->name, name)!= 0) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Node not found\n");
        return;
    }
    if (current == head) {
        head = current->next;
        free(current);
        return;
    }
    struct node *prev = head;
    while (prev->next!= current) {
        prev = prev->next;
    }
    prev->next = current->next;
    free(current);
}

void search_node(char *name) {
    struct node *current = head;
    while (current!= NULL && strcmp(current->name, name)!= 0) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Node not found\n");
        return;
    }
    printf("Node found: %s, value: %d\n", current->name, current->value);
}

int main() {
    char name[100];
    int value;
    printf("Enter a name: ");
    scanf("%s", name);
    printf("Enter a value: ");
    scanf("%d", &value);
    add_node(name, value);
    printf("Node added: %s, value: %d\n", name, value);

    printf("Enter a name to delete: ");
    scanf("%s", name);
    delete_node(name);
    printf("Node deleted: %s\n", name);

    printf("Enter a name to search: ");
    scanf("%s", name);
    search_node(name);

    return 0;
}