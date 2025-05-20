//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TRIE_NODE_SIZE 26

typedef struct TrieNode {
    struct TrieNode *children[TRIE_NODE_SIZE];
    int is_end_of_word;
} TrieNode;

TrieNode* create_trie_node() {
    TrieNode *node = (TrieNode*)calloc(1, sizeof(TrieNode));
    node->is_end_of_word = 0;
    int i;
    for (i = 0; i < TRIE_NODE_SIZE; ++i) {
        node->children[i] = NULL;
    }
    return node;
}

void insert_word(TrieNode *root, const char *word) {
    int length = strlen(word);
    TrieNode *current = root;
    for (int i = 0; i < length; ++i) {
        int index = tolower((unsigned char)word[i]) - 'a';
        if (!current->children[index]) {
            current->children[index] = create_trie_node();
        }
        current = current->children[index];
    }
    current->is_end_of_word = 1;
}

int search_word(TrieNode *root, const char *word, int length) {
    TrieNode *current = root;
    for (int i = 0; i < length; ++i) {
        int index = tolower((unsigned char)word[i]) - 'a';
        if (!current->children[index]) {
            return 0;
        }
        current = current->children[index];
    }
    return current->is_end_of_word;
}

void free_trie(TrieNode *node) {
    for (int i = 0; i < TRIE_NODE_SIZE; ++i) {
        if (node->children[i]) {
            free_trie(node->children[i]);
        }
    }
    free(node);
}

int main() {
    FILE *dictionary = fopen("dictionary.txt", "r");
    if (!dictionary) {
        perror("Error opening dictionary file");
        return 1;
    }

    TrieNode *root = create_trie_node();
    char word[50];

    while (fscanf(dictionary, "%s", word) != EOF) {
        insert_word(root, word);
    }

    fclose(dictionary);

    printf("Enter a word to check: ");
    scanf("%s", word);

    int result = search_word(root, word, strlen(word));

    if (result) {
        printf("The word '%s' is in the dictionary.\n", word);
    } else {
        printf("The word '%s' is not in the dictionary.\n", word);
    }

    free_trie(root);

    return 0;
}