//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_LINE_SIZE 256

int main() {
  printf("------------------\n");
  printf("|   DISK ANALYZER  |\n");
  printf("------------------\n\n");

  char line[MAX_LINE_SIZE];
  char *filename = "./disk.txt";
  FILE *fp;

  fp = fopen(filename, "r");

  if (fp == NULL) {
    printf("[ERROR] Could not open file: %s\n", filename);
    exit(1);
  }

  printf("Analyzing disk...\n\n");

  int lines_read = 0;
  char *files[MAX_FILES];
  int sizes[MAX_FILES];

  // Read each line and add it to our file list
  while (fgets(line, MAX_LINE_SIZE, fp) != NULL) {
    lines_read++;

    // Get the name and size of the file
    char *name = strtok(line, " ");
    int size = atoi(strtok(NULL, " "));

    // Add the file to our list
    files[lines_read - 1] = strdup(name);
    sizes[lines_read - 1] = size;
  }

  // Print the results
  printf("Disk analysis complete:\n\n");
  for (int i = 0; i < lines_read; i++) {
    char *name = files[i];
    int size = sizes[i];

    // Add some post-apocalyptic style to the output
    printf("| FILE: %s", name);
    for (int j = 0; j < 30 - strlen(name); j++) {
      printf(" ");
    }

    printf("| SIZE: %d", size);
    for (int j = 0; j < 18 - numlen(size); j++) {
      printf(" ");
    }

    printf("|");
    for (int j = 0; j < size / 100; j++) {
      printf("=");
    }
    printf(">");

    printf("\n");
  }

  fclose(fp);
  return 0;
}

// Helper function to get the number of digits in a number
int numlen(int num) {
  int len = 0;
  while (num > 0) {
    len++;
    num /= 10;
  }
  return len;
}