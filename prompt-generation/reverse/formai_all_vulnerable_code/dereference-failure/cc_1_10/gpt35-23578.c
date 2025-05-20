//FormAI DATASET v1.0 Category: Text Summarizer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_SIZE 5000
#define MAX_SUMMARY_SIZE 200

typedef struct {
    char word[50];
    int frequency;
} WordFrequency;

// Helper function to check if word is already in array of WordFrequency objects
int contains_word(char *word, WordFrequency *word_freq, int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(word_freq[i].word, word) == 0) {
            word_freq[i].frequency += 1;
            return 1;
        }
    }
    return 0;
}

// Function to remove punctuation from a string
void remove_punctuation(char *str) {
    char *p = str;
    while (*p) {
        if (ispunct(*p)) {
            memmove(p, p + 1, strlen(p + 1) + 1);
        } else {
            p++;
        }
    }
}

// Function to get the top n frequent words in the input string
WordFrequency* get_top_words(char *input, int n) {
    // Remove punctuation from input string
    remove_punctuation(input);
    // Initialize array of WordFrequency objects
    WordFrequency *word_freq = malloc(n * sizeof(WordFrequency));
    int size = 0;
    // Tokenize input string and count frequency of each word
    char *token = strtok(input, " ");
    while (token != NULL) {
        if (!contains_word(token, word_freq, size)) {
            if (size < n) {
                strcpy(word_freq[size].word, token);
                word_freq[size].frequency = 1;
                size++;
            } else {
                int min_frequency = 999999; // set initial value to a large number
                int min_index = -1;
                for (int i = 0; i < n; i++) {
                    if (word_freq[i].frequency < min_frequency) {
                        min_frequency = word_freq[i].frequency;
                        min_index = i;
                    }
                }
                if (word_freq[min_index].frequency < 2) {
                    strcpy(word_freq[min_index].word, token);
                    word_freq[min_index].frequency = 1;
                } else {
                    word_freq[min_index].frequency = 0;
                    contains_word(token, word_freq, size);
                }
            }
        }
        token = strtok(NULL, " ");
    }
    return word_freq;
}

// Function to get the summary of the input string
char* get_summary(char *input) {
    // Get top 10 frequent words in input string
    WordFrequency *top_words = get_top_words(input, 10);
    // Tokenize input string into sentences
    char *token = strtok(input, ".");
    char *summary = malloc(MAX_SUMMARY_SIZE * sizeof(char));
    strcpy(summary, "");
    // Loop through sentences and check if they contain a top word
    while (token != NULL) {
        int found_top_word = 0;
        for (int i = 0; i < 10; i++) {
            if (strstr(token, top_words[i].word) != NULL) {
                found_top_word = 1;
                strcat(summary, token);
                strcat(summary, ".");
                break;
            }
        }
        if (found_top_word == 0 && strlen(summary) < MAX_SUMMARY_SIZE) {
            strcat(summary, token);
            strcat(summary, ".");
        }
        token = strtok(NULL, ".");
    }
    free(top_words);
    return summary;
}

int main() {
    char input[MAX_INPUT_SIZE];
    printf("Enter the text to summarize: \n");
    fgets(input, MAX_INPUT_SIZE, stdin);
    char *summary = get_summary(input);
    printf("Summary: \n%s\n", summary);
    free(summary);
    return 0;
}