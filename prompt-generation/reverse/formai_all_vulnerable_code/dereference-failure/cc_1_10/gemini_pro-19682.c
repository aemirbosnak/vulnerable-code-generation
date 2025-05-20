//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to recover data from a file
int recover_data(char *filename) {
  // Open the file for reading
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error opening file %s", filename);
    return -1;
  }

  // Read the file contents into a buffer
  fseek(fp, 0, SEEK_END);
  long fsize = ftell(fp);
  fseek(fp, 0, SEEK_SET);
  char *buffer = malloc(fsize + 1);
  fread(buffer, fsize, 1, fp);
  fclose(fp);

  // Search the buffer for the data
  char *start = strstr(buffer, "START_DATA");
  char *end = strstr(buffer, "END_DATA");
  if (start == NULL || end == NULL) {
    printf("Data not found in file %s", filename);
    return -1;
  }

  // Write the data to a new file
  fp = fopen("recovered_data.txt", "w");
  if (fp == NULL) {
    printf("Error opening file recovered_data.txt");
    return -1;
  }
  fwrite(start + strlen("START_DATA"), end - start - strlen("END_DATA"), 1, fp);
  fclose(fp);

  // Free the buffer
  free(buffer);

  return 0;
}

int main() {
  // Get the filename from the user
  char filename[256];
  printf("Enter the name of the file to recover data from: ");
  scanf("%s", filename);

  // Recover the data from the file
  int result = recover_data(filename);
  if (result == 0) {
    printf("Data recovered successfully.\n");
  } else {
    printf("Error recovering data.\n");
  }

  return 0;
}