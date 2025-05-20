//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Maximum number of words in the dictionary
#define MAX_WORDS 10000

// Maximum length of a word
#define MAX_WORD_LENGTH 25

// Create a node for the trie
typedef struct trie_node {
    char letter;
    struct trie_node *children[26];
    int is_word;
} trie_node;

// Create a new trie node
trie_node *create_trie_node(char letter) {
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
        int index = tolower(word[i]) - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = create_trie_node(word[i]);
        }
        current = current->children[index];
    }
    current->is_word = 1;
}

// Check if a word is in the trie
int is_word_in_trie(trie_node *root, char *word) {
    trie_node *current = root;
    for (int i = 0; i < strlen(word); i++) {
        int index = tolower(word[i]) - 'a';
        if (current->children[index] == NULL) {
            return 0;
        }
        current = current->children[index];
    }
    return current->is_word;
}

// Load the dictionary into the trie
void load_dictionary(trie_node *root, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening dictionary file");
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        insert_word(root, word);
    }

    fclose(file);
}

// Check the spelling of a word
int check_spelling(trie_node *root, char *word) {
    return is_word_in_trie(root, word);
}

// Get suggestions for a misspelled word
void get_suggestions(trie_node *root, char *word, char *suggestions[]) {
    trie_node *current = root;
    int index = 0;

    // Iterate over the trie until we reach the end of the word
    for (int i = 0; i < strlen(word); i++) {
        index = tolower(word[i]) - 'a';
        if (current->children[index] == NULL) {
            break;
        }
        current = current->children[index];
    }

    // If we reached the end of the word, add it to the suggestions list
    if (current->is_word) {
        suggestions[index++] = strdup(word);
    }

    // Iterate over the children of the current node and add any words that start with the same prefix to the suggestions list
    for (int i = 0; i < 26; i++) {
        if (current->children[i] != NULL) {
            char new_word[MAX_WORD_LENGTH];
            strcpy(new_word, word);
            new_word[strlen(word)] = current->children[i]->letter;
            get_suggestions(root, new_word, suggestions);
        }
    }
}

// Print the suggestions list
void print_suggestions(char *suggestions[], int num_suggestions) {
    printf("Suggestions:\n");
    for (int i = 0; i < num_suggestions; i++) {
        printf("%s\n", suggestions[i]);
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

// Main function
int main() {
    // Create the root of the trie
    trie_node *root = create_trie_node(' ');

    // Load the dictionary into the trie
    load_dictionary(root, "dictionary.txt");

    // Get the word to check from the user
    char word[MAX_WORD_LENGTH];
    printf("Enter a word to check the spelling of: ");
    scanf("%s", word);

    // Check the spelling of the word
    int is_correct = check_spelling(root, word);

    // If the word is not correct, get suggestions from the trie
    if (!is_correct) {
        char *suggestions[MAX_WORDS];
        int num_suggestions = 0;
        get_suggestions(root, word, suggestions);
        print_suggestions(suggestions, num_suggestions);
    } else {
        printf("The word is spelled correctly.\n");
    }

    // Free the trie
    free_trie(root);

    return 0;
}