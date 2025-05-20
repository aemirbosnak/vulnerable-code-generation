//FormAI DATASET v1.0 Category: Text Summarizer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000
#define MAX_SUMMARY_LENGTH 100

char* summarize_text(char* input_text, int summary_length) {
    // Initialize variables
    int num_sentences = 0;
    int sentence_endings[MAX_STRING_LENGTH]; // Record position of end of each sentence
    char* summary = (char*) malloc(MAX_SUMMARY_LENGTH * sizeof(char));
    memset(summary, 0, MAX_SUMMARY_LENGTH * sizeof(char));
    
    // Find sentence endings
    for (int i = 0; i < strlen(input_text); i++) {
        if (input_text[i] == '.' || input_text[i] == '?' || input_text[i] == '!') {
            sentence_endings[num_sentences] = i;
            num_sentences++;
        }
    }

    // Summarize text
    int summary_index = 0; // Current position in summary string
    for (int i = 0; i < num_sentences; i++) {
        // Find length of current sentence
        int sentence_start = (i == 0) ? 0 : sentence_endings[i-1] + 2;
        int sentence_length = sentence_endings[i] - sentence_start + 1;

        // Copy sentence to temporary buffer
        char buffer[MAX_STRING_LENGTH];
        memcpy(buffer, &input_text[sentence_start], sentence_length);
        buffer[sentence_length] = '\0'; // Add null-terminating character

        // Add sentence to summary if it is short enough
        if (strlen(summary) + sentence_length + 1 < summary_length) {
            strcat(summary, buffer);
            strcat(summary, " ");
        } else {
            break; // Summary is already long enough
        }
    }

    return summary;
}

int main() {
    char input_text[MAX_STRING_LENGTH] = "This is a sample piece of text that contains multiple sentences. The purpose of this program is to summarize this text into a shorter version. The summary should include only the most important sentences. The program should be able to handle text of varying length and complexity. It should work by finding sentence endings and then selecting the most important sentences to include in the summary.";

    char* summary = summarize_text(input_text, MAX_SUMMARY_LENGTH);

    printf("Input text:\n%s\n\n", input_text);
    printf("Summary:\n%s", summary);

    free(summary);
    return 0;
}