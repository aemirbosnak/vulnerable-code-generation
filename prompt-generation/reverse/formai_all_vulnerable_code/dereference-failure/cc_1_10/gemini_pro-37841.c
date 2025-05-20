//GEMINI-pro DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the possible conspiracy theories
const char *theories[] = {
  "The moon landing was faked by NASA.",
  "The Earth is flat.",
  "The government is controlled by aliens.",
  "9/11 was an inside job.",
  "JFK was assassinated by the CIA.",
  "The Loch Ness Monster is real.",
  "Bigfoot is real.",
  "The Bermuda Triangle is a portal to another dimension.",
  "The Illuminati is a real organization that controls the world.",
  "The Bilderberg Group is a secret society that meets to discuss world domination."
};

// Define the possible sources of the conspiracy theories
const char *sources[] = {
  "Anonymous internet user",
  "Government whistleblower",
  "UFO researcher",
  "Paranormal investigator",
  "Conspiracy theorist",
  "New Age guru",
  "Disgruntled employee",
  "Former military officer",
  "Scientist",
  "Journalist"
};

// Define the possible motives for the conspiracy theories
const char *motives[] = {
  "To hide the truth from the public.",
  "To control the population.",
  "To make money.",
  "To gain power.",
  "To discredit someone or something.",
  "To create chaos and confusion.",
  "To entertain people.",
  "To promote a particular ideology.",
  "To sell books or products.",
  "To get attention."
};

// Define the possible evidence for the conspiracy theories
const char *evidence[] = {
  "Eyewitness testimony",
  "Physical evidence",
  "Documentary evidence",
  "Circumstantial evidence",
  "Logic and reason",
  "Intuition",
  "Faith",
  "Hope",
  "Despair",
  "Anger"
};

// Define the possible conclusions of the conspiracy theories
const char *conclusions[] = {
  "The conspiracy theory is true.",
  "The conspiracy theory is false.",
  "The conspiracy theory is partially true.",
  "The conspiracy theory is unknown.",
  "The conspiracy theory is irrelevant.",
  "The conspiracy theory is harmful.",
  "The conspiracy theory is beneficial.",
  "The conspiracy theory is entertaining.",
  "The conspiracy theory is thought-provoking.",
  "The conspiracy theory is dangerous."
};

// Generate a random conspiracy theory
void generate_conspiracy_theory(void) {
  // Get a random seed from the system clock
  srand(time(NULL));

  // Select a random theory
  int theory_index = rand() % (sizeof(theories) / sizeof(theories[0]));
  const char *theory = theories[theory_index];

  // Select a random source
  int source_index = rand() % (sizeof(sources) / sizeof(sources[0]));
  const char *source = sources[source_index];

  // Select a random motive
  int motive_index = rand() % (sizeof(motives) / sizeof(motives[0]));
  const char *motive = motives[motive_index];

  // Select a random piece of evidence
  int evidence_index = rand() % (sizeof(evidence) / sizeof(evidence[0]));
  const char *evidence = evidence[evidence_index];

  // Select a random conclusion
  int conclusion_index = rand() % (sizeof(conclusions) / sizeof(conclusions[0]));
  const char *conclusion = conclusions[conclusion_index];

  // Print the conspiracy theory
  printf("**Conspiracy Theory:** %s\n", theory);
  printf("**Source:** %s\n", source);
  printf("**Motive:** %s\n", motive);
  printf("**Evidence:** %s\n", evidence);
  printf("**Conclusion:** %s\n\n", conclusion);
}

// Main function
int main(void) {
  // Generate 10 random conspiracy theories
  for (int i = 0; i < 10; i++) {
    generate_conspiracy_theory();
  }

  return 0;
}