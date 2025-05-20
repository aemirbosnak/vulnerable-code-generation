//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: post-apocalyptic
// Welcome to the post-apocalyptic CSV reader!

// In this desolate wasteland, data is scarce, and order is a distant memory.
// But fear not, wanderer, for this program will guide you through the treacherous
// labyrinth of comma-separated values.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// We'll define a RADIOACTIVE_CHAR to mark corrupted cells.
#define RADIOACTIVE_CHAR '$'

// The CSV wasteland is a perilous place.
// Let's create a struct to store our hard-won data.
typedef struct {
  char *key;
  char *data;
} DATA_STASH;

// Now, let's build our CSV reader, armed with our trusty machete.

FILE *file;
char buffer[256];
char *token;
char delimiter = ',';

// We'll use a stash of DATA_STASH to collect our loot.
DATA_STASH stash[100];

// Prepare to traverse the wasteland!
int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: csv_reader <csv_file>\n");
    return 1;
  }

  // Open the file and check if it's not contaminated.
  file = fopen(argv[1], "r");
  if (!file) {
    printf("Error opening file: %s\n", argv[1]);
    return 1;
  }

  // Read the first line and prepare for the worst.
  fgets(buffer, sizeof(buffer), file);
  token = strtok(buffer, &delimiter);

  // Initialize our stash.
  int i = 0;
  stash[i].key = strdup(token);

  // We'll use a radioactive character to mark errors.
  stash[i].data = RADIOACTIVE_CHAR;

  // Now, let's venture deeper into the wasteland.
  while (token != NULL) {
    // Detect contamination!
    if (strcmp(token, RADIOACTIVE_CHAR) == 0) {
      // Oops, this data is a goner.
      stash[i].data = RADIOACTIVE_CHAR;
      printf("Warning: Corrupted data found!\n");
    } else {
      // We found some precious data!
      stash[i].data = strdup(token);
    }

    // Keep digging deeper.
    token = strtok(NULL, &delimiter);
    i++;
  }

  // Close the file. We've scavenged all we can.
  fclose(file);

  // Let's display our hard-earned loot.
  printf("Our hard-won data:\n");
  for (int j = 0; j < i; j++) {
    printf("Key: %s, Data: %s\n", stash[j].key, stash[j].data);
  }

  // Remember, in the wasteland, data is more valuable than water.
  return 0;
}