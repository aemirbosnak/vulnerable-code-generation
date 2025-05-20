//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 16

char generateChar()
{
  int charType = rand() % 4; // generates random number between 0 and 3
  char c;
  
  switch (charType)
  {
    case 0: // Generate uppercase letter
      c = 'A' + (rand() % 26);
      break;
    case 1: // Generate lowercase letter
      c = 'a' + (rand() % 26);
      break;
    case 2: // Generate digit
      c = '0' + (rand() % 10);
      break;
    case 3: // Generate special character
      c = "!@#$%^&*()_+-=[]{}|;':\",./<>?"[(rand() % 29)];
      break;
  }
  
  return c;
}

char* generatePassword()
{
  int passwordLength = MIN_PASSWORD_LENGTH + (rand() % (MAX_PASSWORD_LENGTH - MIN_PASSWORD_LENGTH + 1));
  
  char* password = (char*)malloc((passwordLength + 1) * sizeof(char));
  int i;
  
  for (i = 0; i < passwordLength; i++)
  {
    password[i] = generateChar();
  }
  
  password[passwordLength] = '\0';
  
  return password;
}

int isPasswordSecure(char* password)
{
  int hasUpper = 0;
  int hasLower = 0;
  int hasDigit = 0;
  int hasSpecial = 0;
  
  int i;
  for (i = 0; password[i] != '\0'; i++)
  {
    if (isupper(password[i])) hasUpper = 1;
    if (islower(password[i])) hasLower = 1;
    if (isdigit(password[i])) hasDigit = 1;
    if (!isalnum(password[i])) hasSpecial = 1;
  }
  
  if (hasUpper && hasLower && hasDigit && hasSpecial) return 1;
  
  return 0;
}

int main()
{
  srand(time(NULL));
  
  char* password = generatePassword();
  
  while (!isPasswordSecure(password))
  {
    free(password);
    password = generatePassword();
  }
  
  printf("Secure password generated: %s\n", password);
  
  free(password);
  
  return 0;
}