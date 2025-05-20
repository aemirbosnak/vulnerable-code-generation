//FormAI DATASET v1.0 Category: File Backup System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 1024

char* get_timestamp() {
  time_t raw_time;
  struct tm* time_info;
  char* timestamp_buffer;
  
  time(&raw_time);
  time_info = localtime(&raw_time);
  
  timestamp_buffer = malloc(sizeof(char) * 32);
  strftime(timestamp_buffer, 32, "%Y-%m-%d_%H-%M-%S", time_info);
  
  return timestamp_buffer;
}

int main(int argc, char** argv) {
  if (argc != 3) {
    printf("Usage: %s <source_file> <destination_directory>\n", argv[0]);
    return 1;
  }
  
  char* source_path = argv[1];
  char* destination_dir = argv[2];
  
  FILE* source_file = fopen(source_path, "rb");
  
  if (!source_file) {
    printf("Failed to open file %s\n", source_path);
    return 1;
  }
  
  char* timestamp = get_timestamp();
  char* backup_filename = malloc(sizeof(char) * (strlen(destination_dir) + 32));
  sprintf(backup_filename, "%s/%s_%s", destination_dir, source_path, timestamp);
  
  FILE* backup_file = fopen(backup_filename, "wb");
  
  if (!backup_file) {
    printf("Failed to create backup file %s\n", backup_filename);
    fclose(source_file);
    return 1;
  }
  
  char buffer[BUFFER_SIZE];
  size_t bytes_read;
  
  while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, source_file)) > 0) {
    fwrite(buffer, sizeof(char), bytes_read, backup_file);
  }
  
  fclose(source_file);
  fclose(backup_file);
  
  printf("File successfully backed up to %s\n", backup_filename);
  
  return 0;
}