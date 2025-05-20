//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to reverse a string
char *reverse(char *str)
{
  int len = strlen(str);
  char *rev = malloc(len + 1);
  for (int i = 0; i < len; i++)
  {
    rev[i] = str[len - i - 1];
  }
  rev[len] = '\0';
  return rev;
}

// Function to check if a string is a palindrome
int is_palindrome(char *str)
{
  int len = strlen(str);
  for (int i = 0; i < len / 2; i++)
  {
    if (str[i] != str[len - i - 1])
    {
      return 0;
    }
  }
  return 1;
}

// Function to find the longest palindrome in a string
char *longest_palindrome(char *str)
{
  int len = strlen(str);
  int max_len = 0;
  char *max_pal = NULL;
  for (int i = 0; i < len; i++)
  {
    for (int j = i + 1; j < len; j++)
    {
      int sub_len = j - i;
      if (sub_len > max_len && is_palindrome(str + i))
      {
        max_len = sub_len;
        max_pal = str + i;
      }
    }
  }
  return max_pal;
}

// Driver code
int main()
{
  char *str = "racecar";
  char *rev_str = reverse(str);
  printf("Original string: %s\n", str);
  printf("Reversed string: %s\n", rev_str);
  if (is_palindrome(str))
  {
    printf("The string is a palindrome.\n");
  }
  else
  {
    printf("The string is not a palindrome.\n");
  }
  char *max_pal = longest_palindrome(str);
  printf("The longest palindrome in the string is: %s\n", max_pal);
  return 0;
}