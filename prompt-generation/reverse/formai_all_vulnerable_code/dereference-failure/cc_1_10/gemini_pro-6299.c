//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50
#define MAX_DICT_WORDS 10000

// A node in the trie
typedef struct trie_node {
    int is_word;
    struct trie_node *children[26];
} trie_node;

// Create a new trie node
trie_node *create_trie_node() {
    trie_node *node = malloc(sizeof(trie_node));
    node->is_word = 0;
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    return node;
}

// Insert a word into the trie
void insert_word(trie_node *root, char *word) {
    trie_node *curr = root;
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        int idx = tolower(word[i]) - 'a';
        if (curr->children[idx] == NULL) {
            curr->children[idx] = create_trie_node();
        }
        curr = curr->children[idx];
    }
    curr->is_word = 1;
}

// Check if a word is in the trie
int is_word(trie_node *root, char *word) {
    trie_node *curr = root;
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        int idx = tolower(word[i]) - 'a';
        if (curr->children[idx] == NULL) {
            return 0;
        }
        curr = curr->children[idx];
    }
    return curr->is_word;
}

// Load the dictionary into the trie
trie_node *load_dictionary(char *filename) {
    trie_node *root = create_trie_node();

    FILE *dict = fopen(filename, "r");
    if (dict == NULL) {
        perror("Error opening dictionary file");
        return NULL;
    }

    char word[MAX_WORD_LEN];
    while (fscanf(dict, "%s", word) != EOF) {
        insert_word(root, word);
    }

    fclose(dict);
    return root;
}

// Check the spelling of a word
int check_spelling(trie_node *root, char *word) {
    return is_word(root, word);
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

int main() {
    // Load the dictionary into the trie
    trie_node *root = load_dictionary("dictionary.txt");

    // Get the word to check from the user
    char word[MAX_WORD_LEN];
    printf("Enter a word to check: ");
    scanf("%s", word);

    // Check the spelling of the word
    int is_correct = check_spelling(root, word);

    // Print the result
    if (is_correct) {
        printf("%s is spelled correctly.\n", word);
    } else {
        printf("%s is spelled incorrectly.\n", word);
    }

    // Free the trie
    free_trie(root);

    return 0;
}