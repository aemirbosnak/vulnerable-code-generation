//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_DEPTH 10
#define MAX_NAMELEN 256

struct node {
    char name[MAX_NAMELEN];
    struct node *next;
};

struct node *root;

void insert(char *name) {
    struct node *new = malloc(sizeof(struct node));
    strcpy(new->name, name);
    new->next = root;
    root = new;
}

void traverse(void) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }
    char *name = root->name;
    printf("Visiting node %s\n", name);
    if (root->next != NULL) {
        traverse();
    }
}

void delete(char *name) {
    struct node *current = root;
    struct node *prev = NULL;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                root = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Node not found\n");
}

int main(void) {
    insert("A");
    insert("B");
    insert("C");
    insert("D");
    insert("E");
    traverse();
    delete("A");
    traverse();
    return 0;
}