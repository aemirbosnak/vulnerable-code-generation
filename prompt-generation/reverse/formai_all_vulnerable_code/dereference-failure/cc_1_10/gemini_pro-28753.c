//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: genius
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to remove punctuation from a string
char* remove_punctuation(char* str) {
    char* new_str = malloc(strlen(str) + 1);
    int i = 0;
    int j = 0;
    while (str[i] != '\0') {
        if (str[i] != '.' && str[i] != ',' && str[i] != '!' && str[i] != '?' && str[i] != ';' && str[i] != ':') {
            new_str[j] = str[i];
            j++;
        }
        i++;
    }
    new_str[j] = '\0';
    return new_str;
}

// Function to split a string into an array of words
char** split_string(char* str) {
    char** words = malloc(sizeof(char*) * 100);
    int i = 0;
    int j = 0;
    int k = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ') {
            words[k][j] = '\0';
            k++;
            j = 0;
        } else {
            words[k][j] = str[i];
            j++;
        }
        i++;
    }
    words[k][j] = '\0';
    return words;
}

// Function to count the number of occurrences of a word in a string
int count_occurrences(char* str, char* word) {
    int count = 0;
    int i = 0;
    int j = 0;
    while (str[i] != '\0') {
        if (str[i] == word[j]) {
            j++;
        } else {
            j = 0;
        }
        if (j == strlen(word)) {
            count++;
            j = 0;
        }
        i++;
    }
    return count;
}

// Function to find the most frequent word in a string
char* find_most_frequent_word(char* str) {
    char* most_frequent_word = NULL;
    int max_count = 0;
    char** words = split_string(str);
    for (int i = 0; i < 100; i++) {
        if (words[i] != NULL) {
            int count = count_occurrences(str, words[i]);
            if (count > max_count) {
                max_count = count;
                most_frequent_word = words[i];
            }
        }
    }
    return most_frequent_word;
}

// Function to summarize a text
char* summarize_text(char* text) {
    char* summary = malloc(1000);
    char* most_frequent_word = find_most_frequent_word(text);
    sprintf(summary, "The most frequent word in the text is '%s'.", most_frequent_word);
    return summary;
}

int main() {
    char* text = "This is a sample text to be summarized. This text contains multiple sentences and some punctuation. The goal of the summarization is to identify the most frequent word in the text and use it to generate a concise summary.";

    char* summary = summarize_text(text);
    printf("%s\n", summary);

    return 0;
}