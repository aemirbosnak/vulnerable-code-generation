//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 100
#define SUMMARY_LENGTH 3

typedef struct {
    char **words;
    int count;
} WordList;

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int isSpecialChar(char c) {
    return !(isalpha(c) || isdigit(c));
}

WordList extractWords(const char *text) {
    WordList wordList;
    wordList.words = malloc(MAX_WORDS * sizeof(char *));
    wordList.count = 0;

    char *textCopy = strdup(text);
    char *token = strtok(textCopy, " ");
    
    while (token != NULL && wordList.count < MAX_WORDS) {
        toLowerCase(token);
        
        // Remove special characters
        int len = strlen(token);
        for (int j = 0; j < len; j++) {
            if (isSpecialChar(token[j])) {
                token[j] = '\0';
            }
        }

        if (strlen(token) > 0) {
            wordList.words[wordList.count] = strdup(token);
            wordList.count++;
        }
        token = strtok(NULL, " ");
    }

    free(textCopy);
    return wordList;
}

void freeWordList(WordList *wordList) {
    for (int i = 0; i < wordList->count; i++) {
        free(wordList->words[i]);
    }
    free(wordList->words);
}

void printSummary(const char **summary, int count) {
    printf("Here's your cheerful summary!\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", summary[i]);
    }
}

void createSummary(WordList *wordList, const char *text) {
    char *summary[SUMMARY_LENGTH];
    int summaryCount = 0;

    for (int i = 0; i < wordList->count; i++) {
        if (summaryCount < SUMMARY_LENGTH) {
            summary[summaryCount++] = wordList->words[i];
        }
    }
    
    printSummary((const char **)summary, summaryCount);
}

int main() {
    printf("🎉 Welcome to the Happy Text Summarizer! 🎉\n");
    printf("Please enter some joyful text (feel free to use punctuation and special characters!):\n");

    char inputText[1024];
    fgets(inputText, sizeof(inputText), stdin);

    WordList wordList = extractWords(inputText);
    createSummary(&wordList, inputText);

    freeWordList(&wordList);
    printf("\n😄 Thank you for using the Happy Text Summarizer! 🎈 Have a great day!\n");

    return 0;
}