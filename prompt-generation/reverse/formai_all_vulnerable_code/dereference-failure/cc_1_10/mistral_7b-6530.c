//MISTRAL-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_CONSPIRACIES 10
#define WORD_LIST_SIZE 100

const char *conspiracy_topics[NUM_CONSPIRACIES] = {
    "Aliens",
    "Area 51",
    "Moon Landing",
    "Reptilians",
    "Flat Earth",
    "JFK Assassination",
    "Masonic Conspiracy",
    "New World Order",
    "Chemtrails",
    "Bigfoot"
};

const char *alien_races[6] = {
    "Grey Aliens",
    "Reptilian Aliens",
    "Greys with Black Eyes",
    "Tall White Aliens",
    "Blonde Haired Aliens",
    "Humanoid Aliens with Red Eyes"
};

const char *conspiracy_actions[4] = {
    "abducted",
    "implanted microchips",
    "controlled world events",
    "hid the truth from us"
};

const char *government_agencies[3] = {
    "CIA",
    "NSA",
    "FBI"
};

const char *cryptid_creatures[5] = {
    "Chupacabra",
    "Mothman",
    "Sasquatch",
    "Loch Ness Monster",
    "Mokele-Mbembe"
};

int main() {
    srand(time(NULL));

    while (1) {
        int topic = rand() % NUM_CONSPIRACIES;
        int alien = rand() % 6;
        int action = rand() % 4;
        int government = rand() % 3;
        int cryptid = rand() % 5;

        printf(" conspiracy theory:\n");
        printf(" *%s*\n", conspiracy_topics[topic]);
        printf("   *%s*\n", alien_races[alien]);
        printf("     %s\n", conspiracy_actions[action]);
        printf("   *%s*\n", government_agencies[government]);
        printf("   colluded with %s to %s\n", government_agencies[government],
               conspiracy_actions[action]);
        printf(" *%s*\n", cryptid_creatures[cryptid]);
        printf("   was also involved, %s\n",
               cryptid_creatures[cryptid]
                   [rand() % strlen(cryptid_creatures[cryptid])]);
        printf("   in the cover-up!\n");

        sleep(1);
        system("clear");
    }

    return 0;
}