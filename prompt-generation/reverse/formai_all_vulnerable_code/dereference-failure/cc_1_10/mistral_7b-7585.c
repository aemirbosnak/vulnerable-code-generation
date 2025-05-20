//MISTRAL-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_THEORIES 10
#define MAX_THEORY_LEN 100

typedef struct {
    char theory[MAX_THEORY_LEN];
    int probability;
} Theory;

Theory theories[NUM_THEORIES] = {
    {"The moon landing was faked. It was all a government hoax.", 75},
    {"The Illuminati is controlling the world from the shadows.", 85},
    {"Lizards from another dimension are among us.", 60},
    {"The 9/11 attacks were an inside job.", 90},
    {"The government is hiding the existence of alien life.", 55},
    {"The elite drink the blood of the innocent to maintain their power.", 40},
    {"The fluoride in our water is a mind control agent.", 35},
    {"The second moon landing was sabotaged.", 20},
    {"The Freemasons are secretly running the world.", 15},
    {"The pyramids were built by aliens.", 10}
};

void seed_rng() {
    unsigned int seed;
    FILE *rng_file = fopen("/dev/urandom", "r");
    fread(&seed, sizeof(seed), 1, rng_file);
    srand(seed);
}

int get_random_theory_index() {
    int total_probability = 0;
    int index;
    for (int i = 0; i < NUM_THEORIES; i++) {
        total_probability += theories[i].probability;
        if (rand() % 100 < theories[i].probability) {
            index = i;
            break;
        }
    }
    return index;
}

int main() {
    seed_rng();
    Theory selected_theory = theories[get_random_theory_index()];
    printf("Selected Theory: %s\n", selected_theory.theory);
    return 0;
}