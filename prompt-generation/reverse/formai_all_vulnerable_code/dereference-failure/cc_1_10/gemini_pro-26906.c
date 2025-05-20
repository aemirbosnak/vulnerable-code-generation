//GEMINI-pro DATASET v1.0 Category: File handling ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void read_file(char *filename) {
  FILE *fp;
  char buffer[MAX_SIZE];

  fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  while (fgets(buffer, MAX_SIZE, fp) != NULL) {
    printf("%s", buffer);
  }

  fclose(fp);
}

void write_file(char *filename) {
  FILE *fp;
  char buffer[MAX_SIZE];

  fp = fopen(filename, "w");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  printf("Enter text to write to file:\n");
  while (fgets(buffer, MAX_SIZE, stdin) != NULL) {
    fputs(buffer, fp);
  }

  fclose(fp);
}

void copy_file(char *source_filename, char *destination_filename) {
  FILE *source_fp, *destination_fp;
  char buffer[MAX_SIZE];

  source_fp = fopen(source_filename, "r");
  if (source_fp == NULL) {
    perror("Error opening source file");
    exit(1);
  }

  destination_fp = fopen(destination_filename, "w");
  if (destination_fp == NULL) {
    perror("Error opening destination file");
    exit(1);
  }

  while (fgets(buffer, MAX_SIZE, source_fp) != NULL) {
    fputs(buffer, destination_fp);
  }

  fclose(source_fp);
  fclose(destination_fp);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    exit(1);
  }

  char *filename = argv[1];
  char choice;

  printf("Choose an option:\n");
  printf("1. Read file\n");
  printf("2. Write file\n");
  printf("3. Copy file\n");
  printf("4. Exit\n");
  scanf(" %c", &choice);

  switch (choice) {
    case '1':
      read_file(filename);
      break;
    case '2':
      write_file(filename);
      break;
    case '3':
      if (argc < 3) {
        printf("Usage: %s <source_filename> <destination_filename>\n", argv[0]);
        exit(1);
      }
      char *source_filename = argv[2];
      char *destination_filename = argv[3];
      copy_file(source_filename, destination_filename);
      break;
    case '4':
      exit(0);
    default:
      printf("Invalid choice\n");
      break;
  }

  return 0;
}