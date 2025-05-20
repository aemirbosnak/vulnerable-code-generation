//Falcon-180B DATASET v1.0 Category: Text processing ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

// Function to remove leading and trailing spaces from a string
void trim(char *str) {
    char *end;

    // Trim leading spaces
    while (isspace(*str)) {
        str++;
    }

    // Trim trailing spaces
    end = str + strlen(str) - 1;
    while (isspace(*end)) {
        end--;
        *end = '\0';
    }
}

// Function to split a string into words
void split(char *str, char **words) {
    char *token;
    int count = 0;

    // Split string into words
    token = strtok(str, " ");
    while (token!= NULL && count < MAX_WORDS) {
        words[count] = malloc(MAX_WORD_LENGTH);
        strcpy(words[count], token);
        count++;
        token = strtok(NULL, " ");
    }

    // Add null terminator to last element
    words[count] = NULL;
}

// Function to reverse the order of words in a string
void reverse(char **words) {
    char *temp;
    int i, j;

    // Reverse the order of words
    for (i = 0, j = strlen(words[0]) - 1; i < j; i++, j--) {
        temp = words[0][i];
        words[0][i] = words[0][j];
        words[0][j] = temp;
    }
}

// Function to capitalize the first letter of each word in a string
void capitalize(char **words) {
    int i;

    // Capitalize the first letter of each word
    for (i = 0; words[i]!= NULL; i++) {
        words[i][0] = toupper(words[i][0]);
    }
}

int main() {
    char input[MAX_WORD_LENGTH];
    char *words[MAX_WORDS];
    int count = 0;

    // Read input string
    printf("Enter a string: ");
    scanf("%s", input);

    // Trim input string
    trim(input);

    // Split input string into words
    split(input, words);

    // Reverse the order of words
    reverse(words);

    // Capitalize the first letter of each word
    capitalize(words);

    // Print reversed and capitalized string
    printf("Reversed and capitalized string: ");
    for (int i = 0; words[i]!= NULL; i++) {
        printf("%s ", words[i]);
    }

    return 0;
}