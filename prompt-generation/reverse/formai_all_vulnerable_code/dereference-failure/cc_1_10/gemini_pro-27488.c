//GEMINI-pro DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// A simple Wi-Fi signal strength analyzer in the style of Donald Knuth.

// The main function.
int main(int argc, char *argv[]) {
  // Check the command line arguments.
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Get the interface name.
  char *interface = argv[1];

  // Open the interface.
  FILE *fp = fopen(interface, "r");
  if (fp == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  // Read the interface information.
  char line[1024];
  while (fgets(line, sizeof(line), fp) != NULL) {
    // Parse the line.
    char *field[10];
    int i = 0;
    char *token = strtok(line, " ");
    while (token != NULL) {
      field[i++] = token;
      token = strtok(NULL, " ");
    }

    // Print the signal strength.
    if (strcmp(field[0], "ESSID:") == 0) {
      printf("ESSID: %s\n", field[1]);
    } else if (strcmp(field[0], "level:") == 0) {
      int level = atoi(field[1]);
      printf("Level: %d%%\n", level);
    } else if (strcmp(field[0], "frequency:") == 0) {
      int frequency = atoi(field[1]);
      printf("Frequency: %d MHz\n", frequency);
    }
  }

  // Close the interface.
  fclose(fp);

  return EXIT_SUCCESS;
}