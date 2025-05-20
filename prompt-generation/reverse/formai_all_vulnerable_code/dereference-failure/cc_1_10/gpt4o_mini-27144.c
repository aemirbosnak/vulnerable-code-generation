//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CONSPIRACIES 10
#define MAX_ELEMENTS 5
#define MAX_LENGTH 256

typedef struct {
    char *elements[MAX_ELEMENTS];
} ConspiracyTheory;

const char *subjects[] = {
    "aliens", "5G technology", "the Illuminati", "subliminal advertising",
    "aliens in government", "ancient civilizations", "scavenger hunts",
    "secret societies", "time travelers", "mind control"
};

const char *actions[] = {
    "control", "influence", "mind wipe", "observe", "experiment on",
    "manipulate", "destroy", "steal", "eavesdrop on", "brainwash"
};

const char *items[] = {
    "our minds", "our dreams", "the weather", "natural disasters",
    "political leaders", "celebrities", "the internet", "social media",
    "financial markets", "the human race"
};

const char *locations[] = {
    "the moon", "Area 51", "the Bermuda Triangle", "a secret lab",
    "a remote island", "Wall Street", "the Vatican", "Hollywood",
    "the internet", "a parallel universe"
};

const char *affiliates[] = {
    "the government", "big tech companies", "the media", "scientists",
    "the military", "pharmaceuticals", "celebrities", "wealthy elites",
    "mysterious cults", "ancient societies"
};

void generate_conspiracy(ConspiracyTheory *conspiracy) {
    int i, randomIndex;

    for (i = 0; i < MAX_ELEMENTS; i++) {
        switch (rand() % 5) {
            case 0:
                randomIndex = rand() % (sizeof(subjects) / sizeof(subjects[0]));
                conspiracy->elements[i] = strdup(subjects[randomIndex]);
                break;
            case 1:
                randomIndex = rand() % (sizeof(actions) / sizeof(actions[0]));
                conspiracy->elements[i] = strdup(actions[randomIndex]);
                break;
            case 2:
                randomIndex = rand() % (sizeof(items) / sizeof(items[0]));
                conspiracy->elements[i] = strdup(items[randomIndex]);
                break;
            case 3:
                randomIndex = rand() % (sizeof(locations) / sizeof(locations[0]));
                conspiracy->elements[i] = strdup(locations[randomIndex]);
                break;
            case 4:
                randomIndex = rand() % (sizeof(affiliates) / sizeof(affiliates[0]));
                conspiracy->elements[i] = strdup(affiliates[randomIndex]);
                break;
        }
    }
}

void free_conspiracy(ConspiracyTheory *conspiracy) {
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (conspiracy->elements[i] != NULL) {
            free(conspiracy->elements[i]);
            conspiracy->elements[i] = NULL;
        }
    }
}

void print_conspiracy(const ConspiracyTheory *conspiracy) {
    printf("Conspiracy Theory:\n");
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (conspiracy->elements[i] != NULL) {
            printf(" - %s\n", conspiracy->elements[i]);
        }
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    ConspiracyTheory conspiracies[MAX_CONSPIRACIES];
    int numberOfConspiracies = 5; // Number of conspiracy theories to generate

    for (int i = 0; i < numberOfConspiracies; i++) {
        generate_conspiracy(&conspiracies[i]);
        print_conspiracy(&conspiracies[i]);
        free_conspiracy(&conspiracies[i]);
    }

    return 0;
}