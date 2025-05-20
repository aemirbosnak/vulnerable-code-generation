//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <alloca.h>

#define ALPHABET_SIZE 26
#define TRIE_NODE_SIZE (sizeof(bool) * 27)

typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool is_end_of_word;
} TrieNode;

TrieNode* create_node() {
    TrieNode *new_node = calloc(1, TRIE_NODE_SIZE);
    if (!new_node) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    new_node->is_end_of_word = false;
    return new_node;
}

void trie_insert(TrieNode *root, const char *word) {
    TrieNode *current = root;
    for (size_t i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (!current->children[index]) {
            current->children[index] = create_node();
        }
        current = current->children[index];
    }
    current->is_end_of_word = true;
}

bool trie_search(const TrieNode *root, const char *word, size_t length) {
    TrieNode *current = root;
    for (size_t i = 0; i < length; i++) {
        int index = word[i] - 'a';
        if (!current->children[index]) {
            return false;
        }
        current = current->children[index];
    }
    return current != NULL && current->is_end_of_word;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <dictionary_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *dictionary_file = fopen(argv[1], "r");
    if (!dictionary_file) {
        perror("Could not open the dictionary file");
        exit(EXIT_FAILURE);
    }

    TrieNode *root = create_node();

    char word[256];
    size_t capacity = sizeof(word) / sizeof(word[0]);
    size_t length;

    while (fgets(word, capacity, dictionary_file) != NULL) {
        length = strlen(word);
        if (length > 0 && word[length - 1] == '\n') {
            word[length - 1] = '\0';
        }
        trie_insert(root, word);
    }

    fclose(dictionary_file);

    while (true) {
        printf("Enter a word to check (type 'quit' to exit): ");
        scanf("%s", word);

        if (strcmp(word, "quit") == 0) {
            break;
        }

        length = strlen(word);
        if (trie_search(root, word, length)) {
            printf("The word '%s' is in the dictionary.\n", word);
        } else {
            printf("The word '%s' is not in the dictionary.\n", word);
        }
    }

    free(root);
    return EXIT_SUCCESS;
}