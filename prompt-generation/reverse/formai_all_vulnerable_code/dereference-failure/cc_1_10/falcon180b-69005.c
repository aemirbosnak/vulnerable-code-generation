//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 50
#define MAX_SENTENCES 5
#define MAX_WORD_LENGTH 15
#define MAX_WORDS 20

typedef struct {
    char *name;
    char *description;
} ConspiracyTheory;

ConspiracyTheory theories[] = {
    { "Illuminati", "A secretive group of elite individuals who control the world's governments, economies, and media" },
    { "Area 51", "A top-secret military base in Nevada where the US government studies extraterrestrial life and technology" },
    { "Flat Earth", "The belief that the Earth is not a sphere but a flat disk, and that all evidence to the contrary is a hoax" },
    { "Moon Landing Hoax", "The theory that the Apollo moon landings were faked by the US government to win the space race" },
    { "Chemtrails", "The belief that the contrails left by airplanes are actually chemical or biological agents being sprayed into the atmosphere" }
};

void generate_theory(ConspiracyTheory theory, char *sentence) {
    strcat(sentence, theory.name);
    strcat(sentence, " ");
    strcat(sentence, theory.description);
}

int main() {
    srand(time(NULL));

    int num_sentences = rand() % MAX_SENTENCES + 1;
    char *sentences[MAX_SENTENCES];

    for (int i = 0; i < num_sentences; i++) {
        sentences[i] = malloc(MAX_SENTENCE_LENGTH * sizeof(char));
        strcpy(sentences[i], "");
    }

    int num_words = rand() % MAX_WORDS + 1;
    char *words[MAX_WORDS];

    for (int i = 0; i < num_words; i++) {
        words[i] = malloc(MAX_WORD_LENGTH * sizeof(char));
        strcpy(words[i], "");
    }

    for (int i = 0; i < num_sentences; i++) {
        int num_words_in_sentence = rand() % MAX_WORDS + 1;

        for (int j = 0; j < num_words_in_sentence; j++) {
            int word_index = rand() % num_words;
            strcpy(words[word_index], theories[rand() % 5].name);
        }

        for (int j = 0; j < num_words_in_sentence; j++) {
            int word_index = rand() % num_words;
            generate_theory(theories[rand() % 5], sentences[i]);
        }
    }

    for (int i = 0; i < num_sentences; i++) {
        printf("%s\n", sentences[i]);
    }

    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }

    for (int i = 0; i < num_sentences; i++) {
        free(sentences[i]);
    }

    return 0;
}