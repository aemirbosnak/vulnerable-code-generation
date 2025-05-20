//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Romeo and Juliet data types
typedef struct {
  char *name;
  double income;
  double expenses;
  double savings;
} Romeo;

typedef struct {
  char *name;
  double income;
  double expenses;
  double savings;
} Juliet;

// Define the Romeo and Juliet functions
Romeo *createRomeo(char *name, double income, double expenses, double savings) {
  Romeo *romeo = malloc(sizeof(Romeo));
  romeo->name = strdup(name);
  romeo->income = income;
  romeo->expenses = expenses;
  romeo->savings = savings;
  return romeo;
}

Juliet *createJuliet(char *name, double income, double expenses, double savings) {
  Juliet *juliet = malloc(sizeof(Juliet));
  juliet->name = strdup(name);
  juliet->income = income;
  juliet->expenses = expenses;
  juliet->savings = savings;
  return juliet;
}

void destroyRomeo(Romeo *romeo) {
  free(romeo->name);
  free(romeo);
}

void destroyJuliet(Juliet *juliet) {
  free(juliet->name);
  free(juliet);
}

// Print the Romeo and Juliet data
void printRomeo(Romeo *romeo) {
  printf("Romeo: %s\n", romeo->name);
  printf("  Income: $%.2f\n", romeo->income);
  printf("  Expenses: $%.2f\n", romeo->expenses);
  printf("  Savings: $%.2f\n", romeo->savings);
}

void printJuliet(Juliet *juliet) {
  printf("Juliet: %s\n", juliet->name);
  printf("  Income: $%.2f\n", juliet->income);
  printf("  Expenses: $%.2f\n", juliet->expenses);
  printf("  Savings: $%.2f\n", juliet->savings);
}

// Calculate the Romeo and Juliet net worth
double calculateRomeoNetWorth(Romeo *romeo) {
  return romeo->savings - romeo->expenses;
}

double calculateJulietNetWorth(Juliet *juliet) {
  return juliet->savings - juliet->expenses;
}

// Compare the Romeo and Juliet net worths
int compareRomeoAndJulietNetWorths(Romeo *romeo, Juliet *juliet) {
  double romeoNetWorth = calculateRomeoNetWorth(romeo);
  double julietNetWorth = calculateJulietNetWorth(juliet);
  if (romeoNetWorth > julietNetWorth) {
    return 1;
  } else if (romeoNetWorth == julietNetWorth) {
    return 0;
  } else {
    return -1;
  }
}

// Main function
int main() {
  // Create Romeo and Juliet
  Romeo *romeo = createRomeo("Romeo Montague", 50000, 30000, 20000);
  Juliet *juliet = createJuliet("Juliet Capulet", 40000, 25000, 15000);

  // Print Romeo and Juliet
  printRomeo(romeo);
  printJuliet(juliet);

  // Calculate the Romeo and Juliet net worths
  double romeoNetWorth = calculateRomeoNetWorth(romeo);
  double julietNetWorth = calculateJulietNetWorth(juliet);

  // Compare the Romeo and Juliet net worths
  int comparisonResult = compareRomeoAndJulietNetWorths(romeo, juliet);

  // Print the Romeo and Juliet net worths and comparison result
  printf("Romeo's net worth: $%.2f\n", romeoNetWorth);
  printf("Juliet's net worth: $%.2f\n", julietNetWorth);
  if (comparisonResult == 1) {
    printf("Romeo has a higher net worth than Juliet.\n");
  } else if (comparisonResult == 0) {
    printf("Romeo and Juliet have the same net worth.\n");
  } else {
    printf("Juliet has a higher net worth than Romeo.\n");
  }

  // Destroy Romeo and Juliet
  destroyRomeo(romeo);
  destroyJuliet(juliet);

  return 0;
}