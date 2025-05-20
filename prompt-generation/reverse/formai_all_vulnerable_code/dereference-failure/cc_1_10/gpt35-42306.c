//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LEN 20
#define ALPHABET_SIZE 26

struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    int isEndOfWord;
};

struct TrieNode* createNode() {
    struct TrieNode* node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }
    node->isEndOfWord = 0;
    return node;
}

void insert(struct TrieNode* root, char* word) {
    struct TrieNode* current = root;
    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (!current->children[index])
            current->children[index] = createNode();
        current = current->children[index];
    }
    current->isEndOfWord = 1;
}

int search(struct TrieNode* root, char* word) {
    struct TrieNode* current = root;
    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (!current->children[index])
            return 0;
        current = current->children[index];
    }
    return (current && current->isEndOfWord);
}

void translate(struct TrieNode* root, char* sentence) {
    char* token = strtok(sentence, " ");
    while (token) {
        if (search(root, token))
            printf(">");
        else
            printf("%s ", token);
        token = strtok(NULL, " ");
    }
    printf("\n");
}

int main() {
    struct TrieNode* root = createNode();
    char* alienWords[] = {"abb", "baa", "baab", "aaba"};
    for (int i = 0; i < 4; i++) {
        insert(root, alienWords[i]);
    }
    char sentence[MAX_WORD_LEN * 100];
    printf("Enter a sentence in Alien Language:\n");
    fgets(sentence, MAX_WORD_LEN * 100, stdin);
    printf("Translating...\n");
    translate(root, sentence);
    return 0;
}