//FormAI DATASET v1.0 Category: Text Summarizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_WORD_LENGTH 50

void readText(char *text, int len);
int getWordCount(char *text);
int getSentencesCount(char *text);
int tokenize(char *text, char tokens[][MAX_WORD_LENGTH], char delimeter);
void createSummary(char *text, char summary[][MAX_WORD_LENGTH], int summarySize, int wordCount, int sentenceCount, char *tokens[MAX_SENTENCES][MAX_WORD_LENGTH]);

int main() {
    char text[1000];
    printf("Enter Text:\n");
    readText(text, 1000);

    int wordCount = getWordCount(text);
    printf("Words in Text: %d\n", wordCount);

    int sentenceCount = getSentencesCount(text);
    printf("Sentences in Text: %d\n", sentenceCount);

    char tokens[MAX_SENTENCES][MAX_WORD_LENGTH];
    int sentenceStartIndexes[MAX_SENTENCES];
    int sentenceCountIndex = tokenize(text, tokens, '.');
    for (int i=0; i<sentenceCountIndex; i++) {
        sentenceStartIndexes[i] = i;
    }

    // sort sentences based on their length
    for (int i=0;i<sentenceCountIndex;i++) {
        int sentenceLength = strlen(tokens[i]);
        for (int j=i+1;j<sentenceCountIndex;j++) {
            int currentSentenceLength = strlen(tokens[j]);
            if (currentSentenceLength > sentenceLength) {
                char temp[MAX_WORD_LENGTH];
                int tempIndex = sentenceStartIndexes[i];

                sentenceStartIndexes[i] = sentenceStartIndexes[j];
                sentenceStartIndexes[j] = tempIndex;

                strcpy(temp, tokens[i]);
                strcpy(tokens[i], tokens[j]);
                strcpy(tokens[j], temp);

                sentenceLength = strlen(tokens[i]);
            }
        }
    }

    // create summary
    char summary[MAX_SENTENCES][MAX_WORD_LENGTH];
    createSummary(text, summary, 3, wordCount, sentenceCount, (char (*)[])tokens);
    printf("Summary:\n");
    for (int i=0; i<3; i++) {
        printf("%s. ", summary[i]);
    }
    printf("\n");

    return 0;
}

void readText(char *text, int len) {
    int i=0;
    char c;
    while ((c=getchar()) != '\n' && i<len) {
        text[i++] = c;
    }
    text[i] = '\0';
}

int getWordCount(char *text) {
    int wordCount = 0;
    while (*text != '\0') {
        if (*text == ' ') {
            wordCount++;
        }
        text++;
    }
    return wordCount + 1;
}

int getSentencesCount(char *text) {
    int sentenceCount = 0;
    while (*text != '\0') {
        if (*text == '.' || *text == '?' || *text == '!') {
            sentenceCount++;
        }
        text++;
    }
    return sentenceCount;
}

int tokenize(char *text, char tokens[][MAX_WORD_LENGTH], char delimeter) {
    int currentTokenIndex = 0;
    int currentTokenLength = 0;
    while (*text != '\0') {
        if (*text == delimeter) {
            currentTokenLength = 0;
            currentTokenIndex++;
        } else if (*text == '\n') {
            break;
        } else {
            tokens[currentTokenIndex][currentTokenLength++] = *text;
        }
        text++;
    }
    return currentTokenIndex + 1;
}

void createSummary(char *text, char summary[][MAX_WORD_LENGTH], int summarySize, int wordCount, int sentenceCount, char *tokens[MAX_SENTENCES][MAX_WORD_LENGTH]) {
    int sentenceIndexesToInclude[3];
    for (int i=0; i<summarySize; i++) {
        int maxWordCount = 0;
        for (int j=0; j<sentenceCount; j++) {
            int length = strlen(tokens[j]);
            if (length > maxWordCount && !strstr(text, summary[j])) {
                maxWordCount = length;
                sentenceIndexesToInclude[i] = j;
            }
        }
        strcpy(summary[i], tokens[sentenceIndexesToInclude[i]]);
    }
}