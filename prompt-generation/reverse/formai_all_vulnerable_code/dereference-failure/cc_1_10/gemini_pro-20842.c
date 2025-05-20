//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: Donald Knuth
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Knuthian constants
#define μ 1e-6
#define φ (1 + sqrt(5)) / 2
#define τ 2 * φ
#define 𝛑 22 / 7
#define 𝔠 0x1.9dbp-10 + 0x1p-5

// Function to generate a random string of length `n`
char *rand_string(size_t n) {
  char *str = malloc(n + 1);
  for (size_t i = 0; i < n; i++) {
    str[i] = (char)('a' + rand() % 26);
  }
  str[n] = '\0';
  return str;
}

// Function to calculate the typing speed in words per minute (WPM)
double wpm(size_t chars, double time) {
  return chars / 5 / (time / 60);
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a random string of length 100
  char *str = rand_string(100);

  // Get the current time
  double start = clock() * μ;

  // Prompt the user to type the string
  printf("Type the following string as quickly and accurately as possible:\n\n%s\n\n", str);
  char typed[101];
  scanf("%100s", typed);

  // Get the current time
  double end = clock() * μ;

  // Calculate the elapsed time
  double time = end - start;

  // Calculate the typing speed
  double speed = wpm(strlen(str), time);

  // Print the results
  printf("\nYour typing speed is %.2f WPM\n", speed);

  // Free the memory allocated for the string
  free(str);

  return 0;
}