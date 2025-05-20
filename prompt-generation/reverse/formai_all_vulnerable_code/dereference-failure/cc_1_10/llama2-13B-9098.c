//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024
#define MAX_DEPTH 5

typedef struct node {
    char *line;
    struct node *prev;
    struct node *next;
} node_t;

node_t *create_node(char *line) {
    node_t *node = malloc(sizeof(node_t));
    node->line = line;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

void print_node(node_t *node) {
    printf("%s\n", node->line);
    if (node->prev != NULL) {
        print_node(node->prev);
    }
}

void process_line(node_t *head, char *line) {
    node_t *new_node = create_node(line);
    if (head == NULL) {
        head = new_node;
    } else {
        head->next = new_node;
        new_node->prev = head;
    }
    head = new_node;
}

void introspect(node_t *head) {
    if (head == NULL) {
        printf("No lines to introspect.\n");
        return;
    }
    printf("Introspecting...\n");
    node_t *current = head;
    int depth = 0;
    while (current != NULL) {
        if (depth == MAX_DEPTH) {
            break;
        }
        printf("  %s\n", current->line);
        if (current->prev != NULL) {
            printf("  Previous: %s\n", current->prev->line);
        }
        if (current->next != NULL) {
            printf("  Next: %s\n", current->next->line);
        }
        depth++;
        current = current->next;
    }
    printf("\n");
}

int main() {
    node_t *head = NULL;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL) {
        process_line(head, line);
    }
    introspect(head);
    return 0;
}