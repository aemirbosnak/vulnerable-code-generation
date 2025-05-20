//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to reverse a string
void reverseString(char* str) {
    int len = strlen(str);
    char* rev = (char*)malloc(len + 1);
    int i = 0;
    for (int j = len - 1; j >= 0; j--) {
        rev[i++] = tolower(str[j]);
    }
    rev[i] = '\0';
    printf("Reversed string: %s\n", rev);
    free(rev);
}

// Function to count the number of vowels in a string
int countVowels(char* str) {
    int count = 0;
    while (*str!= '\0') {
        if (*str == 'a' || *str == 'e' || *str == 'i' || *str == 'o' || *str == 'u') {
            count++;
        }
        str++;
    }
    return count;
}

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (tolower(str[i])!= tolower(str[len - i - 1])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    // Reverse the string
    reverseString(input);

    // Count the number of vowels
    int vowelCount = countVowels(input);
    printf("Number of vowels: %d\n", vowelCount);

    // Check if the string is a palindrome
    if (isPalindrome(input)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}