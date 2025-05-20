//MISTRAL-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_THEORIES 10

typedef struct {
    char *theory;
    int probability;
} Theory;

Theory theories[NUM_THEORIES] = {
    {"The moon landing was faked.", 75},
    {"9/11 was an inside job.", 50},
    {"The Illuminati control the world.", 85},
    {"Bigfoot is a government experiment.", 25},
    {"The Loch Ness monster is a Soviet submarine.", 15},
    {"Elvis is still alive.", 35},
    {"The pyramids were built by aliens.", 60},
    {"The Flat Earth Society is right.", 10},
    {"The government is hiding the truth about Area 51.", 90},
    {"JFK was assassinated by the CIA.", 45}
};

void seed_rng() {
    time_t rawtime;
    struct tm *timeinfo;
    int seed;

    char *tzptr;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    seed = (int)timeinfo->tm_year * 10000 + (int)timeinfo->tm_mon * 100 + (int)timeinfo->tm_mday;
    seed = seed * 10000 + (int)timeinfo->tm_hour * 1000 + (int)timeinfo->tm_min * 100 + (int)timeinfo->tm_sec;
    srand(seed);
}

int random_theory() {
    int total_probability = 0;
    int index, random_num;

    for (index = 0; index < NUM_THEORIES; index++) {
        total_probability += theories[index].probability;
    }

    random_num = rand() % total_probability;

    for (index = 0; index < NUM_THEORIES; index++) {
        if (random_num < theories[index].probability) {
            return index;
        } else {
            random_num -= theories[index].probability;
        }
    }

    return -1;
}

int main() {
    int i;
    int theory_index;

    seed_rng();

    for (i = 0; i < 10; i++) {
        theory_index = random_theory();

        if (theory_index != -1) {
            printf("Theory %d: %s\n", i + 1, theories[theory_index].theory);
        }
    }

    return 0;
}