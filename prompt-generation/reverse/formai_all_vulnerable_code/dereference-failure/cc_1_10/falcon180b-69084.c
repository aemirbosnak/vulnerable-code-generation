//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH+1];
    int count;
} WordCount;

WordCount words[MAX_WORDS];
int numWords = 0;

void addWord(char* word) {
    int i;
    for(i=0; i<numWords; i++) {
        if(strcmp(words[i].word, word) == 0) {
            words[i].count++;
            return;
        }
    }
    if(numWords >= MAX_WORDS) {
        printf("Error: Maximum number of words reached.\n");
        exit(1);
    }
    strcpy(words[numWords].word, word);
    words[numWords].count = 1;
    numWords++;
}

void printWords(FILE* fp) {
    int i;
    for(i=0; i<numWords; i++) {
        fprintf(fp, "%s %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char* argv[]) {
    FILE* fp;
    char line[1024];
    char word[MAX_WORD_LENGTH+1];
    int inWord = 0;
    int wordLen = 0;
    int i;

    if(argc!= 3) {
        printf("Usage: spellcheck input_file output_file\n");
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if(fp == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    fp = fopen(argv[2], "w");
    if(fp == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    while(fgets(line, sizeof(line), fp)!= NULL) {
        int len = strlen(line);
        for(i=0; i<len; i++) {
            if(isalpha(line[i])) {
                if(!inWord) {
                    inWord = 1;
                    strncpy(word, &line[i], MAX_WORD_LENGTH);
                    word[MAX_WORD_LENGTH] = '\0';
                    wordLen = strlen(word);
                } else {
                    strcat(word, &line[i]);
                    if(wordLen >= MAX_WORD_LENGTH) {
                        inWord = 0;
                        addWord(word);
                        wordLen = 0;
                    }
                }
            } else {
                inWord = 0;
                if(wordLen > 0) {
                    addWord(word);
                    wordLen = 0;
                }
            }
        }
        if(inWord) {
            addWord(word);
        }
    }

    if(inWord) {
        addWord(word);
    }

    printWords(fp);

    fclose(fp);

    return 0;
}