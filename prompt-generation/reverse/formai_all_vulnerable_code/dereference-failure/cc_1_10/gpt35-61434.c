//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {
  int file_descriptor;
  struct stat file_status;
  char* file_contents;
  char buffer[BUFFER_SIZE];
  int lines_processed = 0;
  int chars_processed = 0;
  
  if (argc != 2) {
    printf("Usage: %s <file_path>\n", argv[0]);
    return 1;
  }
  
  file_descriptor = open(argv[1], O_RDONLY);
  
  if (file_descriptor == -1) {
    perror("Error opening file");
    return 1;
  }
  
  if (fstat(file_descriptor, &file_status) == -1) {
    close(file_descriptor);
    perror("Error getting file status");
    return 1;
  }
  
  file_contents = mmap(NULL, file_status.st_size, PROT_READ, MAP_PRIVATE, file_descriptor, 0);
  
  if (file_contents == MAP_FAILED) {
    close(file_descriptor);
    perror("Error mapping file");
    return 1;
  }
  
  while (chars_processed < file_status.st_size) {
    // process one line at a time, delimited by '\n'
    int line_length = strcspn(file_contents + chars_processed, "\n");
    
    strncpy(buffer, file_contents + chars_processed, line_length);
    buffer[line_length] = '\0';
    
    printf("Line %d: %s\n", lines_processed, buffer);
    
    chars_processed += line_length + 1;
    lines_processed++;
  }
  
  munmap(file_contents, file_status.st_size);
  close(file_descriptor);
  
  return 0;
}