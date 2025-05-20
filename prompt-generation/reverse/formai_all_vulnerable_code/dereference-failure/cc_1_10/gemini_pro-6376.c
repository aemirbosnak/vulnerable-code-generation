//GEMINI-pro DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of theories to generate
#define NUM_THEORIES 10

// Create an array of conspiracy theory topics
char *topics[] = {
    "UFOs",
    "Area 51",
    "Bigfoot",
    "Loch Ness Monster",
    "Moon landing hoax",
    "JFK assassination",
    "9/11 attacks",
    "New World Order",
    "Illuminati",
    "Flat Earth"
};

// Create an array of conspiracy theory claims
char *claims[] = {
    "are real and have visited Earth",
    "is a secret military base where aliens are studied",
    "is a real creature that lives in the forests of North America",
    "is a real creature that lives in Loch Ness, Scotland",
    "was faked by NASA",
    "was carried out by the CIA",
    "were an inside job",
    "is a secret organization that controls the world",
    "are a real group of powerful people who control the world",
    "is the true shape of the Earth"
};

// Create an array of conspiracy theory evidence
char *evidence[] = {
    "crashed UFOs have been found",
    "satellite images show strange objects near Area 51",
    "eyewitness accounts of Bigfoot sightings",
    "sonar readings have detected a large creature in Loch Ness",
    "there are inconsistencies in the official story of the moon landing",
    "there are unanswered questions about the JFK assassination",
    "there were explosives planted in the World Trade Center towers",
    "there are secret documents that prove the existence of the New World Order",
    "there are symbols of the Illuminati hidden in plain sight",
    "there is photographic evidence that the Earth is flat"
};

// Generate a random conspiracy theory
void generate_theory() {
    // Get a random topic
    int topic_index = rand() % (sizeof(topics) / sizeof(char *));
    char *topic = topics[topic_index];

    // Get a random claim
    int claim_index = rand() % (sizeof(claims) / sizeof(char *));
    char *claim = claims[claim_index];

    // Get a random evidence
    int evidence_index = rand() % (sizeof(evidence) / sizeof(char *));
    char *evidence = evidence[evidence_index];

    // Print the conspiracy theory
    printf("**Conspiracy Theory:** %s %s because %s\n", topic, claim, evidence);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate NUM_THEORIES conspiracy theories
    for (int i = 0; i < NUM_THEORIES; i++) {
        generate_theory();
    }

    return 0;
}