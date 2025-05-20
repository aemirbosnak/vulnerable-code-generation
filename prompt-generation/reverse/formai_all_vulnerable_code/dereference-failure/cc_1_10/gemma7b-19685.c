//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1024

typedef struct WordNode {
    char *word;
    struct WordNode *next;
} WordNode;

WordNode *word_list = NULL;

void add_word(char *word) {
    WordNode *new_node = malloc(sizeof(WordNode));
    new_node->word = strdup(word);
    new_node->next = NULL;

    if (word_list == NULL) {
        word_list = new_node;
    } else {
        word_list->next = new_node;
        word_list = new_node;
    }
}

void count_words() {
    WordNode *current = word_list;
    int word_count = 0;

    while (current) {
        word_count++;
        current = current->next;
    }

    printf("Total number of words: %d\n", word_count);
}

int main() {
    add_word("The");
    add_word("Quick");
    add_word("Brown");
    add_word("Fox");
    add_word("Jumping");
    add_word("Over");
    add_word("The");

    count_words();

    return 0;
}