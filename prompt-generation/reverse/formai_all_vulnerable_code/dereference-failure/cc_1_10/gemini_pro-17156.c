//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000

// Create a node for the trie
typedef struct trie_node {
    char *word;
    struct trie_node *children[26];
} trie_node;

// Create a new trie node
trie_node *new_trie_node() {
    trie_node *node = malloc(sizeof(trie_node));
    node->word = NULL;
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    return node;
}

// Insert a word into the trie
void insert_word(trie_node *root, char *word) {
    int len = strlen(word);
    trie_node *curr = root;
    for (int i = 0; i < len; i++) {
        int index = word[i] - 'a';
        if (curr->children[index] == NULL) {
            curr->children[index] = new_trie_node();
        }
        curr = curr->children[index];
    }
    curr->word = word;
}

// Check if a word is in the trie
int is_word_in_trie(trie_node *root, char *word) {
    int len = strlen(word);
    trie_node *curr = root;
    for (int i = 0; i < len; i++) {
        int index = word[i] - 'a';
        if (curr->children[index] == NULL) {
            return 0;
        }
        curr = curr->children[index];
    }
    return curr->word != NULL;
}

// Load words from a file into the trie
void load_words(trie_node *root, char *filename) {
    FILE *fp = fopen(filename, "r");
    char word[100];
    while (fscanf(fp, "%s", word) != EOF) {
        insert_word(root, word);
    }
    fclose(fp);
}

// Check the spelling of a word
int check_spelling(trie_node *root, char *word) {
    return is_word_in_trie(root, word);
}

// Suggest corrections for a misspelled word
void suggest_corrections(trie_node *root, char *word) {
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 26; j++) {
            if (j != word[i] - 'a') {
                char new_word[100];
                strncpy(new_word, word, i);
                new_word[i] = 'a' + j;
                strncpy(new_word + i + 1, word + i + 1, len - i - 1);
                new_word[len] = '\0';
                if (is_word_in_trie(root, new_word)) {
                    printf("Suggested correction: %s\n", new_word);
                }
            }
        }
    }
}

// Main function
int main() {
    // Create a trie root node
    trie_node *root = new_trie_node();

    // Load words from a file into the trie
    load_words(root, "words.txt");

    // Check the spelling of a word
    char word[100];
    printf("Enter a word to check the spelling: ");
    scanf("%s", word);
    if (check_spelling(root, word)) {
        printf("The word is spelled correctly.\n");
    } else {
        printf("The word is misspelled.\n");
        suggest_corrections(root, word);
    }

    return 0;
}