//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the character set for the password
char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()";

// Get the length of the password from the user
int get_password_length() {
  int length;
  printf("Enter the desired password length: ");
  scanf("%d", &length);
  return length;
}

// Generate a random password
char *generate_password(int length) {
  char *password = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    int random_index = rand() % (sizeof(charset) - 1);
    password[i] = charset[random_index];
  }
  password[length] = '\0';
  return password;
}

// Print the generated password to the console
void print_password(char *password) {
  printf("Your generated password is: %s\n", password);
}

// Free the memory allocated for the password
void free_password(char *password) {
  free(password);
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Get the password length from the user
  int length = get_password_length();

  // Generate a random password
  char *password = generate_password(length);

  // Print the generated password to the console
  print_password(password);

  // Free the memory allocated for the password
  free_password(password);

  return 0;
}