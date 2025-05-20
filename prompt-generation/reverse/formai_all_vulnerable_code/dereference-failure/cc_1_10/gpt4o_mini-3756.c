//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: Alan Turing
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 100

void reverseString(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

int isPalindrome(const char *str) {
    int start = 0;
    int end = strlen(str) - 1;
    while (start < end) {
        if (str[start] != str[end]) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

void frequencyCount(const char *str) {
    int freq[256] = {0}; // Assuming ASCII character set
    for (int i = 0; str[i]; i++) {
        freq[(unsigned char)str[i]]++;
    }

    printf("Character Frequencies:\n");
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            printf("'%c' : %d\n", (char)i, freq[i]);
        }
    }
}

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char input[MAX_LENGTH];

    // Getting input from the user
    printf("Enter a string (max %d characters): ", MAX_LENGTH - 1);
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character

    // Display original string
    printf("Original String: %s\n", input);

    // Reverse the string
    char *reversed = strdup(input);
    reverseString(reversed);
    printf("Reversed String: %s\n", reversed);
    free(reversed);

    // Check if the original string is a palindrome
    toLowerCase(input); // Convert to lowercase for palindrome check
    if (isPalindrome(input)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    // Reset to original case for frequency count
    printf("Frequency count of characters in the input:\n");
    frequencyCount(input);

    // Additional manipulation: Count vowels and consonants
    int vowels = 0, consonants = 0;
    for (int i = 0; input[i]; i++) {
        char ch = tolower(input[i]);
        if (isalpha(ch)) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }

    printf("Vowels count: %d, Consonants count: %d\n", vowels, consonants);

    // Freeing resources
    return 0;
}