//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to remove all vowels from a string
void remove_vowels(char* str) {
    char vowels[] = "aeiouAEIOU";
    char* p = str;
    while (*p) {
        if (strchr(vowels, *p) == NULL) {
            *p = tolower(*p); // Convert to lowercase if uppercase vowel
        } else {
            *p = '\0'; // Remove vowel
        }
        p++;
    }
}

// Function to reverse a string
void reverse_string(char* str) {
    int len = strlen(str);
    char* start = str;
    char* end = str + len - 1;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

// Function to check if a string is a palindrome
int is_palindrome(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i]!= str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

// Function to replace all occurrences of a character in a string with another character
void replace_char(char* str, char from, char to) {
    while (*str) {
        if (*str == from) {
            *str = to;
        }
        str++;
    }
}

int main() {
    char input_str[1000];
    printf("Enter a string: ");
    fgets(input_str, 1000, stdin); // Read input string from user

    // Remove all vowels from the input string
    remove_vowels(input_str);

    // Reverse the modified string
    reverse_string(input_str);

    // Check if the reversed string is a palindrome
    if (is_palindrome(input_str)) {
        printf("The input string is a palindrome.\n");
    } else {
        printf("The input string is not a palindrome.\n");
    }

    // Replace all occurrences of 'a' with 'z'
    replace_char(input_str, 'a', 'z');

    // Print the modified string
    printf("Modified string: %s\n", input_str);

    return 0;
}