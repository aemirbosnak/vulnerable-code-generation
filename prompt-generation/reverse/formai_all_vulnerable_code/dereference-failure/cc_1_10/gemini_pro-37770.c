//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { false, true } bool;

typedef struct _node {
    char *word;
    int count;
    struct _node *next;
} node;

node *head = NULL;

void insert_node(char *word) {
    node *new_node = malloc(sizeof(node));
    if (!new_node) {
        perror("couldn't allocate memory for new node");
        exit(EXIT_FAILURE);
    }
    new_node->word = strdup(word);
    if (!new_node->word) {
        perror("couldn't allocate memory for new node word");
        exit(EXIT_FAILURE);
    }
    new_node->count = 1;
    new_node->next = NULL;
    if (!head) {
        head = new_node;
    } else {
        node *current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void count_words(char *string) {
    char *word = strtok(string, " ");
    while (word) {
        if (!head) {
            insert_node(word);
        } else {
            node *current = head;
            bool found = false;
            while (current) {
                if (!strcmp(current->word, word)) {
                    current->count++;
                    found = true;
                    break;
                }
                current = current->next;
            }
            if (!found) {
                insert_node(word);
            }
        }
        word = strtok(NULL, " ");
    }
}

void print_word_counts() {
    node *current = head;
    while (current) {
        printf("%s: %d\n", current->word, current->count);
        current = current->next;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s string\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    count_words(argv[1]);
    print_word_counts();
    return EXIT_SUCCESS;
}