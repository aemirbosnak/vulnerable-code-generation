//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Generate a random number between min and max
int random_int(int min, int max) {
  return rand() % (max - min + 1) + min;
}

// Generate a random character from the given string
char random_char(const char *str) {
  return str[random_int(0, strlen(str) - 1)];
}

// Generate a random password of the given length
char *generate_password(int length) {
  char *password = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    // Choose a random character from the following categories:
    // - lowercase letters
    // - uppercase letters
    // - digits
    // - special characters
    int category = random_int(0, 3);
    switch (category) {
      case 0:
        password[i] = random_char("abcdefghijklmnopqrstuvwxyz");
        break;
      case 1:
        password[i] = random_char("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
        break;
      case 2:
        password[i] = random_char("0123456789");
        break;
      case 3:
        password[i] = random_char("!@#$%^&*()-=_+?");
        break;
    }
  }
  password[length] = '\0';
  return password;
}

int main() {
  // Seed the random number generator with the current time
  srand(time(NULL));

  // Get the length of the password from the user
  int length;
  printf("How long should the password be? ");
  scanf("%d", &length);

  // Generate the password
  char *password = generate_password(length);

  // Print the password
  printf("Your password is: %s\n", password);

  // Free the memory allocated for the password
  free(password);

  return 0;
}