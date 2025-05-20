//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_SENTENCES 1000

typedef struct {
    char *text;
    int length;
} Sentence;

int main(int argc, char *argv[]) {
    FILE *inputFile;
    char inputText[1000000];
    int inputLength;
    Sentence sentences[MAX_SENTENCES];
    int numSentences = 0;

    inputFile = fopen("input.txt", "r");

    if(inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    inputLength = fread(inputText, 1, sizeof(inputText), inputFile);

    fclose(inputFile);

    char *token = strtok(inputText, ".?!");

    while(token!= NULL) {
        if(numSentences >= MAX_SENTENCES) {
            printf("Maximum number of sentences reached.\n");
            break;
        }

        int sentenceLength = strlen(token);

        if(sentenceLength > MAX_SENTENCE_LENGTH) {
            printf("Sentence too long.\n");
            break;
        }

        sentences[numSentences].text = malloc(sentenceLength + 1);
        strcpy(sentences[numSentences].text, token);
        sentences[numSentences].length = sentenceLength;

        numSentences++;

        token = strtok(NULL, ".?!");
    }

    printf("Number of sentences: %d\n", numSentences);

    for(int i = 0; i < numSentences; i++) {
        printf("Sentence %d: %s\n", i+1, sentences[i].text);
    }

    for(int i = 0; i < numSentences; i++) {
        free(sentences[i].text);
    }

    return 0;
}