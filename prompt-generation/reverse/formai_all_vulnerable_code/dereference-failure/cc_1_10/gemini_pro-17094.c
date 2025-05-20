//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to remove punctuation from a string
char *remove_punctuation(char *str) {
    char *new_str = malloc(strlen(str) + 1);
    int i, j;
    for (i = 0, j = 0; str[i] != '\0'; i++) {
        if (str[i] != '.' && str[i] != ',' && str[i] != '!' && str[i] != '?' && str[i] != ';' && str[i] != ':') {
            new_str[j++] = str[i];
        }
    }
    new_str[j] = '\0';
    return new_str;
}

// Function to split a string into an array of words
char **split_words(char *str) {
    char **words = malloc(sizeof(char *) * 100);
    char *word = strtok(str, " ");
    int i = 0;
    while (word != NULL) {
        words[i++] = word;
        word = strtok(NULL, " ");
    }
    words[i] = NULL;
    return words;
}

// Function to count the frequency of each word in an array of words
int *count_words(char **words) {
    int *counts = malloc(sizeof(int) * 100);
    int i, j;
    for (i = 0; words[i] != NULL; i++) {
        counts[i] = 0;
        for (j = 0; words[j] != NULL; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                counts[i]++;
            }
        }
    }
    return counts;
}

// Function to find the most frequent word in an array of words
char *most_frequent_word(char **words, int *counts) {
    int max_count = 0;
    int max_index = 0;
    for (int i = 0; words[i] != NULL; i++) {
        if (counts[i] > max_count) {
            max_count = counts[i];
            max_index = i;
        }
    }
    return words[max_index];
}

// Main function
int main() {
    // Get the input text from the user
    char text[1000];
    printf("Enter the text you want to summarize: ");
    gets(text);

    // Remove punctuation from the text
    char *cleaned_text = remove_punctuation(text);

    // Split the text into an array of words
    char **words = split_words(cleaned_text);

    // Count the frequency of each word in the array of words
    int *counts = count_words(words);

    // Find the most frequent word in the array of words
    char *most_frequent = most_frequent_word(words, counts);

    // Print the summary
    printf("The summary of the text is: %s", most_frequent);

    // Free the allocated memory
    free(cleaned_text);
    free(words);
    free(counts);

    return 0;
}