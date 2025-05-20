//FormAI DATASET v1.0 Category: Text Summarizer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUMMARY_SIZE 500 // Maximum size of the summary
#define MAX_SENTENCE_SIZE 100 // Maximum size of a sentence
#define MAX_KEYWORDS 10 // Maximum number of keywords
#define MAX_FILE_SIZE 5000 // Maximum file size

int isKeyword(char *word, char **keywords, int numKeywords) {
    // Check if word is a keyword
    int i;
    for(i=0; i<numKeywords; i++) {
        if(strcmp(word, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    // Check if filename and keywords are provided
    if(argc < 3) {
        printf("Usage: ./summarizer <filename> <keyword1> <keyword2> ... <keywordN>\n");
        return 0;
    }

    char *filename = argv[1];
    char **keywords = (char **)malloc(sizeof(char *)*MAX_KEYWORDS);
    int numKeywords = argc-2;
    int i;
    for(i=0; i<numKeywords; i++) {
        keywords[i] = argv[i+2];
    }

    // Open file
    FILE *fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Could not open file: %s\n", filename);
        return 0;
    }

    // Read file contents
    char *fileData = (char *)malloc(sizeof(char)*MAX_FILE_SIZE);
    char *tempData = (char *)malloc(sizeof(char)*MAX_SENTENCE_SIZE);
    int fileSize = 0;
    while(fscanf(fp, "%s", tempData) != EOF) {
        if((fileSize+strlen(tempData)+1) > MAX_FILE_SIZE) {
            break;
        }
        strcat(fileData, tempData);
        strcat(fileData, " ");
        fileSize += strlen(tempData) + 1;
    }
    fclose(fp);

    // Tokenize fileData into sentences
    char **sentences = (char **)malloc(sizeof(char *)*MAX_FILE_SIZE);
    int numSentences = 0;
    tempData = strtok(fileData, ".");
    while(tempData != NULL) {
        sentences[numSentences] = (char *)malloc(sizeof(char)*MAX_SENTENCE_SIZE);
        strcpy(sentences[numSentences], tempData);
        numSentences++;
        tempData = strtok(NULL, ".");
    }

    // Find sentences with keywords
    int *sentenceIndex = (int *)malloc(sizeof(int)*numSentences);
    int numSelectedSentences = 0;
    for(i=0; i<numSentences; i++) {
        tempData = strtok(sentences[i], " ");
        while(tempData != NULL) {
            // Convert word to lowercase
            int j;
            for(j=0; j<strlen(tempData); j++) {
                tempData[j] = tolower(tempData[j]);
            }

            if(isKeyword(tempData, keywords, numKeywords)) {
                sentenceIndex[numSelectedSentences] = i;
                numSelectedSentences++;
                break;
            }
            tempData = strtok(NULL, " ");
        }
    }

    // Generate summary
    char *summary = (char *)malloc(sizeof(char)*MAX_SUMMARY_SIZE);
    summary[0] = '\0';
    for(i=0; i<numSelectedSentences; i++) {
        strcat(summary, sentences[sentenceIndex[i]]);
        strcat(summary, ".");
        if(strlen(summary) >= MAX_SUMMARY_SIZE) {
            break;
        }
    }

    // Print summary
    printf("%s\n", summary);

    // Free memory
    free(fileData);
    free(tempData);
    for(i=0; i<numSentences; i++) {
        free(sentences[i]);
    }
    free(sentences);
    free(keywords);
    free(sentenceIndex);
    free(summary);

    return 0;
}