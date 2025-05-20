//Code Llama-13B DATASET v1.0 Category: Warehouse Management System ; Style: mathematical
/*
 * Warehouse Management System
 * Example Program
 */

#include <stdio.h>

int main() {
  // Define the number of items to be stored
  int num_items = 10;

  // Define the number of warehouses
  int num_warehouses = 3;

  // Define the number of shelves in each warehouse
  int num_shelves[] = {5, 10, 20};

  // Define the number of aisles in each shelf
  int num_aisles[] = {3, 5, 10};

  // Define the number of rows in each aisle
  int num_rows[] = {2, 4, 6};

  // Define the number of columns in each row
  int num_columns[] = {4, 8, 12};

  // Define the number of items stored in each shelf
  int items_per_shelf[] = {10, 20, 30};

  // Define the number of items stored in each aisle
  int items_per_aisle[] = {15, 30, 45};

  // Define the number of items stored in each row
  int items_per_row[] = {10, 20, 30};

  // Define the number of items stored in each column
  int items_per_column[] = {5, 10, 15};

  // Print the number of items stored in each warehouse
  for (int i = 0; i < num_warehouses; i++) {
    printf("Warehouse %d: %d items\n", i + 1, items_per_shelf[i]);
  }

  // Print the number of items stored in each shelf
  for (int i = 0; i < num_shelves; i++) {
    printf("Shelf %d: %d items\n", i + 1, items_per_shelf[i]);
  }

  // Print the number of items stored in each aisle
  for (int i = 0; i < num_aisles; i++) {
    printf("Aisle %d: %d items\n", i + 1, items_per_aisle[i]);
  }

  // Print the number of items stored in each row
  for (int i = 0; i < num_rows; i++) {
    printf("Row %d: %d items\n", i + 1, items_per_row[i]);
  }

  // Print the number of items stored in each column
  for (int i = 0; i < num_columns; i++) {
    printf("Column %d: %d items\n", i + 1, items_per_column[i]);
  }

  return 0;
}