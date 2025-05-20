//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: Claude Shannon
// Shannon HTML Beautifier in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  char *data;
  struct node *next;
} node;

typedef struct stack {
  node *top;
} stack;

void push(stack *s, char *data) {
  node *n = malloc(sizeof(node));
  n->data = data;
  n->next = s->top;
  s->top = n;
}

char *pop(stack *s) {
  if (s->top == NULL)
    return NULL;
  char *data = s->top->data;
  node *n = s->top;
  s->top = s->top->next;
  free(n);
  return data;
}

int main() {
  stack s;
  s.top = NULL;

  char *html = "<html><head><title>Shannon HTML Beautifier</title></head><body><h1>Hello, Shannon!</h1><p>This is an example of a beautified HTML document.</p></body></html>";

  char *token = strtok(html, "<>");
  while (token != NULL) {
    if (token[0] == '/') {
      char *tag = pop(&s);
      printf("  </%s>\n", tag);
    } else {
      char *tag = malloc(strlen(token) + 1);
      strcpy(tag, token);
      push(&s, tag);
      printf("  <%s>\n", tag);
    }
    token = strtok(NULL, "<>");
  }

  while (s.top != NULL) {
    char *tag = pop(&s);
    printf("  </%s>\n", tag);
  }

  return 0;
}