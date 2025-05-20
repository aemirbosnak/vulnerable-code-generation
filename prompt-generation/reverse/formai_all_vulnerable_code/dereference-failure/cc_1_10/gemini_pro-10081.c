//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

typedef struct node {
    char word[MAX_WORD_LENGTH + 1];
    struct node *next;
} node_t;

node_t *head = NULL;

void insert(char *word) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    strcpy(new_node->word, word);
    new_node->next = head;
    head = new_node;
}

int search(char *word) {
    node_t *current = head;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int main() {
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening dictionary file.\n");
        return EXIT_FAILURE;
    }

    char word[MAX_WORD_LENGTH + 1];
    while (fscanf(fp, "%s", word) != EOF) {
        insert(word);
    }
    fclose(fp);

    char *input = "Hello, how are you?";
    char *token = strtok(input, " ");
    while (token != NULL) {
        if (!search(token)) {
            printf("%s is not a valid word.\n", token);
        }
        token = strtok(NULL, " ");
    }

    return EXIT_SUCCESS;
}