//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Character sets
char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char numbers[] = "0123456789";
char symbols[] = "!@#$%^&*()";

// Function to generate a random character from a given set
char random_char(char *set) {
  int index = rand() % strlen(set);
  return set[index];
}

// Function to generate a secure password
char *generate_password(int length, int complexity) {
  // Allocate memory for the password
  char *password = (char *)malloc(length + 1);

  // Initialize the password with random characters
  for (int i = 0; i < length; i++) {
    password[i] = random_char(lowercase);
  }

  // Increase complexity by adding uppercase, numbers, and symbols
  for (int i = 0; i < complexity; i++) {
    int index = rand() % length;
    switch (rand() % 4) {
      case 0:
        password[index] = random_char(uppercase);
        break;
      case 1:
        password[index] = random_char(numbers);
        break;
      case 2:
        password[index] = random_char(symbols);
        break;
    }
  }

  // Terminate the password with a null character
  password[length] = '\0';

  // Return the password
  return password;
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Get the desired password length and complexity from the user
  int length, complexity;
  printf("Enter the desired password length: ");
  scanf("%d", &length);
  printf("Enter the desired password complexity (0-3): ");
  scanf("%d", &complexity);

  // Generate the password
  char *password = generate_password(length, complexity);

  // Print the password
  printf("Your secure password is: %s\n", password);

  // Free the memory allocated for the password
  free(password);

  return 0;
}