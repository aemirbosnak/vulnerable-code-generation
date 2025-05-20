//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_THEORIES 10
#define MAX_LENGTH 256

const char *theories[NUM_THEORIES] = {
    "Aliens are using our Wi-Fi signals to communicate with each other.",
    "The moon landing was staged by a secret society of lizard people.",
    "Bigfoot is actually a time traveler from an alternate dimension.",
    "Birds are drones created by the government to monitor our every move.",
    "The shape of the Great Pyramid holds the secret to time travel.",
    "Freemasons are trying to create a New World Order through global warming.",
    "Toothpaste is a conspiracy by dental companies to put us in debt.",
    "Every major historical event was orchestrated by a hidden cabal of wizards.",
    "Weather patterns are manipulated by secret organizations to influence global politics.",
    "Your smartphone is secretly monitoring your thoughts and feelings."
};

const char *locations[] = {
    "Area 51",
    "the Bermuda Triangle",
    "the Vatican",
    "Mount Everest",
    "the Amazon rainforest",
    "Antarctica",
    "Stonehenge",
    "the Sphinx",
    "the Dark Web",
    "the Hollow Earth"
};

const char *people[] = {
    "Elon Musk",
    "the Queen of England",
    "Barack Obama",
    "a former astronaut",
    "the CEO of a tech company",
    "a celebrity chef",
    "a famous artist",
    "a historian",
    "a scientist",
    "a conspiracy theorist"
};

void generate_conspiracy_theory(char *output) {
    int theory_index = rand() % NUM_THEORIES;
    int location_index = rand() % (sizeof(locations) / sizeof(locations[0]));
    int person_index = rand() % (sizeof(people) / sizeof(people[0]));

    snprintf(output, MAX_LENGTH, "Theory: %s\nLocation: %s\nInvolved Person: %s",
             theories[theory_index], locations[location_index], people[person_index]);
}

void generate_multiple_theories(int count) {
    char output[MAX_LENGTH];
    for (int i = 0; i < count; i++) {
        generate_conspiracy_theory(output);
        printf("%d. %s\n\n", i + 1, output);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number_of_theories>\n", argv[0]);
        return 1;
    }

    int num_theories = atoi(argv[1]);
    if (num_theories <= 0 || num_theories > 100) {
        fprintf(stderr, "Please enter a valid number of theories (1 - 100).\n");
        return 1;
    }

    srand(time(NULL)); // Seed the random number generator
    generate_multiple_theories(num_theories);

    return 0;
}