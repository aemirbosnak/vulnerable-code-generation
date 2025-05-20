//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: lively
// File backup system, starring our hero: the Backup Buddy!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Backup Buddy's trusty sidekick: the File Manager
struct FileManager {
  FILE *input;
  FILE *output;
};

// Open a file for reading or writing
struct FileManager open_file(char *filename, char *mode) {
  struct FileManager fm;
  fm.input = fopen(filename, mode);
  if (fm.input == NULL) {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }
  return fm;
}

// Close a file
void close_file(struct FileManager fm) {
  fclose(fm.input);
  fclose(fm.output);
}

// Copy the contents of one file to another
void copy_file(struct FileManager src, struct FileManager dst) {
  char buffer[1024];
  while (fread(buffer, sizeof(buffer), 1, src.input) != 0) {
    fwrite(buffer, sizeof(buffer), 1, dst.output);
  }
}

// Create a timestamped backup of a file
void backup_file(char *filename) {
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);
  char timestamp[100];
  strftime(timestamp, sizeof(timestamp), "%Y-%m-%d_%H-%M-%S", tm);

  char backup_filename[100];
  sprintf(backup_filename, "%s.%s", filename, timestamp);

  struct FileManager src = open_file(filename, "r");
  struct FileManager dst = open_file(backup_filename, "w");

  copy_file(src, dst);

  close_file(src);
  close_file(dst);

  printf("Backup of '%s' created as '%s'.\n", filename, backup_filename);
}

// The main event: our Backup Buddy in action!
int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  backup_file(argv[1]);

  return EXIT_SUCCESS;
}