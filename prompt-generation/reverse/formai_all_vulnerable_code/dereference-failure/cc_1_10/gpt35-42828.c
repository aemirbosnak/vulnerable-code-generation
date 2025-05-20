//FormAI DATASET v1.0 Category: Text Summarizer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT 1000
#define MAX_SENTENCES 50
#define MAX_SUMMARY 100

// Function prototypes
int get_text(char text[]);
void clean_text(char text[]);
int count_sentences(char text[]);
void find_sentences(char text[], char sentences[][MAX_INPUT], int n_sentences);
void summarize(char sentences[][MAX_INPUT], char summary[][MAX_INPUT], int n_sentences, int n_summary);
void print_summary(char summary[][MAX_INPUT], int n_summary);

int main() {
    // Variables
    char text[MAX_INPUT];
    char sentences[MAX_SENTENCES][MAX_INPUT];
    char summary[MAX_SUMMARY][MAX_INPUT];
    int n_sentences, n_summary;

    // Get input text
    n_sentences = get_text(text);

    // Clean input text
    clean_text(text);

    // Count number of sentences
    n_sentences = count_sentences(text);

    // Find all sentences and store them in array
    find_sentences(text, sentences, n_sentences);

    // Summarize the text
    n_summary = n_sentences / 2;
    summarize(sentences, summary, n_sentences, n_summary);

    // Print summary
    print_summary(summary, n_summary);

    return 0;
}

/**
 * Gets input text from user and returns
 * the number of sentences in the text.
 */
int get_text(char text[]) {
    int i = 0, c, n_sentences = 0;

    printf("Enter text to summarize:\n");
    while ((c = getchar()) != '\n' && i < MAX_INPUT - 1) {
        text[i++] = c;
        if (c == '.' || c == '?' || c == '!') n_sentences++;
    }
    text[i] = '\0';

    return n_sentences;
}

/**
 * Cleans input text by removing extra spaces
 * and new line characters.
 */
void clean_text(char text[]) {
    int i, j;
    char temp[MAX_INPUT];

    for (i = 0, j = 0; i < strlen(text); i++) {
        if (text[i] == '\n' || text[i] == '\r') {
            // Do nothing
        } else if (isspace(text[i]) && isspace(text[i - 1])) {
            // Do nothing
        } else {
            temp[j++] = text[i];
        }
    }
    temp[j] = '\0';

    strcpy(text, temp);
}

/**
 * Counts the number of sentences in the text.
 */
int count_sentences(char text[]) {
    int i, n_sentences = 0;

    for (i = 0; i < strlen(text); i++) {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') n_sentences++;
    }

    return n_sentences;
}

/**
 * Finds all sentences in the text and stores them
 * in a 2D array.
 */
void find_sentences(char text[], char sentences[][MAX_INPUT], int n_sentences) {
    int i, j, k;

    for (i = 0, j = 0, k = 0; i < strlen(text); i++) {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            sentences[j][k++] = text[i];
            sentences[j++][k] = '\0';
            k = 0;
        } else {
            sentences[j][k++] = text[i];
        }
    }
}

/**
 * Summarizes the text by selecting the most important
 * sentences and storing them in a summary array.
 */
void summarize(char sentences[][MAX_INPUT], char summary[][MAX_INPUT], int n_sentences, int n_summary) {
    int i, j, k, importance[MAX_SENTENCES] = {0};

    // Find the importance of each sentence by counting the number of words
    for (i = 0; i < n_sentences; i++) {
        for (j = 0; j < strlen(sentences[i]); j++) {
            if (isspace(sentences[i][j])) {
                importance[i]++;
            }
        }
        importance[i]++;
    }

    // Select the most important sentences and store them in summary array
    for (i = 0; i < n_summary; i++) {
        k = 0;
        for (j = 0; j < n_sentences; j++) {
            if (importance[j] > importance[k]) {
                k = j;
            }
        }
        importance[k] = 0;
        strcpy(summary[i], sentences[k]);
    }
}

/**
 * Prints the summary to the console.
 */
void print_summary(char summary[][MAX_INPUT], int n_summary) {
    int i;

    printf("\nSummary:\n");
    for (i = 0; i < n_summary; i++) {
        printf("%s", summary[i]);
    }
}