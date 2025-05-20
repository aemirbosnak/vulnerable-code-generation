//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum size of the file to be backed up
#define MAX_FILE_SIZE 1024000

// Function to generate a random file name
char *generate_random_file_name() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate a random number between 1 and 1000000
  int random_number = rand() % 1000000;

  // Convert the random number to a string
  char *file_name = malloc(10);
  sprintf(file_name, "%d.txt", random_number);

  // Return the file name
  return file_name;
}

// Function to create a random file
FILE *create_random_file(char *file_name) {
  // Open the file for writing
  FILE *file = fopen(file_name, "w");

  // Generate a random number of lines to write to the file
  int num_lines = rand() % 100;

  // Write the random number of lines to the file
  for (int i = 0; i < num_lines; i++) {
    // Generate a random line of text
    char *line = malloc(100);
    sprintf(line, "This is line %d of the random file.\n", i);

    // Write the line to the file
    fprintf(file, "%s", line);

    // Free the memory allocated for the line
    free(line);
  }

  // Close the file
  fclose(file);

  // Return the file
  return file;
}

// Function to back up a file
void backup_file(char *file_name) {
  // Open the file to be backed up for reading
  FILE *file = fopen(file_name, "r");

  // Check if the file was opened successfully
  if (file == NULL) {
    printf("Error opening file %s for reading.\n", file_name);
    return;
  }

  // Generate a random file name for the backup file
  char *backup_file_name = generate_random_file_name();

  // Open the backup file for writing
  FILE *backup_file = fopen(backup_file_name, "w");

  // Check if the backup file was opened successfully
  if (backup_file == NULL) {
    printf("Error opening file %s for writing.\n", backup_file_name);
    return;
  }

  // Copy the contents of the file to be backed up to the backup file
  char buffer[MAX_FILE_SIZE];
  while (fread(buffer, sizeof(char), MAX_FILE_SIZE, file) > 0) {
    fwrite(buffer, sizeof(char), MAX_FILE_SIZE, backup_file);
  }

  // Close the files
  fclose(file);
  fclose(backup_file);

  // Delete the original file
  remove(file_name);

  // Print a message indicating that the file was backed up successfully
  printf("File %s backed up successfully to %s.\n", file_name, backup_file_name);
}

int main() {
  // Create a random file
  char *file_name = generate_random_file_name();
  FILE *file = create_random_file(file_name);

  // Back up the file
  backup_file(file_name);

  return 0;
}