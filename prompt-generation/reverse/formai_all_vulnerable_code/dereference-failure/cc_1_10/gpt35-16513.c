//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1000

struct WordFreq {
    char* word;
    int freq;
};

void countWordFreq(char* line, struct WordFreq* words, int* numWords);
void sortWordsByFreq(struct WordFreq* words, int numWords);
void printWordFreq(struct WordFreq* words, int numWords);

int main() {
    char line[MAX_LINE_LENGTH];
    struct WordFreq words[MAX_LINE_LENGTH];
    int numWords = 0;
    
    printf("Enter some text: \n");
    while(fgets(line, MAX_LINE_LENGTH, stdin) != NULL) {
        countWordFreq(line, words, &numWords);
    }
    
    sortWordsByFreq(words, numWords);
    printf("\nWord Frequency Count:\n");
    printWordFreq(words, numWords);
    
    return 0;
}

void countWordFreq(char* line, struct WordFreq* words, int* numWords) {
    char* word;
    char* savePtr = NULL;
    char delim[] = " \n\t.,;:!?'\"(){}[]<>";
    
    word = strtok_r(line, delim, &savePtr);
    while(word != NULL) {
        int i, match = 0;
        for(i = 0; i < *numWords; i++) {
            if(strcmp(word, words[i].word) == 0) {
                words[i].freq++;
                match = 1;
                break;
            }
        }
        if(!match) {
            words[*numWords].word = (char*) malloc(strlen(word)+1);
            strcpy(words[*numWords].word, word);
            words[*numWords].freq = 1;
            (*numWords)++;
        }
        word = strtok_r(NULL, delim, &savePtr);
    }
}

void sortWordsByFreq(struct WordFreq* words, int numWords) {
    int i, j;
    struct WordFreq temp;
    
    for(i = 0; i < numWords-1; i++) {
        for(j = i+1; j < numWords; j++) {
            if(words[i].freq < words[j].freq) {
                temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

void printWordFreq(struct WordFreq* words, int numWords) {
    int i;
    for(i = 0; i < numWords; i++) {
        printf("%-20s %d\n", words[i].word, words[i].freq);
        free(words[i].word);
    }
}