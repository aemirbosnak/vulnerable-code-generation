//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 256

// Function to convert a string to uppercase
void to_uppercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

// Function to reverse a string
void reverse_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Function to remove whitespace from the start and end of a string
void trim_whitespace(char *str) {
    char *end;

    // Trim leading space
    while (isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    // Null-terminate the trimmed string
    *(end + 1) = '\0';
}

// Function to concatenate two strings with a separator
char *concat_with_separator(const char *str1, const char *str2, const char *separator) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    size_t len_sep = strlen(separator);
    char *result = (char *)malloc(len1 + len2 + len_sep + 1); // +1 for null-terminator

    if (result) {
        strcpy(result, str1);
        strcat(result, separator);
        strcat(result, str2);
    }

    return result;
}

// Function to count vowels in a string
int count_vowels(const char *str) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        char ch = tolower(str[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }
    return count;
}

// Main function performing various string manipulations
int main() {
    char input[MAX_STRING_LENGTH];

    // Prompt user for a string
    printf("Enter a string (max %d characters): ", MAX_STRING_LENGTH - 1);
    fgets(input, MAX_STRING_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0; // Remove trailing newline

    // Display original string
    printf("Original String: %s\n", input);

    // Convert to uppercase
    char upper[MAX_STRING_LENGTH];
    strcpy(upper, input);
    to_uppercase(upper);
    printf("Uppercase: %s\n", upper);

    // Reverse string
    char reversed[MAX_STRING_LENGTH];
    strcpy(reversed, input);
    reverse_string(reversed);
    printf("Reversed: %s\n", reversed);

    // Trim whitespace
    char trimmed[MAX_STRING_LENGTH];
    strcpy(trimmed, input);
    trim_whitespace(trimmed);
    printf("Trimmed: %s\n", trimmed);

    // Concatenate the original string with a sample string
    const char *sample_string = "World!";
    char *concatenated = concat_with_separator(input, sample_string, " ");
    if (concatenated) {
        printf("Concatenated with '%s': %s\n", sample_string, concatenated);
        free(concatenated); // Free the allocated memory
    }

    // Count vowels
    int vowel_count = count_vowels(input);
    printf("Number of vowels in the original string: %d\n", vowel_count);

    // Exit message
    printf("String manipulation completed successfully!\n");
    return 0;
}