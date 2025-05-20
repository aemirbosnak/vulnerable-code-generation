//GEMINI-pro DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the conspiracy theory topics
char *topics[] = {
    "Aliens",
    "Bigfoot",
    "Chemtrails",
    "Flat Earth",
    "Illuminati",
    "JFK Assassination",
    "Moon Landing",
    "New World Order",
    "Roswell UFO",
    "9/11 Inside Job"
};

// Define the conspiracy theory types
char *types[] = {
    "Cover-up",
    "Hoax",
    "Mind control",
    "False flag",
    "Secret society",
    "Government plot",
    "Corporate conspiracy",
    "Media manipulation",
    "Scientific fraud",
    "Religious deception"
};

// Define the conspiracy theory evidence
char *evidence[] = {
    "Eyewitness accounts",
    "Leaked documents",
    "Physical evidence",
    "Circumstantial evidence",
    "Statistical anomalies",
    "Expert testimony",
    "Logic and reason",
    "Intuition",
    "Dreams",
    "Premonitions"
};

// Define the conspiracy theory conclusions
char *conclusions[] = {
    "The truth is being hidden from us.",
    "We are being manipulated and controlled.",
    "Our world is not what it seems.",
    "We need to wake up and fight for our freedom.",
    "The end is near.",
    "We are all going to die.",
    "There is no hope.",
    "We are doomed.",
    "We are alone.",
    "We are insignificant."
};

// Generate a random conspiracy theory
void generate_conspiracy_theory() {
    // Get a random topic
    int topic_index = rand() % (sizeof(topics) / sizeof(char *));
    char *topic = topics[topic_index];

    // Get a random type
    int type_index = rand() % (sizeof(types) / sizeof(char *));
    char *type = types[type_index];

    // Get a random evidence
    int evidence_index = rand() % (sizeof(evidence) / sizeof(char *));
    char *evidence = evidence[evidence_index];

    // Get a random conclusion
    int conclusion_index = rand() % (sizeof(conclusions) / sizeof(char *));
    char *conclusion = conclusions[conclusion_index];

    // Print the conspiracy theory
    printf("**Conspiracy Theory:**\n");
    printf("Topic: %s\n", topic);
    printf("Type: %s\n", type);
    printf("Evidence: %s\n", evidence);
    printf("Conclusion: %s\n", conclusion);
}

int main() {
    // Set the random seed
    srand(time(NULL));

    // Generate 100 random conspiracy theories
    for (int i = 0; i < 100; i++) {
        generate_conspiracy_theory();
        printf("\n");
    }

    return 0;
}