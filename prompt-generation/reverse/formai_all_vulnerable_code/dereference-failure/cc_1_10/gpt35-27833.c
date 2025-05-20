//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_THEORIES 10
#define MAX_LENGTH 100

char* theories[] = {
    "The Illuminati controls the weather through satellites.",
    "The government is hiding the cure for cancer.",
    "The moon landing was faked.",
    "Aliens have infiltrated the government.",
    "The earth is flat and the government is covering it up.",
    "The pyramids were built by aliens.",
    "The Bermuda Triangle is a portal to another dimension.",
    "The Titanic sinking was planned by the government.",
    "The government is spying on us through our phones.",
    "9/11 was an inside job."
};

char* locations[] = {
    "Washington D.C.",
    "Area 51",
    "The Vatican",
    "The North Pole",
    "The Bermuda Triangle",
    "Roswell, New Mexico",
    "The Great Pyramids",
    "The White House",
    "The International Space Station",
    "The Moon"
};

char* people[] = {
    "Barack Obama",
    "Mark Zuckerberg",
    "Elon Musk",
    "Bill Gates",
    "Donald Trump",
    "The Pope",
    "Queen Elizabeth II",
    "Vladimir Putin",
    "Angelina Jolie",
    "Kim Kardashian"
};

char* generate_conspiracy_theory() {
    int theory_index = rand() % NUM_THEORIES;
    int location_index = rand() % 10;
    int person_index = rand() % 10;

    char* theory = theories[theory_index];
    char* location = locations[location_index];
    char* person = people[person_index];

    char* result = malloc(MAX_LENGTH);
    snprintf(result, MAX_LENGTH, "%s %s %s", theory, location, person);

    return result;
}

int main() {
    srand(time(NULL));
    printf("Here are some conspiracy theories:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d. %s\n", i+1, generate_conspiracy_theory());
    }
    return 0;
}