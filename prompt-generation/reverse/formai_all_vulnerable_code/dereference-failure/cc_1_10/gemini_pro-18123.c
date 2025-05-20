//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Exciting variable names!
char const * const ALPHABET = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
char const * const NUMBERS = "0123456789";
char const * const SYMBOLS = "!@#$%^&*_-=+";

// Prepare for randomness!
void chaos_monkey(char *str, size_t len)
{
  int i, j;
  for (i = 0; i < len; i++)
  {
    j = rand() % len;
    char c = str[i];
    str[i] = str[j];
    str[j] = c;
  }
}

// Generate a random password!
char *generate_password(size_t len)
{
  // Prepare the password vessel.
  char *password = malloc(len + 1);
  password[len] = '\0';

  // Summon the power of randomness!
  srand(time(NULL));

  // Mix and match characters, numbers, and symbols like a mad scientist!
  int i, char_type;
  for (i = 0; i < len; i++)
  {
    char_type = rand() % 3;
    switch (char_type)
    {
    case 0:
      password[i] = ALPHABET[rand() % strlen(ALPHABET)];
      break;
    case 1:
      password[i] = NUMBERS[rand() % strlen(NUMBERS)];
      break;
    case 2:
      password[i] = SYMBOLS[rand() % strlen(SYMBOLS)];
      break;
    }
  }

  // Invoke the chaos monkey to scramble the password like a secret agent!
  chaos_monkey(password, len);

  return password;
}

// Let's get this party started!
int main(void)
{
  // Get the length of the password you desire, oh mighty user!
  printf("Dearest user, how long should your password be? ");
  int len;
  scanf("%d", &len);

  // Behold, your password!
  char *password = generate_password(len);

  // Share the magic!
  printf("Behold, your password, as strong as a titanium vault: %s\n", password);

  // Free the password from its temporary memory abode.
  free(password);

  return 0;
}