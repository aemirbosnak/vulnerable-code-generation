//LLAMA2-13B DATASET v1.0 Category: Word Count Tool ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORD_LENGTH 20
#define MIN_WORD_LENGTH 2

// Function to count the number of words in a given string
int wordCount(char *str) {
    int word_count = 0;
    char *token;

    // Tokenize the input string into words
    while (strtok_r(str, " ", &token) != NULL) {
        // Check if the token is a word or not
        if (isalpha(token[0]) && token[1] != '\0') {
            word_count++;
        }
    }

    return word_count;
}

// Function to calculate the average word length
double averageWordLength(char *str) {
    int i = 0;
    int sum = 0;
    char *token;

    // Tokenize the input string into words
    while (strtok_r(str, " ", &token) != NULL) {
        // Calculate the length of the current word
        int word_length = strcspn(token, " \t\r\n");

        // Add the length to the sum
        sum += word_length;
        i++;
    }

    // Calculate the average word length
    double average = (double)sum / i;

    return average;
}

int main() {
    // Input string
    char str[] = "The quick brown fox jumps over the lazy dog";

    // Calculate the number of words in the input string
    int word_count = wordCount(str);
    printf("Number of words: %d\n", word_count);

    // Calculate the average word length
    double average = averageWordLength(str);
    printf("Average word length: %f\n", average);

    return 0;
}