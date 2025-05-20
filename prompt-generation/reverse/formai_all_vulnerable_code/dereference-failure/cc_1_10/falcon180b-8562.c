//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_WORDS 100
#define MAX_SENTENCES 100
#define MAX_PARAGRAPHS 10

typedef struct {
    char *words[MAX_WORDS];
    int num_words;
} Sentence;

typedef struct {
    Sentence sentences[MAX_SENTENCES];
    int num_sentences;
} Paragraph;

void generate_sentence(Sentence *sentence) {
    int i;
    char *word;

    for (i = 0; i < MAX_WORDS; i++) {
        do {
            word = (char *)malloc(10 * sizeof(char));
            sprintf(word, "%d", rand() % 1000);
        } while (isdigit(word[0]));

        if (i == 0) {
            strcpy(word, "The");
        } else if (i == 1) {
            strcpy(word, "quick");
        } else if (i == 2) {
            strcpy(word, "brown");
        } else if (i == 3) {
            strcpy(word, "fox");
        }

        sentence->words[i] = word;
    }

    sentence->num_words = i;
}

void generate_paragraph(Paragraph *paragraph) {
    int i;
    Sentence sentence;

    for (i = 0; i < MAX_SENTENCES; i++) {
        generate_sentence(&sentence);
        paragraph->sentences[i] = sentence;
    }

    paragraph->num_sentences = i;
}

int main() {
    int i;
    Paragraph paragraph;

    srand(time(NULL));

    generate_paragraph(&paragraph);

    for (i = 0; i < paragraph.num_sentences; i++) {
        printf("%s ", paragraph.sentences[i].words[0]);

        if (i == 0) {
            printf("jumps over the lazy dog.\n");
        } else {
            printf(". ");
        }
    }

    return 0;
}