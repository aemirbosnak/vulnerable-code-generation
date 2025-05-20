//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TEXT_LENGTH 1000
#define MAX_SUMMARY_LENGTH 150
#define MAX_SENTENCES 100
#define MAX_SENTENCE_LENGTH 200

void generate_summary(char text[], char summary[]) {
    char *sentences[MAX_SENTENCES];
    int sentence_count = 0;

    // Breaking the text into sentences
    char *token = strtok(text, ".!?");
    while (token != NULL && sentence_count < MAX_SENTENCES) {
        sentences[sentence_count] = (char *)malloc(strlen(token) + 1);
        strcpy(sentences[sentence_count], token);
        sentence_count++;
        token = strtok(NULL, ".!?");
    }

    // Simplistic approach: Pick first few sentences for a summary
    strcpy(summary, "");
    for (int i = 0; i < sentence_count && i < 3; i++) {
        strcat(summary, sentences[i]);
        if (i < sentence_count - 1) {
            strcat(summary, ". ");
        }
    }

    // Freeing allocated memory
    for (int i = 0; i < sentence_count; i++) {
        free(sentences[i]);
    }
}

int main() {
    char text[MAX_TEXT_LENGTH];
    char summary[MAX_SUMMARY_LENGTH];

    printf("Enter the text you wish to summarize (limit 1000 characters):\n");
    fgets(text, MAX_TEXT_LENGTH, stdin);
    
    // Trimming newline character that fgets may include
    text[strcspn(text, "\n")] = 0; 

    generate_summary(text, summary);

    printf("\nSummary:\n%s\n", summary);
    return 0;
}