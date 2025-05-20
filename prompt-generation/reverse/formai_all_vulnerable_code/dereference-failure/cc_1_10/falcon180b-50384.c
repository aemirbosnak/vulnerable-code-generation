//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_SENTENCES 1000

typedef struct {
    char *text;
    int length;
} Sentence;

Sentence sentences[MAX_SENTENCES];
int num_sentences;

void add_sentence(char *text) {
    if (num_sentences >= MAX_SENTENCES) {
        printf("Error: maximum number of sentences reached.\n");
        return;
    }

    int length = strlen(text);
    if (length > MAX_SENTENCE_LENGTH) {
        printf("Error: sentence too long.\n");
        return;
    }

    sentences[num_sentences].text = malloc(length + 1);
    strcpy(sentences[num_sentences].text, text);
    sentences[num_sentences].length = length;

    num_sentences++;
}

void print_sentences() {
    for (int i = 0; i < num_sentences; i++) {
        printf("%s\n", sentences[i].text);
    }
}

void summarize_text() {
    int total_length = 0;

    for (int i = 0; i < num_sentences; i++) {
        total_length += sentences[i].length;
    }

    int max_sentence_length = total_length / num_sentences;

    printf("Summary:\n");
    for (int i = 0; i < num_sentences; i++) {
        if (sentences[i].length > max_sentence_length) {
            printf("%s\n", sentences[i].text);
        }
    }
}

int main() {
    add_sentence("The quick brown fox jumps over the lazy dog.");
    add_sentence("Sphinx of black quartz, judge my vow.");
    add_sentence("Pack my box with five dozen liquor jugs.");

    print_sentences();

    summarize_text();

    return 0;
}