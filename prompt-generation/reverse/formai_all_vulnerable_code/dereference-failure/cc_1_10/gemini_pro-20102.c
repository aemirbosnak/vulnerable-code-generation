//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: genius
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 30

typedef struct trie_node {
    struct trie_node *children[26];
    bool is_word;
} trie_node;

trie_node *new_trie_node() {
    trie_node *node = malloc(sizeof(trie_node));
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    node->is_word = false;
    return node;
}

void insert_word(trie_node *root, char *word) {
    trie_node *current = root;
    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = new_trie_node();
        }
        current = current->children[index];
    }
    current->is_word = true;
}

bool search_word(trie_node *root, char *word) {
    trie_node *current = root;
    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (current->children[index] == NULL) {
            return false;
        }
        current = current->children[index];
    }
    return current->is_word;
}

void free_trie(trie_node *root) {
    for (int i = 0; i < 26; i++) {
        if (root->children[i] != NULL) {
            free_trie(root->children[i]);
        }
    }
    free(root);
}

int main() {
    // Read the dictionary into a trie
    trie_node *root = new_trie_node();
    FILE *dictionary = fopen("dictionary.txt", "r");
    char word[MAX_WORD_LENGTH];
    while (fscanf(dictionary, "%s", word) != EOF) {
        insert_word(root, word);
    }
    fclose(dictionary);

    // Read the input text
    FILE *input = fopen("input.txt", "r");
    char text[10000];
    fread(text, sizeof(char), 10000, input);
    fclose(input);

    // Split the input text into words
    char *words[MAX_WORDS];
    int num_words = 0;
    char *token = strtok(text, " ");
    while (token != NULL) {
        words[num_words++] = token;
        token = strtok(NULL, " ");
    }

    // Check each word in the input text for spelling errors
    for (int i = 0; i < num_words; i++) {
        if (!search_word(root, words[i])) {
            printf("%s is not a word\n", words[i]);
        }
    }

    // Free the trie
    free_trie(root);

    return 0;
}