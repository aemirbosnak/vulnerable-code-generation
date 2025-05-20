//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Welcome message and instructions
void welcome() {
  printf("\n========================================================================\n");
  printf("Welcome to the Post-Apocalyptic Password Generator, survivor!\n");
  printf("This generator will help you create strong and unique passwords in a world gone mad.\n");
  printf("\nInstructions:\n");
  printf("1. Enter the desired password length (minimum 8 characters).\n");
  printf("2. Choose from the following character sets:\n");
  printf("   - Lowercase letters (a-z)\n");
  printf("   - Uppercase letters (A-Z)\n");
  printf("   - Numbers (0-9)\n");
  printf("   - Special characters (!@#$%^&*) (optional)\n");
  printf("3. Input your choices by entering the corresponding numbers (e.g., 1234).\n");
  printf("\nReady to generate your password? Let's get started!\n");
  printf("========================================================================\n\n");
}

// Get password length
int get_password_length() {
  int length;
  printf("Enter the desired password length (minimum 8 characters): ");
  scanf("%d", &length);
  while (length < 8) {
    printf("Invalid length. Please enter a length of at least 8 characters: ");
    scanf("%d", &length);
  }
  return length;
}

// Get character set choices
int get_character_set_choices() {
  int choices;
  printf("Choose from the following character sets:\n");
  printf("1. Lowercase letters (a-z)\n");
  printf("2. Uppercase letters (A-Z)\n");
  printf("3. Numbers (0-9)\n");
  printf("4. Special characters (!@#$%^&*) (optional)\n");
  printf("Enter your choices by entering the corresponding numbers (e.g., 1234): ");
  scanf("%d", &choices);
  return choices;
}

// Generate random password
char* generate_password(int length, int choices) {
  char* password = malloc(length + 1);
  srand(time(NULL));

  // Create a character pool based on the user's choices
  char pool[62];
  int pool_index = 0;
  if (choices & 1) {
    for (int i = 97; i <= 122; i++) {
      pool[pool_index++] = i;
    }
  }
  if (choices & 2) {
    for (int i = 65; i <= 90; i++) {
      pool[pool_index++] = i;
    }
  }
  if (choices & 4) {
    for (int i = 48; i <= 57; i++) {
      pool[pool_index++] = i;
    }
  }
  if (choices & 8) {
    char special_chars[] = "!@#$%^&*";
    for (int i = 0; i < strlen(special_chars); i++) {
      pool[pool_index++] = special_chars[i];
    }
  }

  // Generate the password
  for (int i = 0; i < length; i++) {
    int random_index = rand() % pool_index;
    password[i] = pool[random_index];
  }
  password[length] = '\0';

  return password;
}

// Main function
int main() {
  // Display welcome message
  welcome();

  // Get password length
  int length = get_password_length();

  // Get character set choices
  int choices = get_character_set_choices();

  // Generate and display password
  char* password = generate_password(length, choices);
  printf("\nYour post-apocalyptic password: %s\n", password);

  // Cleanup
  free(password);

  return 0;
}