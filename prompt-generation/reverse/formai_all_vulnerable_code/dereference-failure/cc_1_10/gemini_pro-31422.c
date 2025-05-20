//GEMINI-pro DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the arrays of conspiracy theories.
char *subjects[] = {
  "JFK",
  "9/11",
  "Area 51",
  "Moon landing",
  "Flat Earth",
  "Illuminati",
  "New World Order",
  "Chemtrails",
  "Fluoride",
  "GMOs",
  "Climate change",
  "COVID-19"
};

char *verbs[] = {
  "is a hoax",
  "was an inside job",
  "is a cover-up",
  "is being hidden from us",
  "is a threat to our freedom",
  "is a plot to control us",
  "is a sign of the end times"
};

char *objects[] = {
  "the government",
  "the media",
  "the Illuminati",
  "the Bilderberg Group",
  "the Trilateral Commission",
  "the Council on Foreign Relations",
  "the New World Order",
  "the aliens",
  "the reptilians",
  "the Zionists",
  "the communists",
  "the socialists"
};

// Get a random number between 0 and the given maximum.
int rand_int(int max) {
  return rand() % (max + 1);
}

// Generate a random conspiracy theory.
char *generate_conspiracy_theory() {
  // Get random indices for the subject, verb, and object.
  int subject_index = rand_int(sizeof(subjects) / sizeof(char *) - 1);
  int verb_index = rand_int(sizeof(verbs) / sizeof(char *) - 1);
  int object_index = rand_int(sizeof(objects) / sizeof(char *) - 1);

  // Allocate memory for the conspiracy theory.
  char *conspiracy_theory = malloc(strlen(subjects[subject_index]) + strlen(verbs[verb_index]) + strlen(objects[object_index]) + 1);

  // Concatenate the subject, verb, and object into the conspiracy theory.
  strcpy(conspiracy_theory, subjects[subject_index]);
  strcat(conspiracy_theory, " ");
  strcat(conspiracy_theory, verbs[verb_index]);
  strcat(conspiracy_theory, " ");
  strcat(conspiracy_theory, objects[object_index]);

  // Return the conspiracy theory.
  return conspiracy_theory;
}

// Print the given conspiracy theory.
void print_conspiracy_theory(char *conspiracy_theory) {
  printf("%s\n", conspiracy_theory);
}

// Generate and print a random conspiracy theory.
int main() {
  // Seed the random number generator.
  srand(time(NULL));

  // Generate a random conspiracy theory.
  char *conspiracy_theory = generate_conspiracy_theory();

  // Print the conspiracy theory.
  print_conspiracy_theory(conspiracy_theory);

  // Free the memory allocated for the conspiracy theory.
  free(conspiracy_theory);

  return 0;
}