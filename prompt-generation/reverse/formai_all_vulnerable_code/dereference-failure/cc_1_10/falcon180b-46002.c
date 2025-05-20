//Falcon-180B DATASET v1.0 Category: Error handling ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function to split string into words
void split_string(char *str, char **words) {
    int i = 0, j = 0, k = 0;
    char *token;

    // Remove leading/trailing spaces
    while (isspace(*(str + i)))
        i++;
    while (isspace(*(str + j - 1)))
        j--;

    // Copy string without spaces
    strncpy(str, str + i, j - i);
    str[j - i] = '\0';

    // Tokenize string
    token = strtok(str, " ");
    while (token!= NULL) {
        words[k++] = token;
        token = strtok(NULL, " ");
    }
}

int main() {
    char input_string[MAX_SIZE];
    char *words[MAX_SIZE];
    int num_words;

    // Get input string from user
    printf("Enter a string: ");
    fgets(input_string, MAX_SIZE, stdin);

    // Split string into words
    split_string(input_string, words);
    num_words = strlen(words);

    // Reverse the order of the words
    for (int i = 0; i < num_words / 2; i++) {
        char *temp = words[i];
        words[i] = words[num_words - i - 1];
        words[num_words - i - 1] = temp;
    }

    // Print reversed string
    printf("Reversed string: ");
    for (int i = 0; i < num_words; i++) {
        printf("%s ", words[i]);
    }

    return 0;
}