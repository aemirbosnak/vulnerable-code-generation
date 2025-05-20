//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_SENTENCES 1000
#define MIN_SENTENCE_LENGTH 5
#define MAX_WORD_LENGTH 20

typedef struct {
    int id;
    char sentence[MAX_SENTENCE_LENGTH];
} Sentence;

Sentence sentences[MAX_SENTENCES];
int num_sentences = 0;

void add_sentence(char* input) {
    int i = 0;
    int j = 0;
    while (i < strlen(input)) {
        if (isspace(input[i])) {
            if (j >= MIN_SENTENCE_LENGTH) {
                strncpy(sentences[num_sentences].sentence, input + i - j, MAX_SENTENCE_LENGTH);
                sentences[num_sentences].id = num_sentences;
                num_sentences++;
                j = 0;
            }
        } else if (j >= MAX_SENTENCE_LENGTH) {
            break;
        } else {
            strncat(sentences[num_sentences - 1].sentence, &input[i], 1);
            j++;
        }
        i++;
    }
}

void print_sentences() {
    for (int i = 0; i < num_sentences; i++) {
        printf("%d: %s\n", sentences[i].id, sentences[i].sentence);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        return 1;
    }

    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }

    char line[MAX_SENTENCE_LENGTH];
    while (fgets(line, MAX_SENTENCE_LENGTH, fp)!= NULL) {
        add_sentence(line);
    }

    fclose(fp);

    print_sentences();

    return 0;
}