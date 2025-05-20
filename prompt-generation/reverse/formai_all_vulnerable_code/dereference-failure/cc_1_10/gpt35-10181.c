//FormAI DATASET v1.0 Category: Spell checking ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50
#define MAX_DICT_SIZE 100000

// Trie node structure
struct TrieNode {
    struct TrieNode *children[26];
    int isEndOfWord;
};

// Function to create a new Trie node
struct TrieNode *newTrieNode() {
    struct TrieNode *node = (struct TrieNode*) malloc(sizeof(struct TrieNode));
    node->isEndOfWord = 0;
    int i;
    for(i=0; i<26; i++) {
        node->children[i] = NULL;
    }
    return node;
}

// Function to insert a word into the Trie
void insert(struct TrieNode *root, char *key) {
    struct TrieNode *current = root;
    int len = strlen(key);
    int i, index;
    for(i=0; i<len; i++) {
        index = key[i] - 'a';
        if(current->children[index] == NULL) {
            current->children[index] = newTrieNode();
        }
        current = current->children[index];
    }
    current->isEndOfWord = 1;
}

// Function to search for a word in the Trie
int search(struct TrieNode *root, char *key) {
    struct TrieNode *current = root;
    int len = strlen(key);
    int i, index;
    for(i=0; i<len; i++) {
        index = key[i] - 'a';
        if(current->children[index] == NULL) {
            return 0;
        }
        current = current->children[index];
    }
    return (current != NULL && current->isEndOfWord);
}

// Function to check if a character is a valid alphabet or not
int isAlpha(char c) {
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return 1;
    }
    else {
        return 0;
    }
}

// Main function
int main() {
    FILE *fp;
    char filename[50];
    char dictionary[MAX_DICT_SIZE][MAX_WORD_LEN];
    int numWords = 0;
    printf("Please enter the name of the dictionary file: ");
    scanf("%s", filename);

    // Read dictionary file and insert words into Trie
    fp = fopen(filename, "r");
    char buffer[MAX_WORD_LEN];
    while(fscanf(fp, "%s", buffer) != EOF) {
        insert(newTrieNode(), buffer);
        strcpy(dictionary[numWords], buffer);
        numWords++;
    }
    fclose(fp);

    // Read input file and check for spelling errors
    printf("Please enter the name of the input file: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    int lineNum = 1;
    char line[1000];
    while(fgets(line, sizeof(line), fp) != NULL) {
        char *token;
        token = strtok(line, " \t\n");
        while(token != NULL) {
            if(!search(newTrieNode(), token)) {
                printf("Line %d: \"%s\" is not a valid word, did you mean:\n", lineNum, token);
                int i, j, index = 0, len = strlen(token);
                for(i=0; i<len; i++) {
                    if(isAlpha(token[i])) { // Check if character is a valid alphabet
                        char temp = token[i];
                        for(j=0; j<26; j++) {
                            token[i] = 'a' + j;
                            if(search(newTrieNode(), token)) {
                                printf("%d. %s\n", index+1, token);
                                index++;
                            }
                        }
                        token[i] = temp;
                    }
                }
            }
            token = strtok(NULL, " \t\n");
        }
        lineNum++;
    }
    fclose(fp);

    return 0;
}