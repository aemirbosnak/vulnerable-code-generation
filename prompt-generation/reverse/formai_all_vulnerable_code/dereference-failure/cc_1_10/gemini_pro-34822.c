//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a sentence.
#define MAX_SENTENCE_LENGTH 1024

// Define the maximum number of sentences in a paragraph.
#define MAX_PARAGRAPH_LENGTH 100

// Define the maximum number of paragraphs in a text.
#define MAX_TEXT_LENGTH 10

// Define the maximum length of a summary.
#define MAX_SUMMARY_LENGTH 1024

// Define the minimum number of sentences in a summary.
#define MIN_SUMMARY_LENGTH 1

// Get the next sentence from the text.
char *get_next_sentence(char *text) {
    char *sentence = strtok(text, ".");
    return sentence;
}

// Get the next paragraph from the text.
char *get_next_paragraph(char *text) {
    char *paragraph = strtok(text, "\n\n");
    return paragraph;
}

// Get the next text from the file.
char *get_next_text(FILE *file) {
    char *text = NULL;
    size_t len = 0;
    getline(&text, &len, file);
    return text;
}

// Summarize the text.
char *summarize_text(char *text, int num_sentences) {
    // Check if the number of sentences is valid.
    if (num_sentences < MIN_SUMMARY_LENGTH || num_sentences > MAX_SUMMARY_LENGTH) {
        return NULL;
    }

    // Get the first sentence from the text.
    char *sentence = get_next_sentence(text);

    // Create the summary.
    char *summary = malloc(MAX_SUMMARY_LENGTH);
    strcpy(summary, sentence);

    // Get the remaining sentences from the text.
    for (int i = 1; i < num_sentences; i++) {
        sentence = get_next_sentence(NULL);
        strcat(summary, " ");
        strcat(summary, sentence);
    }

    // Return the summary.
    return summary;
}

// Print the summary.
void print_summary(char *summary) {
    printf("%s\n", summary);
}

// Main function.
int main() {
    // Open the text file.
    FILE *file = fopen("text.txt", "r");
    if (file == NULL) {
        printf("Could not open the text file.\n");
        return 1;
    }

    // Get the text from the file.
    char *text = get_next_text(file);

    // Summarize the text.
    char *summary = summarize_text(text, 5);

    // Print the summary.
    print_summary(summary);

    // Close the text file.
    fclose(file);

    // Free the memory allocated for the summary.
    free(summary);

    return 0;
}