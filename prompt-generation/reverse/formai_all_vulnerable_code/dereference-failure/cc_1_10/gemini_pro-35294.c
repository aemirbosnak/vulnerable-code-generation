//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 255

struct trie_node {
    int is_word;
    struct trie_node *children[26];
};

struct trie {
    struct trie_node *root;
};

struct trie *create_trie() {
    struct trie *t = malloc(sizeof(struct trie));
    t->root = malloc(sizeof(struct trie_node));
    t->root->is_word = 0;
    for (int i = 0; i < 26; i++) {
        t->root->children[i] = NULL;
    }
    return t;
}

void insert_word(struct trie *t, char *word) {
    struct trie_node *current = t->root;
    for (int i = 0; i < strlen(word); i++) {
        int index = tolower(word[i]) - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = malloc(sizeof(struct trie_node));
            current->children[index]->is_word = 0;
            for (int j = 0; j < 26; j++) {
                current->children[index]->children[j] = NULL;
            }
        }
        current = current->children[index];
    }
    current->is_word = 1;
}

int search_word(struct trie *t, char *word) {
    struct trie_node *current = t->root;
    for (int i = 0; i < strlen(word); i++) {
        int index = tolower(word[i]) - 'a';
        if (current->children[index] == NULL) {
            return 0;
        }
        current = current->children[index];
    }
    return current->is_word;
}

int main() {
    struct trie *t = create_trie();
    FILE *fp = fopen("dictionary.txt", "r");
    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word) != EOF) {
        insert_word(t, word);
    }
    fclose(fp);

    char input[MAX_WORD_LENGTH];
    while (1) {
        printf("Enter a word (or q to quit): ");
        scanf("%s", input);
        if (strcmp(input, "q") == 0) {
            break;
        }
        if (search_word(t, input)) {
            printf("%s is a valid word.\n", input);
        } else {
            printf("%s is not a valid word.\n", input);
        }
    }

    return 0;
}