//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
#include <sys/stat.h>

// Define the maximum number of files that can be backed up at once
#define MAX_FILES 100

// Define the maximum size of a single file that can be backed up
#define MAX_FILE_SIZE 1024 * 1024 * 1024

// Define the path to the backup directory
#define BACKUP_DIR "/backup"

// Define the file extension for backup files
#define BACKUP_EXT ".bak"

// Function to get the current time as a string
char *get_current_time() {
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);
  char *time_str = malloc(sizeof(char) * 26);
  strftime(time_str, 26, "%Y-%m-%d %H:%M:%S", tm);
  return time_str;
}

// Function to create a backup directory if it does not exist
void create_backup_dir() {
  struct stat st;
  if (stat(BACKUP_DIR, &st) == -1) {
    mkdir(BACKUP_DIR, 0755);
  }
}

// Function to get a list of files in a directory
char **get_files_in_dir(const char *dir_path, int *num_files) {
  DIR *dir = opendir(dir_path);
  if (dir == NULL) {
    return NULL;
  }

  struct dirent *entry;
  char **files = malloc(sizeof(char *) * MAX_FILES);
  int i = 0;
  while ((entry = readdir(dir)) != NULL) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      continue;
    }

    char *file_path = malloc(sizeof(char) * (strlen(dir_path) + strlen(entry->d_name) + 1));
    strcpy(file_path, dir_path);
    strcat(file_path, "/");
    strcat(file_path, entry->d_name);

    files[i] = file_path;
    i++;
  }

  closedir(dir);

  *num_files = i;
  return files;
}

// Function to copy a file to the backup directory
int copy_file(const char *src_file_path, const char *dst_file_path) {
  FILE *src_file = fopen(src_file_path, "rb");
  if (src_file == NULL) {
    return -1;
  }

  FILE *dst_file = fopen(dst_file_path, "wb");
  if (dst_file == NULL) {
    fclose(src_file);
    return -1;
  }

  char buffer[1024];
  int bytes_read;
  while ((bytes_read = fread(buffer, sizeof(char), sizeof(buffer), src_file)) > 0) {
    fwrite(buffer, sizeof(char), bytes_read, dst_file);
  }

  fclose(src_file);
  fclose(dst_file);

  return 0;
}

// Function to perform a file backup
int backup_files(char **files, int num_files) {
  create_backup_dir();

  char *time_str = get_current_time();

  for (int i = 0; i < num_files; i++) {
    char *src_file_path = files[i];

    struct stat st;
    if (stat(src_file_path, &st) == -1) {
      continue;
    }

    if (st.st_size > MAX_FILE_SIZE) {
      continue;
    }

    char *dst_file_path = malloc(sizeof(char) * (strlen(BACKUP_DIR) + strlen(time_str) + strlen(BACKUP_EXT) + strlen(src_file_path) + 1));
    strcpy(dst_file_path, BACKUP_DIR);
    strcat(dst_file_path, "/");
    strcat(dst_file_path, time_str);
    strcat(dst_file_path, "_");
    strcat(dst_file_path, src_file_path);
    strcat(dst_file_path, BACKUP_EXT);

    printf("Backing up file %s to %s\n", src_file_path, dst_file_path);

    if (copy_file(src_file_path, dst_file_path) == -1) {
      printf("Error backing up file %s\n", src_file_path);
    }

    free(dst_file_path);
  }

  free(time_str);

  return 0;
}

// Main function
int main() {
  char *dir_path = ".";
  int num_files;
  char **files = get_files_in_dir(dir_path, &num_files);
  if (files == NULL) {
    printf("Error getting files in directory %s\n", dir_path);
    return -1;
  }

  if (backup_files(files, num_files) == -1) {
    printf("Error backing up files\n");
    return -1;
  }

  for (int i = 0; i < num_files; i++) {
    free(files[i]);
  }
  free(files);

  return 0;
}