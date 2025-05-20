//FormAI DATASET v1.0 Category: Database querying ; Style: surrealist
#include <stdio.h>
#include <string.h>

// surreal function prototypes
void elephant_in_the_query(char query[]);
void clockwork_orange(int num_rows, int num_cols, int table[][num_cols]);
void melting_database(char query[], int num_rows, int num_cols, int table[][num_cols]);

int main() {
  char query[100];
  int num_cols = 3;
  int num_rows = 5;
  int table[num_rows][num_cols];

  elephant_in_the_query(query);
  clockwork_orange(num_rows, num_cols, table);
  melting_database(query, num_rows, num_cols, table);

  return 0;
}

void elephant_in_the_query(char query[]) {
  printf("Welcome to the database querying program. Please enter your query:\n");
  fgets(query, 100, stdin);
  printf("\nElephant in the query. Processing...");
}

void clockwork_orange(int num_rows, int num_cols, int table[][num_cols]) {
  int cell_value = 1;
  for (int i = 0; i < num_rows; i++) {
    for (int j = 0; j < num_cols; j++) {
      if (i % 2 == 0) {
        table[i][j] = cell_value;
      } else {
        table[i][j] = cell_value * 2;
      }
      cell_value++;
    }
  }
  printf("\nClockwork orange. Table generated.\n");
}

void melting_database(char query[], int num_rows, int num_cols, int table[][num_cols]) {
  int result = 0;
  if (strstr(query, "COUNT") != NULL) {
    result = num_rows * num_cols;
  } else if (strstr(query, "SUM") != NULL) {
    for (int i = 0; i < num_rows; i++) {
      for (int j = 0; j < num_cols; j++) {
        result += table[i][j];
      }
    }
  } else if (strstr(query, "AVG") != NULL) {
    int total = 0;
    for (int i = 0; i < num_rows; i++) {
      for (int j = 0; j < num_cols; j++) {
        total += table[i][j];
      }
    }
    result = total / (num_rows * num_cols);
  } else {
    result = -1;
  }

  if (result != -1) {
    printf("\nMelting database. Result: %d\n", result);
  } else {
    printf("\nMelting database. Invalid query.\n");
  }
}