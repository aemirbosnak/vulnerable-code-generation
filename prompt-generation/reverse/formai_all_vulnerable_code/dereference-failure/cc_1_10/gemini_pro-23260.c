//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The heartbroken file
FILE *heartbroken;

// The mending file
FILE *mending;

// The fragments of the broken heart
char *fragments[100];

// The number of fragments
int num_fragments;

// The function that mends the broken heart
void mend_heart(char *filename) {
  // Open the broken heart file
  heartbroken = fopen(filename, "r");

  // Check if the file was opened successfully
  if (heartbroken == NULL) {
    printf("Unable to open the broken heart file.\n");
    exit(1);
  }

  // Read the fragments of the broken heart into an array
  for (num_fragments = 0; fgets(fragments[num_fragments], 100, heartbroken) != NULL; num_fragments++) {}

  // Close the broken heart file
  fclose(heartbroken);

  // Open the mending file
  mending = fopen("mended_heart.txt", "w");

  // Check if the file was opened successfully
  if (mending == NULL) {
    printf("Unable to open the mending file.\n");
    exit(1);
  }

  // Mend the broken heart by writing the fragments to the mending file
  for (int i = 0; i < num_fragments; i++) {
    fputs(fragments[i], mending);
  }

  // Close the mending file
  fclose(mending);

  // Print a message to the user
  printf("The broken heart has been mended.\n");
}

// The main function
int main(int argc, char *argv[]) {
  // Check if the user specified a filename
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    exit(1);
  }

  // Mend the broken heart
  mend_heart(argv[1]);

  // Return 0 to indicate that the program ran successfully
  return 0;
}