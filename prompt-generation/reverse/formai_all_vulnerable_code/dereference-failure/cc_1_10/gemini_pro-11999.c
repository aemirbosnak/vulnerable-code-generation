//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

// reverse a string
char *reverse(char *str) {
  char *p1, *p2;
  if (!str || !*str)
    return str;
  for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2) {
    *p1 ^= *p2;
    *p2 ^= *p1;
    *p1 ^= *p2;
  }
  return str;
}

// concatenate two strings
char *concat(char *str1, char *str2) {
  char *newstr;
  if (!str1 || !*str1)
    return str2;
  if (!str2 || !*str2)
    return str1;
  newstr = malloc(strlen(str1) + strlen(str2) + 1);
  if (!newstr)
    return NULL;
  strcpy(newstr, str1);
  strcat(newstr, str2);
  return newstr;
}

// find the longest common substring
char *lcs(char *str1, char *str2) {
  int len1, len2, i, j, maxlen = 0, start = 0;
  if (!str1 || !*str1 || !str2 || !*str2)
    return NULL;
  len1 = strlen(str1);
  len2 = strlen(str2);
  for (i = 0; i < len1; ++i) {
    for (j = 0; j < len2; ++j) {
      while (str1[i + j] == str2[j] && i + j < len1 && j < len2)
        ++j;
      if (j - start > maxlen) {
        maxlen = j - start;
        start = i;
      }
    }
  }
  if (maxlen == 0)
    return NULL;
  char *newstr = malloc(maxlen + 1);
  if (!newstr)
    return NULL;
  strncpy(newstr, str1 + start, maxlen);
  newstr[maxlen] = '\0';
  return newstr;
}

// generate a random string of length n
char *random_string(int n) {
  char *str;
  int i;
  if (n <= 0)
    return NULL;
  str = malloc(n + 1);
  if (!str)
    return NULL;
  for (i = 0; i < n; ++i)
    str[i] = (rand() % 26) + 'a';
  str[n] = '\0';
  return str;
}

int main() {
  char *str1, *str2, *str3;
  int n;

  // generate two random strings
  str1 = random_string(10);
  str2 = random_string(15);

  // print the original strings
  printf("String 1: %s\n", str1);
  printf("String 2: %s\n", str2);

  // reverse the first string
  str3 = reverse(str1);
  printf("Reversed String 1: %s\n", str3);
  free(str3);

  // concatenate the two strings
  str3 = concat(str1, str2);
  printf("Concatenated String: %s\n", str3);
  free(str3);

  // find the longest common substring
  str3 = lcs(str1, str2);
  if (!str3)
    printf("No common substring found\n");
  else
    printf("Longest Common Substring: %s\n", str3);
  free(str3);

  // generate a random string of length 20
  n = 20;
  str3 = random_string(n);
  printf("Random String of Length %d: %s\n", n, str3);
  free(str3);

  // free the allocated memory
  free(str1);
  free(str2);

  return 0;
}