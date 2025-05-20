//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LEN 32

// Create a node for the Trie
typedef struct TrieNode {
    char letter;
    struct TrieNode *children[26];
    bool is_word;
} TrieNode;

// Create a new Trie node
TrieNode *create_trie_node(char letter) {
    TrieNode *node = malloc(sizeof(TrieNode));
    node->letter = letter;
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    node->is_word = false;
    return node;
}

// Insert a word into the Trie
void insert_word(TrieNode *root, char *word) {
    TrieNode *current = root;
    int index;

    for (int i = 0; i < strlen(word); i++) {
        index = word[i] - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = create_trie_node(word[i]);
        }
        current = current->children[index];
    }

    current->is_word = true;
}

// Check if a word exists in the Trie
bool check_word(TrieNode *root, char *word) {
    TrieNode *current = root;
    int index;

    for (int i = 0; i < strlen(word); i++) {
        index = word[i] - 'a';
        if (current->children[index] == NULL) {
            return false;
        }
        current = current->children[index];
    }

    return current->is_word;
}

// Find the closest word to the given word in the Trie
char *find_closest_word(TrieNode *root, char *word) {
    TrieNode *current = root;
    int index;
    char *closest_word = NULL;

    for (int i = 0; i < strlen(word); i++) {
        index = word[i] - 'a';
        if (current->children[index] != NULL) {
            current = current->children[index];
            closest_word = word;
        } else {
            break;
        }
    }

    // If we found a word, check if it is the closest word
    if (closest_word != NULL && current->is_word) {
        return closest_word;
    }

    // Otherwise, find the closest word among the children of the current node
    for (int i = 0; i < 26; i++) {
        if (current->children[i] != NULL) {
            char *child_word = find_closest_word(current->children[i], word);
            if (child_word != NULL) {
                if (closest_word == NULL || strlen(child_word) < strlen(closest_word)) {
                    closest_word = child_word;
                }
            }
        }
    }

    return closest_word;
}

// Free the Trie
void free_trie(TrieNode *root) {
    for (int i = 0; i < 26; i++) {
        if (root->children[i] != NULL) {
            free_trie(root->children[i]);
        }
    }
    free(root);
}

int main() {
    // Create the Trie
    TrieNode *root = create_trie_node(' ');

    // Insert some words into the Trie
    insert_word(root, "apple");
    insert_word(root, "banana");
    insert_word(root, "cherry");
    insert_word(root, "dog");
    insert_word(root, "elephant");

    // Check if a word exists in the Trie
    printf("apple: %s\n", check_word(root, "apple") ? "Yes" : "No");
    printf("banana: %s\n", check_word(root, "banana") ? "Yes" : "No");
    printf("cherry: %s\n", check_word(root, "cherry") ? "Yes" : "No");
    printf("dog: %s\n", check_word(root, "dog") ? "Yes" : "No");
    printf("elephant: %s\n", check_word(root, "elephant") ? "Yes" : "No");

    // Find the closest word to a given word in the Trie
    printf("Closest word to \"app\": %s\n", find_closest_word(root, "app"));
    printf("Closest word to \"ban\": %s\n", find_closest_word(root, "ban"));
    printf("Closest word to \"che\": %s\n", find_closest_word(root, "che"));
    printf("Closest word to \"do\": %s\n", find_closest_word(root, "do"));
    printf("Closest word to \"ele\": %s\n", find_closest_word(root, "ele"));

    // Free the Trie
    free_trie(root);

    return 0;
}