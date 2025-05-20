//FormAI DATASET v1.0 Category: Text Summarizer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 10000
#define MAX_SUMMARY_LENGTH 1000

typedef struct word_count_t {
    char word[50];
    int count;
} word_count;

// Function to split the input text into an array of words
char** split_words(char* input_text, int* num_words) {
    int i;
    char** words = malloc(MAX_INPUT_LENGTH * sizeof(char*));
    for (i = 0; i < MAX_INPUT_LENGTH; i++) {
        words[i] = malloc(50 * sizeof(char));
    }
    char* token = strtok(input_text, " ");
    i = 0;
    while(token != NULL) {
        if (strlen(token) > 1) { // ignore single letter words
            strcpy(words[i], token);
            i++;
        }
        token = strtok(NULL, " ");
    }
    *num_words = i;
    return words;
}

// Function to count the frequency of each word in the input text
word_count* count_words(char** words, int num_words, int* num_unique_words) {
    int i, j, k;
    word_count* unique_words = malloc(num_words * sizeof(word_count));
    char temp_word[50];
    int temp_count;
    for (i = 0; i < num_words; i++) {
        strcpy(temp_word, words[i]);
        temp_count = 1;
        for (j = i + 1; j < num_words; j++) {
            if (strcmp(temp_word, words[j]) == 0) {
                temp_count++;
                for (k = j; k < num_words - 1; k++) {
                    strcpy(words[k], words[k+1]);
                }
                num_words--;
                j--;
            }
        }
        strcpy(unique_words[*num_unique_words].word, temp_word);
        unique_words[*num_unique_words].count = temp_count;
        (*num_unique_words)++;
    }
    unique_words = realloc(unique_words, (*num_unique_words) * sizeof(word_count));
    return unique_words;
}

// Function to sort the unique words by frequency in descending order
void sort_words(word_count* unique_words, int num_unique_words) {
    int i, j;
    word_count temp_word;
    for (i = 0; i < num_unique_words; i++) {
        for (j = i + 1; j < num_unique_words; j++) {
            if (unique_words[i].count < unique_words[j].count) {
                temp_word = unique_words[i];
                unique_words[i] = unique_words[j];
                unique_words[j] = temp_word;
            }
        }
    }
}

int main() {
    char input_text[MAX_INPUT_LENGTH];
    char summary_text[MAX_SUMMARY_LENGTH];
    printf("Enter the input text (up to %d characters):\n", MAX_INPUT_LENGTH);
    fgets(input_text, MAX_INPUT_LENGTH, stdin);
    
    int num_words = 0;
    char** words = split_words(input_text, &num_words);
    
    int num_unique_words = 0;
    word_count* unique_words = count_words(words, num_words, &num_unique_words);
    
    sort_words(unique_words, num_unique_words);
    
    int summary_length = 0;
    int i = 0;
    while (summary_length < MAX_SUMMARY_LENGTH && i < num_unique_words) {
        strcat(summary_text, unique_words[i].word);
        strcat(summary_text, " ");
        summary_length += strlen(unique_words[i].word) + 1;
        i++;
    }
    summary_text[summary_length] = '\0';
    
    printf("\nSummary text (up to %d characters):\n\n", MAX_SUMMARY_LENGTH);
    printf("%s\n", summary_text);
    
    for (i = 0; i < MAX_INPUT_LENGTH; i++) {
        free(words[i]);
    }
    free(words);
    free(unique_words);
    
    return 0;
}