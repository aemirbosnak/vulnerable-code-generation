//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 10

typedef struct {
  char name[20];
  int age;
  float salary;
} row_t;

typedef struct {
  row_t rows[MAX_ROWS];
  int num_rows;
  int num_cols;
} table_t;

table_t *create_table(int num_cols) {
  table_t *table = malloc(sizeof(table_t));
  table->num_cols = num_cols;
  table->num_rows = 0;
  return table;
}

void free_table(table_t *table) {
  free(table);
}

int add_row(table_t *table, row_t row) {
  if (table->num_rows >= MAX_ROWS) {
    return -1;
  }
  table->rows[table->num_rows++] = row;
  return 0;
}

int get_row(table_t *table, int row_num, row_t *row) {
  if (row_num < 0 || row_num >= table->num_rows) {
    return -1;
  }
  *row = table->rows[row_num];
  return 0;
}

int update_row(table_t *table, int row_num, row_t row) {
  if (row_num < 0 || row_num >= table->num_rows) {
    return -1;
  }
  table->rows[row_num] = row;
  return 0;
}

int delete_row(table_t *table, int row_num) {
  if (row_num < 0 || row_num >= table->num_rows) {
    return -1;
  }
  table->num_rows--;
  for (int i = row_num; i < table->num_rows; i++) {
    table->rows[i] = table->rows[i + 1];
  }
  return 0;
}

void print_table(table_t *table) {
  printf("--------------------------------------------------------------------------------\n");
  printf("| %-20s | %-5s | %-10s |\n", "Name", "Age", "Salary");
  printf("--------------------------------------------------------------------------------\n");
  for (int i = 0; i < table->num_rows; i++) {
    row_t row = table->rows[i];
    printf("| %-20s | %-5d | %-10.2f |\n", row.name, row.age, row.salary);
  }
  printf("--------------------------------------------------------------------------------\n");
}

int main() {
  table_t *table = create_table(3);
  row_t row1 = {"John Doe", 30, 10000.00};
  row_t row2 = {"Jane Doe", 25, 12000.00};
  row_t row3 = {"John Smith", 40, 15000.00};
  add_row(table, row1);
  add_row(table, row2);
  add_row(table, row3);
  print_table(table);
  row_t row;
  get_row(table, 1, &row);
  printf("Row 1: %s, %d, %.2f\n", row.name, row.age, row.salary);
  row.age = 35;
  update_row(table, 1, row);
  print_table(table);
  delete_row(table, 0);
  print_table(table);
  free_table(table);
  return 0;
}