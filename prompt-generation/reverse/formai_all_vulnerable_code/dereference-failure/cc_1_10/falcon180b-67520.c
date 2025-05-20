//Falcon-180B DATASET v1.0 Category: File handling ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_LINE_SIZE 1000
#define MAX_WORD_SIZE 50

typedef struct {
    char word[MAX_WORD_SIZE];
    int count;
} WordCount;

int compare(const void* a, const void* b) {
    WordCount* p = (WordCount*)a;
    WordCount* q = (WordCount*)b;

    if (p->count > q->count)
        return -1;
    else if (p->count < q->count)
        return 1;
    else
        return 0;
}

int main() {
    FILE* inputFile = NULL;
    FILE* outputFile = NULL;
    char line[MAX_LINE_SIZE];
    WordCount words[1000];
    int numWords = 0;
    int i;
    char* token;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    // Read input file
    while (fgets(line, MAX_LINE_SIZE, inputFile)!= NULL) {
        numWords = 0;
        token = strtok(line, ",.?!:;\"'()[]{}<>");
        while (token!= NULL) {
            strcpy(words[numWords].word, token);
            words[numWords].count = 1;
            numWords++;
            token = strtok(NULL, ",.?!:;\"'()[]{}<>");
        }

        // Sort words by frequency
        qsort(words, numWords, sizeof(WordCount), compare);

        // Write sorted words to output file
        for (i = 0; i < numWords; i++) {
            fprintf(outputFile, "%s %d\n", words[i].word, words[i].count);
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}