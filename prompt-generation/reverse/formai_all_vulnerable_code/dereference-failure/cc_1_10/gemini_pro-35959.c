//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

int main() {
  // Open the /proc directory
  DIR *proc = opendir("/proc");
  if (proc == NULL) {
    perror("opendir");
    return 1;
  }

  // Iterate over the entries in the /proc directory
  struct dirent *entry;
  while ((entry = readdir(proc)) != NULL) {
    // Check if the entry is a directory
    struct stat statbuf;
    if (stat(entry->d_name, &statbuf) == -1) {
      perror("stat");
      continue;
    }
    if (!S_ISDIR(statbuf.st_mode)) {
      continue;
    }

    // Get the process ID
    int pid = atoi(entry->d_name);

    // Read the /proc/[pid]/status file
    char filename[256];
    snprintf(filename, sizeof(filename), "/proc/%d/status", pid);
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
      perror("open");
      continue;
    }
    char buffer[4096];
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer));
    if (bytes_read == -1) {
      perror("read");
      close(fd);
      continue;
    }
    close(fd);

    // Parse the /proc/[pid]/status file
    char *line;
    char *key;
    char *value;
    line = strtok(buffer, "\n");
    while (line != NULL) {
      key = strtok(line, ":");
      value = strtok(NULL, "\n");
      if (key != NULL && value != NULL) {
        printf("%s: %s\n", key, value);
      }
      line = strtok(NULL, "\n");
    }

    printf("\n");
  }

  // Close the /proc directory
  closedir(proc);

  return 0;
}