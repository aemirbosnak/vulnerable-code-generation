//GEMINI-pro DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: careful
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
    "Loch Ness Monster",
    "Moon Landing",
    "New World Order",
    "Roswell UFO",
    "Secret Societies",
    "UFOs",
    "9/11 Truth"
};

// Define the conspiracy theory types
char *types[] = {
    "Cover-up",
    "Disinformation",
    "Hoax",
    "Mind control",
    "Plot",
    "Propaganda",
    "Psyop",
    "Subversion",
    "Suppression"
};

// Define the conspiracy theory evidence
char *evidence[] = {
    "Anonymous sources",
    "Classified documents",
    "Coincidence",
    "Eyewitness testimony",
    "Forensic evidence",
    "Government documents",
    "Media bias",
    "Physical evidence",
    "Scientific studies",
    "Unexplained phenomena"
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

    // Print the conspiracy theory
    printf("**Conspiracy Theory:** %s\n", topic);
    printf("**Type:** %s\n", type);
    printf("**Evidence:** %s\n\n", evidence);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate 10 random conspiracy theories
    for (int i = 0; i < 10; i++) {
        generate_conspiracy_theory();
    }

    return 0;
}