//Gemma-7B DATASET v1.0 Category: Text Summarizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main() {
    char text[MAX_BUFFER_SIZE];
    char summary[MAX_BUFFER_SIZE];
    int text_length = 0;
    int summary_length = 0;

    printf("Enter text: ");
    fgets(text, MAX_BUFFER_SIZE, stdin);

    // Calculate text length
    text_length = strlen(text);

    // Summarize text
    summary_length = summarize_text(text, summary, text_length);

    // Print summary
    printf("Summary: %s", summary);

    return 0;
}

int summarize_text(char *text, char *summary, int text_length) {
    int i = 0;
    int j = 0;
    char *keywords[MAX_BUFFER_SIZE];
    int keyword_count = 0;

    // Extract keywords from text
    extract_keywords(text, keywords, &keyword_count);

    // Create summary using keywords
    for (i = 0; i < keyword_count; i++) {
        summary[j++] = keywords[i];
    }

    // Return summary length
    return j;
}

int extract_keywords(char *text, char **keywords, int *keyword_count) {
    char *words[MAX_BUFFER_SIZE];
    int word_count = 0;
    int i = 0;

    // Tokenize text
    tokenize(text, words);

    // Count keywords
    for (i = 0; words[i] != NULL; i++) {
        keywords[word_count++] = words[i];
    }

    *keyword_count = word_count;

    return 0;
}

int tokenize(char *text, char **words) {
    char *ptr = text;
    char *word = NULL;
    int i = 0;

    words[i] = NULL;

    // Loop over text until end of text is reached
    while (ptr && *ptr) {
        // Check if word is ending
        if (*ptr == ' ' || *ptr == '\n' || *ptr == '\t' || *ptr == '\0') {
            // Null terminate word
            words[i++] = word;
            word = NULL;
        } else if (word == NULL) {
            // Allocate memory for word
            word = malloc(MAX_BUFFER_SIZE);
            word[0] = '\0';
            word = ptr;
        } else {
            // Append character to word
            word[i++] = *ptr;
        }

        ptr++;
    }

    return 0;
}