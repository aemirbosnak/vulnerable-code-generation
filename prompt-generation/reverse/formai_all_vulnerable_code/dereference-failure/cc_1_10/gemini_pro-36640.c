//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_WORDS 100

typedef struct {
    char *words[MAX_WORDS];
    int num_words;
} sentence;

typedef struct {
    sentence sentences[MAX_SENTENCES];
    int num_sentences;
} text;

text *read_text(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    text *t = malloc(sizeof(text));
    t->num_sentences = 0;

    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        sentence s;
        s.num_words = 0;

        char *word = strtok(line, " ,.-!?");
        while (word != NULL) {
            s.words[s.num_words++] = strdup(word);
            word = strtok(NULL, " ,.-!?");
        }

        t->sentences[t->num_sentences++] = s;
    }

    fclose(fp);

    return t;
}

void free_text(text *t) {
    for (int i = 0; i < t->num_sentences; i++) {
        for (int j = 0; j < t->sentences[i].num_words; j++) {
            free(t->sentences[i].words[j]);
        }
    }

    free(t);
}

void print_text(text *t) {
    for (int i = 0; i < t->num_sentences; i++) {
        for (int j = 0; j < t->sentences[i].num_words; j++) {
            printf("%s ", t->sentences[i].words[j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    text *t = read_text(argv[1]);
    if (t == NULL) {
        return EXIT_FAILURE;
    }

    print_text(t);

    free_text(t);

    return EXIT_SUCCESS;
}