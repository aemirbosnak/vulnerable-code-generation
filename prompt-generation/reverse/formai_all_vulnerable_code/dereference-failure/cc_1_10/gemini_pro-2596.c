//GEMINI-pro DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CONSPIRACIES 10

// Array of conspiracy theories
char *conspiracies[] = {
  "The moon landing was faked.",
  "Aliens are living among us.",
  "The government is hiding the truth about UFOs.",
  "The Illuminati is a real organization.",
  "The world is controlled by a secret cabal of elites.",
  "The end of the world is coming.",
  "The vaccine is a government plot to track and control us.",
  "The 5G network is causing COVID-19.",
  "The Earth is flat.",
  "The Holocaust never happened."
};

// Array of modifiers
char *modifiers[] = {
  "definitely",
  "probably",
  "possibly",
  "maybe",
  "could be",
  "might be",
  "is likely",
  "is possible",
  "is a possibility",
  "is a hoax"
};

// Function to generate a random conspiracy theory
char *generate_conspiracy_theory() {
  // Get a random conspiracy theory
  int conspiracy_index = rand() % NUM_CONSPIRACIES;
  char *conspiracy = conspiracies[conspiracy_index];

  // Get a random modifier
  int modifier_index = rand() % NUM_CONSPIRACIES;
  char *modifier = modifiers[modifier_index];

  // Concatenate the conspiracy theory and the modifier
  char *theory = malloc(strlen(conspiracy) + strlen(modifier) + 2);
  strcpy(theory, conspiracy);
  strcat(theory, " ");
  strcat(theory, modifier);

  return theory;
}

// Main function
int main() {
  // Set the random seed
  srand(time(NULL));

  // Generate 10 random conspiracy theories
  for (int i = 0; i < 10; i++) {
    char *theory = generate_conspiracy_theory();
    printf("%s\n", theory);
    free(theory);
  }

  return 0;
}