//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 100

// A node in the trie
typedef struct trie_node {
    char letter;
    struct trie_node *children[26];
    int is_word;
} trie_node;

// Create a new trie node
trie_node *new_trie_node(char letter) {
    trie_node *node = malloc(sizeof(trie_node));
    node->letter = letter;
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    node->is_word = 0;
    return node;
}

// Insert a word into the trie
void insert_word(trie_node *root, char *word) {
    trie_node *current = root;
    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = new_trie_node(word[i]);
        }
        current = current->children[index];
    }
    current->is_word = 1;
}

// Check if a word is in the trie
int is_word_in_trie(trie_node *root, char *word) {
    trie_node *current = root;
    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (current->children[index] == NULL) {
            return 0;
        }
        current = current->children[index];
    }
    return current->is_word;
}

// Free the trie
void free_trie(trie_node *root) {
    for (int i = 0; i < 26; i++) {
        if (root->children[i] != NULL) {
            free_trie(root->children[i]);
        }
    }
    free(root);
}

// Load the dictionary into the trie
trie_node *load_dictionary(char *filename) {
    trie_node *root = new_trie_node(' ');

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening dictionary file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LEN];
    while (fscanf(file, "%s", word) != EOF) {
        insert_word(root, word);
    }

    fclose(file);

    return root;
}

// Check the spelling of a word
int check_spelling(trie_node *root, char *word) {
    return is_word_in_trie(root, word);
}

// Main function
int main() {
    trie_node *root = load_dictionary("dictionary.txt");

    char word[MAX_WORD_LEN];
    while (1) {
        printf("Enter a word to check: ");
        scanf("%s", word);

        if (check_spelling(root, word)) {
            printf("%s is spelled correctly.\n", word);
        } else {
            printf("%s is spelled incorrectly.\n", word);
        }
    }

    free_trie(root);

    return 0;
}