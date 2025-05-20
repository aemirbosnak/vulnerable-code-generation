//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 50

typedef struct TrieNode {
    bool is_word;
    struct TrieNode *children[26];
} TrieNode;

TrieNode *create_trie_node() {
    TrieNode *node = malloc(sizeof(TrieNode));
    node->is_word = false;
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void insert_word(TrieNode *root, const char *word) {
    TrieNode *node = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (node->children[index] == NULL) {
            node->children[index] = create_trie_node();
        }
        node = node->children[index];
    }
    node->is_word = true;
}

bool search_word(TrieNode *root, const char *word) {
    TrieNode *node = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (node->children[index] == NULL) {
            return false;
        }
        node = node->children[index];
    }
    return node->is_word;
}

void free_trie(TrieNode *root) {
    for (int i = 0; i < 26; i++) {
        if (root->children[i] != NULL) {
            free_trie(root->children[i]);
        }
    }
    free(root);
}

void load_dictionary(TrieNode *root, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening dictionary file");
        exit(1);
    }

    char word[MAX_WORD_LEN + 1];
    while (fscanf(file, "%s", word) != EOF) {
        insert_word(root, word);
    }

    fclose(file);
}

bool check_spelling(TrieNode *root, const char *word) {
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j <= len; j++) {
            char subword[MAX_WORD_LEN + 1];
            strncpy(subword, word + i, j - i);
            subword[j - i] = '\0';
            if (search_word(root, subword)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    TrieNode *root = create_trie_node();
    load_dictionary(root, "dictionary.txt");

    char word[MAX_WORD_LEN + 1];
    printf("Enter a word to check spelling: ");
    scanf("%s", word);

    bool is_valid = check_spelling(root, word);
    if (is_valid) {
        printf("The word is spelled correctly.\n");
    } else {
        printf("The word is spelled incorrectly.\n");
    }

    free_trie(root);
    return 0;
}