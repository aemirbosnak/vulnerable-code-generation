//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024
#define MAX_DEPTH 5

typedef struct node {
    char *word;
    struct node *next;
} node_t;

node_t *create_node(char *word) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->word = word;
    new_node->next = NULL;
    return new_node;
}

void insert_word(node_t **head_ref, char *word) {
    node_t *new_node = create_node(word);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        (*head_ref)->next = new_node;
    }
    (*head_ref)->next = new_node;
}

void print_list(node_t *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List: ");
    while (head != NULL) {
        printf("%s ", head->word);
        head = head->next;
    }
    printf("\n");
}

int main() {
    node_t *head = NULL;
    char line[MAX_LINE_LENGTH];
    int depth = 0;

    while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL) {
        char *word = strtok(line, " ");
        while (word != NULL && depth < MAX_DEPTH) {
            insert_word(&head, word);
            word = strtok(NULL, " ");
            depth++;
        }
    }

    print_list(head);

    return 0;
}