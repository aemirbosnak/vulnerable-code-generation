//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to extract keywords from a sentence
char** extractKeywords(char* sentence, int* numKeywords) {
    char* token;
    char** keywords = NULL;
    int keywordCount = 0;

    // Tokenize the sentence into individual words
    token = strtok(sentence, " ");
    while (token != NULL) {
        // Check if the word is a keyword
        if (strlen(token) > 2 && !strchr(token, ',')) {
            // Add the word to the array of keywords
            keywords = realloc(keywords, sizeof(char*) * (keywordCount + 1));
            keywords[keywordCount] = strdup(token);
            keywordCount++;
        }

        // Get the next token
        token = strtok(NULL, " ");
    }

    *numKeywords = keywordCount;
    return keywords;
}

// Function to calculate the frequency of each keyword in a document
int* calculateKeywordFrequencies(char** keywords, int numKeywords, char* document) {
    int* frequencies = calloc(numKeywords, sizeof(int));

    // Iterate over the document and count the frequency of each keyword
    char* token;
    token = strtok(document, " ");
    while (token != NULL) {
        for (int i = 0; i < numKeywords; i++) {
            if (strcmp(token, keywords[i]) == 0) {
                frequencies[i]++;
            }
        }

        // Get the next token
        token = strtok(NULL, " ");
    }

    return frequencies;
}

// Function to generate a summary of the document
char* generateSummary(char* document, int numKeywords, char** keywords, int* frequencies) {
    // Sort the keywords by frequency in descending order
    for (int i = 0; i < numKeywords - 1; i++) {
        for (int j = i + 1; j < numKeywords; j++) {
            if (frequencies[i] < frequencies[j]) {
                int temp = frequencies[i];
                frequencies[i] = frequencies[j];
                frequencies[j] = temp;

                char* tempKeyword = keywords[i];
                keywords[i] = keywords[j];
                keywords[j] = tempKeyword;
            }
        }
    }

    // Generate the summary
    char* summary = malloc(sizeof(char) * 500);
    strcpy(summary, "");

    int numSentences = 0;
    char* token;
    token = strtok(document, ".");
    while (token != NULL && numSentences < 3) {
        // Check if the sentence contains any of the top keywords
        int containsKeyword = 0;
        for (int i = 0; i < numKeywords; i++) {
            if (strstr(token, keywords[i]) != NULL) {
                containsKeyword = 1;
                break;
            }
        }

        // If the sentence contains a keyword, add it to the summary
        if (containsKeyword) {
            strcat(summary, token);
            strcat(summary, ". ");
            numSentences++;
        }

        // Get the next sentence
        token = strtok(NULL, ".");
    }

    return summary;
}

int main() {
    // Get the input document from the user
    char* document = malloc(sizeof(char) * 1000);
    printf("Enter the document: ");
    fgets(document, 1000, stdin);

    // Extract the keywords from the document
    int numKeywords;
    char** keywords = extractKeywords(document, &numKeywords);

    // Calculate the frequency of each keyword in the document
    int* frequencies = calculateKeywordFrequencies(keywords, numKeywords, document);

    // Generate a summary of the document
    char* summary = generateSummary(document, numKeywords, keywords, frequencies);

    // Print the summary
    printf("Summary: %s", summary);

    // Free the allocated memory
    free(document);
    for (int i = 0; i < numKeywords; i++) {
        free(keywords[i]);
    }
    free(keywords);
    free(frequencies);
    free(summary);

    return 0;
}