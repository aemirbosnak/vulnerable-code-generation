//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUF_SIZE 1024

// Function to create a backup of a file
int backup_file(char *src_file, char *dest_file) {
  FILE *src, *dest;
  char *backup_name;
  int ch, count = 0;

  // Open source file
  src = fopen(src_file, "r");
  if (src == NULL) {
    perror("Error opening source file");
    return -1;
  }

  // Create backup file name
  backup_name = malloc(strlen(dest_file) + 10);
  strcpy(backup_name, dest_file);
  strcat(backup_name, ".bak");

  // Open backup file
  dest = fopen(backup_name, "w");
  if (dest == NULL) {
    perror("Error opening backup file");
    return -1;
  }

  // Copy file contents
  while ((ch = fgetc(src)) != EOF) {
    fputc(ch, dest);
    count++;
  }

  // Close files
  fclose(src);
  fclose(dest);

  return count;
}

// Function to restore a file from a backup
int restore_file(char *backup_file, char *src_file) {
  FILE *backup, *src;
  char *restore_name;
  int ch, count = 0;

  // Open backup file
  backup = fopen(backup_file, "r");
  if (backup == NULL) {
    perror("Error opening backup file");
    return -1;
  }

  // Create restored file name
  restore_name = malloc(strlen(src_file) + 10);
  strcpy(restore_name, src_file);
  strcat(restore_name, ".restored");

  // Open restored file
  src = fopen(restore_name, "w");
  if (src == NULL) {
    perror("Error opening restored file");
    return -1;
  }

  // Copy file contents
  while ((ch = fgetc(backup)) != EOF) {
    fputc(ch, src);
    count++;
  }

  // Close files
  fclose(backup);
  fclose(src);

  return count;
}

// Function to display the user menu
void display_menu() {
  printf("\n\n** File Backup System **\n\n");
  printf("1. Backup a file\n");
  printf("2. Restore a file\n");
  printf("3. Exit\n");
}

// Function to get the user choice
int get_choice() {
  int choice;

  printf("Enter your choice: ");
  scanf("%d", &choice);

  return choice;
}

// Function to get the file names
void get_file_names(char *src_file, char *dest_file) {
  printf("Enter the source file name: ");
  scanf("%s", src_file);

  printf("Enter the destination file name: ");
  scanf("%s", dest_file);
}

// Main function
int main() {
  int choice, count;
  char src_file[BUF_SIZE], dest_file[BUF_SIZE];

  while (1) {
    display_menu();
    choice = get_choice();

    switch (choice) {
      case 1:
        get_file_names(src_file, dest_file);
        count = backup_file(src_file, dest_file);
        if (count > 0) {
          printf("File backed up successfully (%d bytes copied)\n", count);
        } else {
          printf("Error backing up file\n");
        }
        break;
      case 2:
        get_file_names(dest_file, src_file);
        count = restore_file(dest_file, src_file);
        if (count > 0) {
          printf("File restored successfully (%d bytes copied)\n", count);
        } else {
          printf("Error restoring file\n");
        }
        break;
      case 3:
        printf("Thank you for using the File Backup System!\n");
        exit(0);
      default:
        printf("Invalid choice. Please enter a valid number (1-3)\n");
        break;
    }
  }

  return 0;
}