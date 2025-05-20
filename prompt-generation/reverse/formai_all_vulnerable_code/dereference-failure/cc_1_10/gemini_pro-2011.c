//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *str;
  int len;
} String;

String *newString(const char *str) {
  String *s = (String *)malloc(sizeof(String));
  s->len = strlen(str);
  s->str = (char *)malloc(s->len + 1);
  strcpy(s->str, str);
  return s;
}

void freeString(String *s) {
  free(s->str);
  free(s);
}

String *str_cat(String *s1, String *s2) {
  String *s3 = (String *)malloc(sizeof(String));
  s3->len = s1->len + s2->len;
  s3->str = (char *)malloc(s3->len + 1);
  strcpy(s3->str, s1->str);
  strcat(s3->str, s2->str);
  return s3;
}

String *str_substr(String *s, int start, int end) {
  int len = end - start + 1;
  String *s2 = (String *)malloc(sizeof(String));
  s2->len = len;
  s2->str = (char *)malloc(len + 1);
  strncpy(s2->str, s->str + start, len);
  s2->str[len] = '\0';
  return s2;
}

int main() {
  String *s1 = newString("Hello");
  String *s2 = newString("World");
  String *s3 = str_cat(s1, s2);
  printf("%s\n", s3->str);
  String *s4 = str_substr(s3, 0, 4);
  printf("%s\n", s4->str);
  freeString(s1);
  freeString(s2);
  freeString(s3);
  freeString(s4);
  return 0;
}