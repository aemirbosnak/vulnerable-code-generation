//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_LENGTH 50

typedef struct {
    char word[MAX_LENGTH];
    int is_word;
} TrieNode;

TrieNode *trie;
int num_nodes;

void add_word(const char *word) {
    int index = 0, length = strlen(word);
    TrieNode *current = trie;

    for (int i = 0; i < length; i++) {
        int next_index = index + (1 << (word[i] - 'a'));
        if (!current->is_word && next_index < num_nodes) {
            current = &trie[next_index];
        } else {
            if (!current->is_word) {
                current->is_word = 1;
                trie = realloc(trie, sizeof(TrieNode) * (num_nodes + 1));
                memset(&trie[num_nodes], 0, sizeof(TrieNode));
                current = &trie[num_nodes++];
            }
            current->is_word = 1;
            strcpy(current->word, word);
            index = next_index;
        }
    }
}

int check_word(const char *word) {
    int index = 0, length = strlen(word);
    TrieNode *current = trie;

    for (int i = 0; i < length; i++) {
        int next_index = index + (1 << (tolower(word[i]) - 'a'));
        if (next_index >= num_nodes) {
            return 0;
        }
        current = &trie[next_index];
        if (!current->is_word) {
            return 0;
        }
        index = next_index;
    }

    return strcmp(current->word, word) == 0;
}

int main() {
    int i;
    trie = calloc(1, sizeof(TrieNode));
    num_nodes = 1;

    const char *dictionary[] = {
        "apple", "banana", "cherry", "date", "fig", "grape", "kiwi",
        "lemon", "mango", "orange", "pear", "peach", "persimmon",
        "pineapple", "quince", "raspberry", "strawberry", "tangerine",
        "tomato", "watermelon", "zucchini"
    };

    for (i = 0; i < sizeof(dictionary) / sizeof(char *); i++) {
        add_word(dictionary[i]);
    }

    const char *test_words[] = {
        "aple", "banan", "cherryy", "appel", "date", "figg", "grap",
        "kiwiis", "lemonn", "mango0", "orangee", "pear", "peachh",
        "persimon", "raspberrie", "strawberrry", "tangerinee", "tomatoo",
        "watermelonn", "zucchinni", "apple123", "appel123"
    };

    for (i = 0; i < sizeof(test_words) / sizeof(char *); i++) {
        int result = check_word(test_words[i]);
        printf("%s is %svalid\n", test_words[i], result ? "" : "in");
    }

    free(trie);
    return 0;
}