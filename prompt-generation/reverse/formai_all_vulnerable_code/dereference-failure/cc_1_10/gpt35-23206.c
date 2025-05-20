//FormAI DATASET v1.0 Category: Spell checking ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WORD_LENGTH 100 // maximum length of a word
#define MAX_WORDS 10000 // maximum number of words in the dictionary

struct trie_node{
    struct trie_node *children[26];
    int is_end_of_word; // to mark the end of a word
};

// Inserts a word into trie
void insert(struct trie_node *root, char *key){
    int index;
    struct trie_node *temp = root;
    for(int i=0; i<strlen(key); i++){
        index = tolower(key[i]) - 'a'; // convert upper case to lower case
        if(temp->children[index] == NULL){
            temp->children[index] = (struct trie_node*)malloc(sizeof(struct trie_node));
            for(int j=0; j<26; j++){
                temp->children[index]->children[j] = NULL;
            }
            temp->children[index]->is_end_of_word = 0;
        }
        temp = temp->children[index];
    }
    temp->is_end_of_word = 1;
}

// Searches the word in trie
int search(struct trie_node *root, char *key){
    int index;
    struct trie_node *temp = root;
    for(int i=0; i<strlen(key); i++){
        index = tolower(key[i]) - 'a'; // convert upper case to lower case
        if(temp->children[index] == NULL){
            return 0; // word is not present
        }
        temp = temp->children[index];
    }
    return (temp != NULL && temp->is_end_of_word); // return 1 if word is present and is the end of a word
}

// Checks the spelling of a word
void check_spelling(struct trie_node *root, char *word){
    if(search(root, word)){
        printf("%s is spelled correctly\n", word);
    }else{
        int len = strlen(word);
        char temp[WORD_LENGTH];
        printf("%s is not spelled correctly. Suggestions:\n", word);
        // check for deletion
        for(int i=0; i<len; i++){
            int j = 0;
            for(; j<i; j++){
                temp[j] = word[j];
            }
            for(; j<len-1; j++){
                temp[j] = word[j+1];
            }
            temp[len-1] = '\0';
            if(search(root, temp)){
                printf("%s\n", temp);
            }
        }
        // check for transposition
        for(int i=0; i<len-1; i++){
            int j = 0;
            for(; j<i; j++){
                temp[j] = word[j];
            }
            temp[j++] = word[i+1];
            temp[j++] = word[i];
            for(; j<len; j++){
                temp[j] = word[j];
            }
            temp[len] = '\0';
            if(search(root, temp)){
                printf("%s\n", temp);
            }
        }
        // check for substitution
        for(int i=0; i<len; i++){
            for(char ch='a'; ch<='z'; ch++){
                int j = 0;
                for(; j<i; j++){
                    temp[j] = word[j];
                }
                temp[j++] = ch;
                for(; j<len; j++){
                    temp[j] = word[j+1];
                }
                temp[len] = '\0';
                if(search(root, temp)){
                    printf("%s\n", temp);
                }
            }
        }
        // check for insertion
        for(int i=0; i<=len; i++){
            for(char ch='a'; ch<='z'; ch++){
                int j = 0;
                for(; j<i; j++){
                    temp[j] = word[j];
                }
                temp[j++] = ch;
                for(; j<len+1; j++){
                    temp[j] = word[j-1];
                }
                temp[len+1] = '\0';
                if(search(root, temp)){
                    printf("%s\n", temp);
                }
            }
        }
    }
}

int main(){
    struct trie_node *root = (struct trie_node*)malloc(sizeof(struct trie_node));
    for(int i=0; i<26; i++){
        root->children[i] = NULL;
    }
    FILE *fp;
    char word[WORD_LENGTH];
    fp = fopen("dictionary.txt", "r");
    if(fp == NULL){
        printf("Error opening dictionary file");
        exit(1);
    }
    while(fscanf(fp, "%s", word) != EOF){
        insert(root, word);
    }
    fclose(fp);
    char input[WORD_LENGTH];
    while(1){
        printf("Enter a word to check spelling (type exit to quit): ");
        scanf("%s", input);
        if(strcmp(input, "exit") == 0){
            break;
        }
        check_spelling(root, input);
    }
    return 0;
}