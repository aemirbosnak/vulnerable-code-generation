//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *word;
    int count;
    struct node *next;
} node_t;

void insert_word(node_t **head, char *word) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->word = strdup(word);
    new_node->count = 1;
    new_node->next = *head;
    *head = new_node;
}

void increment_word_count(node_t **head, char *word) {
    node_t *current = *head;

    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            current->count++;
            return;
        }
        current = current->next;
    }

    insert_word(head, word);
}

void print_word_counts(node_t *head) {
    node_t *current = head;

    while (current != NULL) {
        printf("%s: %d\n", current->word, current->count);
        current = current->next;
    }
}

void free_word_counts(node_t *head) {
    node_t *current = head;

    while (current != NULL) {
        node_t *next = current->next;
        free(current->word);
        free(current);
        current = next;
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    node_t *head = NULL;

    char word[1024];
    while (fscanf(fp, "%s", word) != EOF) {
        increment_word_count(&head, word);
    }

    fclose(fp);

    print_word_counts(head);

    free_word_counts(head);

    return EXIT_SUCCESS;
}