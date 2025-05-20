//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Generate a random string of length n
char *generate_random_string(int n) {
  char *str = malloc(n + 1);
  for (int i = 0; i < n; i++) {
    // Generate a random character between 'a' and 'z'
    str[i] = (char)('a' + rand() % 26);
  }
  str[n] = '\0';
  return str;
}

// Generate a random number between min and max
int generate_random_number(int min, int max) {
  return rand() % (max - min + 1) + min;
}

// Generate a secure password of length n
char *generate_secure_password(int n) {
  // Generate a random string of length n
  char *str = generate_random_string(n);

  // Add a random number to the beginning of the string
  int num = generate_random_number(100000, 999999);
  char num_str[6];
  sprintf(num_str, "%d", num);
  strcat(str, num_str);

  // Add a random special character to the end of the string
  char special_chars[] = "!@#$%^&*()";
  char special_char = special_chars[rand() % strlen(special_chars)];
  strcat(str, &special_char);

  return str;
}

int main() {
  // Generate a secure password of length 20
  char *password = generate_secure_password(20);

  // Print the password
  printf("Generated password: %s\n", password);

  // Free the memory allocated for the password
  free(password);

  return 0;
}