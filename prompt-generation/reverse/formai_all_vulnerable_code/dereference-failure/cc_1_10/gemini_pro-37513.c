//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a node for the trie
typedef struct trie_node {
    char letter;
    int is_word;
    struct trie_node *children[26];
} trie_node;

// Create a new trie node
trie_node *create_trie_node(char letter) {
    trie_node *new_node = (trie_node *)malloc(sizeof(trie_node));
    new_node->letter = letter;
    new_node->is_word = 0;
    for (int i = 0; i < 26; i++) {
        new_node->children[i] = NULL;
    }
    return new_node;
}

// Insert a word into the trie
void insert_word_into_trie(trie_node *root, char *word) {
    if (word == NULL || *word == '\0') {
        return;
    }
    int index = *word - 'a';
    if (root->children[index] == NULL) {
        root->children[index] = create_trie_node(*word);
    }
    insert_word_into_trie(root->children[index], word + 1);
}

// Check if a word is in the trie
int is_word_in_trie(trie_node *root, char *word) {
    if (word == NULL || *word == '\0') {
        return root->is_word;
    }
    int index = *word - 'a';
    if (root->children[index] == NULL) {
        return 0;
    }
    return is_word_in_trie(root->children[index], word + 1);
}

// Get all the words in the trie
void get_all_words_in_trie(trie_node *root, char *prefix, char *words[], int *num_words) {
    if (root->is_word) {
        words[*num_words] = (char *)malloc(strlen(prefix) + 1);
        strcpy(words[*num_words], prefix);
        *num_words += 1;
    }
    for (int i = 0; i < 26; i++) {
        if (root->children[i] != NULL) {
            char new_prefix[strlen(prefix) + 2];
            strcpy(new_prefix, prefix);
            new_prefix[strlen(prefix)] = root->children[i]->letter;
            new_prefix[strlen(prefix) + 1] = '\0';
            get_all_words_in_trie(root->children[i], new_prefix, words, num_words);
        }
    }
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

// Spell check a word
int spell_check_word(trie_node *root, char *word) {
    return is_word_in_trie(root, word);
}

// Get all the suggestions for a misspelled word
void get_suggestions_for_misspelled_word(trie_node *root, char *word, char *suggestions[], int *num_suggestions) {
    if (word == NULL || *word == '\0') {
        return;
    }
    int index = *word - 'a';
    if (root->children[index] == NULL) {
        return;
    }
    char new_prefix[strlen(word) + 2];
    strcpy(new_prefix, word);
    new_prefix[strlen(word)] = root->children[index]->letter;
    new_prefix[strlen(word) + 1] = '\0';
    get_all_words_in_trie(root->children[index], new_prefix, suggestions, num_suggestions);
}

// Main function
int main() {
    // Create a trie
    trie_node *root = create_trie_node('a');

    // Insert some words into the trie
    insert_word_into_trie(root, "hello");
    insert_word_into_trie(root, "world");
    insert_word_into_trie(root, "computer");
    insert_word_into_trie(root, "science");
    insert_word_into_trie(root, "technology");

    // Spell check some words
    printf("Is 'hello' spelled correctly? %d\n", spell_check_word(root, "hello"));
    printf("Is 'world' spelled correctly? %d\n", spell_check_word(root, "world"));
    printf("Is 'computer' spelled correctly? %d\n", spell_check_word(root, "computer"));
    printf("Is 'science' spelled correctly? %d\n", spell_check_word(root, "science"));
    printf("Is 'technology' spelled correctly? %d\n", spell_check_word(root, "technology"));
    printf("Is 'misspelled' spelled correctly? %d\n", spell_check_word(root, "misspelled"));

    // Get suggestions for misspelled words
    char *suggestions[100];
    int num_suggestions;
    get_suggestions_for_misspelled_word(root, "misspelled", suggestions, &num_suggestions);
    printf("Suggestions for 'misspelled':\n");
    for (int i = 0; i < num_suggestions; i++) {
        printf("%s\n", suggestions[i]);
        free(suggestions[i]);
    }

    // Free the trie
    free_trie(root);

    return 0;
}