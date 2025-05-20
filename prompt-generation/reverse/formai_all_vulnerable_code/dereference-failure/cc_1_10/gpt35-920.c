//FormAI DATASET v1.0 Category: Data recovery tool ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the data structure that we will use to store the recovered data */
typedef struct {
  char* filename;
  char* data;
  size_t size;
} RecoveryFile;

/* Function to recover data from a file */
RecoveryFile* recoverDataFrom(char* filename) {
  FILE* file = fopen(filename, "r");
  if (!file) {
    printf("Could not open file %s for reading\n", filename);
    return NULL;
  }

  /* Determine the size of the file */
  fseek(file, 0L, SEEK_END);
  size_t fileSize = ftell(file);
  fseek(file, 0L, SEEK_SET);

  /* Allocate memory for the data */
  char* data = (char*)malloc(fileSize);

  /* Read the data from the file */
  size_t bytesRead = fread(data, 1, fileSize, file);
  if (bytesRead != fileSize) {
    printf("Error reading data from file %s\n", filename);
    free(data);
    fclose(file);
    return NULL;
  }

  /* Create the RecoveryFile struct */
  RecoveryFile* recoveryFile = (RecoveryFile*)malloc(sizeof(RecoveryFile));
  recoveryFile->filename = filename;
  recoveryFile->data = data;
  recoveryFile->size = fileSize;

  /* Close the file */
  fclose(file);

  /* Return the RecoveryFile */
  return recoveryFile;
}

/* Main function to recover data from multiple files */
int main(int argc, char** argv) {
  /* Check that at least one file was specified */
  if (argc < 2) {
    printf("Usage: recover <filename> [filename2 filename3 ...]\n");
    return EXIT_FAILURE;
  }

  /* Recover data from each file */
  RecoveryFile** recoveryFiles = (RecoveryFile**)malloc(sizeof(RecoveryFile*) * (argc - 1));
  int numFilesRecovered = 0;
  for (int i = 1; i < argc; i++) {
    RecoveryFile* recoveryFile = recoverDataFrom(argv[i]);
    if (recoveryFile != NULL) {
      recoveryFiles[numFilesRecovered++] = recoveryFile;
    }
  }

  /* Print out the recovered data */
  printf("Recovered data:\n");
  for (int i = 0; i < numFilesRecovered; i++) {
    printf("%-20s%-5ld\n", recoveryFiles[i]->filename, recoveryFiles[i]->size);
    printf("%s\n", recoveryFiles[i]->data);
    printf("\n");
  }

  /* Free the memory allocated for the data */
  for (int i = 0; i < numFilesRecovered; i++) {
    free(recoveryFiles[i]->data);
    free(recoveryFiles[i]);
  }
  free(recoveryFiles);

  /* Exit successfully */
  return EXIT_SUCCESS;
}