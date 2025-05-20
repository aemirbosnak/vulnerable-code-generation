//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_LEN 100

struct node {
    char *word;
    struct node *next;
};

struct trie {
    struct node *root;
};

struct trie *create_trie()
{
    struct trie *t = malloc(sizeof(struct trie));
    t->root = NULL;
    return t;
}

void insert_word(struct trie *t, char *word)
{
    struct node *n = t->root;
    int i;
    for (i = 0; i < strlen(word); i++) {
        if (!n) {
            n = malloc(sizeof(struct node));
            n->word = malloc(sizeof(char) * (i + 1));
            strncpy(n->word, word, i);
            n->word[i] = '\0';
            n->next = NULL;
            if (!t->root) {
                t->root = n;
            } else {
                struct node *prev = t->root;
                while (prev->next) {
                    prev = prev->next;
                }
                prev->next = n;
            }
        }
        while (n->next && strncmp(n->word, word, i + 1) != 0) {
            n = n->next;
        }
        if (!n->next || strncmp(n->word, word, i + 1) != 0) {
            struct node *nn = malloc(sizeof(struct node));
            nn->word = malloc(sizeof(char) * (i + 2));
            strncpy(nn->word, word, i + 1);
            nn->word[i + 1] = '\0';
            nn->next = NULL;
            n->next = nn;
        }
        n = n->next;
    }
}

int is_word(struct trie *t, char *word)
{
    struct node *n = t->root;
    int i;
    for (i = 0; i < strlen(word); i++) {
        if (!n) {
            return 0;
        }
        while (n->next && strncmp(n->word, word, i + 1) != 0) {
            n = n->next;
        }
        if (!n->next || strncmp(n->word, word, i + 1) != 0) {
            return 0;
        }
        n = n->next;
    }
    return 1;
}

void free_trie(struct trie *t)
{
    struct node *n = t->root;
    while (n) {
        struct node *next = n->next;
        free(n->word);
        free(n);
        n = next;
    }
    free(t);
}

int main()
{
    struct trie *t = create_trie();
    char *words[] = {"hello", "world", "and", "welcome", "to", "the", "spell", "checker", "example"};
    int i;
    for (i = 0; i < sizeof(words) / sizeof(char *); i++) {
        insert_word(t, words[i]);
    }
    char *input = "hello world and welcome to the spell checker example";
    char *words_input = strtok(input, " ");
    while (words_input) {
        if (!is_word(t, words_input)) {
            printf("'%s' is not a word\n", words_input);
        }
        words_input = strtok(NULL, " ");
    }
    free_trie(t);
    return 0;
}