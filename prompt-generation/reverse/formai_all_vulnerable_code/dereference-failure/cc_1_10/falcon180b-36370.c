//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 10000

typedef struct wordFrequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

typedef struct index {
    WordFrequency *words;
    int numWords;
} Index;

Index *createIndex() {
    Index *index = (Index *)malloc(sizeof(Index));
    index->words = (WordFrequency *)malloc(MAX_NUM_WORDS * sizeof(WordFrequency));
    index->numWords = 0;
    return index;
}

void addWordToIndex(Index *index, char *word) {
    int i = 0;
    while(i < index->numWords && strcasecmp(index->words[i].word, word)!= 0) {
        i++;
    }
    if(i == index->numWords) {
        if(index->numWords == MAX_NUM_WORDS) {
            printf("Error: Index is full.\n");
            return;
        }
        index->words[index->numWords].word[0] = tolower(word[0]);
        strcpy(&(index->words[index->numWords].word[1]), word);
        index->words[index->numWords].frequency = 1;
        index->numWords++;
    } else {
        index->words[i].frequency++;
    }
}

void printIndex(Index *index) {
    for(int i = 0; i < index->numWords; i++) {
        printf("%s: %d\n", index->words[i].word, index->words[i].frequency);
    }
}

int main() {
    Index *index = createIndex();
    char word[MAX_WORD_LENGTH];
    while(fgets(word, MAX_WORD_LENGTH, stdin)!= NULL) {
        addWordToIndex(index, word);
    }
    printIndex(index);
    return 0;
}