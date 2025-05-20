//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *data;
  int len;
} string_t;

string_t *string_new(char *data) {
  string_t *s = malloc(sizeof(string_t));
  s->data = data;
  s->len = strlen(data);
  return s;
}

void string_free(string_t *s) {
  free(s->data);
  free(s);
}

string_t *string_concat(string_t *a, string_t *b) {
  char *data = malloc(a->len + b->len + 1);
  strcpy(data, a->data);
  strcpy(data + a->len, b->data);
  return string_new(data);
}

string_t *string_replace(string_t *s, char *old, char *new) {
  int old_len = strlen(old);
  int new_len = strlen(new);
  char *data = malloc(s->len + new_len - old_len + 1);
  char *p = s->data;
  char *q = data;
  while (*p) {
    if (!strncmp(p, old, old_len)) {
      memcpy(q, new, new_len);
      q += new_len;
      p += old_len;
    } else {
      *q++ = *p++;
    }
  }
  *q = '\0';
  return string_new(data);
}

int main() {
  string_t *s = string_new("Hello, world!");
  s = string_replace(s, "world", "universe");
  printf("%s\n", s->data);
  string_free(s);
  return 0;
}