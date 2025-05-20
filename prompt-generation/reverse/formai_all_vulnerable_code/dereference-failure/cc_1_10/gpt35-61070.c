//FormAI DATASET v1.0 Category: Text Summarizer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCES 100
#define MAX_SENTENCE_LENGTH 200

char* removePunctuation(char*);

int main() {
    char article[MAX_SENTENCES][MAX_SENTENCE_LENGTH];
    char *sentences[MAX_SENTENCES];
    int numSentences = 0;
    char summary[500] = "";

    printf("Enter article (max %d sentences): \n", MAX_SENTENCES);
    for(int i = 0; i < MAX_SENTENCES; i++) {
        fgets(article[i], sizeof(article[i]), stdin);
        if(article[i][0] == '\n') break;
        sentences[i] = malloc(strlen(article[i]) + 1);
        memcpy(sentences[i], article[i], strlen(article[i]) + 1);
        numSentences++;
    }

    for(int i = 0; i < numSentences; i++) {
        sentences[i] = removePunctuation(sentences[i]);
    }

    int maxWords = numSentences * 10;
    char **words = malloc(maxWords * sizeof(char*));
    int countWords = 0;

    for(int i = 0; i < numSentences; i++) {
        char* sentence = sentences[i];
        char* word = strtok(sentence, " ");
        while(word != NULL) {
            if(countWords < maxWords) {
                words[countWords] = word;
                countWords++;
            }
            word = strtok(NULL, " ");
        }
    }

    int summaryWords = 0;
    for(int i = 0; i < countWords; i++) {
        strcat(summary, words[i]);
        strcat(summary, " ");
        summaryWords++;
        if(summaryWords >= 40) break;
    }

    printf("\nSummary:\n%s\n", summary);
    return 0;
}

char* removePunctuation(char* sentence) {
    int len = strlen(sentence);
    int i, j = 0;
    char* newSentence = malloc(len * sizeof(char));
    for(i = 0; i < len; i++) {
        if(ispunct(sentence[i])) continue;
        newSentence[j] = tolower(sentence[i]);
        j++;
    }
    newSentence[j] = '\0';
    return newSentence;
}