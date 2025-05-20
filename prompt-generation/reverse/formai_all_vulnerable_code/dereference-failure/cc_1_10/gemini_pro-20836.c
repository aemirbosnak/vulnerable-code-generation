//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the number of occurrences of a substring in a string
int count_substring(const char *string, const char *substring) {
    int count = 0;
    int string_length = strlen(string);
    int substring_length = strlen(substring);

    for (int i = 0; i <= string_length - substring_length; i++) {
        if (strncmp(string + i, substring, substring_length) == 0) {
            count++;
        }
    }

    return count;
}

// Function to replace all occurrences of a substring in a string with another substring
char *replace_substring(char *string, const char *substring, const char *replacement) {
    int string_length = strlen(string);
    int substring_length = strlen(substring);
    int replacement_length = strlen(replacement);

    int count = count_substring(string, substring);

    // Allocate memory for the new string
    char *new_string = malloc(string_length + (count * (replacement_length - substring_length)) + 1);

    int new_string_index = 0;

    for (int i = 0; i < string_length; i++) {
        if (strncmp(string + i, substring, substring_length) == 0) {
            for (int j = 0; j < replacement_length; j++) {
                new_string[new_string_index++] = replacement[j];
            }

            i += substring_length - 1;
        } else {
            new_string[new_string_index++] = string[i];
        }
    }

    new_string[new_string_index] = '\0';

    return new_string;
}

// Function to convert a string to uppercase
char *to_uppercase(char *string) {
    int string_length = strlen(string);

    for (int i = 0; i < string_length; i++) {
        string[i] = toupper(string[i]);
    }

    return string;
}

// Function to convert a string to lowercase
char *to_lowercase(char *string) {
    int string_length = strlen(string);

    for (int i = 0; i < string_length; i++) {
        string[i] = tolower(string[i]);
    }

    return string;
}

// Function to trim whitespace from a string
char *trim_whitespace(char *string) {
    int string_length = strlen(string);

    // Trim leading whitespace
    int start_index = 0;

    while (string[start_index] == ' ') {
        start_index++;
    }

    // Trim trailing whitespace
    int end_index = string_length - 1;

    while (string[end_index] == ' ') {
        end_index--;
    }

    // Create a new string with the trimmed whitespace
    char *trimmed_string = malloc(end_index - start_index + 2);

    int trimmed_string_index = 0;

    for (int i = start_index; i <= end_index; i++) {
        trimmed_string[trimmed_string_index++] = string[i];
    }

    trimmed_string[trimmed_string_index] = '\0';

    return trimmed_string;
}

// Function to remove all punctuation from a string
char *remove_punctuation(char *string) {
    int string_length = strlen(string);

    // Create a new string with the punctuation removed
    char *new_string = malloc(string_length + 1);

    int new_string_index = 0;

    for (int i = 0; i < string_length; i++) {
        if (ispunct(string[i])) {
            continue;
        }

        new_string[new_string_index++] = string[i];
    }

    new_string[new_string_index] = '\0';

    return new_string;
}

// Function to count the number of words in a string
int count_words(const char *string) {
    int count = 0;
    int in_word = 0;

    int string_length = strlen(string);

    for (int i = 0; i < string_length; i++) {
        if (isspace(string[i])) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            count++;
        }
    }

    return count;
}

// Function to reverse a string
char *reverse_string(char *string) {
    int string_length = strlen(string);

    for (int i = 0; i < string_length / 2; i++) {
        char temp = string[i];
        string[i] = string[string_length - i - 1];
        string[string_length - i - 1] = temp;
    }

    return string;
}

int main() {
    // Example string
    char *string = "The quick brown fox jumps over the lazy dog.";

    // Count the number of occurrences of a substring
    int count = count_substring(string, "the");
    printf("The number of occurrences of \"the\" in the string is %d\n", count);

    // Replace all occurrences of a substring with another substring
    char *new_string = replace_substring(string, "the", "a");
    printf("The new string after replacing \"the\" with \"a\" is %s\n", new_string);
    free(new_string);

    // Convert a string to uppercase
    char *upper_string = to_uppercase(string);
    printf("The string in uppercase is %s\n", upper_string);
    free(upper_string);

    // Convert a string to lowercase
    char *lower_string = to_lowercase(string);
    printf("The string in lowercase is %s\n", lower_string);
    free(lower_string);

    // Trim whitespace from a string
    char *trimmed_string = trim_whitespace(string);
    printf("The string after trimming whitespace is %s\n", trimmed_string);
    free(trimmed_string);

    // Remove all punctuation from a string
    char *no_punctuation_string = remove_punctuation(string);
    printf("The string after removing punctuation is %s\n", no_punctuation_string);
    free(no_punctuation_string);

    // Count the number of words in a string
    int word_count = count_words(string);
    printf("The number of words in the string is %d\n", word_count);

    // Reverse a string
    char *reversed_string = reverse_string(string);
    printf("The reversed string is %s\n", reversed_string);
    free(reversed_string);

    return 0;
}