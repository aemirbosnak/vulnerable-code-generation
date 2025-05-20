//FormAI DATASET v1.0 Category: Text Summarizer ; Style: safe
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 1000
#define MAX_WORD 100

/*
 This program takes an input from the user and then
 summarize it in a few lines.
*/

/*The following function removes the punctuations from the text*/
void remove_punctuations(char* text){
    char punctuations[] = ",.:;?!";
    for(int i=0; i<strlen(text); i++){
        for(int j=0; j<strlen(punctuations); j++){
            if(text[i]==punctuations[j]){
                text[i] = ' ';
            }
        }
    }
}

/*This function creates a hashmap for the words in the text.*/
void create_word_map(char* text, int* word_map, char** words){
    char* token = strtok(text, " ");
    int count = 0;
    while(token!=NULL){
        words[count] = (char*)malloc(MAX_WORD*sizeof(char));
        strcpy(words[count], token);
        word_map[count] = 1;
        token = strtok(NULL, " ");
        count++;
    }
}

/*This function summarizes the text*/
void summarize_text(char* text){
    int word_map[MAX];
    char* words[MAX];
    //Remove punctuations
    remove_punctuations(text);
    //Create hashmap for the words
    create_word_map(text, word_map, words);
    //Calculate frequency of the words
    for(int i=0; i<MAX; i++){
        if(word_map[i]==1){
            int frequency = 1;
            for(int j=i+1; j<MAX; j++){
                if(word_map[j]==1 && strcmp(words[i], words[j])==0){
                    frequency++;
                    word_map[j] = 0;
                }
            }
            printf("%s - %d\n", words[i], frequency);
        }
     }
}

/*Driver function*/
int main(){
    char text[MAX];
    printf("Enter the text you want to summarize:\n");
    fgets(text, MAX, stdin);
    printf("Summary:\n");
    summarize_text(text);
    return 0;
}