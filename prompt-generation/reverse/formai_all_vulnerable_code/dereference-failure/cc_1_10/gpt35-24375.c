//FormAI DATASET v1.0 Category: File Backup System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// define max backup file name length
#define MAX_FILENAME_LENGTH 100

// function to get the current time as string
char* get_current_time() {
  time_t current_time;
  char* c_time_string;
  current_time = time(NULL);
  if (current_time == ((time_t)-1)) {
     fprintf(stderr, "Failed to get the current time\n");
     exit(EXIT_FAILURE);
  }
  c_time_string = ctime(&current_time);
  if (c_time_string == NULL) {
     fprintf(stderr, "Failed to convert the current time to a string\n");
     exit(EXIT_FAILURE);
  }
  return c_time_string;
}

// function to backup a file
void backup_file(char* filename) {
  // create backup file name
  char* backup_filename = malloc(MAX_FILENAME_LENGTH);
  char* timestamp = get_current_time();
  snprintf(backup_filename, MAX_FILENAME_LENGTH, "%s.%s", filename, timestamp);
  // open input and output files
  FILE* input_file = fopen(filename, "rb");
  if (input_file == NULL) {
    fprintf(stderr, "Failed to open input file: %s\n", filename);
    exit(EXIT_FAILURE);
  }
  FILE* output_file = fopen(backup_filename, "wb");
  if (output_file == NULL) {
    fprintf(stderr, "Failed to open output file: %s\n", backup_filename);
    exit(EXIT_FAILURE);
  }
  // read from input file and write to output file
  int buffer_size = 1024;
  char* buffer = malloc(buffer_size);
  int read_count;
  do {
    read_count = fread(buffer, 1, buffer_size, input_file);
    fwrite(buffer, 1, read_count, output_file);
  } while (read_count == buffer_size);
  // close files and clean up
  free(buffer);
  fclose(input_file);
  fclose(output_file);
  free(backup_filename);
}

int main(int argc, char* argv[]) {
  // check arguments
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  // backup the file
  backup_file(argv[1]);
  printf("Backup successful: %s\n", argv[1]);
  return 0;
}