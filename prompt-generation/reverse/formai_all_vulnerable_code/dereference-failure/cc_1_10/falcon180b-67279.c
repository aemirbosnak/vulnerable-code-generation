//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: Ada Lovelace
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

void add_sentence(Sentence* sentences, int num_sentences, char* text) {
    int i;
    for (i = 0; i < num_sentences; i++) {
        if (sentences[i].length == 0) {
            strcpy(sentences[i].text, text);
            sentences[i].length = strlen(text);
            return;
        }
    }
}

void print_sentences(Sentence* sentences, int num_sentences) {
    int i;
    for (i = 0; i < num_sentences; i++) {
        if (sentences[i].length > 0) {
            printf("%s\n", sentences[i].text);
        }
    }
}

int main() {
    FILE* input_file;
    char* input_text = NULL;
    size_t input_size = 0;
    char* line = NULL;
    size_t line_size = 0;
    Sentence sentences[MAX_SENTENCES];
    int num_sentences = 0;

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    while ((getline(&line, &line_size, input_file))!= -1) {
        add_sentence(sentences, num_sentences, line);
        num_sentences++;
    }

    fclose(input_file);

    print_sentences(sentences, num_sentences);

    return 0;
}