//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024
#define MAX_DEPTH 5

typedef struct node {
    char *line;
    size_t len;
    struct node *prev, *next;
} node_t;

node_t *create_node(char *line, size_t len) {
    node_t *node = (node_t *) malloc(sizeof(node_t));
    node->line = line;
    node->len = len;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

void free_node(node_t *node) {
    free(node);
}

void print_node(node_t *node) {
    printf("%s\n", node->line);
}

node_t *read_lines(FILE *file) {
    char line[MAX_LINE_LENGTH];
    size_t len;
    node_t *head = NULL, *curr = NULL;

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        curr = create_node(line, len);
        if (head == NULL) {
            head = curr;
        } else {
            curr->prev = head;
            head->next = curr;
            head = curr;
        }
    }

    return head;
}

void process_lines(node_t *head) {
    node_t *curr = head;
    while (curr != NULL) {
        print_node(curr);
        curr = curr->next;
    }
}

int main() {
    FILE *file = fopen("example.txt", "r");
    node_t *head = read_lines(file);
    process_lines(head);
    fclose(file);
    return 0;
}