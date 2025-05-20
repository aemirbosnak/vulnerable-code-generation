//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

typedef struct node {
    char word[MAX_WORD_LENGTH];
    struct node *next;
} node;

node *head = NULL;

void insert_word(char *word) {
    node *new_node = malloc(sizeof(node));
    strcpy(new_node->word, word);
    new_node->next = head;
    head = new_node;
}

int is_word_in_dictionary(char *word) {
    node *current = head;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void spell_check(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        if (!is_word_in_dictionary(word)) {
            printf("%s is not in the dictionary\n", word);
        }
    }

    fclose(file);
}

int main() {
    insert_word("hello");
    insert_word("world");
    spell_check("text.txt");
    return 0;
}