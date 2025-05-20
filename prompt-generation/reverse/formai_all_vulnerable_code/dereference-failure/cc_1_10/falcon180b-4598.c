//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_SENTENCES 1000

typedef struct {
    char *text;
    size_t length;
} Sentence;

Sentence *read_sentences(FILE *file, size_t *num_sentences) {
    Sentence *sentences = malloc(sizeof(Sentence) * MAX_SENTENCES);
    size_t count = 0;

    char buffer[MAX_SENTENCE_LENGTH];
    while (fgets(buffer, MAX_SENTENCE_LENGTH, file)!= NULL) {
        if (count >= MAX_SENTENCES) {
            fprintf(stderr, "Error: Too many sentences.\n");
            exit(1);
        }

        sentences[count].text = strdup(buffer);
        sentences[count].length = strlen(buffer);
        count++;
    }

    *num_sentences = count;
    return sentences;
}

void free_sentences(Sentence *sentences, size_t num_sentences) {
    for (size_t i = 0; i < num_sentences; i++) {
        free(sentences[i].text);
    }
    free(sentences);
}

char *join_sentences(Sentence *sentences, size_t num_sentences) {
    char *summary = malloc(sizeof(char) * (MAX_SENTENCE_LENGTH * num_sentences));
    char *ptr = summary;

    for (size_t i = 0; i < num_sentences; i++) {
        strcat(ptr, sentences[i].text);
        if (i < num_sentences - 1) {
            strcat(ptr, " ");
        }
    }

    return summary;
}

void print_summary(char *summary) {
    printf("Summary:\n%s\n", summary);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file.\n");
        return 1;
    }

    size_t num_sentences = 0;
    Sentence *sentences = read_sentences(file, &num_sentences);
    fclose(file);

    char *summary = join_sentences(sentences, num_sentences);
    print_summary(summary);

    free_sentences(sentences, num_sentences);
    free(summary);

    return 0;
}