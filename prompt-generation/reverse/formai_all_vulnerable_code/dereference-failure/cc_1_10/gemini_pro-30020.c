//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom hash function for strings
unsigned long hash(char *str) {
    unsigned long h = 5381;
    while (*str) {
        h = ((h << 5) + h) + *str++;
    }
    return h;
}

// Custom comparator for strings
int compare(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

// Function to summarize a text
char *summarize(char *text, int num_sentences) {
    // Split the text into sentences
    char *sentences[100];
    int num_sentences_found = 0;
    char *sentence_start = text;
    while (*text) {
        if (*text == '.' || *text == '!' || *text == '?') {
            sentences[num_sentences_found++] = sentence_start;
            sentence_start = text + 1;
            *text = '\0';
        }
        text++;
    }

    // Calculate the frequency of each sentence
    int frequencies[100];
    for (int i = 0; i < num_sentences_found; i++) {
        frequencies[i] = 0;
        for (int j = 0; j < num_sentences_found; j++) {
            if (strcmp(sentences[i], sentences[j]) == 0) {
                frequencies[i]++;
            }
        }
    }

    // Sort the sentences by frequency in descending order
    qsort(sentences, num_sentences_found, sizeof(char *), compare);

    // Create the summary
    char *summary = malloc(1000);
    strcpy(summary, "");
    for (int i = 0; i < num_sentences; i++) {
        strcat(summary, sentences[i]);
        strcat(summary, " ");
    }

    return summary;
}

// Main function
int main() {
    // Get the input text
    char *text = "This is a sample text. This text has multiple sentences. The goal is to summarize this text into a few sentences. The summary should include the most important sentences from the original text.";

    // Summarize the text
    char *summary = summarize(text, 3);

    // Print the summary
    printf("Summary: %s\n", summary);

    return 0;
}