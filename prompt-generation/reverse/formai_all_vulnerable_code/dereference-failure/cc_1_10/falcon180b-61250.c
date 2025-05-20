//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_CONSPIRACIES 10
#define MAX_WORD_LENGTH 10

typedef struct {
    char *name;
    char *description;
} Conspiracy;

Conspiracy conspiracies[MAX_CONSPIRACIES] = {
    {"Flat Earth", "The Earth is not round, but flat"},
    {"Moon Landing Hoax", "The moon landing was faked"},
    {"9/11 was an inside job", "The 9/11 attacks were orchestrated by the US government"},
    {"Illuminati", "A secret society controlling world events"},
    {"Chemtrails", "Aircraft are spraying chemicals into the atmosphere"},
    {"Lizard People", "Shape-shifting reptilian humanoids control world governments"},
    {"Area 51", "A secret government base where aliens and UFOs are studied"},
    {"New World Order", "A secretive group of elites seeking to establish global domination"},
    {"Bigfoot", "A large, hairy, human-like creature living in remote areas"},
    {"Crop Circles", "Mysterious patterns appearing in fields, supposedly created by aliens"}
};

void generate_conspiracy_theory(Conspiracy *theory) {
    srand(time(NULL));
    int num_words = rand() % MAX_WORDS + 1;
    char *words[MAX_WORDS];
    for (int i = 0; i < num_words; i++) {
        int word_length = rand() % MAX_WORD_LENGTH + 1;
        words[i] = (char *)malloc(word_length + 1);
        for (int j = 0; j < word_length; j++) {
            words[i][j] = rand() % 26 + 'a';
        }
        words[i][word_length] = '\0';
    }
    char *theory_text = (char *)malloc(1000);
    strcpy(theory_text, "");
    for (int i = 0; i < num_words; i++) {
        strcat(theory_text, words[i]);
        strcat(theory_text, " ");
    }
    strcat(theory_text, " ");
    strcat(theory_text, theory->name);
    strcat(theory_text, " ");
    strcat(theory_text, theory->description);
    printf("%s\n", theory_text);
    free(theory_text);
    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }
}

int main() {
    int num_theories = rand() % MAX_CONSPIRACIES + 1;
    for (int i = 0; i < num_theories; i++) {
        generate_conspiracy_theory(&conspiracies[i]);
    }
    return 0;
}