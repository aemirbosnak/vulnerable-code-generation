//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void reverseString(char *str);
int isPalindrome(char *str);
int countVowels(char *str);
int countConsonants(char *str);
void toUpperCase(char *str);
void toLowerCase(char *str);

int main() {
    char *inputString = NULL;
    size_t inputSize = 0;

    printf("Welcome to the String Manipulation Program!\n");
    printf("Please enter a string (max 100 characters): ");
    
    getline(&inputString, &inputSize, stdin);

    // Remove newline character if present
    inputString[strcspn(inputString, "\n")] = 0;

    printf("\nYou entered: %s\n", inputString);

    // String Reversal
    char *reversedString = strdup(inputString); // Duplicate string for manipulation
    reverseString(reversedString);
    printf("Reversed String: %s\n", reversedString);

    // Check if the string is a palindrome
    if (isPalindrome(inputString)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    // Count vowels and consonants
    int vowelCount = countVowels(inputString);
    int consonantCount = countConsonants(inputString);
    printf("Number of vowels: %d\n", vowelCount);
    printf("Number of consonants: %d\n", consonantCount);

    // Convert to upper case
    char *upperString = strdup(inputString);
    toUpperCase(upperString);
    printf("Uppercase String: %s\n", upperString);

    // Convert to lower case
    char *lowerString = strdup(inputString);
    toLowerCase(lowerString);
    printf("Lowercase String: %s\n", lowerString);

    // Free dynamically allocated memory
    free(reversedString);
    free(upperString);
    free(lowerString);
    free(inputString);

    return 0;
}

void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int isPalindrome(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (tolower(str[i]) != tolower(str[len - i - 1])) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Is a palindrome
}

int countVowels(char *str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }
    return count;
}

int countConsonants(char *str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);
        if (isalpha(ch) && !(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
            count++;
        }
    }
    return count;
}

void toUpperCase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

void toLowerCase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}