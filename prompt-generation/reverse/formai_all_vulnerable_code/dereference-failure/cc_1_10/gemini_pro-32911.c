//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 1000

struct trie_node {
    char letter;
    struct trie_node *children[26];
    int is_word;
};

struct trie {
    struct trie_node *root;
};

struct trie *create_trie() {
    struct trie *new_trie = malloc(sizeof(struct trie));
    new_trie->root = malloc(sizeof(struct trie_node));
    new_trie->root->letter = '\0';
    new_trie->root->is_word = 0;
    for (int i = 0; i < 26; i++) {
        new_trie->root->children[i] = NULL;
    }
    return new_trie;
}

void insert_word(struct trie *trie, char *word) {
    struct trie_node *current_node = trie->root;
    int i;
    for (i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (current_node->children[index] == NULL) {
            current_node->children[index] = malloc(sizeof(struct trie_node));
            current_node->children[index]->letter = word[i];
            current_node->children[index]->is_word = 0;
            for (int j = 0; j < 26; j++) {
                current_node->children[index]->children[j] = NULL;
            }
        }
        current_node = current_node->children[index];
    }
    current_node->is_word = 1;
}

int search_word(struct trie *trie, char *word) {
    struct trie_node *current_node = trie->root;
    int i;
    for (i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (current_node->children[index] == NULL) {
            return 0;
        }
        current_node = current_node->children[index];
    }
    return current_node->is_word;
}

void free_trie(struct trie *trie) {
    struct trie_node *current_node = trie->root;
    for (int i = 0; i < 26; i++) {
        if (current_node->children[i] != NULL) {
            free_trie(current_node->children[i]);
        }
    }
    free(current_node);
    free(trie);
}

int main() {
    struct trie *dictionary = create_trie();
    insert_word(dictionary, "hello");
    insert_word(dictionary, "world");
    insert_word(dictionary, "computer");
    insert_word(dictionary, "science");
    insert_word(dictionary, "technology");

    char word[MAX_WORD_LENGTH];
    printf("Enter a word to check: ");
    scanf("%s", word);

    if (search_word(dictionary, word)) {
        printf("%s is a valid word.\n", word);
    } else {
        printf("%s is not a valid word.\n", word);
    }

    free_trie(dictionary);
    return 0;
}