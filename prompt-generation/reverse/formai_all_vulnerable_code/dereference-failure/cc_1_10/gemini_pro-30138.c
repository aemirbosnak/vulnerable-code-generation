//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Welcome to the post-apocalyptic string manipulator!

// Define the maximum string length
#define MAX_STRING 1024

// Some post-apocalyptic functions
char *ruin(char *str);
char *decay(char *str);
char *mutate(char *str);
char *rebuild(char *str);

// Main function
int main() {
  // Declare variables
  char str[MAX_STRING];
  int choice;

  // Get the input string
  printf("Enter a string: ");
  fgets(str, MAX_STRING, stdin);

  // Display the menu
  printf("Choose an operation:\n");
  printf("1. Ruin\n");
  printf("2. Decay\n");
  printf("3. Mutate\n");
  printf("4. Rebuild\n");
  printf("5. Exit\n");

  // Get the user's choice
  scanf("%d", &choice);

  // Perform the selected operation
  switch (choice) {
    case 1:
      printf("Ruined string: %s\n", ruin(str));
      break;
    case 2:
      printf("Decayed string: %s\n", decay(str));
      break;
    case 3:
      printf("Mutated string: %s\n", mutate(str));
      break;
    case 4:
      printf("Rebuilt string: %s\n", rebuild(str));
      break;
    case 5:
      exit(0);
    default:
      printf("Invalid choice!\n");
  }

  return 0;
}

// Ruin the string
char *ruin(char *str) {
  int len = strlen(str);
  for (int i = 0; i < len; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      str[i] = str[i] - 32;
    } else if (str[i] >= 'A' && str[i] <= 'Z') {
      str[i] = str[i] + 32;
    }
  }
  return str;
}

// Decay the string
char *decay(char *str) {
  int len = strlen(str);
  for (int i = 0; i < len; i++) {
    if (rand() % 2 == 0) {
      str[i] = '\0';
    }
  }
  return str;
}

// Mutate the string
char *mutate(char *str) {
  int len = strlen(str);
  for (int i = 0; i < len; i++) {
    if (rand() % 10 == 0) {
      str[i] = rand() % 26 + 'a';
    }
  }
  return str;
}

// Rebuild the string
char *rebuild(char *str) {
  int len = strlen(str);
  char *new_str = malloc(len + 1);
  int j = 0;
  for (int i = 0; i < len; i++) {
    if (str[i] != '\0') {
      new_str[j++] = str[i];
    }
  }
  new_str[j] = '\0';
  return new_str;
}