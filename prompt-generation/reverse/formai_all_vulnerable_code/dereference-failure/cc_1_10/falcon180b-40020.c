//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to count words in a string
int countWords(char* str) {
    int count = 0;
    char* word = strtok(str, " ");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }
    return count;
}

// Function to remove punctuation from a string
char* removePunctuation(char* str) {
    char* dest = malloc(strlen(str) + 1);
    char* src = str;
    char* dest_ptr = dest;
    while (*src) {
        if (!isalpha(*src)) {
            src++;
            continue;
        }
        *dest_ptr++ = *src++;
    }
    *dest_ptr = '\0';
    return dest;
}

// Function to check if a string is empty or contains only whitespace
int isValidString(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (!isspace(str[i])) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char* input_str = NULL;
    char* cleaned_str = NULL;
    int word_count = 0;
    int is_valid_string = 0;

    // Prompt user for input
    printf("Enter a string to count words: ");
    scanf("%s", input_str);

    // Check if input is valid
    is_valid_string = isValidString(input_str);
    if (!is_valid_string) {
        printf("Input string is empty or contains only whitespace.\n");
        return 1;
    }

    // Remove punctuation from input string
    cleaned_str = removePunctuation(input_str);

    // Count words in cleaned string
    word_count = countWords(cleaned_str);

    // Print word count
    printf("The input string contains %d words.\n", word_count);

    // Free memory
    free(input_str);
    free(cleaned_str);

    return 0;
}