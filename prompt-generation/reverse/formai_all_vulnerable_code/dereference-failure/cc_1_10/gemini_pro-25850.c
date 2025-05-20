//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: mathematical
// A Mathematical Word Count Tool

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Word count function
int word_count(char *string) {
    int words = 0;
    int in_word = 0;
    for (int i = 0; i < strlen(string); i++) {
        if (isalpha(string[i])) {
            if (!in_word) {
                words++;
                in_word = 1;
            }
        } else {
            in_word = 0;
        }
    }
    return words;
}

// Main function
int main() {
    // Get the input string
    char *string = (char *)malloc(sizeof(char) * 1000);
    printf("Enter a string: ");
    scanf("%[^\n]", string);

    // Count the words
    int words = word_count(string);

    // Print the word count
    printf("The word count is: %d\n", words);

    // Calculate the average word length
    double avg_word_length = (double)strlen(string) / words;

    // Print the average word length
    printf("The average word length is: %.2f\n", avg_word_length);

    // Calculate the standard deviation of the word lengths
    double std_dev = 0;
    for (int i = 0; i < strlen(string); i++) {
        if (isalpha(string[i])) {
            int word_length = 1;
            while (i + word_length < strlen(string) && isalpha(string[i + word_length])) {
                word_length++;
            }
            std_dev += pow(word_length - avg_word_length, 2);
            i += word_length - 1;
        }
    }
    std_dev = sqrt(std_dev / words);

    // Print the standard deviation of the word lengths
    printf("The standard deviation of the word lengths is: %.2f\n", std_dev);

    // Free the allocated memory
    free(string);

    return 0;
}