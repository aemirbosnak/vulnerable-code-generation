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

void add_word(char *word) {
    WordNode *new_node = malloc(sizeof(WordNode));
    new_node->word = strdup(word);
    new_node->next = NULL;

    if (word_list == NULL) {
        word_list = new_node;
    } else {
        WordNode *current = word_list;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
    }
}

int main() {
    char text[] = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";

    add_word("The");
    add_word("quick");
    add_word("brown");
    add_word("fox");
    add_word("jumps");
    add_word("over");
    add_word("lazy");
    add_word("dog");

    WordNode *current = word_list;
    while (current) {
        printf("%s ", current->word);
    }

    printf("\n");

    return 0;
}