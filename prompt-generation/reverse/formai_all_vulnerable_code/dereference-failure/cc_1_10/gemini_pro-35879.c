//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to split the input text into sentences
char** split_sentences(char* text, int* num_sentences) {
    char** sentences = NULL;
    char* sentence = strtok(text, ".!?");
    while (sentence != NULL) {
        sentences = realloc(sentences, (*num_sentences + 1) * sizeof(char*));
        sentences[*num_sentences] = sentence;
        (*num_sentences)++;
        sentence = strtok(NULL, ".!?");
    }
    return sentences;
}

// Function to summarize the text
char* summarize_text(char** sentences, int num_sentences) {
    // Calculate the average sentence length
    int total_length = 0;
    for (int i = 0; i < num_sentences; i++) {
        total_length += strlen(sentences[i]);
    }
    int avg_length = total_length / num_sentences;

    // Create a new string to store the summary
    char* summary = malloc((avg_length + 1) * num_sentences * sizeof(char));
    int summary_length = 0;

    // Add the first sentence to the summary
    strcat(summary, sentences[0]);
    summary_length += strlen(sentences[0]);

    // Add the remaining sentences to the summary, one by one
    for (int i = 1; i < num_sentences; i++) {
        // Check if the summary is already too long
        if (summary_length + strlen(sentences[i]) > avg_length * num_sentences) {
            break;
        }
        // Add the sentence to the summary
        strcat(summary, " ");
        strcat(summary, sentences[i]);
        summary_length += strlen(sentences[i]) + 1;
    }

    // Return the summary
    return summary;
}

// Function to print the text and its summary
void print_text_and_summary(char* text, char* summary) {
    printf("Original Text:\n%s\n", text);
    printf("\nSummary:\n%s\n", summary);
}

int main() {
    // Get the input text from the user
    char text[1000];
    printf("Enter your text:\n");
    fgets(text, 1000, stdin);

    // Split the text into sentences
    int num_sentences = 0;
    char** sentences = split_sentences(text, &num_sentences);

    // Summarize the text
    char* summary = summarize_text(sentences, num_sentences);

    // Print the text and its summary
    print_text_and_summary(text, summary);

    // Free the memory allocated for the sentences and the summary
    free(sentences);
    free(summary);

    return 0;
}