//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT 256
#define MAX_BUFFER 512

void to_uppercase(char *str) {
    while (*str) {
        *str = toupper((unsigned char) *str);
        str++;
    }
}

void reverse_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int count_vowels(const char *str) {
    int count = 0;
    while (*str) {
        char c = tolower((unsigned char) *str);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
        str++;
    }
    return count;
}

void replace_vowels(char *str, char replacement) {
    while (*str) {
        char c = tolower((unsigned char) *str);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            *str = replacement;
        }
        str++;
    }
}

void print_string_info(const char *str) {
    printf("Original String: %s\n", str);
    printf("Length: %lu\n", strlen(str));
    printf("Vowel Count: %d\n", count_vowels(str));
    printf("First Character: '%c'\n", str[0]);
}

void split_string(char *str, char delimiter) {
    char *token = strtok(str, &delimiter);
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = strtok(NULL, &delimiter);
    }
}

void string_operations(char *input) {
    char buffer[MAX_BUFFER];
    
    // Step 1: Convert to uppercase
    strcpy(buffer, input);
    to_uppercase(buffer);
    printf("Uppercase: %s\n", buffer);
    
    // Step 2: Reverse String
    strcpy(buffer, input);
    reverse_string(buffer);
    printf("Reversed: %s\n", buffer);
    
    // Step 3: Count vowels
    int vowels = count_vowels(input);
    printf("Vowel Count: %d\n", vowels);
    
    // Step 4: Replace Vowels
    strcpy(buffer, input);
    replace_vowels(buffer, '*');
    printf("Vowels replaced with '*': %s\n", buffer);
    
    // Step 5: Print string info
    print_string_info(input);
    
    // Step 6: Split String
    strcpy(buffer, input);
    printf("Splitting on spaces:\n");
    split_string(buffer, ' ');
}

int main() {
    char input[MAX_INPUT];

    printf("Enter a string (max 255 characters): ");
    fgets(input, MAX_INPUT, stdin);
    
    // Remove newline character from input
    input[strcspn(input, "\n")] = 0;   

    // Check for empty string
    if (strlen(input) == 0) {
        printf("No input provided! Exiting.\n");
        return 1;
    }

    // Perform string operations
    string_operations(input);

    return 0;
}