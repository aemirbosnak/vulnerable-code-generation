//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: mathematical
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 100000

struct trie_node {
    int is_word;
    struct trie_node *children[26];
};

struct trie_node *create_node() {
    struct trie_node *node = (struct trie_node *)malloc(sizeof(struct trie_node));
    node->is_word = 0;
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void insert_word(struct trie_node *root, char *word) {
    struct trie_node *node = root;
    int length = strlen(word);

    for (int i = 0; i < length; i++) {
        int index = tolower(word[i]) - 'a';
        if (node->children[index] == NULL) {
            node->children[index] = create_node();
        }
        node = node->children[index];
    }

    node->is_word = 1;
}

int search_word(struct trie_node *root, char *word) {
    struct trie_node *node = root;
    int length = strlen(word);

    for (int i = 0; i < length; i++) {
        int index = tolower(word[i]) - 'a';
        if (node->children[index] == NULL) {
            return 0;
        }
        node = node->children[index];
    }

    return node->is_word;
}

void delete_trie(struct trie_node *root) {
    for (int i = 0; i < 26; i++) {
        if (root->children[i]!= NULL) {
            delete_trie(root->children[i]);
        }
    }
    free(root);
}

int main() {
    FILE *dictionary = fopen("dictionary.txt", "r");
    if (dictionary == NULL) {
        printf("Error opening dictionary file.\n");
        return 1;
    }

    char word[MAX_WORD_LENGTH];
    struct trie_node *root = create_node();

    while (fscanf(dictionary, "%s", word)!= EOF) {
        insert_word(root, word);
    }

    fclose(dictionary);

    char input_word[MAX_WORD_LENGTH];
    while (1) {
        printf("Enter a word to check: ");
        fgets(input_word, MAX_WORD_LENGTH, stdin);
        int length = strlen(input_word);
        if (input_word[length - 1] == '\n') {
            input_word[length - 1] = '\0';
        }

        if (search_word(root, input_word)) {
            printf("%s is a valid word.\n", input_word);
        } else {
            printf("%s is not a valid word.\n", input_word);
        }
    }

    delete_trie(root);

    return 0;
}