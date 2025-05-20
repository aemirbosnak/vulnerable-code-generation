//FormAI DATASET v1.0 Category: Text Summarizer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 2000
#define MAX_OUTPUT_LENGTH 500

/*
 * Helper function to count the number 
 * of sentences in the input text
 */
int count_sentences(char* text) {
    int count = 0;
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            count++;
        }
    }
    return count;
}

/*
 * Helper function to split the input text 
 * into an array of sentences
 */
char** split_sentences(char* text, int num_sentences) {
    char** sentences = malloc(num_sentences * sizeof(char*));
    int sentence_idx = 0;
    char* token = strtok(text, ".?!");
    while (token != NULL) {
        sentences[sentence_idx] = token;
        sentence_idx++;
        token = strtok(NULL, ".?!");
    }
    return sentences;
}

/*
 * Helper function to count the number 
 * of words in a sentence
 */
int count_words(char* sentence) {
    int count = 0;
    char* token = strtok(sentence, " ");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

/*
 * Helper function to split a sentence 
 * into an array of words
 */
char** split_words(char* sentence, int num_words) {
    char** words = malloc(num_words * sizeof(char*));
    int word_idx = 0;
    char* token = strtok(sentence, " ");
    while (token != NULL) {
        words[word_idx] = token;
        word_idx++;
        token = strtok(NULL, " ");
    }
    return words;
}

/*
 * Main function for text summarization
 */
char* summarize_text(char* text, int max_length) {
    int num_sentences = count_sentences(text);
    char** sentences = split_sentences(text, num_sentences);
    int num_words = 0;
    for (int i = 0; i < num_sentences; i++) {
        num_words += count_words(sentences[i]);
    }
    char** words = malloc(num_words * sizeof(char*));
    int word_idx = 0;
    for (int i = 0; i < num_sentences; i++) {
        char** sentence_words = split_words(sentences[i], count_words(sentences[i]));
        for (int j = 0; j < count_words(sentences[i]); j++) {
            words[word_idx] = sentence_words[j];
            word_idx++;
        }
    }
    char* summary = malloc(MAX_OUTPUT_LENGTH * sizeof(char));
    strcpy(summary, "");
    for (int i = 0; i < num_sentences; i++) {
        char temp[MAX_OUTPUT_LENGTH];
        if (strlen(summary) + strlen(sentences[i]) < MAX_OUTPUT_LENGTH) {
            strcat(summary, sentences[i]);
            strcat(summary, " ");
        }
    }
    return summary;
}

int main() {
    char text[MAX_INPUT_LENGTH];
    printf("Enter the text to summarize:\n");
    fgets(text, MAX_INPUT_LENGTH, stdin);
    char* summary = summarize_text(text, MAX_OUTPUT_LENGTH);
    printf("\nSummary:\n%s", summary);
    free(summary);
    return 0;
}