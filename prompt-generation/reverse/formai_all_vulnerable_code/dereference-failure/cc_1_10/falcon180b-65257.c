//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: introspective
#include <stdio.h>
#include <string.h>

// Function to reverse a string
void reverse_string(char* str) {
    int len = strlen(str);
    char* reversed = malloc(len + 1);
    if (reversed == NULL) {
        printf("Error: Memory allocation failed\n");
        return;
    }
    int i = 0;
    for (int j = len - 1; j >= 0; j--) {
        reversed[i++] = str[j];
    }
    reversed[i] = '\0'; // Add null terminator
    printf("Reversed string: %s\n", reversed);
    free(reversed); // Free allocated memory
}

// Function to check if a string is a palindrome
int is_palindrome(char* str) {
    int len = strlen(str);
    char* reversed = malloc(len + 1);
    if (reversed == NULL) {
        printf("Error: Memory allocation failed\n");
        return -1;
    }
    int i = 0;
    for (int j = len - 1; j >= 0; j--) {
        reversed[i++] = str[j];
    }
    reversed[i] = '\0'; // Add null terminator
    if (strcmp(str, reversed) == 0) {
        printf("The string is a palindrome\n");
        return 1;
    } else {
        printf("The string is not a palindrome\n");
        return 0;
    }
}

// Function to remove all vowels from a string
void remove_vowels(char* str) {
    int len = strlen(str);
    char* vowels = "aeiouAEIOU";
    char* result = malloc(len + 1);
    if (result == NULL) {
        printf("Error: Memory allocation failed\n");
        return;
    }
    int i = 0;
    for (int j = 0; j < len; j++) {
        if (strchr(vowels, str[j]) == NULL) {
            result[i++] = str[j];
        }
    }
    result[i] = '\0'; // Add null terminator
    printf("String with vowels removed: %s\n", result);
    free(result); // Free allocated memory
}

// Function to convert a string to uppercase
void string_to_uppercase(char* str) {
    int len = strlen(str);
    char* uppercase = malloc(len + 1);
    if (uppercase == NULL) {
        printf("Error: Memory allocation failed\n");
        return;
    }
    int i = 0;
    for (int j = 0; j < len; j++) {
        uppercase[i++] = toupper(str[j]);
    }
    uppercase[i] = '\0'; // Add null terminator
    printf("String in uppercase: %s\n", uppercase);
    free(uppercase); // Free allocated memory
}

int main() {
    char str1[100] = "racecar";
    reverse_string(str1);

    char str2[100] = "A man a plan a canal Panama";
    is_palindrome(str2);

    char str3[100] = "The quick brown fox jumps over the lazy dog";
    remove_vowels(str3);

    char str4[100] = "Hello World";
    string_to_uppercase(str4);

    return 0;
}