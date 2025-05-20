//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Generate a random string of length n
char *generate_string(int n) {
  char *str = malloc(n + 1);
  for (int i = 0; i < n; i++) {
    str[i] = 'a' + rand() % 26;
  }
  str[n] = '\0';
  return str;
}

// Compare two strings and return the number of errors
int compare_strings(char *str1, char *str2) {
  int errors = 0;
  for (int i = 0; i < strlen(str1); i++) {
    if (str1[i] != str2[i]) {
      errors++;
    }
  }
  return errors;
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Get the user's input
  printf("Enter your name: ");
  char name[256];
  scanf("%s", name);

  // Generate a random string
  int n = 100;
  char *str = generate_string(n);

  // Display the string to the user
  printf("Type the following string as quickly and accurately as possible:\n");
  printf("%s\n", str);

  // Start the timer
  clock_t start = clock();

  // Get the user's input
  char input[256];
  scanf("%s", input);

  // Stop the timer
  clock_t end = clock();

  // Calculate the time taken
  double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

  // Compare the user's input to the original string
  int errors = compare_strings(str, input);

  // Calculate the typing speed
  double speed = (double)n / time_taken;

  // Display the results
  printf("Name: %s\n", name);
  printf("Typing speed: %.2f words per minute\n", speed);
  printf("Errors: %d\n", errors);

  // Free the allocated memory
  free(str);

  return 0;
}