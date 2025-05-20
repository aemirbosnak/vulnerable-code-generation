//FormAI DATASET v1.0 Category: Text Summarizer ; Style: mind-bending
#include <stdio.h>
#include <string.h>

// Constants
#define MAX_PARAGRAPHS 100
#define MAX_LINES 50
#define MAX_CHARS 500
#define MAX_SUMMARY_CHARS 250

// Function to get input text from user
char* getInputText(char* prompt) {
    char* inputText = (char*) malloc(MAX_PARAGRAPHS * MAX_LINES * MAX_CHARS * sizeof(char));
    printf("%s", prompt);
    fgets(inputText, MAX_PARAGRAPHS * MAX_LINES * MAX_CHARS, stdin);
    return inputText;
}

// Function to split input text into sentences
void splitIntoSentences(char* inputText, char* sentenceArray[]) {
    int i = 0;
    sentenceArray[i] = strtok(inputText, ".?!");

    while (sentenceArray[i] != NULL) {
        i++;
        sentenceArray[i] = strtok(NULL, ".?!");
    }
}

// Function to calculate sentence scores
void calculateSentenceScores(char* sentenceArray[], float sentenceScores[], int numSentences) {
    int i, j;
    int sentenceLength, numWords;
    char* word;

    for (i = 0; i < numSentences; i++) {
        sentenceLength = strlen(sentenceArray[i]);
        numWords = 0;

        // Count number of words in sentence
        for (j = 0; j < sentenceLength; j++) {
            if (sentenceArray[i][j] == ' ') {
                numWords++;
            }
        }

        // Calculate sentence score
        sentenceScores[i] = (float) numWords / (float) sentenceLength;
    }
}

// Function to display the summary
void displaySummary(char* sentenceArray[], float sentenceScores[], int numSentences) {
    int i, j, summaryLength = 0;
    char summary[MAX_SUMMARY_CHARS] = "";
    float maxScore;
    int maxScoreIndex;

    for (i = 0; i < numSentences; i++) {
        maxScore = 0.0;

        // Find sentence with highest score
        for (j = 0; j < numSentences; j++) {
            if (sentenceScores[j] > maxScore) {
                maxScore = sentenceScores[j];
                maxScoreIndex = j;
            }
        }

        // Add sentence with highest score to summary
        strcat(summary, sentenceArray[maxScoreIndex]);
        strcat(summary, ". ");

        // Remove sentence with highest score from array
        sentenceScores[maxScoreIndex] = -1.0;

        // Update summary length
        summaryLength += strlen(sentenceArray[maxScoreIndex]);

        // If summary length exceeds maximum length, stop
        if (summaryLength > MAX_SUMMARY_CHARS) {
            break;
        }
    }

    // Print summary
    printf("Summary:\n%s\n", summary);
}

int main() {
    char* inputText;
    char* sentenceArray[MAX_PARAGRAPHS * MAX_LINES];
    float sentenceScores[MAX_PARAGRAPHS * MAX_LINES];
    int numSentences;

    // Get input text from user
    inputText = getInputText("Enter text:\n");

    // Split input text into sentences
    splitIntoSentences(inputText, sentenceArray);

    // Calculate sentence scores
    numSentences = sizeof(sentenceArray) / sizeof(sentenceArray[0]);
    calculateSentenceScores(sentenceArray, sentenceScores, numSentences);

    // Display summary
    displaySummary(sentenceArray, sentenceScores, numSentences);

    return 0;
}