//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *happy_copy(const char *str) {
  char *copy = malloc(strlen(str) + 1);
  if (!copy) return NULL;
  strcpy(copy, str);
  return copy;
}

char *happy_concat(const char *str1, const char *str2) {
  char *concat = malloc(strlen(str1) + strlen(str2) + 1);
  if (!concat) return NULL;
  strcpy(concat, str1);
  strcat(concat, str2);
  return concat;
}

int happy_compare(const char *str1, const char *str2) {
  return strcmp(str1, str2);
}

char *happy_to_upper(char *str) {
  for (char *c = str; *c; c++) *c = toupper(*c);
  return str;
}

char *happy_to_lower(char *str) {
  for (char *c = str; *c; c++) *c = tolower(*c);
  return str;
}

char *happy_trim(char *str) {
  while (*str && isspace(*str)) str++;
  char *end = str + strlen(str) - 1;
  while (end >= str && isspace(*end)) end--;
  end[1] = '\0';
  return str;
}

char *happy_replace(char *str, char from, char to) {
  for (char *c = str; *c; c++)
    if (*c == from) *c = to;
  return str;
}

int main() {
  char *str = "Hello, world!";
  char *copy = happy_copy(str);
  char *concat = happy_concat(str, "!");
  int compare = happy_compare(str, "Hello, world!");
  char *upper = happy_to_upper(copy);
  char *lower = happy_to_lower(concat);
  char *trim = happy_trim(lower);
  char *replace = happy_replace(trim, '!', '?');
  printf("%s\n", copy);
  printf("%s\n", concat);
  printf("%d\n", compare);
  printf("%s\n", upper);
  printf("%s\n", lower);
  printf("%s\n", trim);
  printf("%s\n", replace);
  free(copy);
  free(concat);
  return 0;
}