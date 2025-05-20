//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 1024

typedef struct {
    char *text;
    size_t len;
} text_t;

text_t *read_text(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    char *text = malloc(MAX_LEN);
    if (text == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    size_t len = 0;
    while (fgets(text + len, MAX_LEN - len, fp) != NULL) {
        len += strlen(text + len);
    }

    fclose(fp);

    text_t *result = malloc(sizeof(text_t));
    if (result == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    result->text = text;
    result->len = len;

    return result;
}

void free_text(text_t *text) {
    free(text->text);
    free(text);
}

typedef struct {
    char *sentence;
    size_t len;
    float score;
} sentence_t;

sentence_t *split_sentences(text_t *text) {
    char *text_copy = malloc(text->len + 1);
    if (text_copy == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    memcpy(text_copy, text->text, text->len);
    text_copy[text->len] = '\0';

    char *sentence = strtok(text_copy, ".?!");
    size_t num_sentences = 0;
    while (sentence != NULL) {
        num_sentences++;
        sentence = strtok(NULL, ".?!");
    }

    sentence_t *sentences = malloc(sizeof(sentence_t) * num_sentences);
    if (sentences == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    sentence = strtok(text_copy, ".?!");
    int i = 0;
    while (sentence != NULL) {
        sentences[i].sentence = sentence;
        sentences[i].len = strlen(sentence);
        sentences[i].score = 0.0f;
        i++;
        sentence = strtok(NULL, ".?!");
    }

    free(text_copy);

    return sentences;
}

void free_sentences(sentence_t *sentences, size_t num_sentences) {
    for (size_t i = 0; i < num_sentences; i++) {
        free(sentences[i].sentence);
    }

    free(sentences);
}

void score_sentences(sentence_t *sentences, size_t num_sentences) {
    for (size_t i = 0; i < num_sentences; i++) {
        sentences[i].score += 1.0f / sentences[i].len;

        char *word = strtok(sentences[i].sentence, " ");
        while (word != NULL) {
            if (strlen(word) > 4) {
                sentences[i].score += 0.5f;
            }

            word = strtok(NULL, " ");
        }
    }
}

sentence_t *sort_sentences(sentence_t *sentences, size_t num_sentences) {
    for (size_t i = 0; i < num_sentences - 1; i++) {
        for (size_t j = i + 1; j < num_sentences; j++) {
            if (sentences[i].score < sentences[j].score) {
                sentence_t temp = sentences[i];
                sentences[i] = sentences[j];
                sentences[j] = temp;
            }
        }
    }

    return sentences;
}

char *summarize_text(text_t *text, float percentage) {
    sentence_t *sentences = split_sentences(text);
    size_t num_sentences = text->len / 50;

    score_sentences(sentences, num_sentences);
    sentences = sort_sentences(sentences, num_sentences);

    size_t num_summary_sentences = (size_t)(percentage * num_sentences);
    char *summary = malloc(MAX_LEN);
    if (summary == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    size_t len = 0;
    for (size_t i = 0; i < num_summary_sentences; i++) {
        len += snprintf(summary + len, MAX_LEN - len, "%s ", sentences[i].sentence);
    }

    free_sentences(sentences, num_sentences);

    return summary;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <percentage>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *filename = argv[1];
    float percentage = atof(argv[2]);

    text_t *text = read_text(filename);
    char *summary = summarize_text(text, percentage);

    printf("%s\n", summary);

    free_text(text);
    free(summary);

    return EXIT_SUCCESS;
}