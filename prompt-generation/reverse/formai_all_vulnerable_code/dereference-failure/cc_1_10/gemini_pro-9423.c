//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: shocked
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct trie_node {
    bool is_word;
    struct trie_node* children[26];
} trie_node;

trie_node* create_trie() {
    trie_node* root = malloc(sizeof(trie_node));
    if (root == NULL) {
        return NULL;
    }
    root->is_word = false;
    for (int i = 0; i < 26; i++) {
        root->children[i] = NULL;
    }
    return root;
}

void insert_word(trie_node* root, char* word) {
    trie_node* current = root;
    for (int i = 0; i < strlen(word); i++) {
        char letter = tolower(word[i]);
        int index = letter - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = create_trie();
        }
        current = current->children[index];
    }
    current->is_word = true;
}

bool search_word(trie_node* root, char* word) {
    trie_node* current = root;
    for (int i = 0; i < strlen(word); i++) {
        char letter = tolower(word[i]);
        int index = letter - 'a';
        if (current->children[index] == NULL) {
            return false;
        }
        current = current->children[index];
    }
    return current->is_word;
}

void free_trie(trie_node* root) {
    if (root == NULL) {
        return;
    }
    for (int i = 0; i < 26; i++) {
        free_trie(root->children[i]);
    }
    free(root);
}

int main() {
    trie_node* dictionary = create_trie();
    insert_word(dictionary, "hello");
    insert_word(dictionary, "world");
    insert_word(dictionary, "computer");
    insert_word(dictionary, "science");

    char input[100];
    printf("Enter a word: ");
    scanf("%s", input);

    if (search_word(dictionary, input)) {
        printf("The word is spelled correctly.\n");
    } else {
        printf("The word is spelled incorrectly.\n");
    }

    free_trie(dictionary);
    return 0;
}