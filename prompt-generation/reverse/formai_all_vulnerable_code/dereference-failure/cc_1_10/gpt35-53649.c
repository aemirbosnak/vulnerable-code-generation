//FormAI DATASET v1.0 Category: Spell checking ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 256      // Maximum length of a word
#define MAX_NUM_WORDS 10000   // Maximum number of unique words in the dictionary

/* Trie node data structure */
typedef struct TrieNode{
    int isWord;
    struct TrieNode* children[26];
} TrieNode;

/* Initialize a new Trie node */
TrieNode* createTrieNode(){
    TrieNode* node = (TrieNode*) malloc(sizeof(TrieNode));
    node->isWord = 0;
    for(int i=0; i<26; i++){
        node->children[i] = NULL;
    }
    return node;
}

/* Insert a new word into the Trie */
void insertWordIntoTrie(TrieNode* root, char* word){
    TrieNode* curr = root;
    for(int i=0; i<strlen(word); i++){
        int idx = tolower(word[i]) - 'a';
        if(curr->children[idx] == NULL){
            curr->children[idx] = createTrieNode();
        }
        curr = curr->children[idx];
    }
    curr->isWord = 1;
}

/* Check if a word is present in the Trie */
int searchWordInTrie(TrieNode* root, char* word){
    TrieNode* curr = root;
    for(int i=0; i<strlen(word); i++){
        int idx = tolower(word[i]) - 'a';
        if(curr->children[idx] == NULL){
            return 0;
        }
        curr = curr->children[idx];
    }
    return curr->isWord;
}

/* Clean up the memory used by the Trie */
void cleanupTrie(TrieNode* root){
    if(root == NULL){
        return;
    }
    for(int i=0; i<26; i++){
        if(root->children[i] != NULL){
            cleanupTrie(root->children[i]);
        }
    }
    free(root);
}

/* Load a dictionary file into the Trie */
int loadDictionaryFileIntoTrie(TrieNode** root, char* filename){
    FILE* fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Failed to open dictionary file %s\n", filename);
        return -1;
    }

    char word[MAX_WORD_LEN];
    int numWords = 0;
    while(fgets(word, MAX_WORD_LEN, fp) != NULL && numWords < MAX_NUM_WORDS){
        if(word[strlen(word)-1] == '\n'){
            word[strlen(word)-1] = '\0';
        }
        insertWordIntoTrie(*root, word);
        numWords++;
    }

    fclose(fp);
    return numWords;
}

/* Perform spell-checking on a given input file */
int spellCheckFile(TrieNode* root, char* inputFile, char* outputFile){
    FILE* fpIn = fopen(inputFile, "r");
    if(fpIn == NULL){
        printf("Failed to open input file %s\n", inputFile);
        return -1;
    }

    FILE* fpOut = fopen(outputFile, "w");
    if(fpOut == NULL){
        fclose(fpIn);
        printf("Failed to open output file %s\n", outputFile);
        return -1;
    }

    char word[MAX_WORD_LEN];
    while(fscanf(fpIn, "%s", word) != EOF){
        if(word[strlen(word)-1] == '.' || word[strlen(word)-1] == ',' || word[strlen(word)-1] == ';' ||
           word[strlen(word)-1] == ':' || word[strlen(word)-1] == '?' || word[strlen(word)-1] == '!'){
            word[strlen(word)-1] = '\0';
        }
        if(!searchWordInTrie(root, word)){
            fprintf(fpOut, "<%s> ", word);
        }
        else{
            fprintf(fpOut, "%s ", word);
        }
    }

    fclose(fpIn);
    fclose(fpOut);
    return 0;
}

int main(int argc, char** argv){
    if(argc < 3){
        printf("Usage: %s dictionary_file input_file output_file\n", argv[0]);
        return -1;
    }

    char* dictionaryFile = argv[1];
    char* inputFile = argv[2];
    char* outputFile = argv[3];

    TrieNode* root = createTrieNode();
    printf("Loading dictionary file %s...\n", dictionaryFile);
    int numWords = loadDictionaryFileIntoTrie(&root, dictionaryFile);
    if(numWords < 0){
        cleanupTrie(root);
        return -1;
    }
    printf("Loaded %d words into the dictionary!\n\n", numWords);

    printf("Performing spell-checking on input file %s...\n", inputFile);
    int ret = spellCheckFile(root, inputFile, outputFile);
    cleanupTrie(root);

    if(ret == 0){
        printf("Spell-checking completed successfully!\n");
    }
    else{
        printf("An error occurred during spell-checking\n");
    }

    return ret;
}