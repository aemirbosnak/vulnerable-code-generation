//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20
#define MAX_SENTENCE_LENGTH 100
#define MAX_SENTENCES 1000

typedef struct {
    char *words[MAX_SENTENCES][MAX_WORDS];
    int num_words[MAX_SENTENCES];
    int num_sentences;
} Text;

void generate_sentence(Text *text, int sentence_index) {
    int num_words = rand() % 10 + 1;
    int i;
    for (i = 0; i < num_words; i++) {
        int word_length = rand() % MAX_WORD_LENGTH + 1;
        char *word = malloc(word_length + 1);
        int j;
        for (j = 0; j < word_length; j++) {
            word[j] = rand() % 26 + 'a';
        }
        word[j] = '\0';
        text->words[sentence_index][i] = word;
    }
    text->num_words[sentence_index] = num_words;
}

void generate_text(Text *text) {
    int i;
    for (i = 0; i < MAX_SENTENCES; i++) {
        generate_sentence(text, i);
    }
    text->num_sentences = i;
}

void print_text(Text *text) {
    int i, j;
    for (i = 0; i < text->num_sentences; i++) {
        printf("Sentence %d:\n", i + 1);
        for (j = 0; j < text->num_words[i]; j++) {
            printf("%s ", text->words[i][j]);
        }
        printf("\n\n");
    }
}

int main() {
    srand(time(NULL));
    Text text;
    generate_text(&text);
    print_text(&text);
    return 0;
}