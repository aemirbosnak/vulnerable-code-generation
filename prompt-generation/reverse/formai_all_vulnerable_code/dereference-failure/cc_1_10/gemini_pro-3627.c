//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to reverse a string
char *reverse(char *str)
{
  int len = strlen(str);
  char *rev = malloc(len + 1);
  for (int i = 0; i < len; i++)
    rev[len - i - 1] = str[i];
  rev[len] = '\0';
  return rev;
}

// function to count the number of occurrences of a character in a string
int count_char(char *str, char c)
{
  int count = 0;
  for (int i = 0; str[i] != '\0'; i++)
    if (str[i] == c)
      count++;
  return count;
}

// function to remove all occurrences of a character from a string
char *remove_char(char *str, char c)
{
  int len = strlen(str);
  char *newstr = malloc(len + 1);
  int j = 0;
  for (int i = 0; i < len; i++)
    if (str[i] != c)
      newstr[j++] = str[i];
  newstr[j] = '\0';
  return newstr;
}

// function to replace all occurrences of a character with another character in a string
char *replace_char(char *str, char c1, char c2)
{
  int len = strlen(str);
  char *newstr = malloc(len + 1);
  for (int i = 0; i < len; i++)
    if (str[i] == c1)
      newstr[i] = c2;
    else
      newstr[i] = str[i];
  newstr[len] = '\0';
  return newstr;
}

// function to convert a string to uppercase
char *to_upper(char *str)
{
  int len = strlen(str);
  char *upper = malloc(len + 1);
  for (int i = 0; i < len; i++)
    upper[i] = toupper(str[i]);
  upper[len] = '\0';
  return upper;
}

// function to convert a string to lowercase
char *to_lower(char *str)
{
  int len = strlen(str);
  char *lower = malloc(len + 1);
  for (int i = 0; i < len; i++)
    lower[i] = tolower(str[i]);
  lower[len] = '\0';
  return lower;
}

// function to remove all whitespace from a string
char *remove_whitespace(char *str)
{
  int len = strlen(str);
  char *newstr = malloc(len + 1);
  int j = 0;
  for (int i = 0; i < len; i++)
    if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
      newstr[j++] = str[i];
  newstr[j] = '\0';
  return newstr;
}

// function to replace all whitespace with a single space
char *replace_whitespace(char *str)
{
  int len = strlen(str);
  char *newstr = malloc(len + 1);
  int j = 0;
  for (int i = 0; i < len; i++)
    if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
      newstr[j++] = ' ';
    else
      newstr[j++] = str[i];
  newstr[j] = '\0';
  return newstr;
}

// function to split a string into an array of strings
char **split(char *str, char delim)
{
  int len = strlen(str);
  int count = 0;
  for (int i = 0; i < len; i++)
    if (str[i] == delim)
      count++;
  char **arr = malloc((count + 1) * sizeof(char *));
  int start = 0;
  int end = 0;
  for (int i = 0; i < count + 1; i++)
  {
    while (str[end] != delim && end < len)
      end++;
    arr[i] = malloc(end - start + 1);
    strncpy(arr[i], str + start, end - start);
    arr[i][end - start] = '\0';
    start = end + 1;
    end++;
  }
  return arr;
}

// function to join an array of strings into a single string
char *join(char **arr, int len, char delim)
{
  int total_len = 0;
  for (int i = 0; i < len; i++)
    total_len += strlen(arr[i]) + 1;
  char *str = malloc(total_len);
  int j = 0;
  for (int i = 0; i < len; i++)
  {
    strcpy(str + j, arr[i]);
    j += strlen(arr[i]);
    str[j++] = delim;
  }
  str[j - 1] = '\0';
  return str;
}

// function to test the text processing functions
void test()
{
  char *str = "Hello World!";

  printf("Original string: %s\n", str);
  printf("Reversed string: %s\n", reverse(str));
  printf("Number of occurrences of 'l': %d\n", count_char(str, 'l'));
  printf("String without 'l': %s\n", remove_char(str, 'l'));
  printf("String with 'l' replaced with 'x': %s\n", replace_char(str, 'l', 'x'));
  printf("Uppercase string: %s\n", to_upper(str));
  printf("Lowercase string: %s\n", to_lower(str));
  printf("String without whitespace: %s\n", remove_whitespace(str));
  printf("String with whitespace replaced with a single space: %s\n", replace_whitespace(str));

  char **arr = split(str, ' ');
  for (int i = 0; arr[i] != NULL; i++)
    printf("Split string: %s\n", arr[i]);

  char *newstr = join(arr, 2, '-');
  printf("Joined string: %s\n", newstr);

  free(arr);
  free(newstr);
}

int main()
{
  test();
  return 0;
}