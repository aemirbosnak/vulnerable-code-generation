//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SENTENCE_LENGTH 1024
#define MAX_SENTENCES 1000
#define MIN_SENTENCE_LENGTH 5

typedef struct {
    char *text;
    int length;
} Sentence;

Sentence sentences[MAX_SENTENCES];
int num_sentences = 0;

void add_sentence(char *text) {
    if (num_sentences >= MAX_SENTENCES) {
        printf("Error: Too many sentences.\n");
        exit(1);
    }

    int length = strlen(text);
    if (length < MIN_SENTENCE_LENGTH) {
        printf("Warning: Sentence is too short: %s\n", text);
        return;
    }

    sentences[num_sentences].text = strdup(text);
    sentences[num_sentences].length = length;
    num_sentences++;
}

void print_sentences() {
    for (int i = 0; i < num_sentences; i++) {
        printf("%d. %s\n", i + 1, sentences[i].text);
    }
}

int main() {
    char input[MAX_SENTENCE_LENGTH];

    printf("Enter sentences (type 'done' when finished):\n");

    while (fgets(input, MAX_SENTENCE_LENGTH, stdin)!= NULL) {
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "done") == 0) {
            break;
        }

        add_sentence(input);
    }

    print_sentences();

    return 0;
}