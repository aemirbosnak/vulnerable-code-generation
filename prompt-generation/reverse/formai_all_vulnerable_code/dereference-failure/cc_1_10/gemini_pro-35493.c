//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: shocked
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*                                                                               *
*                    Database Indexing System : Shockingly Simplified!               *
*                                                                               *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** */

typedef struct {
  char key[101];
  int value;
} Entry;

typedef struct {
  Entry entries[100];
  int size;
} Index;

/* ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** */

Index *createIndex() {
  Index *index = (Index *)malloc(sizeof(Index));
  index->size = 0;
  return index;
}

/* ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** */

void insertIndex(Index *index, char *key, int value) {
  strcpy(index->entries[index->size].key, key);
  index->entries[index->size].value = value;
  index->size++;
}

/* ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** */

int searchIndex(Index *index, char *key) {
  for (int i = 0; i < index->size; i++) {
    if (strcmp(index->entries[i].key, key) == 0) {
      return index->entries[i].value;
    }
  }
  return -1;
}

/* ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** */

void printIndex(Index *index) {
  printf("Index contains %d entries:\n", index->size);
  for (int i = 0; i < index->size; i++) {
    printf("\t%s : %d\n", index->entries[i].key, index->entries[i].value);
  }
}

/* ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** */

int main() {
  Index *index = createIndex();

  // ELECTRIC INSERTION!
  insertIndex(index, "Pikachu", 25);
  insertIndex(index, "Charizard", 6);
  insertIndex(index, "Snorlax", 143);
  insertIndex(index, "Mewtwo", 150);
  insertIndex(index, "Eevee", 133);

  // SHOCKING SEARCH!
  printf("Zap! Zap! Searching for Charizard...\n");
  int charizardPower = searchIndex(index, "Charizard");
  printf("Charizard's power level: %d\n", charizardPower);

  // THRILLING PRINT!
  printf("** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **\n");
  printf("Behold! The Database Index!\n");
  printIndex(index);

  // JAW-DROPPING FREEING!
  free(index);

  return 0;
}