//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main() {
  char *password;
  int strength;

  printf("Enter your password: ");
  scanf("%s", password);

  strength = check_strength(password);

  switch (strength) {
    case 0:
      printf("Your password is too weak!\n");
      break;
    case 1:
      printf("Your password is weak!\n");
      break;
    case 2:
      printf("Your password is okay!\n");
      break;
    case 3:
      printf("Your password is strong!\n");
      break;
    case 4:
      printf("Your password is very strong!\n");
      break;
  }

  return 0;
}

int check_strength(char *password) {
  int strength = 0;

  if (strlen(password) < 8) {
    strength++;
  }

  if (!strchr(password, '!') && !strchr(password, '@') && !strchr(password, '#') && !strchr(password, '$') && !strchr(password, '%') && !strchr(password, '^') && !strchr(password, '&') && !strchr(password, '*')) {
    strength++;
  }

  if (!strchr(password, 'a') && !strchr(password, 'b') && !strchr(password, 'c') && !strchr(password, 'd') && !strchr(password, 'e') && !strchr(password, 'f') && !strchr(password, 'g') && !strchr(password, 'h') && !strchr(password, 'i') && !strchr(password, 'j') && !strchr(password, 'k') && !strchr(password, 'l') && !strchr(password, 'm') && !strchr(password, 'n') && !strchr(password, 'o') && !strchr(password, 'p') && !strchr(password, 'q') && !strchr(password, 'r') && !strchr(password, 's') && !strchr(password, 't') && !strchr(password, 'u') && !strchr(password, 'v') && !strchr(password, 'w') && !strchr(password, 'x') && !strchr(password, 'y') && !strchr(password, 'z')) {
    strength++;
  }

  if (!strchr(password, 'A') && !strchr(password, 'B') && !strchr(password, 'C') && !strchr(password, 'D') && !strchr(password, 'E') && !strchr(password, 'F') && !strchr(password, 'G') && !strchr(password, 'H') && !strchr(password, 'I') && !strchr(password, 'J') && !strchr(password, 'K') && !strchr(password, 'L') && !strchr(password, 'M') && !strchr(password, 'N') && !strchr(password, 'O') && !strchr(password, 'P') && !strchr(password, 'Q') && !strchr(password, 'R') && !strchr(password, 'S') && !strchr(password, 'T') && !strchr(password, 'U') && !strchr(password, 'V') && !strchr(password, 'W') && !strchr(password, 'X') && !strchr(password, 'Y') && !strchr(password, 'Z')) {
    strength++;
  }

  if (!strchr(password, '0') && !strchr(password, '1') && !strchr(password, '2') && !strchr(password, '3') && !strchr(password, '4') && !strchr(password, '5') && !strchr(password, '6') && !strchr(password, '7') && !strchr(password, '8') && !strchr(password, '9')) {
    strength++;
  }

  return strength;
}