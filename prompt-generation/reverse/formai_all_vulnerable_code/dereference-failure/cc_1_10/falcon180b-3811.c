//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACIES 100
#define MAX_WORDS 50
#define MAX_WORD_LENGTH 20

typedef struct {
    char *name;
    char *description;
} ConspiracyTheory;

ConspiracyTheory conspiracies[MAX_CONSPIRACIES];

void generate_name(char *name) {
    char vowels[] = "aeiouAEIOU";
    char consonants[] = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
    char *ptr = name;
    int len = strlen(name);

    srand(time(NULL));
    for (int i = 0; i < len; i++) {
        if (i % 2 == 0) {
            *ptr++ = consonants[rand() % (sizeof(consonants) - 1)];
        } else {
            *ptr++ = vowels[rand() % (sizeof(vowels) - 1)];
        }
    }
    *ptr = '\0';
}

void generate_description(char *description) {
    char nouns[] = "government officials aliens corporations media elites";
    char verbs[] = "control manipulate deceive hide plot scheme conspire";
    char prepositions[] = "with against for by using through";
    char articles[] = "the a an";
    char *ptr = description;
    int len = strlen(description);

    srand(time(NULL));
    for (int i = 0; i < len; i++) {
        if (i % 2 == 0) {
            *ptr++ = nouns[rand() % (sizeof(nouns) - 1)];
        } else {
            *ptr++ = verbs[rand() % (sizeof(verbs) - 1)];
        }
    }

    srand(time(NULL));
    for (int i = 0; i < len; i++) {
        if (i % 2 == 0) {
            *ptr++ = prepositions[rand() % (sizeof(prepositions) - 1)];
        } else {
            *ptr++ = articles[rand() % (sizeof(articles) - 1)];
        }
    }

    *ptr = '\0';
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < MAX_CONSPIRACIES; i++) {
        conspiracies[i].name = malloc(MAX_WORD_LENGTH * sizeof(char));
        conspiracies[i].description = malloc(MAX_WORD_LENGTH * sizeof(char));

        generate_name(conspiracies[i].name);
        generate_description(conspiracies[i].description);

        printf("Conspiracy Theory #%d:\nName: %s\nDescription: %s\n\n", i + 1, conspiracies[i].name, conspiracies[i].description);
    }

    return 0;
}