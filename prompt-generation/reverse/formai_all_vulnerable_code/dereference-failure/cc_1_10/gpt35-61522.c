//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Ken Thompson
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_CHARS 1000000
#define MAX_LINES 10000

char* readFile(char* fileName) {

    FILE* fp;
    char* fileContent = (char*)malloc(sizeof(char) * MAX_CHARS);

    fp = fopen(fileName, "r");
    if(fp == NULL) {
        printf("Error opening file!");
        exit(1);
    }

    int index = 0;
    char currentChar = fgetc(fp);

    while(currentChar != EOF) {
        fileContent[index] = currentChar;
        index++;
        currentChar = fgetc(fp);
    }

    fileContent[index] = '\0';

    fclose(fp);

    return fileContent;
}

void tokenizeText(char* text, char tokens[][100]) {

    int i = 0, j = 0, k = 0;

    while(text[i] != '\0') {
        if(text[i] == '.' || text[i] == '?' || text[i] == '!') {
            tokens[j][k] = text[i];
            tokens[j][k+1] = '\0';
            j++;
            k = 0;
        } else {
            tokens[j][k] = text[i];
            k++;
        }
        i++;
    }
}

int getNumOfLines(char tokens[][100]) {

    int numLines = 0;
    for(int i=0; ; i++) {
        if(tokens[i][0] == '\0')
            break;

        numLines++;
    }

    return numLines;
}

int getLineIndex(char* line, char tokens[][100]) {

    int index = -1;
    for(int i=0; ; i++) {
        if(tokens[i][0] == '\0')
            break;

        if(strcmp(line, tokens[i]) == 0) {
            index = i;
            break;
        }
    }

    return index;
}

void printSummary(char tokens[][100], int numLines, int* lineScores, int numSentences) {

    int sentencesPrinted = 0;
    for(int i=0; i<numLines; i++) {
        if(lineScores[i] == 1) {
            printf("%s ", tokens[i]);
            sentencesPrinted++;
        }

        if(sentencesPrinted >= numSentences)
            break;
    }
}

void generateSummary(char tokens[][100], int numLines, int* lineScores, int numSentences) {

    int maxScore = 0;
    int maxScoreIndex = -1;

    for(int i=0; i<numSentences; i++) {
        for(int j=0; j<numLines; j++) {
            if(lineScores[j] == 0) {
                int score = 0;

                for(int k=0; k<numLines; k++) {
                    if(j == k)
                        continue;

                    int lineLength = strlen(tokens[k]);
                    char* tempLine = (char*)malloc(sizeof(char) * lineLength);
                    strcpy(tempLine, tokens[k]);

                    char* word = strtok(tempLine, " ");

                    while(word != NULL) {
                        if(strcmp(word, tokens[j]) == 0) {
                            score++;
                            break;
                        }
                        word = strtok(NULL, " ");
                    }

                    free(tempLine);
                }

                if(score > maxScore) {
                    maxScore = score;
                    maxScoreIndex = j;
                }
            }
        }

        lineScores[maxScoreIndex] = 1;
        maxScore = 0;
        maxScoreIndex = -1;
    }

    printSummary(tokens, numLines, lineScores, numSentences);
}

int main(int argc, char* argv[]) {

    if(argc != 3) {
        printf("Usage: ./summarize <input-file> <num-sentences>\n");
        exit(1);
    }

    char* fileName = argv[1];
    int numSentences = atoi(argv[2]);

    char* text = readFile(fileName);

    char tokens[MAX_LINES][100];
    tokenizeText(text, tokens);

    int numLines = getNumOfLines(tokens);

    int lineScores[MAX_LINES] = {0};

    generateSummary(tokens, numLines, lineScores, numSentences);

    return 0;
}