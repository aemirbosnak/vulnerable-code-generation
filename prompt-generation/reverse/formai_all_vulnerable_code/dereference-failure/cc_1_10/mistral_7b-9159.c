//MISTRAL-7B DATASET v1.0 Category: Text Summarizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct TrieNode {
    int isEndOfWord;
    struct TrieNode *children[26];
} TrieNode;

void initTrie(TrieNode *root) {
    root->isEndOfWord = 0;
    for (int i = 0; i < 26; i++) {
        root->children[i] = NULL;
    }
}

void insert(TrieNode *root, const char *word) {
    TrieNode *current = root;
    for (int level = 0; level < strlen(word); level++) {
        int index = tolower(word[level]) - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = malloc(sizeof(TrieNode));
            initTrie(current->children[index]);
        }
        current = current->children[index];
    }
    current->isEndOfWord = 1;
}

TrieNode *search(TrieNode *root, const char *word, int *length) {
    TrieNode *current = root;
    *length = 0;
    for (int level = 0; level < strlen(word) && current != NULL; level++) {
        int index = tolower(word[level]) - 'a';
        current = current->children[index];
        (*length)++;
    }
    return current;
}

void freeTrie(TrieNode *node) {
    for (int i = 0; i < 26; i++) {
        if (node->children[i] != NULL) {
            freeTrie(node->children[i]);
        }
    }
    free(node);
}

int main() {
    int numTests, i, j, maxLength, numWords;
    char input[100][100];
    char summary[50][100];

    scanf("%d", &numTests);

    TrieNode *trieRoot = malloc(sizeof(TrieNode));
    initTrie(trieRoot);

    for (i = 0; i < numTests; i++) {
        scanf("%s", input[i]);
        insert(trieRoot, input[i]);
    }

    scanf("%d", &numTests);

    for (i = 0; i < numTests; i++) {
        scanf("%s", input[i + numTests]);

        TrieNode *current = trieRoot;
        int length = 0;
        for (j = 0; j < strlen(input[i + numTests]) && current != NULL; j++) {
            int index = tolower(input[i + numTests][j]) - 'a';
            current = current->children[index];
            if (current != NULL) {
                summary[i][length] = input[i + numTests][j];
                length++;
            }
        }

        summary[i][length] = '\0';
        printf("%s\n", summary[i]);
    }

    freeTrie(trieRoot);

    return 0;
}