//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: calm
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 20

// Define the dictionary size
#define DICTIONARY_SIZE 10000

// Create a node for the trie
struct TrieNode {
    struct TrieNode *children[26];
    int is_word;
};

// Create a new trie node
struct TrieNode *create_trie_node() {
    struct TrieNode *node = malloc(sizeof(struct TrieNode));
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    node->is_word = 0;
    return node;
}

// Insert a word into the trie
void insert_word(struct TrieNode *root, char *word) {
    struct TrieNode *current = root;
    for (int i = 0; i < strlen(word); i++) {
        int index = tolower(word[i]) - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = create_trie_node();
        }
        current = current->children[index];
    }
    current->is_word = 1;
}

// Check if a word is in the trie
int is_word_in_trie(struct TrieNode *root, char *word) {
    struct TrieNode *current = root;
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
void load_dictionary(struct TrieNode *root, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening dictionary file\n");
        return;
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        insert_word(root, word);
    }

    fclose(file);
}

// Check the spelling of a word
int check_spelling(struct TrieNode *root, char *word) {
    return is_word_in_trie(root, word);
}

// Print the suggestions for a misspelled word
void print_suggestions(struct TrieNode *root, char *word) {
    // Create a queue to store the suggestions
    struct TrieNode *queue[100];
    int front = 0;
    int rear = 0;

    // Enqueue the root node
    queue[rear++] = root;

    // While the queue is not empty
    while (front != rear) {
        // Dequeue the front node
        struct TrieNode *current = queue[front++];

        // Check if the current node is a word
        if (current->is_word) {
            // Print the word
            printf("%s\n", word);
        }

        // Enqueue the children of the current node
        for (int i = 0; i < 26; i++) {
            if (current->children[i] != NULL) {
                queue[rear++] = current->children[i];
            }
        }
    }
}

// Main function
int main() {
    // Create the root node of the trie
    struct TrieNode *root = create_trie_node();

    // Load the dictionary into the trie
    load_dictionary(root, "dictionary.txt");

    // Get the word to check from the user
    char word[MAX_WORD_LENGTH];
    printf("Enter the word to check: ");
    scanf("%s", word);

    // Check the spelling of the word
    int is_correct = check_spelling(root, word);

    // Print the result
    if (is_correct) {
        printf("The word is spelled correctly\n");
    } else {
        printf("The word is spelled incorrectly\n");
        printf("Suggestions:\n");
        print_suggestions(root, word);
    }

    return 0;
}