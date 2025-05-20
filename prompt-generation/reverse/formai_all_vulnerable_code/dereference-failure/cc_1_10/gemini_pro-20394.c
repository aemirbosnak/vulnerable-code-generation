//GEMINI-pro DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the list of conspiracy theories
const char *conspiracy_theories[] = {
  "The moon landing was faked.",
  "Aliens are living among us.",
  "The government is hiding the truth about UFOs.",
  "The Illuminati is a real organization that controls the world.",
  "The New World Order is a plan to enslave humanity.",
  "The Bilderberg Group is a secret society of powerful people who control the world.",
  "The Trilateral Commission is a secret society of powerful people who control the world.",
  "The Council on Foreign Relations is a secret society of powerful people who control the world.",
  "The World Economic Forum is a secret society of powerful people who control the world.",
  "The United Nations is a secret society of powerful people who control the world."
};

// Define the list of random facts
const char *random_facts[] = {
  "The population of the earth is about 8 billion people.",
  "The earth is about 4.5 billion years old.",
  "The sun is about 150 million kilometers away from the earth.",
  "The speed of light is about 300,000 kilometers per second.",
  "The average human lifespan is about 79 years.",
  "The average human body temperature is about 37 degrees Celsius.",
  "The human brain has about 100 billion neurons.",
  "The human heart beats about 100,000 times per day.",
  "The human lungs inhale about 2,000 liters of air per day.",
  "The human stomach can hold about 1 liter of food."
};

// Generate a random conspiracy theory
char *generate_conspiracy_theory() {
  // Get a random conspiracy theory from the list
  int conspiracy_theory_index = rand() % (sizeof(conspiracy_theories) / sizeof(char *));
  char *conspiracy_theory = conspiracy_theories[conspiracy_theory_index];

  // Get a random fact from the list
  int random_fact_index = rand() % (sizeof(random_facts) / sizeof(char *));
  char *random_fact = random_facts[random_fact_index];

  // Combine the conspiracy theory and the random fact
  char *result = malloc(strlen(conspiracy_theory) + strlen(random_fact) + 1);
  strcpy(result, conspiracy_theory);
  strcat(result, " ");
  strcat(result, random_fact);

  return result;
}

// Print a random conspiracy theory
void print_conspiracy_theory() {
  // Generate a random conspiracy theory
  char *conspiracy_theory = generate_conspiracy_theory();

  // Print the conspiracy theory
  printf("%s\n", conspiracy_theory);

  // Free the memory allocated for the conspiracy theory
  free(conspiracy_theory);
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Print a random conspiracy theory
  print_conspiracy_theory();

  return 0;
}