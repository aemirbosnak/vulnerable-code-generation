//FormAI DATASET v1.0 Category: Text Summarizer ; Style: decentralized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SUMMARY_SIZE 200

char* summarize_text(char* text, int max_summary_size);

int main() {
    char text[] = "This is a long piece of text that needs to be summarized. It should be shortened to a maximum of 200 characters while still retaining its key points.";
    char* summary;

    summary = summarize_text(text, MAX_SUMMARY_SIZE);

    printf("%s", summary);

    free(summary);

    return 0;
}

char* summarize_text(char* text, int max_summary_size) {
    int text_length = strlen(text);
    char* summary = malloc(max_summary_size);
    int i = 0, j = 0;

    // Copy up to max_shorten characters or until the end of the text
    while (i < max_summary_size && i < text_length) {
        summary[j] = text[i];
        i++;
        j++;
    }

    // Attempt to find the last sentence if the summary is cut off
    if (i == max_summary_size) {
        while (j > 0 && summary[j] != '.') {
            j--;
        }

        // If no sentence is found, simply cut off the summary
        if (j == 0) {
            summary[max_summary_size] = '\0';
        } else {
            summary[j+1] = '\0';
        }
    } else {
        summary[i] = '\0';
    }

    return summary;
}