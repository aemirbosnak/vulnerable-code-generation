//FormAI DATASET v1.0 Category: Text Summarizer ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 1000
#define MAX_SUMMARY_LENGTH 100

// This function extracts the first sentence from a given paragraph
char* extractFirstSentence(char* paragraph) {
    char* sentence = (char*) malloc(MAX_STRING_LENGTH * sizeof(char));
    int i = 0, j = 0, flag = 0;

    // Iterate over each character of the paragraph
    while (paragraph[i] != '\0') {
        // Check if the current character is a punctuation mark
        if (paragraph[i] == '.' || paragraph[i] == '?' || paragraph[i] == '!') {
            // Check if the next character is a space or a new line
            if (paragraph[i + 1] == ' ' || paragraph[i + 1] == '\n') {
                // Set the flag to indicate that the first sentence has been found
                flag = 1;
                // Add the punctuation mark to the sentence
                sentence[j++] = paragraph[i++];
                // Add a null terminator to the sentence
                sentence[j++] = '\0';
                break;
            }
        }
        // Copy the current character to the sentence
        sentence[j++] = paragraph[i++];
    }

    // If the first sentence has not been found, return null
    if (!flag) {
        free(sentence);
        return NULL;
    }

    return sentence;
}

// This function calculates the frequency of each word in a given paragraph
void calculateFrequency(char* paragraph, char** words, int* frequency, int numWords) {
    // Convert the paragraph to lower case
    char* lowerCase = (char*) malloc(strlen(paragraph) * sizeof(char));
    int i = 0, j = 0;
    while (paragraph[i]) {
        lowerCase[j] = tolower(paragraph[i]);
        i++;
        j++;
    }
    lowerCase[j] = '\0';

    // Tokenize the lower case string into words
    char* word = strtok(lowerCase, " ,.-\n");
    while (word != NULL) {
        // Check if the word is in the list of words
        for (i = 0; i < numWords; i++) {
            if (strcmp(word, words[i]) == 0) {
                // Increment the frequency of the word
                frequency[i]++;
                break;
            }
        }
        word = strtok(NULL, " ,.-\n");
    }

    free(lowerCase);
}

// This function generates a summary of a given paragraph
char* generateSummary(char* paragraph, char** keywords, int numKeywords) {
    char* summary = (char*) malloc(MAX_SUMMARY_LENGTH * sizeof(char));
    summary[0] = '\0';

    // Extract the first sentence of the paragraph
    char* firstSentence = extractFirstSentence(paragraph);
    if (firstSentence == NULL) {
        return summary;
    }

    // Concatenate the first sentence to the summary
    strcat(summary, firstSentence);

    // Calculate the frequency of each keyword in the paragraph
    int* frequency = (int*) calloc(numKeywords, sizeof(int));
    calculateFrequency(paragraph, keywords, frequency, numKeywords);

    // Find the most frequent keyword
    int maxFrequency = 0;
    char* mostFrequentKeyword = NULL;
    int i;
    for (i = 0; i < numKeywords; i++) {
        if (frequency[i] > maxFrequency) {
            maxFrequency = frequency[i];
            mostFrequentKeyword = keywords[i];
        }
    }

    // Add the most frequent keyword to the summary
    strcat(summary, " ");
    strcat(summary, mostFrequentKeyword);

    return summary;
}

// This is the main function of the program
int main() {
    char* paragraph = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed accumsan vestibulum sem, nec tristique elit consequat vitae. Nulla eleifend elit quis nulla rutrum, ut venenatis libero volutpat. Nunc porta mattis enim, quis sodales felis condimentum quis. Sed vehicula nunc ut velit euismod, quis placerat mauris tempor. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Morbi scelerisque diam eget felis interdum ornare. Integer malesuada lacus at metus feugiat, sed rhoncus purus sagittis. Mauris aliquam tellus in rutrum laoreet. Nam posuere dui sed mauris hendrerit, at mollis justo bibendum. Sed consectetur finibus massa, nec eleifend quam eleifend vitae.";

    char* keywords[] = {"ipsum", "dolor", "consectetur", "nulla", "vehicula", "morbi", "lacus", "mauris", "finibus"};
    int numKeywords = sizeof(keywords) / sizeof(char*);

    char* summary = generateSummary(paragraph, keywords, numKeywords);

    printf("%s\n", summary);

    free(summary);

    return 0;
}