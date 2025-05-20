//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert all characters in a string to uppercase
void to_uppercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

// Function to remove punctuation from a string
void remove_punctuation(char *str) {
    char *dst = str;
    while (*str) {
        if (!ispunct((unsigned char)*str)) {
            *dst++ = *str;
        }
        str++;
    }
    *dst = '\0';  // Null-terminate the string
}

// Function to count words in a string
int count_words(const char *str) {
    int count = 0;
    const char *delimiters = " \n\t";
    char *temp = strdup(str);  // Create a copy of the string
    char *token = strtok(temp, delimiters);
    while (token) {
        count++;
        token = strtok(NULL, delimiters);
    }
    free(temp);  // Clean up
    return count;
}

// Function to count the frequency of each word in a string
void count_word_frequency(const char *str) {
    char *temp = strdup(str);
    char *token;
    const char *delimiters = " \n\t";
    int freq[100] = {0};  // Initialize frequencies to 0
    char *words[100] = {NULL};  // Array to hold words
    int word_count = 0;

    // Tokenize the string and count frequency
    token = strtok(temp, delimiters);
    while (token) {
        int found = 0;
        // Check if the word is already in the list
        for (int i = 0; i < word_count; i++) {
            if (strcmp(words[i], token) == 0) {
                freq[i]++;
                found = 1;
                break;
            }
        }
        // If the word is new, add it to the list
        if (!found && word_count < 100) {
            words[word_count] = strdup(token);
            freq[word_count] = 1;
            word_count++;
        }
        token = strtok(NULL, delimiters);
    }

    // Print word frequencies
    printf("Word Frequencies:\n");
    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i], freq[i]);
        free(words[i]);  // Clean up allocated memory
    }

    free(temp);  // Clean up
}

// Main function to process text input
int main() {
    // Buffer to hold input text
    char *input_text = NULL;
    size_t len = 0;

    printf("Enter text (type 'EXIT' to finish):\n");

    // Get multi-line user input until 'EXIT'
    while (1) {
        // Read a line from stdin
        getline(&input_text, &len, stdin);
        // Check for exit
        if (strcmp(input_text, "EXIT\n") == 0) {
            break;
        }
        // Process the input text
        to_uppercase(input_text);  
        remove_punctuation(input_text);
        int word_count = count_words(input_text);
        printf("Processed line: %s", input_text);
        printf("Word count: %d\n", word_count);
        count_word_frequency(input_text);
    }

    // Clean up
    free(input_text);
    return 0;
}