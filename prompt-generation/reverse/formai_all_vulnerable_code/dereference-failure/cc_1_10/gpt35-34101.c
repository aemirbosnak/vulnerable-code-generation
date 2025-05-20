//FormAI DATASET v1.0 Category: Text Summarizer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_TEXT_LEN = 10000;
const int MAX_SUMMARY_LEN = 1000;
const int DEFAULT_NUM_SENTENCES = 3;

/* Count the number of sentences in the given text */
int count_sentences(char* text) {
    int count = 0;
    int i = 0;

    while (text[i] != '\0') {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            count++;
        }
        i++;
    }

    return count;
}

/* Given a text and a number of sentences, return a summary of the text */
char* summarize_text(char* text, int num_sentences) {
    /* Allocate memory for the summary */
    char* summary = (char*)malloc(MAX_SUMMARY_LEN * sizeof(char));
    if (summary == NULL) {
        printf("Error: could not allocate memory for summary\n");
        exit(1);
    }
    memset(summary, 0, MAX_SUMMARY_LEN);

    /* Tokenize the text into sentences */
    char* sentence = strtok(text, ".!?");
    int sentence_count = 0;
    while (sentence != NULL && sentence_count < num_sentences) {
        /* Append the sentence to the summary */
        strcat(summary, sentence);
        strcat(summary, ". ");

        /* Get the next sentence */
        sentence = strtok(NULL, ".!?");
        sentence_count++;
    }

    /* Remove any trailing whitespace */
    int len = strlen(summary);
    while (len > 0 && (summary[len-1] == ' ' || summary[len-1] == '\t' || summary[len-1] == '\n')) {
        summary[len-1] = '\0';
        len--;
    }

    return summary;
}

int main() {
    /* Allocate memory for the text */
    char* text = (char*)malloc(MAX_TEXT_LEN * sizeof(char));
    if (text == NULL) {
        printf("Error: could not allocate memory for text\n");
        exit(1);
    }

    /* Read the text from stdin */
    printf("Enter text to summarize (maximum %d characters):\n", MAX_TEXT_LEN);
    fgets(text, MAX_TEXT_LEN, stdin);

    /* Remove any trailing whitespace from the text */
    int len = strlen(text);
    while (len > 0 && (text[len-1] == ' ' || text[len-1] == '\t' || text[len-1] == '\n')) {
        text[len-1] = '\0';
        len--;
    }

    /* Count the number of sentences in the text */
    int num_sentences = count_sentences(text);

    /* Determine the number of sentences to include in the summary */
    int summary_length = DEFAULT_NUM_SENTENCES;
    if (num_sentences < DEFAULT_NUM_SENTENCES) {
        summary_length = num_sentences;
    }

    /* Generate the summary of the text */
    char* summary = summarize_text(text, summary_length);

    /* Print the summary */
    printf("\nSummary:\n");
    printf("%s\n", summary);

    /* Free the memory allocated for the text and summary */
    free(text);
    free(summary);

    return 0;
}