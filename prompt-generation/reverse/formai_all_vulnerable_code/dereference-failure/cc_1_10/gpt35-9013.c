//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 50
#define MAX_SUMMARY_LEN 500

char* find_sentences(char *text);

char* find_summary(char *text, char *keywords, int n_sentences);

int main() {
    char text[] = "The quick brown fox jumps over the lazy dog. This is the second sentence. The third sentence is here. And the fourth one too!";

    char *sentences = find_sentences(text);

    char *summary = find_summary(text, "quick brown fox", 2);

    printf("Sentences: %s\n", sentences);

    printf("Summary: %s\n", summary);

    free(sentences);

    free(summary);

    return 0;
}

char* find_sentences(char *text) {
    char *sentences = (char*) malloc(MAX_SENTENCES * sizeof(char));

    char sentence[MAX_SUMMARY_LEN];

    int n_sentences = 0;

    for (int i = 0, j = 0; text[i] != '\0'; i++) {
        sentence[j++] = text[i];

        if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            sentence[j] = '\0';

            strcat(sentences, sentence);

            n_sentences++;

            j = 0;

            if (n_sentences == MAX_SENTENCES) {
                break;
            }
        }
    }

    return sentences;
}

char* find_summary(char *text, char *keywords, int n_sentences) {
    char *summary = (char*) malloc(MAX_SUMMARY_LEN * sizeof(char));

    char *matched_sentence = NULL;

    char *ptr = strtok(text, ".");

    while (ptr != NULL) {
        if (strstr(ptr, keywords) != NULL) {
            matched_sentence = ptr;

            break;
        }

        ptr = strtok(NULL, ".");
    }

    if (matched_sentence == NULL) {
        return "";
    }

    strcat(summary, matched_sentence);

    n_sentences--;

    ptr = strtok(NULL, ".");

    while (n_sentences > 0 && ptr != NULL) {
        strcat(summary, ".");

        strcat(summary, ptr);

        n_sentences--;

        ptr = strtok(NULL, ".");
    }

    return summary;
}