//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define WORD_SIZE 32
#define MAX_WORDS 1000

typedef struct word_node {
    char word[WORD_SIZE];
    int count;
    struct word_node *next;
} word_node;

word_node *head = NULL;

void add_word(char *word) {
    word_node *new_node = malloc(sizeof(word_node));
    strcpy(new_node->word, word);
    new_node->count = 1;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        return;
    }

    word_node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
}

void parse_string(char *string) {
    char *token = strtok(string, " ");
    while (token != NULL) {
        // Convert token to lowercase
        for (int i = 0; i < strlen(token); i++) {
            token[i] = tolower(token[i]);
        }

        add_word(token);

        token = strtok(NULL, " ");
    }
}

void print_word_list() {
    word_node *current = head;
    while (current != NULL) {
        printf("%s: %d\n", current->word, current->count);
        current = current->next;
    }
}

int main() {
    char *string = "Once upon a time, there was a little girl named Alice who lived in a world of her own imagination.";

    parse_string(string);

    print_word_list();

    return 0;
}