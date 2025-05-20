//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: Alan Turing
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
int num_sentences = 0;

void add_sentence(char *text) {
    if (num_sentences >= MAX_SENTENCES) {
        printf("Error: Maximum number of sentences reached.\n");
        return;
    }

    int length = strlen(text);
    if (length > MAX_SENTENCE_LENGTH) {
        printf("Error: Sentence too long.\n");
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

int main() {
    char input[MAX_SENTENCE_LENGTH];

    while (fgets(input, MAX_SENTENCE_LENGTH, stdin)!= NULL) {
        add_sentence(input);
    }

    print_sentences();

    return 0;
}