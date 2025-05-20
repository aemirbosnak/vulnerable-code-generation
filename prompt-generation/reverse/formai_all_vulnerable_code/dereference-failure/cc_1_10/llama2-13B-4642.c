//LLAMA2-13B DATASET v1.0 Category: Data recovery tool ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

void recovery_tool(char *part_name, char *file_name) {
  DIR *dirp;
  struct dirent *dirent;
  char full_path[1024];
  char buffer[BUFFER_SIZE];
  int fd;
  off_t start = 0, end = 0;

  if ((dirp = opendir(part_name)) == NULL) {
    perror("Error opening partition");
    return;
  }

  while ((dirent = readdir(dirp)) != NULL) {
    if (strcmp(dirent->d_name, ".") == 0 || strcmp(dirent->d_name, "..") == 0)
      continue;

    // Check if the file is a regular file
    if (dirent->d_type != DT_REG)
      continue;

    // Get the full path of the file
    snprintf(full_path, sizeof(full_path), "%s/%s", part_name, dirent->d_name);

    // Open the file and check if it's a valid file
    if ((fd = open(full_path, O_RDONLY, 0)) == -1) {
      perror("Error opening file");
      continue;
    }

    // Get the file's size
    if (fseek(fd, 0, SEEK_END) != 0) {
      perror("Error seeking to end of file");
      close(fd);
      continue;
    }

    // Get the file's size
    end = ftell(fd);

    // Seek back to the beginning of the file
    if (fseek(fd, 0, SEEK_SET) != 0) {
      perror("Error seeking to beginning of file");
      close(fd);
      continue;
    }

    // Read the file's contents into a buffer
    read(fd, buffer, BUFFER_SIZE);

    // Check if the file's contents match the expected pattern
    if (strstr(buffer, file_name) == NULL)
      continue;

    // Found the file! Print its contents
    printf("%s\n", buffer);

    // Close the file and return
    close(fd);
    return;
  }

  // If we reached this point, we didn't find the file
  printf("File not found\n");
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <partition_name> <file_name>\n", argv[0]);
    return 1;
  }

  char *part_name = argv[1];
  char *file_name = argv[2];

  recovery_tool(part_name, file_name);

  return 0;
}