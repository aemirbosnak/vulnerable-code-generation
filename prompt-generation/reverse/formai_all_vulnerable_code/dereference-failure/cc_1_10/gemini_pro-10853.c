//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a sentence
#define MAX_SENTENCE_LENGTH 100

// Get the text from the user
char *get_text(void) {
    char *text = NULL;
    size_t len = 0;
    printf("Enter the text you want to summarize: ");
    getline(&text, &len, stdin);
    return text;
}

// Summarize the text
char *summarize_text(char *text) {
    // Create a new string to hold the summary
    char *summary = malloc(strlen(text) / 2);

    // Split the text into sentences
    char *sentences[100];
    int num_sentences = 0;
    char *sentence = strtok(text, ".");
    while (sentence != NULL) {
        sentences[num_sentences++] = sentence;
        sentence = strtok(NULL, ".");
    }

    // Get the most important sentences
    char *important_sentences[10];
    int num_important_sentences = 0;
    for (int i = 0; i < num_sentences; i++) {
        if (strlen(sentences[i]) > MAX_SENTENCE_LENGTH) {
            important_sentences[num_important_sentences++] = sentences[i];
        }
    }

    // Create the summary
    strcpy(summary, "");
    for (int i = 0; i < num_important_sentences; i++) {
        strcat(summary, important_sentences[i]);
        strcat(summary, ". ");
    }

    // Return the summary
    return summary;
}

// Print the summary
void print_summary(char *summary) {
    printf("Summary: %s\n", summary);
}

// Main function
int main(void) {
    // Get the text from the user
    char *text = get_text();

    // Summarize the text
    char *summary = summarize_text(text);

    // Print the summary
    print_summary(summary);

    // Free the memory allocated for the text and the summary
    free(text);
    free(summary);

    return 0;
}