//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_SENTENCES 1000
#define MIN_SENTENCE_LENGTH 5

typedef struct {
    char *text;
    int length;
} Sentence;

Sentence sentences[MAX_SENTENCES];
int num_sentences;

void add_sentence(char *text) {
    if (num_sentences >= MAX_SENTENCES) {
        printf("Error: Maximum number of sentences reached.\n");
        return;
    }

    int length = strlen(text);
    if (length < MIN_SENTENCE_LENGTH) {
        printf("Warning: Sentence is too short: %s\n", text);
        return;
    }

    sentences[num_sentences].text = malloc(length + 1);
    strcpy(sentences[num_sentences].text, text);
    sentences[num_sentences].length = length;

    num_sentences++;
}

void print_sentences() {
    for (int i = 0; i < num_sentences; i++) {
        printf("%d. %s\n", i + 1, sentences[i].text);
    }
}

void free_sentences() {
    for (int i = 0; i < num_sentences; i++) {
        free(sentences[i].text);
    }
}

int main() {
    srand(time(NULL));

    add_sentence("The quick brown fox jumps over the lazy dog.");
    add_sentence("Sphinx of black quartz, judge my vow.");
    add_sentence("Pack my box with five dozen liquor jugs.");

    print_sentences();

    free_sentences();

    return 0;
}