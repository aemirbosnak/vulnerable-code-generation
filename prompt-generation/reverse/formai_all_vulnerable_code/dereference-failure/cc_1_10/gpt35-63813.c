//FormAI DATASET v1.0 Category: Word Count Tool ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_FILE_NAME 100
#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

// Function to remove punctuations from a word
void remove_punctuations(char *word) {
    char *buffer = word;
    char *src = word;
    while (*src) {
        if (ispunct(*src)) {
            src++;
        } else {
            *buffer++ = *src++;
        }
    }
    *buffer = '\0';
}

// Function to convert all characters to lower case
void to_lower(char *word) {
    for (int i = 0; i < strlen(word); i++) {
        word[i] = tolower(word[i]);
    }
}

int main() {
    char file_name[MAX_FILE_NAME];
    printf("Enter the name of the file: ");
    scanf("%s", file_name);

    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    // Read the file content and store in one string
    char *content = malloc(sizeof(char) * MAX_WORDS * MAX_WORD_LENGTH);
    char *word = malloc(sizeof(char) * MAX_WORD_LENGTH);
    int count = 0;
    while (fscanf(fp, "%s", word) == 1) {
        remove_punctuations(word);
        to_lower(word);
        strcat(content, word);
        strcat(content, " ");
        count++;
    }
    free(word);
    fclose(fp);

    // Tokenize the content string by space
    char *token;
    char **tokens = malloc(sizeof(char*) * MAX_WORDS);
    token = strtok(content, " ");
    int i = 0;
    while (token != NULL) {
        tokens[i++] = strdup(token);
        token = strtok(NULL, " ");
    }
    free(content);

    // Count the words and occurrences
    int word_count = 0;
    char **words = malloc(sizeof(char*) * MAX_WORDS);
    int *occurrences = malloc(sizeof(int) * MAX_WORDS);

    for (int j = 0; j < i; j++) {
        int found = 0;
        for (int k = 0; k < word_count; k++) {
            if (strcmp(words[k], tokens[j]) == 0) {
                occurrences[k]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            words[word_count] = strdup(tokens[j]);
            occurrences[word_count++] = 1;
        }
    }
    free(tokens);

    // Sort the words by occurrences
    for (int j = 0; j < word_count; j++) {
        for (int k = j + 1; k < word_count; k++) {
            if (occurrences[j] < occurrences[k]) {
                int temp_occurrences = occurrences[j];
                occurrences[j] = occurrences[k];
                occurrences[k] = temp_occurrences;
                char *temp_word = words[j];
                words[j] = words[k];
                words[k] = temp_word;
            }
        }
    }

    // Print the result
    printf("\n");
    printf("Total words: %d\n", count);
    printf("Unique words: %d\n", word_count);
    printf("Word count:\n");
    for (int j = 0; j < word_count; j++) {
        printf("%s: %d\n", words[j], occurrences[j]);
        free(words[j]);
    }
    free(words);
    free(occurrences);

    return 0;
}