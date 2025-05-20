//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: Donald Knuth
// A meager backup system, with obsequious apologies to Prof. Knuth

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Global variables
int verbose = 0;  // Loquaciousness flag
char *source, *backup;  // Paths to source and backup files

// Custom error handler
void error(char *msg) {
  fprintf(stderr, "%s\n", msg);
  exit(EXIT_FAILURE);
}

// Timestamp function
char *timestamp() {
  time_t rawtime;
  struct tm *timeinfo;

  time(&rawtime);
  timeinfo = localtime(&rawtime);
  return asctime(timeinfo);
}

// Enter, the main() function
int main(int argc, char *argv[]) {
  // Fast and loose argument parsing
  if (argc == 4 && strcmp(argv[1], "-v") == 0) {
    verbose = 1;
    source = argv[2];
    backup = argv[3];
  } else if (argc == 3) {
    source = argv[1];
    backup = argv[2];
  } else {
    error("Usage: backup [-v] source backup");
  }

  // Allocate a buffer for the source file
  FILE *src = fopen(source, "r");
  if (src == NULL) {
    error("Could not open source file");
  }
  fseek(src, 0, SEEK_END);
  long size = ftell(src);
  rewind(src);
  char *buf = malloc(size + 1);
  if (buf == NULL) {
    error("Could not allocate buffer");
  }

  // Read the source file into the buffer
  if (fread(buf, 1, size, src) != size) {
    error("Could not read source file");
  }
  fclose(src);

  // Open the backup file
  FILE *bak = fopen(backup, "w");
  if (bak == NULL) {
    error("Could not open backup file");
  }

  // Write the timestamp to the backup file
  if (verbose) {
    fprintf(bak, "Backup created on %s\n", timestamp());
  }

  // Write the source file to the backup file
  if (fwrite(buf, 1, size, bak) != size) {
    error("Could not write to backup file");
  }
  fclose(bak);

  // Clean up
  free(buf);

  // Polite farewell
  if (verbose) {
    printf("Backup complete.\n");
  }
  return EXIT_SUCCESS;
}