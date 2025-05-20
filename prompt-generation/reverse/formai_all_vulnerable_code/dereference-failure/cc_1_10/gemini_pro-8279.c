//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 1024

// Function to print the longest word in a given string
void printLongestWord(char *str) {
    int max_word_length = 0;
    char *max_word = NULL;
    char *word_start = str;

    while (*str != '\0') {
        if (*str == ' ' || *str == '\n' || *str == '\t') {
            if (str - word_start > max_word_length) {
                max_word_length = str - word_start;
                max_word = word_start;
            }
            word_start = str + 1;
        }
        str++;
    }

    if (str - word_start > max_word_length) {
        max_word_length = str - word_start;
        max_word = word_start;
    }

    printf("The longest word in the given string is: %.*s\n", max_word_length, max_word);
}

// Function to count the number of words in a given string
int countWords(char *str) {
    int count = 0;
    int in_word = 0;

    while (*str != '\0') {
        if (*str == ' ' || *str == '\n' || *str == '\t') {
            in_word = 0;
        } else if (!in_word) {
            count++;
            in_word = 1;
        }
        str++;
    }

    return count;
}

// Function to reverse the order of words in a given string
void reverseWords(char *str) {
    int len = strlen(str);
    int i, j;
    char temp;

    // Reverse the entire string
    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    // Reverse each word in the string
    i = 0;
    while (str[i] != '\0') {
        j = i;
        while (str[j] != ' ' && str[j] != '\0') {
            j++;
        }
        j--;
        while (i < j) {
            temp = str[i];
            str[i] = str[j];
            str[j] = temp;
            i++;
            j--;
        }
        i = j + 1;
    }
}

// Function to remove all duplicate words from a given string
void removeDuplicateWords(char *str) {
    int i, j, len;
    char *temp;

    // Create a temporary array to store the unique words
    len = strlen(str);
    temp = (char *)malloc(len * sizeof(char));

    // Copy the first word to the temporary array
    i = 0;
    j = 0;
    while (str[i] != ' ' && str[i] != '\0') {
        temp[j++] = str[i++];
    }
    temp[j++] = ' ';

    // Iterate over the remaining words in the string
    while (str[i] != '\0') {
        // Skip any duplicate words
        while (str[i] == ' ' && str[i + 1] == ' ') {
            i++;
        }

        // Copy the unique word to the temporary array
        j = 0;
        while (str[i] != ' ' && str[i] != '\0') {
            temp[j++] = str[i++];
        }
        temp[j++] = ' ';
    }

    // Copy the temporary array back to the original string
    strcpy(str, temp);

    // Free the temporary array
    free(temp);
}

int main() {
    char str[MAX_LINE_LENGTH];

    // Get the input string from the user
    printf("Enter a string: ");
    fgets(str, MAX_LINE_LENGTH, stdin);

    // Print the longest word in the string
    printLongestWord(str);

    // Count the number of words in the string
    printf("The number of words in the string is: %d\n", countWords(str));

    // Reverse the order of words in the string
    reverseWords(str);
    printf("The string with the order of words reversed: %s\n", str);

    // Remove all duplicate words from the string
    removeDuplicateWords(str);
    printf("The string with all duplicate words removed: %s\n", str);

    return 0;
}