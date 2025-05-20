//Gemma-7B DATASET v1.0 Category: String manipulation ; Style: thoughtful
#include <stdio.h>
#include <string.h>

void rotate_string(char *str, int n) {
  int len = strlen(str);
  char *temp = malloc(len);
  memcpy(temp, str, len);
  str = realloc(str, len + 1);
  memset(str, 0, len);
  memcpy(str, temp, len);
  free(temp);
}

int is_palindrome(char *str) {
  int i = 0;
  int len = strlen(str);
  for (i = 0; i < len / 2; i++) {
    if (str[i] != str[len - 1 - i]) {
      return 0;
    }
  }
  return 1;
}

void compress_string(char *str) {
  int i = 0;
  int len = strlen(str);
  char *comp = malloc(len);
  int count = 1;
  comp[0] = str[0];
  for (i = 1; i < len; i++) {
    if (str[i] == str[i - 1]) {
      count++;
    } else {
      comp[count++] = str[i];
    }
  }
  comp[count] = '\0';
  strcpy(str, comp);
  free(comp);
}

int main() {
  char str[] = "abcba";
  rotate_string(str, 2);
  printf("%s\n", str);

  char str2[] = "abcba";
  if (is_palindrome(str2)) {
    printf("%s is a palindrome\n", str2);
  }

  char str3[] = "abcabc";
  compress_string(str3);
  printf("%s\n", str3);

  return 0;
}