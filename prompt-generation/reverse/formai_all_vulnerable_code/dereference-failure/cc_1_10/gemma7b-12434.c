//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: complete
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_PASS_LENGTH 256

typedef struct Password {
  char *pass;
  int strength;
} Password;

int calculateStrength(char *pass) {
  int strength = 0;
  int i = 0;

  for (; pass[i] != '\0'; i++) {
    if (isupper(pass[i])) strength++;
    else if (islower(pass[i])) strength++;
    else if (isdigit(pass[i])) strength++;
    else if (ispunct(pass[i])) strength++;
  }

  return strength;
}

Password *createPassword(char *pass) {
  Password *pw = malloc(sizeof(Password));
  pw->pass = strdup(pass);
  pw->strength = calculateStrength(pass);

  return pw;
}

int main() {
  char pass[MAX_PASS_LENGTH];

  printf("Enter your password: ");
  scanf("%s", pass);

  Password *pw = createPassword(pass);

  switch (pw->strength) {
    case 0:
      printf("Your password is very weak.\n");
      break;
    case 1:
      printf("Your password is weak.\n");
      break;
    case 2:
      printf("Your password is moderate.\n");
      break;
    case 3:
      printf("Your password is strong.\n");
      break;
    case 4:
      printf("Your password is very strong.\n");
      break;
  }

  free(pw);

  return 0;
}