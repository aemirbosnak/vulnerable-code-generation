//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_SENTENCES 1000
#define MAX_WORDS_PER_SENTENCE 20

typedef struct {
    char *text;
    int length;
} Sentence;

typedef struct {
    Sentence *sentences;
    int num_sentences;
} Text;

void read_sentences(Text *text) {
    char input[MAX_SENTENCE_LENGTH];
    printf("Enter sentences (type 'done' when finished):\n");
    while (fgets(input, MAX_SENTENCE_LENGTH, stdin)!= NULL) {
        if (strcmp(input, "done") == 0) {
            break;
        }
        Sentence *new_sentence = malloc(sizeof(Sentence));
        new_sentence->text = strdup(input);
        new_sentence->length = strlen(input);
        text->sentences = realloc(text->sentences, sizeof(Sentence) * ++text->num_sentences);
        text->sentences[text->num_sentences - 1] = *new_sentence;
    }
}

void summarize_text(Text *text, int max_summary_length) {
    int i, j, k, num_words = 0;
    char *summary = malloc(sizeof(char) * max_summary_length);
    for (i = 0; i < text->num_sentences; i++) {
        for (j = 0; j < text->sentences[i].length; j++) {
            if (isalpha(text->sentences[i].text[j])) {
                num_words++;
                if (num_words > MAX_WORDS_PER_SENTENCE) {
                    break;
                }
            }
        }
        if (num_words > 0) {
            strncat(summary, text->sentences[i].text, num_words);
            strncat(summary, " ", 1);
            num_words = 0;
        }
    }
    printf("Summary: %s\n", summary);
    free(summary);
}

int main() {
    Text text;
    text.sentences = NULL;
    text.num_sentences = 0;
    printf("Enter text to summarize:\n");
    read_sentences(&text);
    int max_summary_length;
    printf("Enter maximum summary length (in words): ");
    scanf("%d", &max_summary_length);
    summarize_text(&text, max_summary_length);
    for (int i = 0; i < text.num_sentences; i++) {
        free(text.sentences[i].text);
    }
    free(text.sentences);
    return 0;
}