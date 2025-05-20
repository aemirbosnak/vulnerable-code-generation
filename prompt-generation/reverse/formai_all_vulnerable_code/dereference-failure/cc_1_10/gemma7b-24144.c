//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CMeta {
  char name[256];
  char value[256];
  struct CMeta* next;
} CMeta;

CMeta* extractMeta(char* data) {
  CMeta* head = NULL;
  char* p = data;
  char* key, *value;

  while (p) {
    key = strstr(p, ":");
    if (key) {
      value = key + 1;
      while (*value && isspace(*value)) {
        value++;
      }

      CMeta* newMeta = malloc(sizeof(CMeta));
      strncpy(newMeta->name, key, 255);
      strncpy(newMeta->value, value, 255);
      newMeta->next = head;
      head = newMeta;
    }

    p = strstr(p, "\n");
  }

  return head;
}

int main() {
  char data[] = "Name: John Doe\nEmail: john.doe@example.com\nAge: 30\n";

  CMeta* meta = extractMeta(data);

  while (meta) {
    printf("%s: %s\n", meta->name, meta->value);
    meta = meta->next;
  }

  return 0;
}