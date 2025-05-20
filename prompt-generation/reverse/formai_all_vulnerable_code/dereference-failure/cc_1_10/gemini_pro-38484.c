//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_SENTENCES 10

struct Sentence {
    char *text;
    int length;
};

struct Text {
    struct Sentence *sentences;
    int num_sentences;
};

char *read_line(FILE *f) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read = getline(&line, &len, f);
    if (read == -1) {
        return NULL;
    }
    return line;
}

struct Text *read_text(FILE *f) {
    struct Text *text = malloc(sizeof(struct Text));
    text->sentences = NULL;
    text->num_sentences = 0;
    char *line = NULL;
    while ((line = read_line(f)) != NULL) {
        line = strtok(line, ".!?");
        while (line != NULL) {
            struct Sentence *sentence = malloc(sizeof(struct Sentence));
            sentence->text = strdup(line);
            sentence->length = strlen(sentence->text);
            text->sentences = realloc(text->sentences, (text->num_sentences + 1) * sizeof(struct Sentence));
            text->sentences[text->num_sentences++] = *sentence;
            free(sentence);
            line = strtok(NULL, ".!?");
        }
        free(line);
    }
    return text;
}

void free_text(struct Text *text) {
    for (int i = 0; i < text->num_sentences; i++) {
        free(text->sentences[i].text);
    }
    free(text->sentences);
    free(text);
}

char *summarize_text(struct Text *text) {
    char *summary = NULL;
    for (int i = 0; i < text->num_sentences; i++) {
        struct Sentence *sentence = &text->sentences[i];
        if (sentence->length > 20) {
            char *words = strdup(sentence->text);
            char *word = strtok(words, " ");
            while (word != NULL) {
                if (strlen(word) > 5) {
                    summary = realloc(summary, (strlen(summary) + strlen(word) + 2) * sizeof(char));
                    strcat(summary, word);
                    strcat(summary, " ");
                }
                word = strtok(NULL, " ");
            }
            free(words);
        }
    }
    return summary;
}

int main() {
    FILE *f = fopen("text.txt", "r");
    if (f == NULL) {
        perror("Error opening file");
        return 1;
    }
    struct Text *text = read_text(f);
    fclose(f);
    char *summary = summarize_text(text);
    printf("%s", summary);
    free(summary);
    free_text(text);
    return 0;
}