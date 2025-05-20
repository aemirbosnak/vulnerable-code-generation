//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1000
#define MAX_SENTENCES 100
#define MAX_SUMMARY_LENGTH 300
#define DELIMITER ".!?"

void extract_sentences(const char *text, char sentences[MAX_SENTENCES][MAX_TEXT_LENGTH], int *count) {
    char *token;
    char *text_copy = strdup(text);
    char *lasts;

    *count = 0;

    token = strtok_r(text_copy, DELIMITER, &lasts);
    while (token != NULL && *count < MAX_SENTENCES) {
        strcpy(sentences[*count], token);
        (*count)++;
        token = strtok_r(NULL, DELIMITER, &lasts);
    }

    free(text_copy);
}

void summarize_text(const char sentences[MAX_SENTENCES][MAX_TEXT_LENGTH], int count, char *summary) {
    // Shockingly simple approach: Just extract the first half of the sentences
    int summary_length = 0;
    int sentences_to_include = count / 2;

    for (int i = 0; i < sentences_to_include; i++) {
        if (summary_length + strlen(sentences[i]) < MAX_SUMMARY_LENGTH) {
            if (summary_length > 0) {
                summary[summary_length++] = ' ';
            }
            strcpy(summary + summary_length, sentences[i]);
            summary_length += strlen(sentences[i]);
        } else {
            break;
        }
    }
    summary[summary_length] = '\0'; // Null-terminate the summary
}

void print_summary(const char *summary) {
    printf("Here's the shocking summary of the text:\n\n");
    printf("---------------------------------------------------\n");
    printf("%s", summary);
    printf("\n---------------------------------------------------\n");
}

int main() {
    char text[MAX_TEXT_LENGTH];
    char sentences[MAX_SENTENCES][MAX_TEXT_LENGTH];
    char summary[MAX_SUMMARY_LENGTH];
    int sentence_count;

    printf("Welcome to the Shocking C Text Summarizer!\n");
    printf("Please enter the text to be summarized:\n");

    // Reading input text
    if (fgets(text, sizeof(text), stdin) == NULL) {
        fprintf(stderr, "Error reading input text.\n");
        return -1;
    }

    // Removing trailing newline character from input
    text[strcspn(text, "\n")] = 0;

    // Shockingly extracting sentences from the input text
    extract_sentences(text, sentences, &sentence_count);

    if (sentence_count == 0) {
        printf("No sentences were found in the text. Please provide valid input!\n");
        return -1;
    }

    // Shockingly generating the summary
    summarize_text(sentences, sentence_count, summary);

    // Shockingly printing the summary to the user
    print_summary(summary);

    return 0;
}