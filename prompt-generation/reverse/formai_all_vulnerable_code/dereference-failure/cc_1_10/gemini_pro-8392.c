//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: random
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

typedef struct node {
    char *word;
    int count;
    struct node *next;
} node_t;

node_t *head = NULL;
node_t *tail = NULL;

void add_word(const char *word) {
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        fprintf(stderr, "Error allocating memory for new node: %s\n", strerror(errno));
        exit(1);
    }

    new_node->word = strdup(word);
    if (new_node->word == NULL) {
        fprintf(stderr, "Error duplicating word: %s\n", strerror(errno));
        exit(1);
    }

    new_node->count = 1;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}

void print_words() {
    node_t *current_node = head;

    while (current_node != NULL) {
        printf("%s: %d\n", current_node->word, current_node->count);
        current_node = current_node->next;
    }
}

void free_words() {
    node_t *current_node = head;
    node_t *next_node;

    while (current_node != NULL) {
        next_node = current_node->next;
        free(current_node->word);
        free(current_node);
        current_node = next_node;
    }

    head = NULL;
    tail = NULL;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <text file>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word) != EOF) {
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        add_word(word);
    }

    fclose(fp);

    print_words();

    free_words();

    return 0;
}