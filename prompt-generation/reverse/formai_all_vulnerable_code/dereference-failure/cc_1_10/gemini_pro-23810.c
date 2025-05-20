//GEMINI-pro DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the conspiracy theory categories
char *categories[] = {
    "Government",
    "Aliens",
    "Celebrities",
    "Technology",
    "Health",
    "Finance",
    "The Illuminati",
    "The New World Order",
    "The Bilderberg Group",
    "9/11",
    "The JFK Assassination",
    "The Moon Landing",
    "The Roswell Incident",
    "The Bermuda Triangle",
    "The Loch Ness Monster",
    "Bigfoot",
    "The chupacabra",
    "The Mothman",
    "The Jersey Devil"
};

// Define the conspiracy theory types
char *types[] = {
    "Cover-up",
    "Hoax",
    "False flag",
    "Mind control",
    "New World Order",
    "Illuminati",
    "Secret society",
    "Alien invasion",
    "Government conspiracy",
    "Celebrity conspiracy",
    "Health conspiracy",
    "Financial conspiracy",
    "9/11 conspiracy",
    "JFK Assassination conspiracy",
    "Moon Landing conspiracy",
    "Roswell Incident conspiracy",
    "Bermuda Triangle conspiracy",
    "Loch Ness Monster conspiracy",
    "Bigfoot conspiracy",
    "Chupacabra conspiracy",
    "Mothman conspiracy",
    "Jersey Devil conspiracy"
};

// Define the conspiracy theory evidence
char *evidence[] = {
    "Documents",
    "Witnesses",
    "Physical evidence",
    "Circumstantial evidence",
    "Logic",
    "Intuition",
    "Common sense",
    "Gut feeling",
    "Hearsay",
    "Rumors",
    "Speculation",
    "Conjecture",
    "Innuendo",
    "Implication",
    "Suggestion",
    "Insinuation",
    "Hint",
    "Nudge",
    "Wink"
};

// Define the conspiracy theory conclusions
char *conclusions[] = {
    "The government is lying to us.",
    "Aliens are real.",
    "Celebrities are controlled by the Illuminati.",
    "Technology is being used to control us.",
    "The health industry is a scam.",
    "The financial system is rigged.",
    "The Illuminati is a real organization.",
    "The New World Order is coming.",
    "The Bilderberg Group is a secret society.",
    "9/11 was an inside job.",
    "The JFK Assassination was a conspiracy.",
    "The Moon Landing was a hoax.",
    "The Roswell Incident was a government cover-up.",
    "The Bermuda Triangle is a real mystery.",
    "The Loch Ness Monster is real.",
    "Bigfoot is real.",
    "The chupacabra is real.",
    "The Mothman is real.",
    "The Jersey Devil is real."
};

// Generate a random conspiracy theory
void generate_conspiracy_theory() {
    // Get a random category
    int category_index = rand() % (sizeof(categories) / sizeof(char *));
    char *category = categories[category_index];

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
    printf("**Conspiracy Theory:** %s is a %s based on %s that concludes %s.\n", category, type, evidence, conclusion);
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