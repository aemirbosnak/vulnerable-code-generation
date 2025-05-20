//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 20

typedef struct trie_node {
    struct trie_node *children[26];
    int is_word;
} trie_node;

trie_node *create_trie_node() {
    trie_node *new_node = malloc(sizeof(trie_node));
    for (int i = 0; i < 26; i++) {
        new_node->children[i] = NULL;
    }
    new_node->is_word = 0;
    return new_node;
}

void insert_word(trie_node *root, char *word) {
    trie_node *current = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = create_trie_node();
        }
        current = current->children[index];
    }
    current->is_word = 1;
}

int search_word(trie_node *root, char *word) {
    trie_node *current = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (current->children[index] == NULL) {
            return 0;
        }
        current = current->children[index];
    }
    return current->is_word;
}

char *suggest_word(trie_node *root, char *word) {
    trie_node *current = root;
    char *suggestion = malloc(MAX_WORD_LEN);
    int i = 0;
    while (word[i] != '\0') {
        int index = word[i] - 'a';
        if (current->children[index] == NULL) {
            break;
        }
        suggestion[i] = word[i];
        current = current->children[index];
        i++;
    }

    if (current->is_word) {
        return suggestion;
    }

    for (int j = 0; j < 26; j++) {
        if (current->children[j] != NULL) {
            suggestion[i] = j + 'a';
            char *sub_suggestion = suggest_word(current->children[j], word + i + 1);
            if (sub_suggestion != NULL) {
                strcat(suggestion, sub_suggestion);
                return suggestion;
            }
        }
    }

    return NULL;
}

int main() {
    trie_node *root = create_trie_node();

    char words[MAX_WORDS][MAX_WORD_LEN];
    int num_words = 0;

    FILE *dictionary = fopen("dictionary.txt", "r");
    if (dictionary == NULL) {
        printf("Error opening dictionary file.\n");
        return 1;
    }

    while (fscanf(dictionary, "%s", words[num_words]) != EOF) {
        num_words++;
    }

    fclose(dictionary);

    for (int i = 0; i < num_words; i++) {
        insert_word(root, words[i]);
    }

    char input[MAX_WORD_LEN];
    printf("Enter a word: ");
    scanf("%s", input);

    if (search_word(root, input)) {
        printf("The word is spelled correctly.\n");
    } else {
        char *suggestion = suggest_word(root, input);
        if (suggestion != NULL) {
            printf("The word is misspelled. Did you mean '%s'?\n", suggestion);
        } else {
            printf("The word is not in the dictionary.\n");
        }
    }

    return 0;
}