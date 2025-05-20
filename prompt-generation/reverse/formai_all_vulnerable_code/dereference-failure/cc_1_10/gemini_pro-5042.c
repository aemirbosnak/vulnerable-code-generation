//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *word;
    int count;
    struct node *next;
} node_t;

node_t *head = NULL;

void add_word(char *word) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->word = malloc(strlen(word) + 1);
    strcpy(new_node->word, word);
    new_node->count = 1;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        node_t *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void count_words(char *text) {
    char *token = strtok(text, " ");
    while (token != NULL) {
        add_word(token);
        token = strtok(NULL, " ");
    }
}

void print_word_counts() {
    node_t *current = head;
    while (current != NULL) {
        printf("%s: %d\n", current->word, current->count);
        current = current->next;
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <text file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    char *text = malloc(size + 1);
    fread(text, size, 1, fp);
    fclose(fp);

    count_words(text);
    print_word_counts();

    return 0;
}