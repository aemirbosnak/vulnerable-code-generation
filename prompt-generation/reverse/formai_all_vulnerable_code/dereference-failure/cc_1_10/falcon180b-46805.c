//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define SUMMARY_LENGTH 500

struct sentence {
    char *text;
    int length;
};

struct sentence *sentences;
int num_sentences;

void add_sentence(char *text) {
    struct sentence *new_sentence = malloc(sizeof(struct sentence));
    new_sentence->text = strdup(text);
    new_sentence->length = strlen(text);
    sentences = realloc(sentences, sizeof(struct sentence) * ++num_sentences);
    sentences[num_sentences - 1] = *new_sentence;
}

void summarize() {
    int total_length = 0;
    int i;
    for (i = 0; i < num_sentences; i++) {
        total_length += sentences[i].length;
    }
    int avg_sentence_length = total_length / num_sentences;
    int num_summarized_sentences = 0;
    int summary_length = 0;
    char *summary = malloc(SUMMARY_LENGTH * sizeof(char));
    for (i = 0; i < num_sentences; i++) {
        if (summary_length + sentences[i].length >= SUMMARY_LENGTH) {
            break;
        }
        strcat(summary, sentences[i].text);
        summary_length += sentences[i].length;
        num_summarized_sentences++;
    }
    printf("Summary:\n%s\n", summary);
}

int main() {
    char input[MAX_SENTENCE_LENGTH];
    while (fgets(input, MAX_SENTENCE_LENGTH, stdin)!= NULL) {
        input[strcspn(input, "\n")] = '\0'; // Remove newline character
        add_sentence(input);
    }
    summarize();
    return 0;
}