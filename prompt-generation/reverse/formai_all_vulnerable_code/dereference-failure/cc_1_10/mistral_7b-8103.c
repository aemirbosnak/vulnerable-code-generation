//MISTRAL-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ELEMENTS 10
#define ELEMENT_LENGTH 50

typedef struct {
    char name[ELEMENT_LENGTH];
    int probability;
} ConspiracyElement;

ConspiracyElement elements[MAX_ELEMENTS] = {
    {"The moon is made of green cheese", 30},
    {"Elvis Presley is still alive and living in a mansion under the Earth", 20},
    {"The Illuminati control the world through mind control", 15},
    {"Area 51 is a government cover-up of alien technology", 25},
    {"The Bermuda Triangle is a portal to another dimension", 10},
    {"The US government orchestrated the 9/11 attacks", 5},
    {"Bigfoot is a government experiment", 8},
    {"The flat Earth theory is true", 5},
    {"The moon landing was faked", 7},
    {"The Loch Ness Monster is a Chinese dragon", 2}
};

void seed_rng(int seed) {
    srand(seed);
}

int get_random_number(int limit) {
    int random_number = rand() % limit;
    return random_number;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <seed>\n", argv[0]);
        return 1;
    }

    seed_rng(atoi(argv[1]));

    int random_index = get_random_number(MAX_ELEMENTS);
    ConspiracyElement chosen_element = elements[random_index];

    printf("Conspiracy Theory Generator: %s\n", chosen_element.name);
    printf("Probability: %d%%\n", chosen_element.probability);

    return 0;
}