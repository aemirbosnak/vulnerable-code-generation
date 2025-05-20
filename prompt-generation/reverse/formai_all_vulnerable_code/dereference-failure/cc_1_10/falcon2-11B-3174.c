//Falcon2-11B DATASET v1.0 Category: Antivirus scanner ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <signal.h>
#include <dirent.h>

void create_directory(char *directory_name) {
  struct stat st;
  int fd;

  if (stat(directory_name, &st) == 0) {
    if (!S_ISDIR(st.st_mode)) {
      perror("Error: ");
      exit(EXIT_FAILURE);
    } else {
      printf("Directory %s already exists\n", directory_name);
      return;
    }
  } else if (errno == ENOENT) {
    fd = mkdir(directory_name, 0755);
    if (fd < 0) {
      perror("Error: ");
      exit(EXIT_FAILURE);
    } else {
      printf("Directory %s created\n", directory_name);
    }
  } else {
    perror("Error: ");
    exit(EXIT_FAILURE);
  }
}

void search_files(char *directory_name, char *file_name, int *found) {
  DIR *dp;
  struct dirent *entry;
  char filename[FILENAME_MAX];

  if ((dp = opendir(directory_name)) == NULL) {
    perror("Error: ");
    exit(EXIT_FAILURE);
  }

  while ((entry = readdir(dp))!= NULL) {
    if (strstr(entry->d_name, file_name)!= NULL) {
      *found = 1;
      printf("Found: %s\n", entry->d_name);
      break;
    }
  }

  closedir(dp);
}

void scan_for_virus(char *file_name, char *virus_name) {
  int fd;
  char buffer[4096];
  char *virus_signature = "VIRUS";

  fd = open(file_name, O_RDONLY);
  if (fd == -1) {
    perror("Error: ");
    exit(EXIT_FAILURE);
  }

  while (read(fd, buffer, sizeof(buffer)) > 0) {
    if (strstr(buffer, virus_signature)!= NULL) {
      printf("Virus found in %s\n", file_name);
      exit(EXIT_FAILURE);
    }
  }

  close(fd);
}

void check_and_remove_virus(char *file_name, char *virus_name) {
  int fd;
  char buffer[4096];
  char *virus_signature = "VIRUS";

  fd = open(file_name, O_RDONLY);
  if (fd == -1) {
    perror("Error: ");
    exit(EXIT_FAILURE);
  }

  while (read(fd, buffer, sizeof(buffer)) > 0) {
    if (strstr(buffer, virus_signature)!= NULL) {
      printf("Virus found in %s\n", file_name);
      remove(file_name);
      exit(EXIT_SUCCESS);
    }
  }

  close(fd);
}

int main(int argc, char **argv) {
  if (argc!= 2) {
    printf("Usage: %s <file_name>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  char file_name[FILENAME_MAX];
  char virus_name[FILENAME_MAX];
  int found = 0;

  strcpy(file_name, argv[1]);
  strcpy(virus_name, "VIRUS");

  create_directory("temp");
  search_files("temp", file_name, &found);

  if (found == 1) {
    scan_for_virus(file_name, virus_name);
  } else {
    check_and_remove_virus(file_name, virus_name);
  }

  return 0;
}