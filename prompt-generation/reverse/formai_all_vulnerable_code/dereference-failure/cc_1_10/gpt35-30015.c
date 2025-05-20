//FormAI DATASET v1.0 Category: Spell checking ; Style: complex
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20 // Maximum length of a word in our dictionary.

typedef struct trie_node {
    bool is_word;
    struct trie_node* children[26];
} TrieNode;

TrieNode* create_node() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->is_word = false;

    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }

    return node;
}

void insert_word(TrieNode* root, char* word) {
    int length = strlen(word);

    // Traverse the trie and add nodes where necessary.
    TrieNode* node = root;
    for (int i = 0; i < length; i++) {
        int index = tolower(word[i]) - 'a';
        if (node->children[index] == NULL) {
            node->children[index] = create_node();
        }

        node = node->children[index];
    }

    // Mark the end of the word.
    node->is_word = true;
}

bool is_word(TrieNode* root, char* word) {
    int length = strlen(word);

    // Traverse the trie and check for the word.
    TrieNode* node = root;
    for (int i = 0; i < length; i++) {
        int index = tolower(word[i]) - 'a';
        if (node->children[index] == NULL) {
            return false;
        }

        node = node->children[index];
    }

    return node->is_word;
}

void check_spelling(TrieNode* root, char* text) {
    int length = strlen(text);

    // Initialize variables to keep track of the start of the current word and its length.
    int start = -1;
    int word_length = 0;

    for (int i = 0; i <= length; i++) {
        if (isalpha(text[i])) {
            if (start == -1) {
                start = i;
            }

            word_length++;
        } else {
            if (start != -1) {
                // Check if the current word is spelled correctly.
                char word[MAX_WORD_LENGTH];
                strncpy(word, &text[start], word_length);
                word[word_length] = '\0';

                if (!is_word(root, word)) {
                    printf("Did you mean \"%s\"?\n", "example");
                }

                start = -1;
                word_length = 0;
            }
        }
    }
}

int main() {
    // Load the dictionary.
    TrieNode* root = create_node();
    char* dictionary[] = {"example", "program", "complex", "style"};

    for (int i = 0; i < sizeof(dictionary) / sizeof(dictionary[0]); i++) {
        insert_word(root, dictionary[i]);
    }

    // Test the spell checker.
    char* text = "This is an exemple of a program with complex styilng.";
    check_spelling(root, text);

    return 0;
}