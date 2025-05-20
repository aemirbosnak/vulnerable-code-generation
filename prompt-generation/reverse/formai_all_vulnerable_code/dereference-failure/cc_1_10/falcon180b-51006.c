//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_SENTENCES 1000
#define MAX_WORDS_PER_SENTENCE 20

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

    int length = strlen(text);
    if (length > MAX_SENTENCE_LENGTH) {
        printf("Error: Sentence is too long.\n");
        exit(1);
    }

    sentences[num_sentences].text = malloc(length + 1);
    strcpy(sentences[num_sentences].text, text);
    sentences[num_sentences].length = length;

    num_sentences++;
}

void summarize() {
    int total_words = 0;

    for (int i = 0; i < num_sentences; i++) {
        total_words += sentences[i].length;
    }

    int avg_words_per_sentence = total_words / num_sentences;
    int max_words_per_sentence = avg_words_per_sentence + (avg_words_per_sentence / 2);

    printf("Summary:\n");
    printf("Total sentences: %d\n", num_sentences);
    printf("Average words per sentence: %d\n", avg_words_per_sentence);
    printf("Maximum words per sentence: %d\n", max_words_per_sentence);
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

    summarize();

    return 0;
}