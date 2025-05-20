//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define NUM_LETTERS 26

typedef struct trieNode {
    int count;
    struct trieNode *children[NUM_LETTERS];
} TrieNode;

TrieNode *createNode() {
    TrieNode *node = (TrieNode*) malloc(sizeof(TrieNode));
    node->count = 0;
    for(int i = 0; i < NUM_LETTERS; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void insertWord(TrieNode *root, char *word) {
    TrieNode *current = root;
    int index = 0;
    while(word[index]) {
        char c = tolower(word[index]);
        if(!current->children[c-'a']) {
            current->children[c-'a'] = createNode();
        }
        current = current->children[c-'a'];
        index++;
    }
    current->count++;
}

void printWords(TrieNode *root, char word[MAX_WORD_LENGTH], int level) {
    if(root->count > 0) {
        word[level] = '\0';
        printf("%s : %d\n", word, root->count);
    }
    for(int i = 0; i < NUM_LETTERS; i++) {
        if(root->children[i]) {
            word[level] = 'a'+i;
            printWords(root->children[i], word, level+1);
        }
    }
}

void freeTrie(TrieNode *root) {
    if(root == NULL) {
        return;
    }
    for(int i = 0; i < NUM_LETTERS; i++) {
        if(root->children[i]) {
            freeTrie(root->children[i]);
        }
    }
    free(root);
}

int main(int argc, char *argv[]) {
    char *filename = argv[1];
    FILE *fp = fopen(filename, "r");
    if(!fp) {
        printf("Error: Unable to open file %s\n", filename);
        return 1;
    }

    TrieNode *root = createNode();

    char word[MAX_WORD_LENGTH];
    char c;
    int index = 0;
    while((c = fgetc(fp)) != EOF) {
        if(isalpha(c)) {
            word[index++] = c;
        }
        else if(index > 0) {
            word[index] = '\0';
            insertWord(root, word);
            index = 0;
        }
    }

    if(index > 0) {
        word[index] = '\0';
        insertWord(root, word);
    }
    printWords(root, word, 0);
    freeTrie(root);
    fclose(fp);
    return 0;
}