//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Function to concatenate two strings
void concatenate(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char *result = (char*) malloc(len1 + len2 + 1); // Allocate memory for the result string

    strcpy(result, str1); // Copy the first string
    strcat(result, str2); // Concatenate the second string

    printf("Concatenated string: %s\n", result); // Print the result
    free(result); // Free the allocated memory
}

// Function to reverse a string
void reverse(char *str) {
    int len = strlen(str);
    char *result = (char*) malloc(len + 1); // Allocate memory for the result string

    int i = 0;
    for (int j = len - 1; j >= 0; j--) {
        result[i++] = str[j]; // Copy the characters in reverse order
    }
    result[i] = '\0'; // Terminate the result string

    printf("Reversed string: %s\n", result); // Print the result
    free(result); // Free the allocated memory
}

// Function to compare two strings
int compare(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 == len2) {
        for (int i = 0; i < len1; i++) {
            if (str1[i]!= str2[i]) {
                return 1; // Strings are not equal
            }
        }
        return 0; // Strings are equal
    } else {
        return 1; // Strings are not equal
    }
}

int main() {
    char str1[MAX_SIZE];
    char str2[MAX_SIZE];

    // Get input from the user
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);

    // Concatenate the strings
    concatenate(str1, str2);

    // Reverse the concatenated string
    char *result = (char*) malloc(strlen(str1) + strlen(str2) + 1);
    strcpy(result, str1);
    strcat(result, str2);
    reverse(result);

    // Compare the strings
    int result_compare = compare(str1, str2);
    printf("Strings are %s\n", result_compare? "not equal" : "equal");

    return 0;
}