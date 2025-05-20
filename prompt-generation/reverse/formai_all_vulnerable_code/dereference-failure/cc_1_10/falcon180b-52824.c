//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CONSPIRACY_LENGTH 1000

typedef struct {
    char name[MAX_CONSPIRACY_LENGTH];
    char description[MAX_CONSPIRACY_LENGTH];
} ConspiracyTheory;

ConspiracyTheory* generate_conspiracy_theory() {
    ConspiracyTheory* theory = malloc(sizeof(ConspiracyTheory));

    srand(time(NULL));
    int theory_type = rand() % 5;

    switch (theory_type) {
        case 0:
            strcpy(theory->name, "The Lizard People");
            strcpy(theory->description, "A secret race of reptilian humanoids controls world politics and the media.");
            break;
        case 1:
            strcpy(theory->name, "Flat Earth");
            strcpy(theory->description, "The Earth is not a globe, but a flat disc, and all evidence to the contrary is a hoax.");
            break;
        case 2:
            strcpy(theory->name, "Chemtrails");
            strcpy(theory->description, "Contrails left by airplanes are actually chemical or biological agents deliberately sprayed for sinister purposes.");
            break;
        case 3:
            strcpy(theory->name, "9/11 Inside Job");
            strcpy(theory->description, "The September 11 attacks were orchestrated by the United States government as a pretext for war.");
            break;
        case 4:
            strcpy(theory->name, "Moon Landing Hoax");
            strcpy(theory->description, "The Apollo Moon landings were faked and the whole thing was staged by NASA and the government.");
            break;
    }

    return theory;
}

void print_conspiracy_theory(ConspiracyTheory* theory) {
    printf("Name: %s\n", theory->name);
    printf("Description: %s\n", theory->description);
}

int main() {
    ConspiracyTheory* theory = generate_conspiracy_theory();
    print_conspiracy_theory(theory);

    free(theory);
    return 0;
}