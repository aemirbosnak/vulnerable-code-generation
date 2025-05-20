//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_SENTENCES 1000

typedef struct {
    char text[MAX_SENTENCE_LENGTH];
    int length;
} Sentence;

void read_sentences(Sentence sentences[], int *num_sentences) {
    char input[MAX_SENTENCE_LENGTH];
    int sentence_index = 0;

    fprintf(stdout, "Enter sentences (type 'done' when finished):\n");

    while (fgets(input, MAX_SENTENCE_LENGTH, stdin)!= NULL) {
        if (strcmp(input, "done") == 0) {
            break;
        }

        strcpy(sentences[sentence_index].text, input);
        sentences[sentence_index].length = strlen(input);
        sentence_index++;

        if (sentence_index == MAX_SENTENCES) {
            fprintf(stderr, "Error: Maximum number of sentences reached.\n");
            exit(EXIT_FAILURE);
        }
    }

    *num_sentences = sentence_index;
}

void summarize_sentences(Sentence sentences[], int num_sentences, int max_summary_length, char *summary) {
    int i, j, k;
    int total_length = 0;
    int num_key_sentences = 0;

    for (i = 0; i < num_sentences; i++) {
        if (sentences[i].length > max_summary_length) {
            fprintf(stderr, "Warning: Sentence '%s' is longer than the maximum summary length.\n", sentences[i].text);
        }

        total_length += sentences[i].length;

        if (total_length > max_summary_length) {
            break;
        }
    }

    num_key_sentences = i;

    for (j = 0; j < num_key_sentences; j++) {
        k = 0;

        while (k < sentences[j].length && summary[k]!= '\0') {
            summary[k] = sentences[j].text[k];
            k++;
        }

        summary[k] = '\0';
    }
}

int main() {
    Sentence sentences[MAX_SENTENCES];
    int num_sentences;

    read_sentences(sentences, &num_sentences);

    char summary[MAX_SENTENCE_LENGTH];
    int max_summary_length = MAX_SENTENCE_LENGTH / num_sentences;

    summarize_sentences(sentences, num_sentences, max_summary_length, summary);

    fprintf(stdout, "Summary:\n%s\n", summary);

    return 0;
}