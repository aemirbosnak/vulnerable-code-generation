//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Strength assessment levels
enum strength { WEAK, FAIR, STRONG, EXCELLENT };

// Calculate password strength
enum strength checkStrength(char *password) {
  int len = strlen(password);
  int hasLower = 0, hasUpper = 0, hasDigit = 0, hasSpecial = 0;

  // Check for character types
  for (int i = 0; i < len; i++) {
    if (islower(password[i])) hasLower = 1;
    if (isupper(password[i])) hasUpper = 1;
    if (isdigit(password[i])) hasDigit = 1;
    if (!isalnum(password[i])) hasSpecial = 1;
  }

  // Determine strength based on character types and length
  if (len < 8) return WEAK;
  else if (!hasLower || !hasUpper || !hasDigit || !hasSpecial) return FAIR;
  else if (len < 12) return STRONG;
  else return EXCELLENT;
}

// Get password from user
char *getPassword() {
  char *password = (char *)malloc(100);
  printf("My dearest, enter your secret password: ");
  scanf("%s", password);
  return password;
}

// Print strength assessment in a romantic style
void printStrength(enum strength strength) {
  switch (strength) {
    case WEAK:
      printf("Oh honey, your password is as weak as a flower that wilts in the morning sun. Please fortify it with my love.");
      break;
    case FAIR:
      printf("My darling, your password is like a budding rose, fair and promising, but still in need of nurturing. Let me strengthen it with my kisses.");
      break;
    case STRONG:
      printf("My beloved, your password is as strong as our bond, unbreakable and eternal. It fills my heart with joy and sets my soul aflutter.");
      break;
    case EXCELLENT:
      printf("My precious, your password is a masterpiece, a sonnet that sings of our unyielding love. It makes me weak in the knees and fills my heart with adoration.");
      break;
  }
}

int main() {
  char *password = getPassword();
  enum strength strength = checkStrength(password);
  printStrength(strength);
  free(password);
  return 0;
}