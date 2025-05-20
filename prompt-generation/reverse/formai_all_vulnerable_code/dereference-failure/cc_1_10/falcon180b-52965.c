//Falcon-180B DATASET v1.0 Category: Text processing ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 1000

// Function to tokenize a string into words
void tokenize(char* str, char** words, int* num_words) {
    int i = 0;
    char* token = strtok(str, ",.!?;:\"'");
    while (token!= NULL && i < MAX_WORDS) {
        words[i] = token;
        i++;
        token = strtok(NULL, ",.!?;:\"'");
    }
    *num_words = i;
}

// Function to reverse the order of the words in a string
void reverse_words(char* str) {
    char* token = strtok(str, ",.!?;:\"'");
    char* reversed_str = NULL;
    while (token!= NULL) {
        char* next_token = strtok(NULL, ",.!?;:\"'");
        if (next_token == NULL) {
            strcat(reversed_str, token);
            strcat(reversed_str, " ");
        } else {
            strcat(reversed_str, token);
            strcat(reversed_str, " ");
            strcat(reversed_str, next_token);
            strcat(reversed_str, " ");
        }
        token = next_token;
    }
    strcpy(str, reversed_str);
    free(reversed_str);
}

int main() {
    char input_str[10000];
    printf("Enter a string: ");
    fgets(input_str, sizeof(input_str), stdin);

    // Remove trailing newline character
    input_str[strcspn(input_str, "\n")] = '\0';

    // Convert all characters to lowercase
    for (int i = 0; input_str[i]!= '\0'; i++) {
        input_str[i] = tolower(input_str[i]);
    }

    // Tokenize the string into words
    char* words[MAX_WORDS];
    int num_words;
    tokenize(input_str, words, &num_words);

    // Reverse the order of the words
    reverse_words(input_str);

    // Print the modified string
    printf("Modified string: %s\n", input_str);

    // Print the number of words
    printf("Number of words: %d\n", num_words);

    // Print the reversed string
    printf("Reversed string: ");
    for (int i = 0; i < num_words; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");

    return 0;
}