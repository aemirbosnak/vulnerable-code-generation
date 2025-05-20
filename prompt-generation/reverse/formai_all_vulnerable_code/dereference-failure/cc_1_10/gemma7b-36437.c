//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TABLES 10
#define MAX_ROWS 100

typedef struct Table {
  char name[20];
  int num_rows;
  struct Row *rows;
} Table;

typedef struct Row {
  char data[100];
  struct Row *next;
} Row;

Table *tables[MAX_TABLES] = { NULL };

void insert_table(char *name, int num_rows) {
  Table *new_table = malloc(sizeof(Table));
  strcpy(new_table->name, name);
  new_table->num_rows = num_rows;
  new_table->rows = NULL;

  tables[0] = new_table;
  for (int i = 1; tables[i] != NULL; i++) {
    tables[i] = tables[i - 1]->rows;
  }
}

void insert_row(char *table_name, char *data) {
  Table *table = NULL;
  for (int i = 0; tables[i] != NULL; i++) {
    if (strcmp(tables[i]->name, table_name) == 0) {
      table = tables[i];
      break;
    }
  }

  if (table == NULL) {
    return;
  }

  Row *new_row = malloc(sizeof(Row));
  strcpy(new_row->data, data);
  new_row->next = table->rows;
  table->rows = new_row;
}

int main() {
  insert_table("foo", 5);
  insert_row("foo", "bar");
  insert_row("foo", "baz");

  for (int i = 0; tables[i] != NULL; i++) {
    printf("Table: %s, Rows: %d\n", tables[i]->name, tables[i]->num_rows);
    for (Row *row = tables[i]->rows; row != NULL; row = row->next) {
      printf("  Row: %s\n", row->data);
    }
  }

  return 0;
}