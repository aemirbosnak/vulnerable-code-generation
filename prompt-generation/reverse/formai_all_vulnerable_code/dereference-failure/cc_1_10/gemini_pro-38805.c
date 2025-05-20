//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

// Define the maximum length of a file path
#define MAX_PATH_LEN 256

// Define the maximum number of files to backup
#define MAX_FILES 100

// Define the file extension to backup
#define FILE_EXT ".txt"

// Define the backup directory
#define BACKUP_DIR "backup"

// Function to recursively backup files
void backup_files(char *dir, char *backup_dir) {
  // Open the directory
  DIR *dp = opendir(dir);
  if (dp == NULL) {
    perror("opendir");
    return;
  }

  // Create the backup directory if it doesn't exist
  if (mkdir(backup_dir, 0755) != 0) {
    perror("mkdir");
    return;
  }

  // Iterate over the files in the directory
  struct dirent *entry;
  while ((entry = readdir(dp)) != NULL) {
    // Skip hidden files
    if (entry->d_name[0] == '.') {
      continue;
    }

    // Get the file path
    char file_path[MAX_PATH_LEN];
    snprintf(file_path, MAX_PATH_LEN, "%s/%s", dir, entry->d_name);

    // Get the file stat
    struct stat statbuf;
    if (stat(file_path, &statbuf) != 0) {
      perror("stat");
      continue;
    }

    // Check if the file is a regular file
    if (!S_ISREG(statbuf.st_mode)) {
      continue;
    }

    // Check if the file has the specified file extension
    if (strcmp(strrchr(entry->d_name, '.'), FILE_EXT) != 0) {
      continue;
    }

    // Create the backup file path
    char backup_file_path[MAX_PATH_LEN];
    snprintf(backup_file_path, MAX_PATH_LEN, "%s/%s", backup_dir, entry->d_name);

    // Copy the file to the backup directory
    if (copyfile(file_path, backup_file_path) != 0) {
      perror("copyfile");
      continue;
    }

    // Recursively backup files in subdirectories
    if (S_ISDIR(statbuf.st_mode)) {
      char subdir_path[MAX_PATH_LEN];
      snprintf(subdir_path, MAX_PATH_LEN, "%s/%s", dir, entry->d_name);

      char subdir_backup_path[MAX_PATH_LEN];
      snprintf(subdir_backup_path, MAX_PATH_LEN, "%s/%s", backup_dir, entry->d_name);

      backup_files(subdir_path, subdir_backup_path);
    }
  }

  // Close the directory
  closedir(dp);
}

// Function to copy a file
int copyfile(char *src, char *dst) {
  // Open the source file
  FILE *src_fp = fopen(src, "rb");
  if (src_fp == NULL) {
    perror("fopen (src)");
    return -1;
  }

  // Open the destination file
  FILE *dst_fp = fopen(dst, "wb");
  if (dst_fp == NULL) {
    perror("fopen (dst)");
    fclose(src_fp);
    return -1;
  }

  // Copy the file
  int c;
  while ((c = fgetc(src_fp)) != EOF) {
    if (fputc(c, dst_fp) == EOF) {
      perror("fputc");
      fclose(src_fp);
      fclose(dst_fp);
      return -1;
    }
  }

  // Close the files
  fclose(src_fp);
  fclose(dst_fp);

  return 0;
}

// Main function
int main() {
  // Get the current time
  time_t now = time(NULL);

  // Create the backup directory name
  char backup_dir[MAX_PATH_LEN];
  snprintf(backup_dir, MAX_PATH_LEN, "%s/%s", BACKUP_DIR, ctime(&now));

  // Backup the files
  backup_files(".", backup_dir);

  return 0;
}