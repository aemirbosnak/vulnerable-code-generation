//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACY_LENGTH 1000

typedef struct {
    char *name;
    char *description;
} Conspiracy;

Conspiracy conspiracies[] = {
    {"The Illuminati", "A secret society that controls world affairs"},
    {"Area 51", "A top-secret government facility where aliens are studied"},
    {"Flat Earth", "The belief that the Earth is flat, not round"},
    {"9/11 was an inside job", "The theory that the U.S. government orchestrated the 9/11 attacks"},
    {"Moon landing hoax", "The belief that the moon landings were faked"},
    {"Chemtrails", "The theory that airplane contrails are actually chemical or biological agents"},
    {"New World Order", "A secretive group of international elites who seek to establish a one-world government"},
    {"Lizard people", "The belief that shape-shifting reptilian aliens control world politics"},
    {"Bigfoot", "A legendary ape-like creature said to inhabit the forests of North America"},
    {"Elvis sightings", "Reports of seeing Elvis Presley alive after his supposed death"}
};

int main() {
    srand(time(NULL));

    int num_conspiracies = rand() % 10 + 1;
    Conspiracy *selected_conspiracies = malloc(num_conspiracies * sizeof(Conspiracy));

    for (int i = 0; i < num_conspiracies; i++) {
        int index = rand() % sizeof(conspiracies) / sizeof(conspiracies[0]);
        selected_conspiracies[i] = conspiracies[index];
    }

    char conspiracy_text[MAX_CONSPIRACY_LENGTH];
    conspiracy_text[0] = '\0';

    for (int i = 0; i < num_conspiracies; i++) {
        strcat(conspiracy_text, selected_conspiracies[i].name);
        strcat(conspiracy_text, ", ");
    }

    printf("Random Conspiracy Theory: %s\n", conspiracy_text);

    for (int i = 0; i < num_conspiracies; i++) {
        free(selected_conspiracies[i].name);
        free(selected_conspiracies[i].description);
    }
    free(selected_conspiracies);

    return 0;
}