//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

// Define the periodic table
char **table = NULL;

// Function to initialize the periodic table
void initializeTable() {
  table = malloc(116 * sizeof(char *));
  for (int i = 0; i < 116; i++) {
    table[i] = malloc(20 * sizeof(char));
  }
  // Fill the table with data
  for (int i = 0; i < 116; i++) {
    for (int j = 0; j < 20; j++) {
      table[i][j] = '\0';
    }
  }
}

// Function to add an element to the periodic table
void addElement(char *name, int atomicNumber, int blockNumber, int electronConfiguration) {
  initializeTable();
  // Find the empty slot in the table
  int i = -1;
  for (int j = 0; j < 116; j++) {
    for (int k = 0; k < 20; k++) {
      if (table[j][k] == '\0') {
        i = j;
        break;
      }
    }
  }
  // If an empty slot is found, add the element
  if (i != -1) {
    table[i][0] = name;
    table[i][1] = atomicNumber;
    table[i][2] = blockNumber;
    table[i][3] = electronConfiguration;
  }
}

// Function to print the periodic table
void printTable() {
  printf("------------------------------------------------------------------------\n");
  printf("  # | Name | Atomic Number | Block Number | Electron Configuration |\n");
  printf("------------------------------------------------------------------------\n");
  for (int i = 0; i < 116; i++) {
    for (int j = 0; j < 20; j++) {
      if (table[i][0] != '\0') {
        printf("  %3d | %10s | %d | %d | %s |\n", table[i][1], table[i][0], table[i][2], table[i][3], table[i][4]);
      }
    }
  }
  printf("------------------------------------------------------------------------\n");
}

int main() {
  // Add some elements to the periodic table
  addElement("Hydrogen", 1, 1, "2, 1");
  addElement("Helium", 2, 1, "2, 2");
  addElement("Sodium", 11, 1, "2, 8, 1");
  addElement("Potassium", 19, 1, "2, 8, 1");

  // Print the periodic table
  printTable();

  return 0;
}