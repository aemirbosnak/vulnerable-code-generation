//Gemma-7B DATASET v1.0 Category: Text Summarizer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LEN 1024

int main() {
    char text[MAX_TEXT_LEN];
    char summary[MAX_TEXT_LEN];
    int text_len = 0;
    int summary_len = 0;

    // Get the text from the user
    printf("Enter text: ");
    getline(text, MAX_TEXT_LEN, stdin);

    // Calculate the text length
    text_len = strlen(text);

    // Summarize the text
    summary_len = summarize_text(text, summary, text_len);

    // Print the summary
    printf("Summary: \n");
    printf("%s", summary);

    return 0;
}

int summarize_text(char *text, char *summary, int text_len) {
    int summary_len = 0;
    int i = 0;
    char *words[MAX_TEXT_LEN];

    // Split the text into words
    words[i] = strtok(text, " ");
    while (words[i] != NULL) {
        i++;
        words[i] = strtok(NULL, " ");
    }

    // Create a summary
    summary_len = write_summary(words, summary, text_len);

    return summary_len;
}

int write_summary(char *words, char *summary, int text_len) {
    int i = 0;
    int summary_len = 0;

    // Calculate the number of words in the text
    int num_words = count_words(words);

    // Create a summary of the text
    summary_len = write_summary_sentences(words, summary, num_words);

    return summary_len;
}

int count_words(char *words[]) {
    int i = 0;
    int num_words = 0;

    for (i = 0; words[i] != NULL; i++) {
        num_words++;
    }

    return num_words;
}

int write_summary_sentences(char *words, char *summary, int num_words) {
    int i = 0;
    int summary_len = 0;

    // Create a summary of the text in the form of sentences
    for (i = 0; i < num_words; i++) {
        strcat(summary, words[i]);
        strcat(summary, " ");
    }

    summary_len = strlen(summary);

    return summary_len;
}