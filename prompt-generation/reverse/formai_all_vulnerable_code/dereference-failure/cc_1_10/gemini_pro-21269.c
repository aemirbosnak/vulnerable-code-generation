//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <dirent.h>

// Function to get the current time and date
char *get_time() {
  time_t rawtime;
  struct tm * timeinfo;
  time(&rawtime);
  timeinfo = localtime (&rawtime);
  char *time_str = malloc(sizeof(char) * 20);
  strftime(time_str, 20, "%Y-%m-%d-%H-%M-%S", timeinfo);
  return time_str;
}

// Function to create a backup of a file or copy a file to another location
void backup_file(char *source, char *destination) {
  FILE *source_file, *destination_file;
  char c;

  // Open the source file
  source_file = fopen(source, "r");
  if (source_file == NULL) {
    perror("Error opening source file");
    exit(EXIT_FAILURE);
  }

  // Open the destination file
  destination_file = fopen(destination, "w");
  if (destination_file == NULL) {
    perror("Error opening destination file");
    exit(EXIT_FAILURE);
  }

  // Copy the contents of the source file to the destination file
  while ((c = fgetc(source_file)) != EOF) {
    fputc(c, destination_file);
  }

  // Close both files
  fclose(source_file);
  fclose(destination_file);

  printf("Backup of %s created successfully at %s\n", source, get_time());
}

// Function to create a directory
int create_directory(char *path) {
  struct stat st = {0};
  if (stat(path, &st) == -1) {
    if (mkdir(path, S_IRWXU | S_IRWXG | S_IRWXO) == -1) {
      perror("Error creating directory");
      return -1;
    }
  }
  return 0;
}

// Function to backup all files in a directory
void backup_directory(char *source_dir, char *destination_dir) {
  DIR *source_directory, *destination_directory;
  struct dirent *dirent;
  char source_file[256];
  char destination_file[256];

  // Open the source directory
  source_directory = opendir(source_dir);
  if (source_directory == NULL) {
    perror("Error opening source directory");
    exit(EXIT_FAILURE);
  }

  // Open the destination directory
  destination_directory = opendir(destination_dir);
  if (destination_directory == NULL) {
    perror("Error opening destination directory");
    exit(EXIT_FAILURE);
  }

  // Create the backup directory if it does not exist
  if (create_directory(destination_dir) == -1) {
    perror("Error creating backup directory");
    exit(EXIT_FAILURE);
  }

  // Loop through the files in the source directory
  while ((dirent = readdir(source_directory)) != NULL) {
    // Skip the current directory and the parent directory
    if (strcmp(dirent->d_name, ".") == 0 || strcmp(dirent->d_name, "..") == 0) {
      continue;
    }

    // Get the full path of the source file
    strcpy(source_file, source_dir);
    strcat(source_file, "/");
    strcat(source_file, dirent->d_name);

    // Get the full path of the destination file
    strcpy(destination_file, destination_dir);
    strcat(destination_file, "/");
    strcat(destination_file, dirent->d_name);

    // Backup the file
    backup_file(source_file, destination_file);
  }

  // Close both directories
  closedir(source_directory);
  closedir(destination_directory);

  printf("Backup of %s created successfully at %s\n", source_dir, get_time());
}

// Main function
int main(int argc, char *argv[]) {
  // Check if the user has provided the correct number of arguments
  if (argc != 3) {
    printf("Usage: %s <source> <destination>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Check if the source file or directory exists
  struct stat st;
  if (stat(argv[1], &st) == -1) {
    perror("Error: Source file or directory does not exist");
    exit(EXIT_FAILURE);
  }

  // Check if the destination directory exists
  if (stat(argv[2], &st) == -1) {
    perror("Error: Destination directory does not exist");
    exit(EXIT_FAILURE);
  }

  // Check if the source is a file or a directory
  if (S_ISREG(st.st_mode)) {
    // Backup the file
    backup_file(argv[1], argv[2]);
  } else if (S_ISDIR(st.st_mode)) {
    // Backup the directory
    backup_directory(argv[1], argv[2]);
  } else {
    printf("Error: Source is not a file or a directory\n");
    exit(EXIT_FAILURE);
  }

  return 0;
}