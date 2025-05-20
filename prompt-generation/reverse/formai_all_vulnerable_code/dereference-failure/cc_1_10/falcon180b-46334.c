//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SENTENCE_LENGTH 1000
#define SUMMARY_LENGTH 100

typedef struct {
    char *text;
    int length;
} Sentence;

typedef struct {
    Sentence *sentences;
    int num_sentences;
    int summary_length;
} Summary;

Summary *create_summary(char *text, int summary_length) {
    Summary *summary = malloc(sizeof(Summary));
    summary->num_sentences = 0;
    summary->summary_length = summary_length;
    summary->sentences = malloc(sizeof(Sentence));
    summary->sentences[0].text = strdup(text);
    summary->sentences[0].length = strlen(text);
    return summary;
}

void add_sentence(Summary *summary, char *text) {
    Sentence *new_sentences = realloc(summary->sentences, sizeof(Sentence) * (summary->num_sentences + 1));
    if (new_sentences == NULL) {
        printf("Error: failed to allocate memory.\n");
        exit(EXIT_FAILURE);
    }
    summary->sentences = new_sentences;
    summary->num_sentences++;
    summary->sentences[summary->num_sentences - 1].text = strdup(text);
    summary->sentences[summary->num_sentences - 1].length = strlen(text);
}

void print_summary(Summary *summary) {
    for (int i = 0; i < summary->num_sentences; i++) {
        printf("%s ", summary->sentences[i].text);
    }
}

int main() {
    char input_text[MAX_SENTENCE_LENGTH];
    printf("Enter a text to summarize: ");
    fgets(input_text, MAX_SENTENCE_LENGTH, stdin);

    int summary_length;
    printf("Enter the desired summary length: ");
    scanf("%d", &summary_length);

    Summary *summary = create_summary(input_text, summary_length);

    char *token;
    char *sentence = strtok_r(input_text, ".", &token);
    while (sentence!= NULL) {
        add_sentence(summary, sentence);
        sentence = strtok_r(NULL, ".", &token);
    }

    printf("Summary:\n");
    print_summary(summary);

    return 0;
}