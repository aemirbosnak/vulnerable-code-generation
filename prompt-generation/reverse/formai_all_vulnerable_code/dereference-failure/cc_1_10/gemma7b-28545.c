//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1024

typedef struct CSV_Entry {
  char **data;
  int num_cols;
  struct CSV_Entry *next;
} CSV_Entry;

CSV_Entry *csv_read(char *filename) {
  CSV_Entry *head = NULL;
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }

  char line[MAX_LINES];
  while (fgets(line, MAX_LINES, fp) != NULL) {
    CSV_Entry *new_entry = malloc(sizeof(CSV_Entry));
    new_entry->data = malloc(MAX_LINES * sizeof(char *));
    new_entry->num_cols = 0;

    char *ptr = line;
    char **columns = new_entry->data;
    while (*ptr) {
      columns[new_entry->num_cols++] = strdup(ptr);
      ptr += strcspn(ptr, ",") + 1;
    }

    new_entry->next = head;
    head = new_entry;
  }

  fclose(fp);
  return head;
}

int main() {
  CSV_Entry *entries = csv_read("data.csv");
  for (CSV_Entry *entry = entries; entry; entry = entry->next) {
    for (int i = 0; i < entry->num_cols; i++) {
      printf("%s,", entry->data[i]);
    }
    printf("\n");
  }

  return 0;
}