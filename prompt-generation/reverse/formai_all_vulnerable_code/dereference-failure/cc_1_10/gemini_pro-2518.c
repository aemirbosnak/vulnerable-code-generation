//GEMINI-pro DATASET v1.0 Category: Educational ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Define the maximum size of the input string
#define MAX_STRING_SIZE 100

// Define a structure to store the results of the analysis
typedef struct {
    int num_words;      // The number of words in the string
    int num_chars;      // The number of characters in the string
    int num_digits;     // The number of digits in the string
    int num_uppercase;  // The number of uppercase letters in the string
    int num_lowercase;  // The number of lowercase letters in the string
    int num_spaces;     // The number of spaces in the string
    int num_sentences;  // The number of sentences in the string
    int num_punctuation; // The number of punctuation marks in the string
} string_analysis_results;

// Function to analyze a string and return the results
string_analysis_results analyze_string(char *string) {
    string_analysis_results results;

    // Initialize the results
    results.num_words = 0;
    results.num_chars = 0;
    results.num_digits = 0;
    results.num_uppercase = 0;
    results.num_lowercase = 0;
    results.num_spaces = 0;
    results.num_sentences = 0;
    results.num_punctuation = 0;

    // Loop through the string and analyze each character
    for (int i = 0; string[i] != '\0'; i++) {
        // Increment the number of characters
        results.num_chars++;

        // Check if the character is a digit
        if (isdigit(string[i])) {
            // Increment the number of digits
            results.num_digits++;
        }
        // Check if the character is an uppercase letter
        else if (isupper(string[i])) {
            // Increment the number of uppercase letters
            results.num_uppercase++;
        }
        // Check if the character is a lowercase letter
        else if (islower(string[i])) {
            // Increment the number of lowercase letters
            results.num_lowercase++;
        }
        // Check if the character is a space
        else if (isspace(string[i])) {
            // Increment the number of spaces
            results.num_spaces++;

            // Check if the previous character was a period, question mark, or exclamation mark
            if (i > 0 && (string[i - 1] == '.' || string[i - 1] == '?' || string[i - 1] == '!')) {
                // Increment the number of sentences
                results.num_sentences++;
            }
        }
        // Check if the character is a punctuation mark
        else if (ispunct(string[i])) {
            // Increment the number of punctuation marks
            results.num_punctuation++;
        }
    }

    // Check if the last character in the string is a period, question mark, or exclamation mark
    if (string[strlen(string) - 1] == '.' || string[strlen(string) - 1] == '?' || string[strlen(string) - 1] == '!') {
        // Increment the number of sentences
        results.num_sentences++;
    }

    // Count the number of words in the string
    char *word = strtok(string, " ");
    while (word != NULL) {
        // Increment the number of words
        results.num_words++;

        // Get the next word
        word = strtok(NULL, " ");
    }

    // Return the results
    return results;
}

// Function to print the results of the analysis
void print_results(string_analysis_results results) {
    // Print the number of words
    printf("Number of words: %d\n", results.num_words);

    // Print the number of characters
    printf("Number of characters: %d\n", results.num_chars);

    // Print the number of digits
    printf("Number of digits: %d\n", results.num_digits);

    // Print the number of uppercase letters
    printf("Number of uppercase letters: %d\n", results.num_uppercase);

    // Print the number of lowercase letters
    printf("Number of lowercase letters: %d\n", results.num_lowercase);

    // Print the number of spaces
    printf("Number of spaces: %d\n", results.num_spaces);

    // Print the number of sentences
    printf("Number of sentences: %d\n", results.num_sentences);

    // Print the number of punctuation marks
    printf("Number of punctuation marks: %d\n", results.num_punctuation);
}

// Main function
int main() {
    // Get the input string from the user
    char string[MAX_STRING_SIZE];
    printf("Enter a string: ");
    fgets(string, MAX_STRING_SIZE, stdin);

    // Analyze the string
    string_analysis_results results = analyze_string(string);

    // Print the results of the analysis
    print_results(results);

    return 0;
}