//FormAI DATASET v1.0 Category: Text Summarizer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getWordCount(char *str) {
    int wordCount = 0, i = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            wordCount++;
        }
        i++;
    }
    wordCount++;
    return wordCount;
}

void summarize(char *str, int summarySize) {
    int wordCount = getWordCount(str);
    int sentenceCount = 0, i = 0;
    char *temp = malloc(sizeof(char) * strlen(str) + 1);
    char *tempWord;
    strcpy(temp, str);
    printf("Generating summary...\n\n");

    while (i < strlen(temp)) {
        if (temp[i] == '.') {
            sentenceCount++;
        }
        i++;
    }

    int wordsPerSentence = (wordCount / sentenceCount);

    tempWord = strtok(temp, " \n\t");
    i = 1;

    while (tempWord != NULL) {
        printf("%s ", tempWord);
        if (i % wordsPerSentence == 0) {
            printf(".\n\n");
        }
        tempWord = strtok(NULL, " \n\t");
        i++;
    }

    free(temp);
}

int main() {
    char str[1000];
    int summarySize;
    printf("Enter a text to summarize: ");
    fgets(str, sizeof(str), stdin);
    printf("Enter summary size in sentences: ");
    scanf("%d", &summarySize);
    printf("\n");
    summarize(str, summarySize);
    return 0;
}