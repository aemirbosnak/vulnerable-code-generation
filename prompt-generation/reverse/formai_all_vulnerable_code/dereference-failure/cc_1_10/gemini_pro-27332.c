//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

// Global variables
char *src_dir; // Source directory
char *dst_dir; // Destination directory
char *backup_name; // Backup file name
int keep_days; // Number of days to keep backups

// Function to create a time-stamped backup file name
char *create_backup_name() {
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);
  char *buf = malloc(100);
  strftime(buf, 100, "%Y-%m-%d_%H:%M:%S", tm);
  return buf;
}

// Function to copy a file
int copy_file(char *src, char *dst) {
  FILE *fsrc, *fdst;
  char buf[1024];
  int n;

  // Open source file
  fsrc = fopen(src, "rb");
  if (fsrc == NULL) {
    perror("fopen");
    return -1;
  }

  // Open destination file
  fdst = fopen(dst, "wb");
  if (fdst == NULL) {
    perror("fopen");
    fclose(fsrc);
    return -1;
  }

  // Copy data from source to destination
  while ((n = fread(buf, 1, sizeof(buf), fsrc)) > 0) {
    fwrite(buf, 1, n, fdst);
  }

  // Close files
  fclose(fsrc);
  fclose(fdst);

  return 0;
}

// Function to create a directory
int create_dir(char *dir) {
  int status;

  // Create the directory
  status = mkdir(dir, 0755);
  if (status == -1) {
    perror("mkdir");
    return -1;
  }

  return 0;
}

// Function to remove a directory
int remove_dir(char *dir) {
  int status;

  // Remove the directory
  status = rmdir(dir);
  if (status == -1) {
    perror("rmdir");
    return -1;
  }

  return 0;
}

// Function to remove old backups
int remove_old_backups() {
  DIR *dp;
  struct dirent *entry;
  char *path;
  time_t now, cutoff;

  // Open the destination directory
  dp = opendir(dst_dir);
  if (dp == NULL) {
    perror("opendir");
    return -1;
  }

  // Get the current time
  now = time(NULL);

  // Set the cutoff time
  cutoff = now - (keep_days * 24 * 60 * 60);

  // Iterate over the files in the directory
  while ((entry = readdir(dp)) != NULL) {
    // Skip the current directory and the parent directory
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      continue;
    }

    // Get the full path to the file
    path = malloc(strlen(dst_dir) + strlen(entry->d_name) + 2);
    sprintf(path, "%s/%s", dst_dir, entry->d_name);

    // Get the file's modification time
    struct stat statbuf;
    if (stat(path, &statbuf) == -1) {
      perror("stat");
      free(path);
      continue;
    }

    // Remove the file if it's older than the cutoff time
    if (statbuf.st_mtime < cutoff) {
      remove(path);
    }

    // Free the path
    free(path);
  }

  // Close the directory
  closedir(dp);

  return 0;
}

// Main function
int main(int argc, char *argv[]) {
  // Check the number of arguments
  if (argc != 5) {
    fprintf(stderr, "Usage: %s src_dir dst_dir backup_name keep_days\n", argv[0]);
    return -1;
  }

  // Get the command line arguments
  src_dir = argv[1];
  dst_dir = argv[2];
  backup_name = argv[3];
  keep_days = atoi(argv[4]);

  // Create the destination directory if it doesn't exist
  if (access(dst_dir, F_OK) == -1) {
    if (create_dir(dst_dir) == -1) {
      return -1;
    }
  }

  // Create the backup file name
  char *backup_file = create_backup_name();

  // Copy the source directory to the destination directory
  if (copy_file(src_dir, backup_file) == -1) {
    return -1;
  }

  // Remove old backups
  if (remove_old_backups() == -1) {
    return -1;
  }

  // Free the backup file name
  free(backup_file);

  return 0;
}