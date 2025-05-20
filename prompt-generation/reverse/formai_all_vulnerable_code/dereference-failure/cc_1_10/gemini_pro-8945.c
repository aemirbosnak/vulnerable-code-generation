//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 32

typedef struct node {
    char word[MAX_WORD_LENGTH + 1];
    struct node *next;
} node_t;

node_t *head = NULL;

void insert(char *word) {
    node_t *new_node = malloc(sizeof(node_t));
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

int check_spelling(char *word) {
    if (search(word)) {
        return 1;
    } else {
        return 0;
    }
}

void load_dictionary(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening dictionary file");
        exit(1);
    }

    char word[MAX_WORD_LENGTH + 1];
    while (fscanf(fp, "%s", word) != EOF) {
        insert(word);
    }

    fclose(fp);
}

void spell_check(char *text) {
    char *start = text;
    char *end = text;

    while (*end != '\0') {
        if (isalpha(*end)) {
            end++;
        } else {
            *end = '\0';
            if (!check_spelling(start)) {
                printf("Misspelled word: %s\n", start);
            }
            start = end + 1;
            end++;
        }
    }

    if (!check_spelling(start)) {
        printf("Misspelled word: %s\n", start);
    }
}

int main() {
    load_dictionary("dictionary.txt");

    char text[] = "This is a text to spell check. I hope it works!";
    spell_check(text);

    return 0;
}