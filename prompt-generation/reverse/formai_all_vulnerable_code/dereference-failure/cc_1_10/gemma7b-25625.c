//Gemma-7B DATASET v1.0 Category: Text Summarizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 4096

typedef struct TextSummary {
    char **words;
    int numWords;
    int totalChars;
} TextSummary;

TextSummary *summarizeText(char *text) {
    TextSummary *summary = malloc(sizeof(TextSummary));
    summary->words = malloc(MAX_BUFFER_SIZE * sizeof(char *));
    summary->numWords = 0;
    summary->totalChars = 0;

    char *buffer = malloc(MAX_BUFFER_SIZE);
    int i = 0;
    while (text[i] != '\0') {
        char *word = malloc(MAX_BUFFER_SIZE);
        int j = 0;
        while (text[i] != ' ' && text[i] != '\0') {
            word[j] = text[i];
            i++;
            j++;
        }
        word[j] = '\0';
        summary->words[summary->numWords++] = word;
        summary->totalChars += j + 1;
    }

    free(buffer);
    return summary;
}

int main() {
    char *text = "This is a sample text that will be summarized. It is a long text, but it will be shortened by the summarizing program.";
    TextSummary *summary = summarizeText(text);

    printf("Number of words: %d\n", summary->numWords);
    printf("Total characters: %d\n", summary->totalChars);

    for (int i = 0; i < summary->numWords; i++) {
        printf("Word: %s\n", summary->words[i]);
    }

    free(summary->words);
    free(summary);

    return 0;
}