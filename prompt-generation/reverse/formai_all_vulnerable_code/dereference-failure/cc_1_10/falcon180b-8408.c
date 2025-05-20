//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_SENTENCES 1000

typedef struct {
    char text[MAX_SENTENCE_LENGTH];
    int length;
} Sentence;

typedef struct {
    Sentence sentences[MAX_SENTENCES];
    int num_sentences;
} Text;

char* read_line(FILE* fp) {
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    if ((read = getline(&line, &len, fp)) == -1) {
        fprintf(stderr, "Error reading line\n");
        exit(1);
    }

    return line;
}

void add_sentence(Text* text, const char* sentence) {
    if (text->num_sentences >= MAX_SENTENCES) {
        fprintf(stderr, "Max number of sentences reached\n");
        exit(1);
    }

    strncpy(text->sentences[text->num_sentences].text, sentence, MAX_SENTENCE_LENGTH);
    text->sentences[text->num_sentences].length = strlen(sentence);

    ++text->num_sentences;
}

void print_sentence(const Sentence* sentence) {
    printf("%.*s\n", sentence->length, sentence->text);
}

void summarize_text(const Text* text, double percentage) {
    int num_sentences_to_keep = (int) (text->num_sentences * percentage / 100.0);

    printf("Summary:\n");
    for (int i = 0; i < num_sentences_to_keep; ++i) {
        print_sentence(&text->sentences[i]);
    }
}

int main() {
    FILE* fp = fopen("input.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening input file\n");
        exit(1);
    }

    Text text = { 0 };

    char* line = NULL;
    while ((line = read_line(fp))!= NULL) {
        add_sentence(&text, line);
    }

    summarize_text(&text, 50.0);

    fclose(fp);
    return 0;
}