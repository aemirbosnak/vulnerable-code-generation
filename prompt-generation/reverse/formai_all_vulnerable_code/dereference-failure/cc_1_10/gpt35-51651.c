//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This is the struct containing the values of word and its frequency
typedef struct {
    char *word;
    int count;
} WordFreq;

// This is the function to sort the word frequency list based on count
void sortList(WordFreq **list, int len) {
    int i, j;
    WordFreq *temp = NULL;
    for(i = 0; i < len; i++) {
        for(j = i+1; j < len; j++) {
            if((*list)[i].count < (*list)[j].count) {
                temp = (WordFreq *)malloc(sizeof(WordFreq));
                temp->word = (*list)[i].word;
                temp->count = (*list)[i].count;

                (*list)[i].word = (*list)[j].word;
                (*list)[i].count = (*list)[j].count;

                (*list)[j].word = temp->word;
                (*list)[j].count = temp->count;

                free(temp);
            }
        }
    }
}

// This is the function to check whether a word is valid or not
int isValidWord(char *str) {
    int len = strlen(str);
    int i;
    for(i = 0; i < len; i++) {
        if(!isalpha(str[i])) {
            return 0;
        }
    }
    return 1;
}

// This is the main function
int main(int argc, char *argv[]) {
    char *filepath = NULL;
    int numWords = 10; // Default number of words to display
    int i;

    // Checking the command line arguments
    for(i = 1; i < argc; i++) {
        if(!strcmp(argv[i], "-n")) {
            i++;
            numWords = atoi(argv[i]);
        } else {
            filepath = argv[i];
        }
    }

    // Checking if filepath is provided
    if(filepath == NULL) {
        printf("Error: Please provide filepath\n");
        return 0;
    }

    // Opening file
    FILE *fp = fopen(filepath, "r");
    if(fp == NULL) {
        printf("Error: File not found\n");
        return 0;
    }

    WordFreq *wordFreqList = NULL;
    int numWordsFreqList = 0, isWordExist = 0;
    char *tempStr = (char *)malloc(sizeof(char) * 50);
    while(fscanf(fp, "%s", tempStr) == 1) {
        if(isValidWord(tempStr)) {
            // Looping through the word frequency list to check if the word already exist
            for(i = 0; i < numWordsFreqList; i++) {
                if(!strcmp(wordFreqList[i].word, tempStr)) {
                    isWordExist = 1;
                    wordFreqList[i].count++;
                    break;
                }
            }

            if(!isWordExist) {
                // Increasing capacity of the word frequency list if needed
                if(numWordsFreqList == 0) {
                    wordFreqList = (WordFreq *)malloc(sizeof(WordFreq));
                } else {
                    wordFreqList = (WordFreq *)realloc(wordFreqList, sizeof(WordFreq) * (numWordsFreqList+1));
                }

                // Adding new word and its frequency
                wordFreqList[numWordsFreqList].word = (char *)malloc(sizeof(char) * strlen(tempStr));
                strcpy(wordFreqList[numWordsFreqList].word, tempStr);
                wordFreqList[numWordsFreqList].count = 1;
                numWordsFreqList++;
            }

            isWordExist = 0;
        }
    }

    // Sorting the word frequency list
    sortList(&wordFreqList, numWordsFreqList);

    // Printing the word frequency list
    for(i = 0; i < numWords && i < numWordsFreqList; i++) {
        printf("%d. %-15s %5d\n", i+1, wordFreqList[i].word, wordFreqList[i].count);
    }

    // Closing file and freeing memory
    fclose(fp);
    free(tempStr);
    for(i = 0; i < numWordsFreqList; i++) {
        free(wordFreqList[i].word);
    }
    free(wordFreqList);

    return 0;
}