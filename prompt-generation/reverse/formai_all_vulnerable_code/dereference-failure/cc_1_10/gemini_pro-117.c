//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define a node for the trie
typedef struct TrieNode {
    char letter;
    struct TrieNode *children[26];
    int is_word;
} TrieNode;

// Create a new trie node
TrieNode* create_trie_node(char letter) {
    TrieNode *node = (TrieNode*)malloc(sizeof(TrieNode));
    node->letter = letter;
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    node->is_word = 0;
    return node;
}

// Insert a word into the trie
void insert_word(TrieNode *root, char *word) {
    TrieNode *current = root;
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
int is_word_in_trie(TrieNode *root, char *word) {
    TrieNode *current = root;
    for (int i = 0; i < strlen(word); i++) {
        int index = tolower(word[i]) - 'a';
        if (current->children[index] == NULL) {
            return 0;
        }
        current = current->children[index];
    }
    return current->is_word;
}

// Free the trie
void free_trie(TrieNode *root) {
    for (int i = 0; i < 26; i++) {
        if (root->children[i] != NULL) {
            free_trie(root->children[i]);
        }
    }
    free(root);
}

// Load the dictionary into the trie
void load_dictionary(TrieNode *root, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening dictionary file\n");
        return;
    }

    char word[100];
    while (fscanf(file, "%s", word) != EOF) {
        insert_word(root, word);
    }

    fclose(file);
}

// Check the spelling of a word
int check_spelling(TrieNode *root, char *word) {
    return is_word_in_trie(root, word);
}

// Get suggestions for a misspelled word
void get_suggestions(TrieNode *root, char *word, char *suggestions[]) {
    int i, j, k;
    TrieNode *current = root;

    // Check for suggestions by adding a letter
    for (i = 0; i < strlen(word); i++) {
        for (j = 'a'; j <= 'z'; j++) {
            if (j == word[i]) {
                continue;
            }
            char new_word[100];
            strcpy(new_word, word);
            new_word[i] = j;
            if (is_word_in_trie(root, new_word)) {
                suggestions[k++] = strdup(new_word);
            }
        }
    }

    // Check for suggestions by removing a letter
    for (i = 0; i < strlen(word); i++) {
        char new_word[100];
        strcpy(new_word, word);
        for (j = i + 1; j < strlen(word); j++) {
            new_word[j - 1] = word[j];
        }
        new_word[strlen(word) - 1] = '\0';
        if (is_word_in_trie(root, new_word)) {
            suggestions[k++] = strdup(new_word);
        }
    }

    // Check for suggestions by swapping two letters
    for (i = 0; i < strlen(word) - 1; i++) {
        char new_word[100];
        strcpy(new_word, word);
        char temp = new_word[i];
        new_word[i] = new_word[i + 1];
        new_word[i + 1] = temp;
        if (is_word_in_trie(root, new_word)) {
            suggestions[k++] = strdup(new_word);
        }
    }

    // Check for suggestions by replacing a letter
    for (i = 0; i < strlen(word); i++) {
        for (j = 'a'; j <= 'z'; j++) {
            if (j == word[i]) {
                continue;
            }
            char new_word[100];
            strcpy(new_word, word);
            new_word[i] = j;
            if (is_word_in_trie(root, new_word)) {
                suggestions[k++] = strdup(new_word);
            }
        }
    }
}

// Print the suggestions
void print_suggestions(char *suggestions[], int num_suggestions) {
    if (num_suggestions == 0) {
        printf("No suggestions found\n");
    } else {
        printf("Suggestions:\n");
        for (int i = 0; i < num_suggestions; i++) {
            printf("%s\n", suggestions[i]);
        }
    }
}

// Main function
int main() {
    // Create the root of the trie
    TrieNode *root = create_trie_node(' ');

    // Load the dictionary into the trie
    load_dictionary(root, "dictionary.txt");

    // Get the word to check from the user
    char word[100];
    printf("Enter a word to check: ");
    scanf("%s", word);

    // Check the spelling of the word
    int is_correct = check_spelling(root, word);

    // Print the result
    if (is_correct) {
        printf("%s is spelled correctly\n", word);
    } else {
        printf("%s is spelled incorrectly\n", word);

        // Get suggestions for the misspelled word
        char *suggestions[100];
        get_suggestions(root, word, suggestions);

        // Print the suggestions
        print_suggestions(suggestions, 100);
    }

    // Free the trie
    free_trie(root);

    return 0;
}