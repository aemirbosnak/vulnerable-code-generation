//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <sys/types.h>

#define MAX_PATH 1024
#define MAX_LINE 1024

void curious_sysadmin_tool(void) {
  char *path = "/";
  char *line = "";
  char *mmap_addr = NULL;
  size_t mmap_len = 0;
  int ret = 0;

  while (1) {
    // Print the current directory
    printf("Current Directory: %s\n", path);

    // Read a line from the user
    printf("Enter a command: ");
    fgets(line, MAX_LINE, stdin);

    // Trim the newline character
    line[strcspn(line, "\n")] = '\0';

    // Check if the line is empty
    if (line[0] == '\0') {
      continue;
    }

    // Split the line into a command and arguments
    char *command = strtok(line, " ");
    char *arguments = strtok(NULL, " ");

    // Check if the command is "cd"
    if (strcmp(command, "cd") == 0) {
      // Get the new directory path
      path = arguments;
      ret = chdir(path);
      if (ret < 0) {
        perror("chdir");
      }
      continue;
    }

    // Check if the command is "ls"
    if (strcmp(command, "ls") == 0) {
      // Map the current directory into memory
      mmap_len = syscall(SYS_mmap, path, 0, 0, PROT_READ, MAP_FILE | MAP_PRIVATE, -1, 0);
      if (mmap_len < 0) {
        perror("mmap");
      }
      mmap_addr = mmap(NULL, mmap_len, PROT_READ, MAP_FILE | MAP_PRIVATE, 0, 0);
      if (mmap_addr == MAP_FAILED) {
        perror("mmap");
      }

      // Print the directory contents
      printf("Directory Contents:\n");
      char *ptr = mmap_addr;
      while (*ptr != '\0') {
        printf("%c", *ptr);
        ptr++;
      }

      // Unmap the memory
      munmap(mmap_addr, mmap_len);
      continue;
    }

    // Unknown command
    printf("Unknown command: %s\n", command);
  }
}

int main(void) {
  curious_sysadmin_tool();
  return 0;
}