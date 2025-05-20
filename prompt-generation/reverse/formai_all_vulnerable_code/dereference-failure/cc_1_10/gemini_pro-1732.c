//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 20

typedef struct TrieNode {
    struct TrieNode *children[26];
    int is_word;
} TrieNode;

TrieNode *create_trie() {
    TrieNode *root = malloc(sizeof(TrieNode));
    for (int i = 0; i < 26; i++) {
        root->children[i] = NULL;
    }
    root->is_word = 0;
    return root;
}

void insert_word(TrieNode *root, char *word) {
    TrieNode *current = root;
    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = create_trie();
        }
        current = current->children[index];
    }
    current->is_word = 1;
}

int is_word_in_trie(TrieNode *root, char *word) {
    TrieNode *current = root;
    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (current->children[index] == NULL) {
            return 0;
        }
        current = current->children[index];
    }
    return current->is_word;
}

void free_trie(TrieNode *root) {
    for (int i = 0; i < 26; i++) {
        if (root->children[i] != NULL) {
            free_trie(root->children[i]);
        }
    }
    free(root);
}

int main() {
    TrieNode *dictionary = create_trie();

    // Load the dictionary into the trie
    FILE *f = fopen("dictionary.txt", "r");
    if (f == NULL) {
        perror("Error opening dictionary file");
        return EXIT_FAILURE;
    }
    char word[MAX_WORD_LEN];
    while (fscanf(f, "%s", word) != EOF) {
        insert_word(dictionary, word);
    }
    fclose(f);

    // Get the input text
    char text[MAX_WORDS * MAX_WORD_LEN];
    printf("Enter the text to check for spelling errors: ");
    fgets(text, sizeof(text), stdin);

    // Split the text into words
    char *words[MAX_WORDS];
    int num_words = 0;
    char *token = strtok(text, " ");
    while (token != NULL) {
        words[num_words++] = token;
        token = strtok(NULL, " ");
    }

    // Check each word in the text for spelling errors
    for (int i = 0; i < num_words; i++) {
        if (!is_word_in_trie(dictionary, words[i])) {
            printf("The word \"%s\" is not in the dictionary.\n", words[i]);
        }
    }

    // Free the trie
    free_trie(dictionary);

    return EXIT_SUCCESS;
}