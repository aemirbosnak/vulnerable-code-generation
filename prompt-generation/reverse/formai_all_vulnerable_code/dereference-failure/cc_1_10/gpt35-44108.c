//FormAI DATASET v1.0 Category: Error handling ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

int main(int argc, char *argv[]) {
  FILE *fp;
  char *filename = argv[1];
  int i, num;

  printf("Welcome to my error handling program!\n");

  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  fp = fopen(filename, "r");

  if (fp == NULL) {
    perror("Error opening file");
    printf("Error code: %d\n", errno);
    exit(EXIT_FAILURE);
  }

  printf("\nReading file content...\n\n");

  for (i = 0; i < 10; i++) {
    if (fscanf(fp, "%d", &num) == 1) {
      printf("%d\n", num);
    } else {
      if (feof(fp)) {
        printf("End of file reached\n");
        break;
      } else if (ferror(fp)) {
        perror("Error reading file");
        printf("Error code: %d\n", errno);
        exit(EXIT_FAILURE);
      }
    }
  }

  if (fclose(fp) != 0) {
    perror("Error closing file");
    printf("Error code: %d\n", errno);
    exit(EXIT_FAILURE);
  }

  printf("\nFile closed successfully!\n");

  return 0;
}