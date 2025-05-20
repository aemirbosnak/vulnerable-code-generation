//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX_WORDS 1000
#define MAX_SENTENCE_LENGTH 100
#define MIN_SENTENCE_LENGTH 5
#define MAX_PARAGRAPHS 10
#define MAX_PARAGRAPH_LENGTH 30
#define MIN_PARAGRAPH_LENGTH 3

char *words[MAX_WORDS];
int num_words = 0;

void generate_sentence(char *sentence, int length) {
    int i;
    for (i = 0; i < length; i++) {
        int word_index = rand() % num_words;
        strncat(sentence, words[word_index], strlen(words[word_index]));
        if (i < length - 1) {
            strncat(sentence, " ", 1);
        }
    }
    strncat(sentence, ". ", 2);
}

void generate_paragraph(char *paragraph, int length) {
    int i;
    for (i = 0; i < length; i++) {
        generate_sentence(paragraph + strlen(paragraph), rand() % MAX_SENTENCE_LENGTH + MIN_SENTENCE_LENGTH);
        if (i < length - 1) {
            strncat(paragraph, "\n\n", 3);
        }
    }
}

int main() {
    srand(time(NULL));

    FILE *file = fopen("space_adventure.txt", "w");

    int num_paragraphs = rand() % MAX_PARAGRAPHS + 1;

    for (int i = 0; i < num_paragraphs; i++) {
        char paragraph[MAX_PARAGRAPH_LENGTH];
        generate_paragraph(paragraph, rand() % MAX_PARAGRAPH_LENGTH + MIN_PARAGRAPH_LENGTH);
        fprintf(file, "%s", paragraph);
    }

    fclose(file);

    return 0;
}