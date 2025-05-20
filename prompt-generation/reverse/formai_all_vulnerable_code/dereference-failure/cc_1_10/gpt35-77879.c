//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function Definitions
char *generate_password(int length);

// Main Function
int main(void) {
  printf("Welcome to the Secure Password Generator!\n\n");

  // Initialize random number generator
  srand(time(NULL));

  // Prompt user for desired password length
  int length;
  printf("How long would you like your password to be?");
  scanf("%d", &length);

  if (length < 8) {
    printf("Error: Password length must be at least 8 characters.\n");
    return 1; // Exit program with error code
  }

  // Generate password and display to user
  char *password = generate_password(length);
  printf("\nYour new password is: %s\n", password);

  // Free memory used by password
  free(password);

  return 0; // Exit program successfully
}

// Function to generate a password
char *generate_password(int length) {
  // Define character sets for password
  const char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
  const char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  const char numbers[] = "0123456789";
  const char symbols[] = "!@#$%^&*()_+-=[]{}|;':\",./<>?";

  // Calculate number of characters per character set
  int lowercase_count = length / 2;
  int uppercase_count = length / 4;
  int numbers_count = length / 4;
  int symbols_count = length - lowercase_count - uppercase_count - numbers_count;

  // Initialize password array and pointer
  char *password = (char *) malloc(sizeof(char) * (length + 1));
  char *ptr = password;

  // Add characters from each character set
  for (int i = 0; i < lowercase_count; i++) {
    *ptr++ = lowercase[rand() % (sizeof(lowercase) - 1)];
  }
  for (int i = 0; i < uppercase_count; i++) {
    *ptr++ = uppercase[rand() % (sizeof(uppercase) - 1)];
  }
  for (int i = 0; i < numbers_count; i++) {
    *ptr++ = numbers[rand() % (sizeof(numbers) - 1)];
  }
  for (int i = 0; i < symbols_count; i++) {
    *ptr++ = symbols[rand() % (sizeof(symbols) - 1)];
  }
  *ptr = '\0';

  // Shuffle characters in password array
  for (int i = length - 1; i > 0; i--) {
    int j = rand() % (i + 1);
    char temp = password[i];
    password[i] = password[j];
    password[j] = temp;
  }

  return password;
}