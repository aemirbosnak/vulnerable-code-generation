//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

typedef struct trie_node {
    int is_word;
    struct trie_node *children[26];
} trie_node;

trie_node *create_trie_node() {
    trie_node *node = malloc(sizeof(trie_node));
    node->is_word = 0;
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void insert_word_into_trie(trie_node *root, char *word) {
    if (*word == '\0') {
        root->is_word = 1;
        return;
    }

    int index = *word - 'a';
    if (root->children[index] == NULL) {
        root->children[index] = create_trie_node();
    }

    insert_word_into_trie(root->children[index], word + 1);
}

int search_word_in_trie(trie_node *root, char *word) {
    if (*word == '\0') {
        return root->is_word;
    }

    int index = *word - 'a';
    if (root->children[index] == NULL) {
        return 0;
    }

    return search_word_in_trie(root->children[index], word + 1);
}

int check_spelling_recursively(trie_node *root, char *word) {
    if (*word == '\0') {
        return root->is_word;
    }

    int index = *word - 'a';
    if (root->children[index] == NULL) {
        return 0;
    }

    return check_spelling_recursively(root->children[index], word + 1);
}

int main() {
    trie_node *root = create_trie_node();

    // Insert some words into the trie
    insert_word_into_trie(root, "hello");
    insert_word_into_trie(root, "world");
    insert_word_into_trie(root, "computer");
    insert_word_into_trie(root, "science");
    insert_word_into_trie(root, "technology");

    // Check the spelling of some words
    printf("hello: %d\n", search_word_in_trie(root, "hello"));
    printf("world: %d\n", search_word_in_trie(root, "world"));
    printf("computer: %d\n", search_word_in_trie(root, "computer"));
    printf("science: %d\n", search_word_in_trie(root, "science"));
    printf("technology: %d\n", search_word_in_trie(root, "technology"));

    // Check the spelling of some misspelled words
    printf("helo: %d\n", check_spelling_recursively(root, "helo"));
    printf("wrld: %d\n", check_spelling_recursively(root, "wrld"));
    printf("comptuer: %d\n", check_spelling_recursively(root, "comptuer"));
    printf("sciense: %d\n", check_spelling_recursively(root, "sciense"));
    printf("technolgy: %d\n", check_spelling_recursively(root, "technolgy"));

    return 0;
}