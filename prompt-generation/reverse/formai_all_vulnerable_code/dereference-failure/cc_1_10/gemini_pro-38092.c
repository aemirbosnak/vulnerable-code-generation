//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define PROCFS_PATH "/proc"
#define MAX_BUF_SIZE 1024

void print_newline(void) {
  printf("\n");
}

void print_divider(void) {
  printf("--------------------------------------------------------------------------\n");
}

void print_header(void) {
  printf("%-10s %-10s %-10s %-20s %-10s %-10s\n", "PID", "PPID", "UID", "COMMAND", "STATE", "TIME");
  print_divider();
}

void print_process_info(int pid) {
  char path[MAX_BUF_SIZE];
  char buf[MAX_BUF_SIZE];
  int fd;

  snprintf(path, sizeof(path), "%s/%d/stat", PROCFS_PATH, pid);
  fd = open(path, O_RDONLY);
  if (fd < 0) {
    perror("open");
    return;
  }

  if (read(fd, buf, sizeof(buf)) < 0) {
    perror("read");
    close(fd);
    return;
  }

  close(fd);

  char *tok;
  char state;
  int utime, stime;
  int i = 0;

  tok = strtok(buf, " ");
  while (tok != NULL) {
    switch (i) {
      case 1:
        printf("%-10d ", atoi(tok));
        break;
      case 3:
        printf("%-10d ", atoi(tok));
        break;
      case 10:
        state = tok[0];
        printf("%-10c ", state);
        break;
      case 13:
        utime = atoi(tok);
        break;
      case 14:
        stime = atoi(tok);
        break;
      case 15:
        printf("%-10d ", utime + stime);
        break;
    }
    i++;
    tok = strtok(NULL, " ");
  }

  snprintf(path, sizeof(path), "%s/%d/cmdline", PROCFS_PATH, pid);
  fd = open(path, O_RDONLY);
  if (fd < 0) {
    perror("open");
    return;
  }

  if (read(fd, buf, sizeof(buf)) < 0) {
    perror("read");
    close(fd);
    return;
  }

  close(fd);

  printf("%-20s", buf);
  print_newline();
}

int main(void) {
  DIR *dir;
  struct dirent *entry;

  dir = opendir(PROCFS_PATH);
  if (dir == NULL) {
    perror("opendir");
    return EXIT_FAILURE;
  }

  print_header();

  while ((entry = readdir(dir)) != NULL) {
    char *ptr;

    ptr = entry->d_name;
    while (*ptr != '\0') {
      if (*ptr >= '0' && *ptr <= '9') {
        break;
      }
      ptr++;
    }

    if (*ptr == '\0') {
      continue;
    }

    int pid = atoi(entry->d_name);
    print_process_info(pid);
  }

  closedir(dir);

  return EXIT_SUCCESS;
}