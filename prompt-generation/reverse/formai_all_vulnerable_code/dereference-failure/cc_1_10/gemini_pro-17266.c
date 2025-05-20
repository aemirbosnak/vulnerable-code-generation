//GEMINI-pro DATASET v1.0 Category: Building a XML Parser ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENT_NAME_LEN 128
#define MAX_ELEMENT_VALUE_LEN 1024

typedef struct _Element {
  char name[MAX_ELEMENT_NAME_LEN];
  char value[MAX_ELEMENT_VALUE_LEN];
} Element;

typedef struct _Stack {
  Element* elements;
  int size;
  int top;
} Stack;

Stack* stack_new(int size) {
  Stack* s = malloc(sizeof(Stack));
  if (!s) {
    return NULL;
  }
  s->elements = malloc(sizeof(Element) * size);
  if (!s->elements) {
    free(s);
    return NULL;
  }
  s->size = size;
  s->top = -1;
  return s;
}

void stack_free(Stack* s) {
  if (!s) {
    return;
  }
  if (s->elements) {
    free(s->elements);
  }
  free(s);
}

int stack_push(Stack* s, Element* e) {
  if (!s || !e || s->top == s->size - 1) {
    return -1;
  }
  s->elements[++s->top] = *e;
  return 0;
}

Element* stack_pop(Stack* s) {
  if (!s || s->top == -1) {
    return NULL;
  }
  return &s->elements[s->top--];
}

int parse_xml(char* xml) {
  Stack* s = stack_new(1024);
  if (!s) {
    return -1;
  }

  char* start = xml;
  char* end = xml;
  char* name;
  char* value;
  int i;

  while (*end) {
    if (*end == '<') {
      start = end + 1;
      end = start;
      while (*end && *end != '>') {
        end++;
      }
      name = malloc((end - start + 1) * sizeof(char));
      strncpy(name, start, end - start);
      name[end - start] = '\0';
      Element e;
      strcpy(e.name, name);
      stack_push(s, &e);
      free(name);
    } else if (*end == '>') {
      Element* e = stack_pop(s);
      if (!e) {
        stack_free(s);
        return -1;
      }
      value = malloc((end - start + 1) * sizeof(char));
      strncpy(value, start, end - start);
      value[end - start] = '\0';
      strcpy(e->value, value);
      free(value);
      start = end + 1;
    }
    end++;
  }

  while (s->top != -1) {
    Element* e = stack_pop(s);
    if (!e) {
      stack_free(s);
      return -1;
    }
    printf("<%s>%s</%s>\n", e->name, e->value, e->name);
  }

  stack_free(s);
  return 0;
}

int main(int argc, char** argv) {
  if (argc != 2) {
    printf("Usage: %s <xml_file>\n", argv[0]);
    return 1;
  }

  char* xml = NULL;
  FILE* f = fopen(argv[1], "rb");
  if (!f) {
    printf("Error opening file '%s'\n", argv[1]);
    return 1;
  }
  fseek(f, 0, SEEK_END);
  long fsize = ftell(f);
  fseek(f, 0, SEEK_SET);
  xml = malloc(fsize + 1);
  if (!xml) {
    printf("Error allocating memory for XML document\n");
    fclose(f);
    return 1;
  }
  fread(xml, 1, fsize, f);
  fclose(f);
  xml[fsize] = '\0';

  if (parse_xml(xml)) {
    printf("Error parsing XML document\n");
    free(xml);
    return 1;
  }

  free(xml);
  return 0;
}