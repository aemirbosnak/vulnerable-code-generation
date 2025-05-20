//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 50
#define MAX_WORDS 1000

// Declare a node for the trie
typedef struct trie_node {
    char* word;
    struct trie_node* children[26];
    int is_word;
} trie_node;

// Create a new trie node
trie_node* create_trie_node() {
    trie_node* node = (trie_node*)malloc(sizeof(trie_node));
    node->word = NULL;
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    node->is_word = 0;
    return node;
}

// Insert a word into the trie
void insert_word(trie_node* root, char* word) {
    trie_node* current = root;
    int index;
    for (int i = 0; i < strlen(word); i++) {
        index = word[i] - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = create_trie_node();
        }
        current = current->children[index];
    }
    current->word = word;
    current->is_word = 1;
}

// Search for a word in the trie
int search_word(trie_node* root, char* word) {
    trie_node* current = root;
    int index;
    for (int i = 0; i < strlen(word); i++) {
        index = word[i] - 'a';
        if (current->children[index] == NULL) {
            return 0;
        }
        current = current->children[index];
    }
    return current->is_word;
}

// Load the dictionary into the trie
void load_dictionary(trie_node* root, char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening dictionary file\n");
        return;
    }
    char word[MAX_WORD_LEN];
    while (fscanf(fp, "%s", word) != EOF) {
        insert_word(root, word);
    }
    fclose(fp);
}

// Spell check a text file
void spell_check(trie_node* root, char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening text file\n");
        return;
    }
    char word[MAX_WORD_LEN];
    while (fscanf(fp, "%s", word) != EOF) {
        if (!search_word(root, word)) {
            printf("%s is not in the dictionary\n", word);
        }
    }
    fclose(fp);
}

// Free the trie
void free_trie(trie_node* root) {
    for (int i = 0; i < 26; i++) {
        if (root->children[i] != NULL) {
            free_trie(root->children[i]);
        }
    }
    free(root);
}

int main() {
    trie_node* root = create_trie_node();
    load_dictionary(root, "dictionary.txt");
    spell_check(root, "text.txt");
    free_trie(root);
    return 0;
}