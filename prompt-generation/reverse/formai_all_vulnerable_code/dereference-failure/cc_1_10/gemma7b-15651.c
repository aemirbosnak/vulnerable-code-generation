//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1024

typedef struct WordNode {
    char *word;
    struct WordNode *next;
} WordNode;

WordNode *word_list = NULL;

void insert_word(char *word) {
    WordNode *new_node = malloc(sizeof(WordNode));
    new_node->word = strdup(word);
    new_node->next = NULL;

    if (word_list == NULL) {
        word_list = new_node;
    } else {
        WordNode *last_node = word_list;
        while (last_node->next) {
            last_node = last_node->next;
        }
        last_node->next = new_node;
    }
}

void count_words() {
    int word_count = 0;
    WordNode *current_node = word_list;

    while (current_node) {
        word_count++;
        current_node = current_node->next;
    }

    printf("Total number of words: %d\n", word_count);
}

int main() {
    insert_word("Ken");
    insert_word("Thompson");
    insert_word("C");
    insert_word("Word");
    insert_word("Frequency");
    insert_word("Counter");

    count_words();

    return 0;
}