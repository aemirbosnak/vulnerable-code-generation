//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20
#define MAX_WORDS 10000

struct TrieNode {
    struct TrieNode *children[26];
    int is_word;
};

struct TrieNode *create_trie_node() {
    struct TrieNode *node = malloc(sizeof(struct TrieNode));
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    node->is_word = 0;
    return node;
}

void insert_word_into_trie(struct TrieNode *root, const char *word) {
    struct TrieNode *current_node = root;
    for (int i = 0; i < strlen(word); i++) {
        int index = tolower(word[i]) - 'a';
        if (current_node->children[index] == NULL) {
            current_node->children[index] = create_trie_node();
        }
        current_node = current_node->children[index];
    }
    current_node->is_word = 1;
}

int search_word_in_trie(struct TrieNode *root, const char *word) {
    struct TrieNode *current_node = root;
    for (int i = 0; i < strlen(word); i++) {
        int index = tolower(word[i]) - 'a';
        if (current_node->children[index] == NULL) {
            return 0;
        }
        current_node = current_node->children[index];
    }
    return current_node->is_word;
}

int main() {
    struct TrieNode *root = create_trie_node();

    // Insert words into the trie
    FILE *dictionary_file = fopen("dictionary.txt", "r");
    char word[MAX_WORD_LENGTH];
    while (fscanf(dictionary_file, "%s", word) != EOF) {
        insert_word_into_trie(root, word);
    }
    fclose(dictionary_file);

    // Spell check a sentence
    char sentence[100];
    printf("Enter a sentence: ");
    gets(sentence);

    char *token = strtok(sentence, " ");
    while (token != NULL) {
        if (!search_word_in_trie(root, token)) {
            printf("%s is misspelled.\n", token);
        }
        token = strtok(NULL, " ");
    }

    return 0;
}