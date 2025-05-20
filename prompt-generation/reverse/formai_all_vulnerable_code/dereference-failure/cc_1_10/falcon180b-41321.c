//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main() {
    char input[MAX_SIZE];
    char *token;
    int count = 0;

    printf("Enter a string: ");
    fgets(input, MAX_SIZE, stdin);

    // Remove leading and trailing white spaces
    input[strcspn(input, "\n")] = '\0';
    input[strspn(input, " ")] = '\0';

    // Count the number of words in the string
    token = strtok(input, " ");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, " ");
    }

    // Reverse the order of the words
    char *reversed = malloc(MAX_SIZE);
    strcpy(reversed, input);
    char *temp = strtok(reversed, " ");
    while (temp!= NULL) {
        strcat(input, temp);
        strcat(input, " ");
        temp = strtok(NULL, " ");
    }

    // Capitalize the first letter of each word
    char *capitalized = malloc(MAX_SIZE);
    strcpy(capitalized, input);
    strcat(capitalized, " ");
    char *word = strtok(capitalized, " ");
    while (word!= NULL) {
        strcat(capitalized, toupper(word[0]));
        strcat(capitalized, word + 1);
        strcat(capitalized, " ");
        word = strtok(NULL, " ");
    }

    // Print the modified string
    printf("Modified string: %s\n", capitalized);
    printf("Number of words: %d\n", count);

    return 0;
}