//GEMINI-pro DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Donald Knuth
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// Define the list of conspiracy theories
char *conspiracy_theories[] = {
    "The moon landing was faked.",
    "The Earth is flat.",
    "aliens are real.",
    "The government is hiding the truth about UFOs.",
    "The Illuminati controls the world.",
    "Vaccines cause autism.",
    "Climate change is a hoax.",
    "The Bilderberg Group is a secret organization that controls the world.",
    "The New World Order is coming.",
    "The end of the world is nigh."
};

// Define the list of supporting evidence
char *supporting_evidence[] = {
    "There are no stars in the moon landing photos.",
    "The Earth's shadow on the moon is always a perfect circle.",
    "There are no craters on the moon's surface.",
    "The American flag planted on the moon is waving in the wind.",
    "The Earth is a sphere, not a flat disk.",
    "There have been numerous UFO sightings.",
    "The government has a history of covering up UFO sightings.",
    "The Illuminati is a real organization with a long history.",
    "The Bilderberg Group is a real organization that meets in secret.",
    "The end of the world is predicted in the Bible."
};

// Define the list of red herrings
char *red_herrings[] = {
    "The moon landing was real because I saw it on TV.",
    "The Earth is round because I can see the curvature of the horizon.",
    "Aliens are not real because there is no evidence to support their existence.",
    "The government is not hiding the truth about UFOs because they would have no reason to do so.",
    "The Illuminati is not a real organization because there is no evidence to support its existence.",
    "Vaccines do not cause autism because there is no evidence to support this claim.",
    "Climate change is real because there is overwhelming scientific evidence to support it.",
    "The Bilderberg Group is not a secret organization because their meetings are open to the public.",
    "The New World Order is not coming because there is no evidence to support this claim.",
    "The end of the world is not nigh because there is no evidence to support this claim."
};

// Define the list of random facts
char *random_facts[] = {
    "The population of the Earth is about 8 billion people.",
    "The speed of light is about 300,000 kilometers per second.",
    "The average temperature of the Earth is about 15 degrees Celsius.",
    "The sun is a star.",
    "The moon is a satellite of the Earth.",
    "The Earth is the third planet from the sun.",
    "The solar system is located in the Milky Way galaxy.",
    "The Milky Way galaxy is about 100,000 light-years across.",
    "The universe is about 13.8 billion years old.",
    "The human body is made up of about 60 trillion cells."
};

// Generate a random conspiracy theory
char *generate_conspiracy_theory() {
    // Get a random conspiracy theory
    int conspiracy_theory_index = rand() % (sizeof(conspiracy_theories) / sizeof(char *));
    char *conspiracy_theory = conspiracy_theories[conspiracy_theory_index];

    // Get a random supporting evidence
    int supporting_evidence_index = rand() % (sizeof(supporting_evidence) / sizeof(char *));
    char *supporting_evidence = supporting_evidence[supporting_evidence_index];

    // Get a random red herring
    int red_herring_index = rand() % (sizeof(red_herrings) / sizeof(char *));
    char *red_herring = red_herrings[red_herring_index];

    // Get a random fact
    int random_fact_index = rand() % (sizeof(random_facts) / sizeof(char *));
    char *random_fact = random_facts[random_fact_index];

    // Combine the conspiracy theory, supporting evidence, red herring, and random fact into a single string
    char *conspiracy_theory_string = malloc(strlen(conspiracy_theory) + strlen(supporting_evidence) + strlen(red_herring) + strlen(random_fact) + 4);
    sprintf(conspiracy_theory_string, "%s: %s. But don't forget, %s. Also, did you know that %s?", conspiracy_theory, supporting_evidence, red_herring, random_fact);

    // Return the conspiracy theory string
    return conspiracy_theory_string;
}

// Print a random conspiracy theory to the console
void print_conspiracy_theory() {
    // Generate a random conspiracy theory
    char *conspiracy_theory = generate_conspiracy_theory();

    // Print the conspiracy theory to the console
    printf("%s\n", conspiracy_theory);

    // Free the memory allocated for the conspiracy theory string
    free(conspiracy_theory);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Print a random conspiracy theory to the console
    print_conspiracy_theory();

    // Return 0 to indicate successful execution
    return 0;
}