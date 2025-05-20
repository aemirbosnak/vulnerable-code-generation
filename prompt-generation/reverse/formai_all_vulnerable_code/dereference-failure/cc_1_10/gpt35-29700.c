//FormAI DATASET v1.0 Category: Word Count Tool ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

int main() {
    char *input_str = NULL;
    size_t input_size = 0;
    ssize_t characters_read;

    // Prompt user for input string
    printf("Enter a string: ");
    characters_read = getline(&input_str, &input_size, stdin);

    if (characters_read == -1) {
        printf("Error reading input.\n");
        return 1;
    }

    // Initialize variables for counting words
    int word_count = 0;
    int in_word = 0;
    int input_str_len = strlen(input_str);

    // Loop through each character in the string and count words
    for (int i = 0; i < input_str_len; i++) {
        char current_char = input_str[i];

        // Check if current character is a whitespace character
        if (isspace(current_char)) {
            // If whitespace and we were previously in a word, increment word count
            if (in_word) {
                word_count++;
                in_word = 0;
            }
        } else {
            // If a non-whitespace character, we are in a word
            in_word = 1;
        }
    }

    // Increment word count if we were still in a word at the end of the string
    if (in_word) {
        word_count++;
    }

    // Print word count to user
    printf("Number of words in the input string: %d\n", word_count);

    // Free memory allocated for input string
    free(input_str);

    return 0;
}