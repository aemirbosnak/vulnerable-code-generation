//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
#include <sys/stat.h>

// Define the maximum number of files to backup.
#define MAX_FILES 100

// Define the maximum length of a file path.
#define MAX_PATH_LENGTH 256

// Define the backup directory.
#define BACKUP_DIR "./backup"

// Define the file extension to backup.
#define FILE_EXTENSION ".txt"

// Function to get the current time and date.
char *get_current_time_and_date() {
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);
  char *str = malloc(32);
  strftime(str, 32, "%Y-%m-%d %H:%M:%S", tm);
  return str;
}

// Function to create a backup directory.
int create_backup_directory() {
  int status = mkdir(BACKUP_DIR, 0755);
  if (status != 0) {
    perror("mkdir");
    return -1;
  }
  return 0;
}

// Function to get a list of files to backup.
int get_files_to_backup(char *files[][MAX_PATH_LENGTH]) {
  DIR *dir;
  struct dirent *entry;
  int num_files = 0;

  // Open the current directory.
  dir = opendir(".");
  if (dir == NULL) {
    perror("opendir");
    return -1;
  }

  // Iterate over the directory entries.
  while ((entry = readdir(dir)) != NULL) {
    // Check if the entry is a regular file.
    struct stat statbuf;
    if (stat(entry->d_name, &statbuf) == 0 && S_ISREG(statbuf.st_mode)) {
      // Check if the entry has the correct file extension.
      if (strstr(entry->d_name, FILE_EXTENSION) != NULL) {
        // Add the entry to the list of files to backup.
        strcpy((*files)[num_files++], entry->d_name);
      }
    }
  }

  // Close the directory.
  closedir(dir);

  return num_files;
}

// Function to copy a file to the backup directory.
int copy_file(char *file) {
  char src_path[MAX_PATH_LENGTH];
  char dst_path[MAX_PATH_LENGTH];
  FILE *src;
  FILE *dst;

  // Create the source path.
  strcpy(src_path, file);

  // Create the destination path.
  strcpy(dst_path, BACKUP_DIR);
  strcat(dst_path, "/");
  strcat(dst_path, file);

  // Open the source file.
  src = fopen(src_path, "r");
  if (src == NULL) {
    perror("fopen");
    return -1;
  }

  // Open the destination file.
  dst = fopen(dst_path, "w");
  if (dst == NULL) {
    perror("fopen");
    fclose(src);
    return -1;
  }

  // Copy the file.
  int c;
  while ((c = fgetc(src)) != EOF) {
    fputc(c, dst);
  }

  // Close the files.
  fclose(src);
  fclose(dst);

  return 0;
}

// Function to backup the files.
int backup_files(char *files[][MAX_PATH_LENGTH], int num_files) {
  int i;

  // Create the backup directory.
  if (create_backup_directory() != 0) {
    return -1;
  }

  // Copy the files to the backup directory.
  for (i = 0; i < num_files; i++) {
    if (copy_file((*files)[i]) != 0) {
      return -1;
    }
  }

  return 0;
}

// Main function.
int main() {
  char files[MAX_FILES][MAX_PATH_LENGTH];
  int num_files;

  // Get the current time and date.
  char *current_time_and_date = get_current_time_and_date();

  // Get a list of files to backup.
  num_files = get_files_to_backup(&files);
  if (num_files == -1) {
    return -1;
  }

  // Backup the files.
  if (backup_files(&files, num_files) != 0) {
    return -1;
  }

  // Print a success message.
  printf("Backup successful! %s\n", current_time_and_date);

  // Free the memory allocated for the current time and date.
  free(current_time_and_date);

  return 0;
}