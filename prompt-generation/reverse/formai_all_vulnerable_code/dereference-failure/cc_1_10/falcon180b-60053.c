//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_SENTENCES 1000
#define MAX_WORDS 10000
#define SUMMARY_LENGTH_PERCENTAGE 50

typedef struct {
    char *text;
    int length;
} Sentence;

typedef struct {
    Sentence *sentences;
    int num_sentences;
    int total_words;
} Text;

void initialize_text(Text *text) {
    text->sentences = NULL;
    text->num_sentences = 0;
    text->total_words = 0;
}

void add_sentence(Text *text, char *sentence) {
    Sentence *new_sentence = malloc(sizeof(Sentence));
    new_sentence->text = strdup(sentence);
    new_sentence->length = strlen(sentence);
    text->sentences = realloc(text->sentences, sizeof(Sentence) * (text->num_sentences + 1));
    text->sentences[text->num_sentences] = *new_sentence;
    text->num_sentences++;
    text->total_words += count_words(sentence);
}

int count_words(char *sentence) {
    int count = 0;
    char *token;
    token = strtok(sentence, " ");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

void free_text(Text *text) {
    for (int i = 0; i < text->num_sentences; i++) {
        free(text->sentences[i].text);
    }
    free(text->sentences);
}

void generate_summary(Text *text, int summary_length) {
    int total_sentence_length = 0;
    int current_sentence_length = 0;
    int current_sentence_index = 0;
    char *summary = malloc(summary_length + 1);
    summary[0] = '\0';

    for (int i = 0; i < text->num_sentences; i++) {
        total_sentence_length += text->sentences[i].length;
        if (total_sentence_length >= (int)(SUMMARY_LENGTH_PERCENTAGE / 100.0 * text->total_words)) {
            break;
        }
    }

    for (int i = 0; i < text->num_sentences; i++) {
        if (current_sentence_length + text->sentences[i].length <= summary_length) {
            strcat(summary, text->sentences[i].text);
            current_sentence_length += text->sentences[i].length;
            current_sentence_index = i;
        } else {
            break;
        }
    }

    if (current_sentence_index < text->num_sentences - 1) {
        strcat(summary, "...");
    }

    printf("Summary: %s\n", summary);
    free(summary);
}

int main() {
    Text text;
    initialize_text(&text);

    char input[MAX_SENTENCE_LENGTH];
    while (fgets(input, MAX_SENTENCE_LENGTH, stdin)!= NULL) {
        add_sentence(&text, input);
    }

    int summary_length = (int)(SUMMARY_LENGTH_PERCENTAGE / 100.0 * text.total_words);
    generate_summary(&text, summary_length);

    free_text(&text);
    return 0;
}