//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to remove stop words from a string
char* removeStopWords(char* str) {
    char* stopWords[] = {"a", "an", "the", "and", "or", "but", "for", "nor", "as", "at", "by", "from", "in", "into", "of", "on", "to", "with"};
    int numStopWords = sizeof(stopWords) / sizeof(char*);

    char* newStr = malloc(strlen(str) + 1);
    int newStrLen = 0;

    char* word = strtok(str, " ");
    while (word != NULL) {
        int isStopWord = 0;
        for (int i = 0; i < numStopWords; i++) {
            if (strcmp(word, stopWords[i]) == 0) {
                isStopWord = 1;
                break;
            }
        }
        if (!isStopWord) {
            strcpy(newStr + newStrLen, word);
            newStrLen += strlen(word);
            newStr[newStrLen++] = ' ';
        }
        word = strtok(NULL, " ");
    }

    newStr[newStrLen] = '\0';
    return newStr;
}

// Function to summarize a text
char* summarizeText(char* text) {
    // Remove stop words from the text
    char* noStopWordsText = removeStopWords(text);

    // Split the text into sentences
    char** sentences = malloc(sizeof(char*) * 100);
    int numSentences = 0;

    char* sentence = strtok(noStopWordsText, ".");
    while (sentence != NULL) {
        sentences[numSentences++] = sentence;
        sentence = strtok(NULL, ".");
    }

    // Find the most important sentence in the text
    int mostImportantSentenceIndex = 0;
    int maxScore = 0;

    for (int i = 0; i < numSentences; i++) {
        int score = 0;
        char* word = strtok(sentences[i], " ");
        while (word != NULL) {
            if (strlen(word) > 3) {
                score++;
            }
            word = strtok(NULL, " ");
        }
        if (score > maxScore) {
            maxScore = score;
            mostImportantSentenceIndex = i;
        }
    }

    // Return the most important sentence as the summary
    return sentences[mostImportantSentenceIndex];
}

int main() {
    // Get the text from the user
    char* text = malloc(1000);
    printf("Enter the text: ");
    gets(text);

    // Summarize the text
    char* summary = summarizeText(text);

    // Print the summary
    printf("Summary: %s", summary);

    return 0;
}