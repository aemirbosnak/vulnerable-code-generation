//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// define the maximum word length and total number of words
#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 1000

// function to count the frequency of each word
void count_frequency(char** words, int* freq, int n)
{
    // initialize the frequency counts to zero
    for(int i=0; i<n; i++){
        freq[i] = 0;
    }

    // count the occurrences of each word
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(strcmp(words[i], words[j]) == 0){
                freq[i]++;
            }
        }
    }
}

int main(int argc, char* argv[])
{
    // check if the user has provided a filename as an argument
    if(argc < 2){
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    // open the file for reading
    FILE* fp = fopen(argv[1], "r");
    if(fp == NULL){
        printf("Error opening file.\n");
        return 1;
    }

    // allocate memory for the words and frequency arrays
    char** words = (char**)malloc(MAX_NUM_WORDS * sizeof(char*));
    int* freq = (int*)malloc(MAX_NUM_WORDS * sizeof(int));

    // initialize the words array to NULL
    for(int i=0; i<MAX_NUM_WORDS; i++){
        words[i] = NULL;
    }

    // read the words from the file
    char buffer[MAX_WORD_LENGTH];
    int n = 0;
    while(fscanf(fp, "%s", buffer) != EOF){
        // remove any punctuation from the word
        int len = strlen(buffer);
        for(int i=0; i<len; i++){
            if(!isalpha(buffer[i])){
                buffer[i] = ' ';
            }
            else{
                buffer[i] = tolower(buffer[i]);
            }
        }

        // tokenize the word and add it to the words array
        char* token = strtok(buffer, " ");
        while(token != NULL){
            words[n] = (char*)malloc((strlen(token)+1) * sizeof(char));
            strcpy(words[n], token);
            n++;

            token = strtok(NULL, " ");
        }
    }

    // count the frequency of each word
    count_frequency(words, freq, n);

    // print out the results
    for(int i=0; i<n; i++){
        if(words[i] != NULL && freq[i] > 0){
            printf("%s: %d\n", words[i], freq[i]);
        }
    }

    // free the memory allocated for the words and frequency arrays
    for(int i=0; i<MAX_NUM_WORDS; i++){
        if(words[i] != NULL){
            free(words[i]);
        }
    }
    free(words);
    free(freq);

    // close the file
    fclose(fp);

    // success!
    return 0;
}