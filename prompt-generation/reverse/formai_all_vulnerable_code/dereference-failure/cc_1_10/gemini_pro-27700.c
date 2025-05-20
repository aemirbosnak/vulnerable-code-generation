//GEMINI-pro DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random number between min and max
int random_int(int min, int max) {
  return rand() % (max - min + 1) + min;
}

// Function to generate a random string of length n
char *random_string(int n) {
  char *str = malloc(n + 1);
  for (int i = 0; i < n; i++) {
    str[i] = random_int('a', 'z');
  }
  str[n] = '\0';
  return str;
}

// Function to generate a random conspiracy theory
char *generate_conspiracy_theory() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate the first part of the conspiracy theory
  char *part1 = random_string(random_int(5, 10));

  // Generate the second part of the conspiracy theory
  char *part2 = random_string(random_int(5, 10));

  // Combine the two parts of the conspiracy theory
  char *conspiracy_theory = malloc(strlen(part1) + strlen(part2) + 2);
  strcpy(conspiracy_theory, part1);
  strcat(conspiracy_theory, " is secretly ");
  strcat(conspiracy_theory, part2);

  // Return the conspiracy theory
  return conspiracy_theory;
}

// Main function
int main() {
  // Generate a random conspiracy theory
  char *conspiracy_theory = generate_conspiracy_theory();

  // Print the conspiracy theory
  printf("%s\n", conspiracy_theory);

  // Free the memory allocated for the conspiracy theory
  free(conspiracy_theory);

  return 0;
}