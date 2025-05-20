//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORD_COUNT 10000

typedef struct {
    char word[MAX_WORD_LENGTH+1];
    int count;
} WordCount;

int compareWordCounts(const void *a, const void *b) {
    return ((WordCount*)b)->count - ((WordCount*)a)->count;
}

void printWordCounts(WordCount *wordCounts, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s : %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main() {
    //Allocate memory for word counts
    WordCount *wordCounts = malloc(sizeof(WordCount) * MAX_WORD_COUNT);
    int wordCountIndex = 0;
    
    //Open file and error check
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    
    char buffer[MAX_WORD_LENGTH+1];
    while(fscanf(file, "%s", buffer) == 1) {
        //Make word lowercase
        for (int i = 0; buffer[i]; i++) {
            buffer[i] = tolower(buffer[i]);
        }
        
        //Remove any non-alphabetic characters from word
        int len = strlen(buffer);
        int destIndex = 0;
        for (int i = 0; i < len; i++) {
            if (isalpha(buffer[i])) {
                buffer[destIndex++] = buffer[i];
            }
        }
        buffer[destIndex] = '\0';
        len = destIndex;
        
        //Check if word is too long or short, ignore if true
        if (len <= 1 || len > MAX_WORD_LENGTH) continue;
        
        //Check if word has already been counted, increment count if true
        int found = 0;
        for (int i = 0; i < wordCountIndex; i++) {
            if (strcmp(wordCounts[i].word, buffer) == 0) {
                wordCounts[i].count++;
                found = 1;
                break;
            }
        }
        
        //Add word to wordCounts if not found
        if (!found) {
            strcpy(wordCounts[wordCountIndex].word, buffer);
            wordCounts[wordCountIndex].count = 1;
            wordCountIndex++;
        }
        
        //Check if wordCounts is full, exit if true
        if (wordCountIndex == MAX_WORD_COUNT) {
            printf("Error: Maximum word count reached\n");
            return 1;
        }
    }
    
    //Close file
    fclose(file);
    
    //Sort and print wordCounts
    qsort(wordCounts, wordCountIndex, sizeof(WordCount), compareWordCounts);
    printWordCounts(wordCounts, wordCountIndex);
    
    //Free allocated memory and exit
    free(wordCounts);
    return 0;
}