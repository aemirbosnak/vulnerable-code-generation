//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCE_LENGTH 1000
#define MAX_PARAGRAPH_LENGTH 10000

typedef struct {
    char* text;
    int length;
} Sentence;

typedef struct {
    Sentence* sentences;
    int num_sentences;
} Paragraph;

Paragraph* read_file(FILE* fp) {
    Paragraph* paragraph = malloc(sizeof(Paragraph));
    paragraph->sentences = NULL;
    paragraph->num_sentences = 0;

    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fp))!= -1) {
        if (line[read - 1] == '\n') {
            line[--read] = '\0';
        }

        Sentence* sentence = malloc(sizeof(Sentence));
        sentence->text = strdup(line);
        sentence->length = strlen(sentence->text);

        paragraph->sentences = realloc(paragraph->sentences, sizeof(Sentence) * ++paragraph->num_sentences);
        paragraph->sentences[paragraph->num_sentences - 1] = *sentence;

        free(line);
        line = NULL;
        len = 0;
    }

    free(line);

    return paragraph;
}

void print_paragraph(Paragraph* paragraph) {
    for (int i = 0; i < paragraph->num_sentences; i++) {
        printf("%s\n", paragraph->sentences[i].text);
    }
}

int main() {
    FILE* fp = fopen("example.txt", "r");

    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    Paragraph* paragraph = read_file(fp);
    print_paragraph(paragraph);

    free(paragraph->sentences);
    free(paragraph);

    fclose(fp);

    return 0;
}