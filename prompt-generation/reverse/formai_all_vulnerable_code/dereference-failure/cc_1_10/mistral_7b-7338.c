//MISTRAL-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACIES 10

typedef struct {
    char *conspiracy;
    int probability;
} Conspiracy;

Conspiracy conspiracies[MAX_CONSPIRACIES] = {
    {"The moon landing was faked.", 85},
    {"The Illuminati controls the world.", 92},
    {"Elon Musk is an alien.", 63},
    {"5G causes COVID-19.", 37},
    {"The Flat Earth Theory is true.", 12},
    {"The government is hiding alien technology.", 78},
    {"The Loch Ness Monster is a Russian Submarine.", 45},
    {"The Paul is Dead theory is true.", 51},
    {"The pyramids were built by extraterrestrials.", 27},
    {"The moon is made of cheese.", 1}
};

void seed_rng() {
    unsigned int seed[3];
    char str[128];

    FILE *rng_file = fopen("/dev/urandom", "r");
    if (rng_file == NULL) {
        printf("Failed to open /dev/urandom\n");
        exit(EXIT_FAILURE);
    }

    if (fread(seed, sizeof(unsigned int), 3, rng_file) != 3) {
        printf("Failed to read from /dev/urandom\n");
        exit(EXIT_FAILURE);
    }

    fclose(rng_file);

    snprintf(str, sizeof(str), "%u%u%u", seed[0], seed[1], seed[2]);
    srand(strtoul(str, NULL, 10));
}

int main() {
    int i;
    int random_index;
    int random_number;

    seed_rng();

    printf("The truth is hidden from us.\n");
    printf("Here's a random conspiracy theory for today:\n");

    random_index = rand() % MAX_CONSPIRACIES;
    printf("%s\n", conspiracies[random_index].conspiracy);
    printf("The probability of this theory being true is: %%d%%\n", conspiracies[random_index].probability);

    random_number = rand() % 100 + 1;

    if (random_number <= conspiracies[random_index].probability) {
        printf("Could it be?\n");
    } else {
        printf("Probably just a wild coincidence...\n");
    }

    for (i = 0; i < MAX_CONSPIRACIES; i++) {
        free(conspiracies[i].conspiracy);
    }

    return 0;
}