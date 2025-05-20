//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Romeo and Juliet struct
typedef struct {
  char *name;
  int age;
  float balance;
} RomeoJuliet;

// Create a new Romeo and Juliet
RomeoJuliet *create_romeo_juliet(char *name, int age, float balance) {
  RomeoJuliet *rj = malloc(sizeof(RomeoJuliet));
  rj->name = strdup(name);
  rj->age = age;
  rj->balance = balance;
  return rj;
}

// Free a Romeo and Juliet
void free_romeo_juliet(RomeoJuliet *rj) {
  free(rj->name);
  free(rj);
}

// Print a Romeo and Juliet
void print_romeo_juliet(RomeoJuliet *rj) {
  printf("Name: %s\n", rj->name);
  printf("Age: %d\n", rj->age);
  printf("Balance: %f\n", rj->balance);
}

// Add an expense to a Romeo and Juliet
void add_expense(RomeoJuliet *rj, char *description, float amount) {
  rj->balance -= amount;
  printf("%s spent %f on %s\n", rj->name, amount, description);
}

// Main function
int main() {
  // Create Romeo and Juliet
  RomeoJuliet *romeo = create_romeo_juliet("Romeo", 20, 1000.0f);
  RomeoJuliet *juliet = create_romeo_juliet("Juliet", 18, 500.0f);

  // Add some expenses
  add_expense(romeo, "Flowers", 50.0f);
  add_expense(juliet, "Perfume", 30.0f);
  add_expense(romeo, "Dinner", 100.0f);
  add_expense(juliet, "Dress", 150.0f);

  // Print the Romeo and Juliets
  print_romeo_juliet(romeo);
  print_romeo_juliet(juliet);

  // Free the Romeo and Juliets
  free_romeo_juliet(romeo);
  free_romeo_juliet(juliet);

  return 0;
}