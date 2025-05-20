//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

// Function to check if two strings are equal ignoring case
int strEQ(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 != len2)
        return 0;

    for (int i = 0; i < len1; i++) {
        if (tolower(str1[i]) != tolower(str2[i]))
            return 0;
    }

    return 1;
}

// Function to check if a given string is a palindrome recursively
int isPalindrome(char *str, int *arr[MAX_LENGTH][MAX_LENGTH], int len, int i, int j) {
    // Base case: if we have checked all characters
    if (i >= len / 2)
        return 1;

    // Check if the characters at current indices are same
    if (str[i] != str[len - i - 1])
        return 0;

    // Store the result of the subproblem in the array for optimization
    if (arr[i][len - i - 1] != NULL)
        return arr[i][len - i - 1];

    // Recursive call for the subproblem
    int result = isPalindrome(str, arr, len, i + 1, j - 1);

    // Store the result in the array for future reference
    arr[i][len - i - 1] = malloc(sizeof(int));
    *arr[i][len - i - 1] = result;

    return result;
}

int main() {
    char str[MAX_LENGTH];

    printf("Enter a string: ");
    scanf("%s", str);

    // Check for invalid input
    if (strlen(str) > MAX_LENGTH) {
        printf("Error: Input string too long!\n");
        return 1;
    }

    // Allocate memory for the two-dimensional array
    int **arr = malloc(MAX_LENGTH * sizeof(int *));
    for (int i = 0; i < MAX_LENGTH; i++)
        arr[i] = calloc(MAX_LENGTH, sizeof(int));

    int len = strlen(str);

    // Check if the given string is a palindrome
    int result = isPalindrome(str, arr, len, 0, len - 1);

    // Free allocated memory
    for (int i = 0; i < MAX_LENGTH; i++)
        free(arr[i]);
    free(arr);

    if (result)
        printf("The given string is a palindrome!\n");
    else
        printf("The given string is not a palindrome!\n");

    return 0;
}