//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: retro
// Ahoy there, mateys! Let's embark on a CSV readin' adventure!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our trusty vessel to sail the CSV seas
struct CsvFile {
  FILE *file;
  char *line;
  int lineSize;
  char delimiter;
};

// Let's set sail!
struct CsvFile *csvOpen(const char *filename, char delimiter) {
  // Grab ourselves a ship
  struct CsvFile *csv = malloc(sizeof(struct CsvFile));

  // Open the file and check if we're seaworthy
  csv->file = fopen(filename, "r");
  if (csv->file == NULL) {
    free(csv);
    return NULL;
  }

  // Set our course with the delimiter
  csv->delimiter = delimiter;

  // Get ready to hoist the sails
  csv->lineSize = 0;
  csv->line = NULL;

  return csv;
}

// Time to drop anchor and close the file
void csvClose(struct CsvFile *csv) {
  if (csv->file != NULL) {
    fclose(csv->file);
  }
  if (csv->line != NULL) {
    free(csv->line);
  }
  free(csv);
}

// Let's get the next line, one row at a time
char *csvReadLine(struct CsvFile *csv) {
  // Free up the old line if we're starting fresh
  if (csv->line != NULL) {
    free(csv->line);
    csv->line = NULL;
  }

  // Get the length of the line
  size_t len = 0;
  getline(&csv->line, &len, csv->file);

  // If we got a line, let's trim it down
  if (csv->line != NULL) {
    int lineLen = strlen(csv->line);
    while (lineLen > 0 && csv->line[lineLen - 1] == '\r' || csv->line[lineLen - 1] == '\n') {
      lineLen--;
    }
    csv->line[lineLen] = '\0';
  }

  return csv->line;
}

// Let's see what's inside this cell
char *csvGetCell(struct CsvFile *csv) {
  static char *cell = NULL;
  static size_t cellSize = 0;

  // If we're starting fresh, grab the first cell
  if (cell == NULL) {
    cell = csv->line;
  } else {
    // Find the next delimiter or the end of the line
    int i = 0;
    while (cell[i] != '\0' && cell[i] != csv->delimiter) {
      i++;
    }

    // Update the cell pointer and size
    if (cell[i] != '\0') {
      cell[i] = '\0';
      cell += i + 1;
    } else {
      cell = NULL;
    }
  }

  return cell;
}

// Let's set sail and explore the CSV!
int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Avast there, matey! Ye be needin' a filename and a delimiter to read the CSV.\n");
    return 1;
  }

  // Open the file and set our course
  struct CsvFile *csv = csvOpen(argv[1], argv[2][0]);
  if (csv == NULL) {
    printf("Shiver me timbers! We couldn't open the file, matey.\n");
    return 1;
  }

  // Let's dive into the CSV, one row at a time
  char *line;
  while ((line = csvReadLine(csv)) != NULL) {
    printf("Ahoy! We found a line: %s\n", line);

    // Let's explore the cells in this line
    char *cell;
    while ((cell = csvGetCell(csv)) != NULL) {
      printf("We be findin' a cell: %s\n", cell);
    }

    printf("\n");
  }

  // Time to close down the ship
  csvClose(csv);

  return 0;
}