//FormAI DATASET v1.0 Category: System process viewer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define PROC "/proc"
#define MAX_PATH_LEN 4096

int is_number(const char *str) {
  while (*str) {
    if (!isdigit(*str)) {
        return 0;
    }
    str++;
  }
  return 1;
}

char* get_process_name_from_pid(const char *pid) {
  char *path = (char*) malloc(MAX_PATH_LEN * sizeof(char));
  char *comm_path = (char*) calloc(1, MAX_PATH_LEN);
  strcpy(comm_path, PROC);
  strcat(comm_path, "/");
  strcat(comm_path, pid);
  strcat(comm_path, "/comm");

  realpath(comm_path, path);

  FILE *comm_file = fopen(path, "r");
  char *buff = (char*) calloc(1, MAX_PATH_LEN);
  fread(buff, 1, MAX_PATH_LEN, comm_file);
  fclose(comm_file);

  return buff;
}

void print_process_info(const char *pid) {
  char *proc_path = (char*) calloc(1, MAX_PATH_LEN);
  strcpy(proc_path, PROC);
  strcat(proc_path, "/");
  strcat(proc_path, pid);
  strcat(proc_path, "/");

  char *name = get_process_name_from_pid(pid);
  printf("Process %s (%s):\n", pid, name);

  DIR *dir = opendir(proc_path);
  if (!dir) {
    perror("opendir");
    return;
  }

  struct dirent *dp = NULL;
  while ((dp = readdir(dir)) != NULL) {
    if (is_number(dp->d_name)) {
      char *filename = (char*) calloc(1, MAX_PATH_LEN);
      strcat(filename, proc_path);
      strcat(filename, dp->d_name);

      char *buff = (char*) calloc(1, MAX_PATH_LEN);
      FILE *fp = fopen(filename, "r");
      fread(buff, 1, MAX_PATH_LEN, fp);
      fclose(fp);

      printf("%s: %s\n", dp->d_name, buff);

      free(buff);
      free(filename);
    }
  }

  free(name);
  free(proc_path);
}

void list_all_processes() {
  DIR *dir;
  struct dirent *dp;

  printf("PID\t\tProcess\n");

  dir = opendir(PROC);
  if (dir == NULL) {
    perror("opendir");
    exit(1);
  }

  while ((dp = readdir(dir)) != NULL) {
    if (is_number(dp->d_name)) {
      printf("%s\t\t%s\n", dp->d_name, get_process_name_from_pid(dp->d_name));
    }
  }
}

int main(int argc, char**argv) {
  if (argc < 2) {
    list_all_processes();
  } else {
    print_process_info(argv[1]);
  }
  return 0;
}