//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a string
#define MAX_STRING_LENGTH 100

// Function to reverse a string
void reverse_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Function to encode a string using the Caesar cipher
void caesar_cipher(char *str, int key) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] += key;
    }
}

// Function to decode a string using the Caesar cipher
void caesar_decipher(char *str, int key) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] -= key;
    }
}

// Function to find the longest palindrome in a string
char *longest_palindrome(char *str) {
    int len = strlen(str);
    int max_len = 0;
    int start = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            int k = 0;
            while (i + k < j - k && str[i + k] == str[j - k]) {
                k++;
            }
            if (k > max_len) {
                max_len = k;
                start = i;
            }
        }
    }
    char *palindrome = malloc(max_len + 1);
    strncpy(palindrome, str + start, max_len);
    palindrome[max_len] = '\0';
    return palindrome;
}

// Main function
int main() {
    // Define a string
    char str[] = "Hello, world!";

    // Print the original string
    printf("Original string: %s\n", str);

    // Reverse the string
    reverse_string(str);

    // Print the reversed string
    printf("Reversed string: %s\n", str);

    // Encode the string using the Caesar cipher with a key of 3
    caesar_cipher(str, 3);

    // Print the encoded string
    printf("Encoded string: %s\n", str);

    // Decode the string using the Caesar cipher with a key of 3
    caesar_decipher(str, 3);

    // Print the decoded string
    printf("Decoded string: %s\n", str);

    // Find the longest palindrome in the string
    char *palindrome = longest_palindrome(str);

    // Print the longest palindrome
    printf("Longest palindrome: %s\n", palindrome);

    // Free the memory allocated for the palindrome
    free(palindrome);

    return 0;
}