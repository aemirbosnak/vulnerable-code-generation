//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char *keywords[] = {
    "Illuminati",
    "New World Order",
    "Lizard People",
    "Chemtrails",
    "Flat Earth",
    "9/11",
    "Moon Landing",
    "Area 51",
    "Big Pharma",
    "Deep State",
    "Fake News",
    "Mind Control",
    "Reptilian",
    "Satanic Rituals",
    "Secret Society",
    "UFOs",
    "Vaccines",
    "Zionist Conspiracy"
};

int main() {
    srand(time(NULL));
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);
    int numConspiracies = 3;
    char *conspiracy[numConspiracies];
    for (int i = 0; i < numConspiracies; i++) {
        conspiracy[i] = (char *)malloc(100 * sizeof(char));
        strcpy(conspiracy[i], "");
    }
    for (int i = 0; i < numKeywords; i++) {
        int keywordIndex = rand() % numKeywords;
        strcat(conspiracy[0], keywords[keywordIndex]);
        strcat(conspiracy[0], " ");
    }
    for (int i = 1; i < numConspiracies; i++) {
        int keywordIndex = rand() % numKeywords;
        while (strcmp(keywords[keywordIndex], conspiracy[i - 1]) == 0) {
            keywordIndex = rand() % numKeywords;
        }
        strcat(conspiracy[i], keywords[keywordIndex]);
        strcat(conspiracy[i], " ");
    }
    printf("Random Conspiracy Theory:\n");
    for (int i = 0; i < numConspiracies; i++) {
        printf("%s\n", conspiracy[i]);
    }
    for (int i = 0; i < numConspiracies; i++) {
        free(conspiracy[i]);
    }
    return 0;
}