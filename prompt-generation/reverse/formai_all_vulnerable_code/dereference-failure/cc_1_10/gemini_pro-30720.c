//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Backup system using file copy and checksum verification

// Colors for pretty printing
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define RESET "\x1B[0m"

// File copy function
int file_copy(char *src, char *dest) {
  FILE *from, *to;
  int ch;

  if ((from = fopen(src, "r")) == NULL) {
    perror(RED "Error opening source file" RESET);
    return -1;
  }
  if ((to = fopen(dest, "w")) == NULL) {
    perror(RED "Error opening destination file" RESET);
    return -1;
  }

  while ((ch = fgetc(from)) != EOF) {
    fputc(ch, to);
  }

  fclose(from);
  fclose(to);

  return 0;
}

// Calculate checksum function
unsigned long checksum(char *file) {
  FILE *fp;
  unsigned long ck = 0;
  int ch;

  if ((fp = fopen(file, "r")) == NULL) {
    perror(RED "Error opening file for checksum" RESET);
    return -1;
  }

  while ((ch = fgetc(fp)) != EOF) {
    ck += ch;
  }
  fclose(fp);

  return ck;
}

// Verify checksum function
int verify_checksum(char *file, unsigned long crc) {
  unsigned long new_crc = checksum(file);

  if (new_crc == crc) {
    return 0;
  } else {
    return -1;
  }
}

int main() {
  char src_file[] = "my_important_file.txt";
  char backup_file[] = "backup.txt";
  unsigned long crc;

  // Generate a timestamped backup file name
  char timestamp[20];
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);
  strftime(timestamp, sizeof(timestamp), "%Y-%m-%d-%H-%M-%S", tm);
  sprintf(backup_file, "backup-%s.txt", timestamp);

  // Print backup status
  printf(GREEN "Backing up file: '%s' to '%s'\n" RESET, src_file, backup_file);

  // Copy file
  if (file_copy(src_file, backup_file) != 0) {
    perror(RED "Error copying file" RESET);
    return 1;
  }

  // Calculate and store checksum
  crc = checksum(backup_file);

  // Verify checksum
  if (verify_checksum(backup_file, crc) != 0) {
    perror(RED "Error verifying checksum" RESET);
    return 1;
  }

  // Print backup success message
  printf(GREEN "File backup succeeded with checksum: %lu\n" RESET, crc);

  return 0;
}