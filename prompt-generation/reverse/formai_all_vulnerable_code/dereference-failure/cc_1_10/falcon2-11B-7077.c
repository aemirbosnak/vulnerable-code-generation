//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100
#define MAX_NAME_LEN 20

typedef struct node {
    char name[MAX_NAME_LEN];
    int value;
    struct node *next;
} node;

node *head = NULL;

void insert(char *name, int value) {
    node *new_node = (node *)malloc(sizeof(node));
    strcpy(new_node->name, name);
    new_node->value = value;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        return;
    }

    node *current = head;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void display(void) {
    node *current = head;
    while (current!= NULL) {
        printf("%s -> %d\n", current->name, current->value);
        current = current->next;
    }
}

int main(void) {
    char name[MAX_NAME_LEN];
    int value;
    printf("Enter the name: ");
    fgets(name, MAX_NAME_LEN, stdin);
    sscanf(name, "%s %d", name, &value);
    insert(name, value);
    display();
    return 0;
}