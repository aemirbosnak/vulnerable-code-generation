//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_SUMMARY_LENGTH 500

struct sentence {
    char* text;
    int length;
};

struct sentence* new_sentence(char* text) {
    struct sentence* sentence = malloc(sizeof(struct sentence));
    sentence->text = strdup(text);
    sentence->length = strlen(text);
    return sentence;
}

void delete_sentence(struct sentence* sentence) {
    free(sentence->text);
    free(sentence);
}

int compare_sentences(struct sentence* a, struct sentence* b) {
    return strlen(a->text) - strlen(b->text);
}

char* summarize_text(char* text, int max_summary_length) {
    char* summary = malloc(max_summary_length + 1);
    summary[0] = '\0';
    int current_length = 0;

    struct sentence* sentences[100];
    int num_sentences = 0;

    char* current_sentence = strtok(text, ".");
    while (current_sentence!= NULL) {
        struct sentence* sentence = new_sentence(current_sentence);
        sentences[num_sentences++] = sentence;
        current_sentence = strtok(NULL, ".");
    }

    qsort(sentences, num_sentences, sizeof(struct sentence*), compare_sentences);

    for (int i = 0; i < num_sentences && current_length < max_summary_length; i++) {
        strncat(summary, sentences[i]->text, MAX_SENTENCE_LENGTH);
        current_length += strlen(sentences[i]->text);
        strncat(summary, ". ", 2);
    }

    if (current_length >= max_summary_length) {
        summary[max_summary_length - 3] = '\0';
    } else {
        strcat(summary, ".");
    }

    for (int i = 0; i < num_sentences; i++) {
        delete_sentence(sentences[i]);
    }

    return summary;
}

int main() {
    char* text = "The quick brown fox jumps over the lazy dog. The lazy dog is not amused. ";
    char* summary = summarize_text(text, MAX_SUMMARY_LENGTH);
    printf("Summary: %s\n", summary);
    free(summary);
    return 0;
}