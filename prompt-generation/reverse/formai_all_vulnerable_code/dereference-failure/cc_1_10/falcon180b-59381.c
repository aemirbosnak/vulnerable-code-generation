//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: recursive
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to reverse a string recursively
void reverse(char str[], int start, int end) {
    char temp;

    if (start >= end)
        return;

    // Swap characters at start and end
    temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    // Recursive call for the next set of characters
    reverse(str, start + 1, end - 1);
}

// Function to check if a string is a palindrome recursively
int isPalindrome(char str[], int start, int end) {
    if (start >= end)
        return 1;

    // Check if first and last character match
    if (str[start]!= str[end])
        return 0;

    // Recursive call for the next set of characters
    return isPalindrome(str, start + 1, end - 1);
}

// Function to concatenate two strings recursively
void concatenate(char str1[], char str2[], char result[]) {
    int i, j, k;

    i = strlen(str1) - 1;
    j = strlen(str2) - 1;
    k = strlen(result) - 1;

    while (i >= 0 && j >= 0) {
        result[k] = str1[i];
        i--;
        result[k] = str2[j];
        j--;
        k--;
    }

    while (i >= 0) {
        result[k] = str1[i];
        i--;
        k--;
    }

    while (j >= 0) {
        result[k] = str2[j];
        j--;
        k--;
    }

    result[k] = '\0';
}

int main() {
    char str1[MAX_LENGTH] = "Hello";
    char str2[MAX_LENGTH] = "World";
    char result[MAX_LENGTH * 2];

    printf("Original strings:\n");
    printf("String 1: %s\n", str1);
    printf("String 2: %s\n", str2);

    concatenate(str1, str2, result);
    printf("Concatenated string: %s\n", result);

    reverse(result, 0, strlen(result) - 1);
    printf("Reversed string: %s\n", result);

    if (isPalindrome(result, 0, strlen(result) - 1))
        printf("The string is a palindrome.\n");
    else
        printf("The string is not a palindrome.\n");

    return 0;
}