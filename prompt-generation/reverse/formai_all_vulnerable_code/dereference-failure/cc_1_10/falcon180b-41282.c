//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to reverse a string
void reverse(char *str) {
    int len = strlen(str);
    char *start = str;
    char *end = str + len - 1;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

// Function to check if a string is a palindrome
int isPalindrome(char *str) {
    int len = strlen(str);
    char *start = str;
    char *end = str + len - 1;
    while (start < end) {
        if (tolower(*start)!= tolower(*end)) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

// Function to count the number of words in a string
int countWords(char *str) {
    int count = 0;
    char *start = str;
    while (*start!= '\0') {
        if (isspace(*start)) {
            count++;
        }
        start++;
    }
    return count;
}

// Function to display the frequency of each word in a string
void displayWordFrequency(char *str) {
    int len = strlen(str);
    char *start = str;
    int freq[26] = {0};
    while (*start!= '\0') {
        if (isalpha(*start)) {
            int index = tolower(*start) - 'a';
            freq[index]++;
        }
        start++;
    }
    printf("Word Frequency:\n");
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            printf("%c: %d\n", 'a' + i, freq[i]);
        }
    }
}

int main() {
    char input[1000];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    reverse(input);
    if (isPalindrome(input)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }
    printf("Number of words: %d\n", countWords(input));
    displayWordFrequency(input);
    return 0;
}