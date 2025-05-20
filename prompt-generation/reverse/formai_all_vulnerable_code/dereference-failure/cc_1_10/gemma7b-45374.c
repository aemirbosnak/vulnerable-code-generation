//Gemma-7B DATASET v1.0 Category: Firewall ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
  char str[1024];
  int i, j, k, n = 0;

  printf("Enter a string: ");
  fgets(str, 1024, stdin);

  printf("Number of words in the string: ");
  n = countWords(str);

  printf("Number of vowels in the string: ");
  k = countVowels(str);

  printf("Number of consonants in the string: ");
  j = countConsonants(str);

  printf("Number of digits in the string: ");
  i = countDigits(str);

  printf("\nThe string is: %s", str);
  printf("\nNumber of words: %d", n);
  printf("\nNumber of vowels: %d", k);
  printf("\nNumber of consonants: %d", j);
  printf("\nNumber of digits: %d", i);
}

int countWords(char *str)
{
  int i = 0, n = 0;

  while (str[i] != '\0')
  {
    if (str[i] == ' ' && str[i - 1] != ' ')
    {
      n++;
    }
    i++;
  }

  return n;
}

int countVowels(char *str)
{
  int i = 0, k = 0;

  for (i = 0; str[i] != '\0'; i++)
  {
    if (str[i] >= 'a' && str[i] <= 'z')
    {
      k++;
    }
  }

  return k;
}

int countConsonants(char *str)
{
  int i = 0, j = 0;

  for (i = 0; str[i] != '\0'; i++)
  {
    if (str[i] >= 'a' && str[i] <= 'z')
    {
      j++;
    }
  }

  return j;
}

int countDigits(char *str)
{
  int i = 0, d = 0;

  for (i = 0; str[i] != '\0'; i++)
  {
    if (str[i] >= '0' && str[i] <= '9')
    {
      d++;
    }
  }

  return d;
}