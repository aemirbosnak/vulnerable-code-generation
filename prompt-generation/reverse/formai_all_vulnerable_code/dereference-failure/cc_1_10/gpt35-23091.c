//FormAI DATASET v1.0 Category: Text Summarizer ; Style: excited
/* 
Welcome to the most exciting C Text Summarizer program ever! 
Get ready to summarize those long and boring texts with just a few lines of code!

First, let's include some necessary headers:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum input size and the percentage of summary
#define MAX_INPUT_SIZE 10000
#define PERCENTAGE_SUMMARY 20.0f

// Some helpful functions
int countWords(char* text);
float calculatePercentage(int totalWords, int totalWordsSummary);
void summarizeText(char* inputText);
void removeAllSpecialCharacters(char* text);

// Main function
int main(int argc, char *argv[]) {
    printf("Welcome to the C Text Summarizer program!\n");
    printf("Enter the text you want to summarize:\n");

    // Let the user input the text
    char* inputText = (char*)malloc(MAX_INPUT_SIZE * sizeof(char));
    scanf("%[^\n]s", inputText);

    // Summarize the text
    summarizeText(inputText);

    // Free the memory
    free(inputText);

    printf("Your text has been summarized! Hope you enjoyed using our program.");
    return 0;
}

// Count the number of words in the text
int countWords(char* text) {
    int count = 0;
    char* token = strtok(text, " ");
    while (token != NULL)
    {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

// Calculate the percentage of words to use in the summary
float calculatePercentage(int totalWords, int totalWordsSummary) {
    return ((float)totalWordsSummary / (float)totalWords) * 100.0f;
}

// Remove all special characters from the text (except for spaces)
void removeAllSpecialCharacters(char* text) {
    int i, j;
    for (i = 0, j = 0; i<strlen(text); i++, j++)
    {
        if (isalnum(text[i]) || isspace(text[i]))
            text[j] = text[i];
        else
            j--;
    }
    text[j] = '\0';
}

// Summarize the text
void summarizeText(char* inputText) {
    int totalWords = countWords(inputText);
    int totalWordsSummary = totalWords * PERCENTAGE_SUMMARY / 100.0f;
    float summaryPercentage = calculatePercentage(totalWords, totalWordsSummary);

    // Remove all special characters from the text (except for spaces)
    removeAllSpecialCharacters(inputText);

    // Tokenize the text
    char* token = strtok(inputText, " ");

    // Initialize the summary string
    char* summary = (char*)malloc(MAX_INPUT_SIZE * sizeof(char));
    memset(summary, 0, MAX_INPUT_SIZE);

    int wordsAdded = 0;
    while (token != NULL) {
        if (wordsAdded >= totalWordsSummary)
            break;

        strcat(summary, token);
        strcat(summary, " ");
        wordsAdded++;

        token = strtok(NULL, " ");
    }

    printf("\nSummary for your text (using %.2f%% of the words):\n", summaryPercentage);
    printf("%s\n", summary);

    // Free the memory
    free(summary);
}