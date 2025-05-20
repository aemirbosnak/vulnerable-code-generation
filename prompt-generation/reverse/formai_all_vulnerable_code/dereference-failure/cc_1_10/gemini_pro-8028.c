//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: mind-bending
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_COLUMNS 10
#define MAX_ROWS 1000
#define MAX_INDEXES 10

typedef struct {
  int id;
  char name[50];
  int age;
  float salary;
} row_t;

typedef struct {
  char name[50];
  int col;
  int *index;
} index_t;

row_t rows[MAX_ROWS];
index_t indexes[MAX_INDEXES];
int num_rows = 0;
int num_indexes = 0;

void insert_row(int id, char *name, int age, float salary) {
  rows[num_rows].id = id;
  strcpy(rows[num_rows].name, name);
  rows[num_rows].age = age;
  rows[num_rows].salary = salary;
  num_rows++;
}

void create_index(char *name, int col) {
  strcpy(indexes[num_indexes].name, name);
  indexes[num_indexes].col = col;
  indexes[num_indexes].index = malloc(sizeof(int) * num_rows);
  for (int i = 0; i < num_rows; i++) {
    indexes[num_indexes].index[i] = i;
  }
  qsort(indexes[num_indexes].index, num_rows, sizeof(int),
        (int (*)(const void *, const void *))strcmp);
  num_indexes++;
}

void search_index(char *name, int col, int value) {
  int *index = bsearch(&value, indexes[col].index, num_rows, sizeof(int),
                     (int (*)(const void *, const void *))strcmp);
  if (index != NULL) {
    printf("Found row %d\n", *index);
  } else {
    printf("Not found\n");
  }
}

int main() {
  insert_row(1, "John Doe", 30, 50000);
  insert_row(2, "Jane Doe", 25, 40000);
  insert_row(3, "Peter Parker", 20, 30000);
  insert_row(4, "Mary Jane", 22, 25000);
  insert_row(5, "Tony Stark", 40, 100000);

  create_index("name", 1);
  create_index("age", 2);
  create_index("salary", 3);

  search_index("name", 1, "John Doe");
  search_index("age", 2, 25);
  search_index("salary", 3, 50000);

  return 0;
}