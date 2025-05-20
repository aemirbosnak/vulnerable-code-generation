//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SENTENCES_COUNT 3

char *extract_sentences(char *text, int count);
int count_sentences(char *text);

int main() {
    char input_text[500];
    char *summaries[SENTENCES_COUNT];
    int i, sentences_count;

    printf("Enter the text to summarize:\n");
    fgets(input_text, sizeof(input_text), stdin);

    sentences_count = count_sentences(input_text);
    if (sentences_count < SENTENCES_COUNT) {
        fprintf(stderr, "Error: input text does not have enough sentences.\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < SENTENCES_COUNT; i++) {
        summaries[i] = extract_sentences(input_text, i+1);
        printf("%d. %s\n", i+1, summaries[i]);
    }

    return 0;
}

char *extract_sentences(char *text, int count) {
    char *copy, *sentence, *p, *start;
    int i;

    copy = strdup(text);
    if (copy == NULL) {
        fprintf(stderr, "Error: failed to duplicate input text.\n");
        exit(EXIT_FAILURE);
    }

    sentence = malloc(strlen(text) + 1);
    if (sentence == NULL) {
        fprintf(stderr, "Error: failed to allocate memory for sentence.\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0, start = p = copy; i < count; i++) {
        p = strchr(p, '.');
        if (p == NULL) {
            fprintf(stderr, "Error: input text does not have %d sentences.\n", count);
            exit(EXIT_FAILURE);
        }
        p++;
    }

    while (*start == ' ') start++;
    while (*p == ' ') p--;

    strncpy(sentence, start, p - start);
    sentence[p - start] = '\0';

    free(copy);
    return sentence;
}

int count_sentences(char *text) {
    int count = 0;
    char *p, *start;

    for (p = start = text; *p != '\0'; p++) {
        if (*p == '.') {
            count++;
            start = p;
        }
    }

    if (start < p && *(p-1) != '.') count++;

    return count;
}