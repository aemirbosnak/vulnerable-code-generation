//FormAI DATASET v1.0 Category: Text Summarizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000
#define PARANOID_FACTOR 100

int main(int argc, char const *argv[])
{
    char text[MAX_STRING_LENGTH];
    int summary_length;
    float paranoia_factor;
    char *summary = malloc(sizeof(char) * MAX_STRING_LENGTH);

    // Prompt user for text and summary length
    printf("Enter the text: ");
    fgets(text, MAX_STRING_LENGTH, stdin);
    printf("Enter the length of the summary: ");
    scanf("%d", &summary_length);

    // Check for possible buffer overflow attack
    if (strlen(text) > MAX_STRING_LENGTH/ PARANOID_FACTOR ) {
        printf("Possible buffer overflow attack detected! Exiting...\n");
        exit(EXIT_FAILURE);
    }

    // Check for possible integer overflow attack
    if (summary_length > MAX_STRING_LENGTH/ PARANOID_FACTOR) {
        printf("Possible integer overflow attack detected! Exiting...\n");
        exit(EXIT_FAILURE);
    }

    // Prompt user for paranoia factor
    printf("Enter the paranoia factor (0.0 - 1.0): ");
    scanf("%f", &paranoia_factor);

    // Check if paranoia factor is within acceptable range
    if (paranoia_factor < 0.0 || paranoia_factor > 1.0) {
        printf("Paranoia factor out of range! Exiting...\n");
        exit(EXIT_FAILURE);
    }

    // Actual summarization logic
    int i, word_count = 0;
    for (i = 0; i < strlen(text); i++) {
        if (text[i] == ' ' || text[i] == '\n') {
            word_count++;
            if (word_count <= summary_length) {
                strncat(summary, text, i + 1);
            }
        }
    }

    // Add paranoia factor to summary
    if (paranoia_factor > 0.5) {
        strcat(summary, "\n\nDo not trust this summary! It may be hiding critical information.");
    }

    printf("Summary: %s\n", summary);

    free(summary);
    return EXIT_SUCCESS;
}