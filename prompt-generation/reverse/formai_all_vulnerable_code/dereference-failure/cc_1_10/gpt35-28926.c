//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Cyberpunk
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

// Function to check if a character is a punctuation mark or not
bool isPunctuation(char ch) {
    return ch == '.' || ch == ',' || ch == '?' || ch == '!' || ch == ';' || ch == ':';
}

// Function to count the frequency of the given word in the given text
int countWordFrequency(char *text, char *word) {
    int frequency = 0;
    char *token, *strptr;
    char buffer[MAX_BUFFER_SIZE];

    // Make a copy of the text so that we can modify it
    strcpy(buffer, text);

    // Loop through each word in the text
    while ((token = strtok_r(buffer, " \t\n", &strptr)) != NULL) {
        // Check if the word matches the given word
        if (strcasecmp(token, word) == 0) {
            frequency++;
        }

        // Move the buffer pointer forwards to the next word
        buffer[0] = '\0';
        buffer[MAX_BUFFER_SIZE - 1] = '\0';
        buffer[MAX_BUFFER_SIZE - 2] = ' ';
        strcpy(buffer, strptr);
    }

    return frequency;
}

int main() {
    char text[MAX_BUFFER_SIZE];
    char word[MAX_BUFFER_SIZE];

    // Get the text and word input from the user
    printf("Enter the text: ");
    fgets(text, MAX_BUFFER_SIZE, stdin);
    printf("Enter the word to count: ");
    scanf("%s", word);

    // Remove any punctuation from the text
    for (int i = 0; i < strlen(text); i++) {
        if (isPunctuation(text[i])) {
            text[i] = ' ';
        }
    }

    // Calculate the frequency of the word in the text
    int frequency = countWordFrequency(text, word);

    // Print the result
    printf("The word '%s' appears %d times in the text.", word, frequency);

    return 0;
}