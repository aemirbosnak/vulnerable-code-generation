//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20 // Maximum character length for password
#define NUM_SPECIAL_CHARS 6 // Number of special characters to include

// Function prototypes
char generateRandomChar(char, char);
char* generateRandomPassword();
char* generateRandomSubstring(char*, int);
void shuffleArray(char*, int);

int main() {
  char* password = generateRandomPassword();
  
  printf("Your new password is: %s\n", password);
  
  free(password); // Free memory allocation
  
  return 0;
}

// Generates a random character within the ASCII range specified by the parameters
char generateRandomChar(char lower, char upper) {
  return (rand() % (upper - lower + 1)) + lower;
}

// Generates a random password
char* generateRandomPassword() {
  // Seed random number generator
  srand(time(NULL));
  
  // Initialize password array
  char* password = malloc(sizeof(char) * MAX_PASSWORD_LENGTH + 1);
  password[MAX_PASSWORD_LENGTH] = '\0';
  
  // Generate random substring of length 6
  char* substring = generateRandomSubstring("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789", NUM_SPECIAL_CHARS);
  
  // Generate random password using the following structure:
  // - 2 uppercase letters
  // - 2 lowercase letters
  // - 2 digits
  // - 6 special characters, randomly arranged
  password[0] = generateRandomChar('A', 'Z');
  password[1] = generateRandomChar('A', 'Z');
  password[2] = generateRandomChar('a', 'z');
  password[3] = generateRandomChar('a', 'z');
  password[4] = generateRandomChar('0', '9');
  password[5] = generateRandomChar('0', '9');
  for (int i = 6; i < MAX_PASSWORD_LENGTH; i++) {
    password[i] = substring[i - 6];
  }
  
  // Shuffle the array so that the special characters are in random positions
  shuffleArray(password + 6, MAX_PASSWORD_LENGTH - 6);
  
  free(substring); // Free memory allocation
  
  return password;
}

// Generates a random substring of a given length from a given string
char* generateRandomSubstring(char* str, int length) {
  // Initialize substring array
  char* substring = malloc(sizeof(char) * length + 1);
  substring[length] = '\0';
  
  // Generate random substring
  for (int i = 0; i < length; i++) {
    substring[i] = str[rand() % strlen(str)];
  }
  
  return substring;
}

// Shuffles an array using the Fisher-Yates shuffle algorithm
void shuffleArray(char* arr, int length) {
  for (int i = length - 1; i > 0; i--) {
    int j = rand() % (i + 1);
    char temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
}