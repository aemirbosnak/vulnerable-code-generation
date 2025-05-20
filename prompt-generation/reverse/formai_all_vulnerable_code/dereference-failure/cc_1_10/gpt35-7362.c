//FormAI DATASET v1.0 Category: Text Summarizer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 1000
#define MAX_SENTENCES 100

void removeNewLine(char *string) {
    int len = strlen(string);
    if(string[len-1] == '\n') {
        string[len-1] = '\0';
    }
}

int isEndOfSentence(char c) {
    return c == '.' || c == '?' || c == '!';
}

int countWords(char *sentence) {
    int words = 0;
    char *p = sentence;
    while(*p) {
        while(isspace(*p)) {
            p++;
        }
        if(*p) {
            words++;
        }
        while(*p && !isspace(*p)) {
            p++;
        }
    }
    return words;
}

void summarize(char *text) {
    char *sentences[MAX_SENTENCES];
    char sentence[MAX_STRING_LENGTH];
    int numSentences = 0;
    int numWords = 0;
    int i;

    // Parse input text and extract sentences
    char *p = text;
    while(*p) {
        char c = *p;
        sentence[numWords] = c;
        numWords++;
        if(isEndOfSentence(c)) {
            sentence[numWords] = '\0';
            sentences[numSentences] = malloc(numWords+1);
            strcpy(sentences[numSentences], sentence);
            numSentences++;
            numWords = 0;
        }
        p++;
    }

    // Sort sentences by length using insertion sort algorithm
    for(i = 1; i < numSentences; i++) {
        char *key = sentences[i];
        int j = i - 1;
        while(j >= 0 && strlen(sentences[j]) < strlen(key)) {
            sentences[j+1] = sentences[j];
            j--;
        }
        sentences[j+1] = key;
    }

    // Output top 3 sentences
    printf("Top sentences:\n");
    for(i = 0; i < 3 && i < numSentences; i++) {
        printf("%s\n", sentences[i]);
    }

    // Free allocated memory
    for(i = 0; i < numSentences; i++) {
        free(sentences[i]);
    }
}

int main(void) {
    char text[MAX_STRING_LENGTH];
    printf("Enter text to summarize:\n");
    fgets(text, MAX_STRING_LENGTH, stdin);
    removeNewLine(text);
    summarize(text);
    return 0;
}