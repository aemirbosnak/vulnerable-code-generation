//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

// Define the maximum length of file names
#define MAX_FILE_NAME_LENGTH 256

// Define the maximum number of files to backup
#define MAX_NUM_FILES 1024

// Define the backup directory
#define BACKUP_DIR "/home/user/backup"

// Function to backup a single file
int backup_file(char *file_name) {
  // Open the file to be backed up
  int fd = open(file_name, O_RDONLY);
  if (fd == -1) {
    perror("open");
    return -1;
  }

  // Get the file size
  struct stat file_stat;
  if (fstat(fd, &file_stat) == -1) {
    perror("fstat");
    close(fd);
    return -1;
  }

  // Create the backup file
  char backup_file_name[MAX_FILE_NAME_LENGTH];
  snprintf(backup_file_name, MAX_FILE_NAME_LENGTH, "%s/%s", BACKUP_DIR, file_name);
  int backup_fd = open(backup_file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (backup_fd == -1) {
    perror("open");
    close(fd);
    return -1;
  }

  // Copy the file contents to the backup file
  char buffer[4096];
  ssize_t bytes_read;
  while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
    if (write(backup_fd, buffer, bytes_read) == -1) {
      perror("write");
      close(fd);
      close(backup_fd);
      return -1;
    }
  }

  // Close the files
  close(fd);
  close(backup_fd);

  return 0;
}

// Function to backup all files in a directory
int backup_directory(char *dir_name) {
  // Open the directory
  DIR *dir = opendir(dir_name);
  if (dir == NULL) {
    perror("opendir");
    return -1;
  }

  // Iterate over the files in the directory
  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    // Skip hidden files
    if (entry->d_name[0] == '.') {
      continue;
    }

    // Get the full path to the file
    char file_name[MAX_FILE_NAME_LENGTH];
    snprintf(file_name, MAX_FILE_NAME_LENGTH, "%s/%s", dir_name, entry->d_name);

    // Backup the file
    if (backup_file(file_name) == -1) {
      closedir(dir);
      return -1;
    }
  }

  // Close the directory
  closedir(dir);

  return 0;
}

// Main function
int main(int argc, char **argv) {
  // Check if the backup directory exists
  if (access(BACKUP_DIR, F_OK) == -1) {
    // Create the backup directory
    if (mkdir(BACKUP_DIR, 0755) == -1) {
      perror("mkdir");
      return -1;
    }
  }

  // Backup all files in the current directory
  if (backup_directory(".") == -1) {
    return -1;
  }

  return 0;
}