//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PERIOD_TABLE_SIZE 118

typedef struct PeriodTable {
  char name[20];
  int atomicNumber;
  float atomicMass;
  char block;
  char type;
  struct PeriodTable* next;
} PeriodTable;

PeriodTable* createPeriodTable(void);
void displayPeriodTable(PeriodTable* table);
void searchPeriodTable(PeriodTable* table, char element);

int main() {
  PeriodTable* table = createPeriodTable();
  displayPeriodTable(table);
  searchPeriodTable(table, 'Na');

  return 0;
}

PeriodTable* createPeriodTable(void) {
  PeriodTable* table = (PeriodTable*)malloc(sizeof(PeriodTable));
  table->name[0] = '\0';
  table->atomicNumber = 0;
  table->atomicMass = 0.0f;
  table->block = 'a';
  table->type = 'n';
  table->next = NULL;

  return table;
}

void displayPeriodTable(PeriodTable* table) {
  while (table) {
    printf("%s (%d) - %f, %c, %c\n", table->name, table->atomicNumber, table->atomicMass, table->block, table->type);
    table = table->next;
  }
}

void searchPeriodTable(PeriodTable* table, char element) {
  while (table) {
    if (strcmp(table->name, element) == 0) {
      printf("Element: %s\n", table->name);
      printf("Atomic Number: %d\n", table->atomicNumber);
      printf("Atomic Mass: %f\n", table->atomicMass);
      printf("Block: %c\n", table->block);
      printf("Type: %c\n", table->type);
      return;
    }
    table = table->next;
  }

  printf("Element not found.\n");
}