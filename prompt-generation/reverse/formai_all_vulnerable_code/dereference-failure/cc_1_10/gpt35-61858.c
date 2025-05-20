//FormAI DATASET v1.0 Category: Data mining ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  // initialize variables
  int numEntries = 0;
  char* filePath = NULL;
  char buffer[1024];
  FILE* dataFile = NULL;

  // get file path from user
  printf("Enter the path of the data file: ");
  fgets(buffer, sizeof(buffer), stdin);
  buffer[strlen(buffer) - 1] = '\0'; // remove newline character
  filePath = (char*) malloc(sizeof(char) * (strlen(buffer) + 1)); // allocate memory for file path
  strcpy(filePath, buffer); // copy file path into allocated memory

  // open data file
  dataFile = fopen(filePath, "r");
  if (dataFile == NULL) {
    printf("Failed to open file\n");
    return 1;
  }

  // count number of entries in data file
  while (fgets(buffer, sizeof(buffer), dataFile)) {
    numEntries++;
  }

  // reset file pointer to beginning of file
  fseek(dataFile, 0, SEEK_SET);

  // allocate memory for data array
  int** data = (int**) malloc(sizeof(int*) * numEntries);
  for (int i = 0; i < numEntries; i++) {
    data[i] = (int*) malloc(sizeof(int) * 3); // assume each entry has three integer values
  }

  // read data from file into array
  int entryCount = 0;
  while (fgets(buffer, sizeof(buffer), dataFile)) {
    int value1, value2, value3;
    sscanf(buffer, "%d,%d,%d", &value1, &value2, &value3);
    data[entryCount][0] = value1;
    data[entryCount][1] = value2;
    data[entryCount][2] = value3;
    entryCount++;
  }

  // close file
  fclose(dataFile);

  // perform data mining operation
  int sum = 0;
  for (int i = 0; i < numEntries; i++) {
    sum += data[i][0] + data[i][1] + data[i][2];
  }
  int average = sum / (numEntries * 3);
  printf("The average value is %d\n", average);

  // free memory
  for (int i = 0; i < numEntries; i++) {
    free(data[i]);
  }
  free(data);
  free(filePath);

  return 0;
}