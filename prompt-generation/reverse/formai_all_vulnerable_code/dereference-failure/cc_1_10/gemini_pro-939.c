//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to print a happy message
void print_happy() {
  printf(":-) File synchronization complete!\n");
}

// Helper function to compare two files
int compare_files(FILE *file1, FILE *file2) {
  // Check if the files are the same size
  long file1_size = ftell(file1);
  long file2_size = ftell(file2);
  if (file1_size != file2_size) {
    return 0;
  }

  // Compare the contents of the files
  rewind(file1);
  rewind(file2);
  int c1, c2;
  while ((c1 = fgetc(file1)) != EOF && (c2 = fgetc(file2)) != EOF) {
    if (c1 != c2) {
      return 0;
    }
  }

  // If we reach the end of both files without finding any differences,
  // then the files are the same
  return 1;
}

// Main function
int main() {
  // Open the two files to be synchronized
  FILE *file1 = fopen("file1.txt", "r");
  FILE *file2 = fopen("file2.txt", "w");

  // Check if the files could be opened
  if (file1 == NULL || file2 == NULL) {
    printf("Error opening files\n");
    return 1;
  }

  // Compare the files
  int are_files_the_same = compare_files(file1, file2);

  // If the files are the same, print a happy message and exit
  if (are_files_the_same) {
    print_happy();
    fclose(file1);
    fclose(file2);
    return 0;
  }

  // If the files are not the same, copy the contents of file1 to file2
  char buffer[1024];
  while (fgets(buffer, sizeof(buffer), file1) != NULL) {
    fputs(buffer, file2);
  }

  // Close the files
  fclose(file1);
  fclose(file2);

  // Print a happy message
  print_happy();

  return 0;
}