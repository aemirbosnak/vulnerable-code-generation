//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_SENTENCES 1000

typedef struct {
    char *text;
    int length;
} Sentence;

Sentence sentences[MAX_SENTENCES];
int num_sentences;

void add_sentence(char *text) {
    if (num_sentences >= MAX_SENTENCES) {
        printf("Error: Too many sentences.\n");
        exit(1);
    }

    sentences[num_sentences].text = malloc(strlen(text) + 1);
    strcpy(sentences[num_sentences].text, text);
    sentences[num_sentences].length = strlen(text);

    num_sentences++;
}

void print_sentences() {
    for (int i = 0; i < num_sentences; i++) {
        printf("%s (%d characters)\n", sentences[i].text, sentences[i].length);
    }
}

void summarize_text() {
    int total_chars = 0;

    for (int i = 0; i < num_sentences; i++) {
        total_chars += sentences[i].length;
    }

    int max_sentence_length = total_chars / num_sentences;

    printf("Summary:\n");
    for (int i = 0; i < num_sentences; i++) {
        if (sentences[i].length <= max_sentence_length) {
            printf("%s (%d characters)\n", sentences[i].text, sentences[i].length);
        }
    }
}

int main() {
    char input_text[MAX_SENTENCE_LENGTH];

    printf("Enter text to summarize:\n");
    fgets(input_text, MAX_SENTENCE_LENGTH, stdin);

    char *token = strtok(input_text, ",.?!");
    while (token!= NULL) {
        add_sentence(token);
        token = strtok(NULL, ",.?!");
    }

    print_sentences();
    summarize_text();

    return 0;
}