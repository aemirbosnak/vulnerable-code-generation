//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: complex
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Preprocessor macros to reduce code clutter
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
#define SWAP(a, b) {typeof(a) temp = a; a = b; b = temp;}

// Function prototypes
char* reverse_string(const char* str);
char* to_upper(char* str);
char* to_lower(char* str);
char** split_string(const char* str, char delimiter);
int count_words(const char* str);

int main() {
    // Create a string
    char str[] = "This is a test string.";

    // Reverse the string
    char* reversed_str = reverse_string(str);
    printf("Reversed string: %s\n", reversed_str);

    // Convert the string to uppercase
    char* upper_str = to_upper(str);
    printf("Uppercase string: %s\n", upper_str);

    // Convert the string to lowercase
    char* lower_str = to_lower(str);
    printf("Lowercase string: %s\n", lower_str);

    // Split the string by spaces
    char** words = split_string(str, ' ');
    printf("Words in the string:\n");
    for (int i = 0; i < count_words(str); i++) {
        printf("%s\n", words[i]);
    }

    // Clean up the allocated memory
    free(reversed_str);
    free(upper_str);
    free(lower_str);
    for (int i = 0; i < count_words(str); i++) {
        free(words[i]);
    }
    free(words);

    return 0;
}

// Function to reverse a string
char* reverse_string(const char* str) {
    char* reversed = malloc(strlen(str) + 1);
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        reversed[len - i - 1] = str[i];
    }
    reversed[len] = '\0';
    return reversed;
}

// Function to convert a string to uppercase
char* to_upper(char* str) {
    for (char* p = str; *p; p++) {
        *p = toupper(*p);
    }
    return str;
}

// Function to convert a string to lowercase
char* to_lower(char* str) {
    for (char* p = str; *p; p++) {
        *p = tolower(*p);
    }
    return str;
}

// Function to split a string by a delimiter
char** split_string(const char* str, char delimiter) {
    int count = 1;
    const char* p = str;
    while (*p) {
        if (*p == delimiter) {
            count++;
        }
        p++;
    }

    char** words = malloc(sizeof(char*) * count);
    p = str;
    int i = 0;
    while (*p) {
        char* word_start = p;
        while (*p && *p != delimiter) {
            p++;
        }
        int word_len = p - word_start;
        words[i] = malloc(word_len + 1);
        memcpy(words[i], word_start, word_len);
        words[i][word_len] = '\0';
        i++;
        if (*p) {
            p++;
        }
    }

    return words;
}

// Function to count the number of words in a string
int count_words(const char* str) {
    int count = 0;
    for (const char* p = str; *p; p++) {
        if (isspace(*p)) {
            count++;
        }
    }
    return count + 1;
}