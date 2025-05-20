//GEMINI-pro DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Array of possible conspiracy theories
char *theories[] = {
  "The moon landing was faked by the government.",
  "Aliens are living among us.",
  "The Illuminati is a real organization that controls the world.",
  "The JFK assassination was a conspiracy.",
  "9/11 was an inside job.",
  "The earth is flat.",
  "Vaccines are dangerous.",
  "The government is using mind control technology.",
  "The end of the world is coming soon.",
  "We are living in a simulation."
};

// Array of possible evidence
char *evidence[] = {
  "I saw it on the internet.",
  "My uncle's friend's cousin works for the government.",
  "There's a documentary about it.",
  "I read it in a book.",
  "I saw a UFO once.",
  "I have a gut feeling.",
  "It just doesn't make sense.",
  "The government is hiding the truth.",
  "The media is lying to us.",
  "I believe in my heart."
};

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a random conspiracy theory
  int theoryIndex = rand() % (sizeof(theories) / sizeof(char *));
  char *theory = theories[theoryIndex];

  // Generate a random piece of evidence
  int evidenceIndex = rand() % (sizeof(evidence) / sizeof(char *));
  char *evidence = evidence[evidenceIndex];

  // Print the conspiracy theory and evidence
  printf("OMG! I can't believe it! Did you know that %s? I have proof! %s", theory, evidence);

  return 0;
}