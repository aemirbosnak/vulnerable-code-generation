//FormAI DATASET v1.0 Category: Data recovery tool ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Shape shifting function
void shapeShift(char *data, int size) {
  int i;
  char temp;

  for(i = 0; i < size / 2; i++) {
    temp = data[i];
    data[i] = data[size - i - 1];
    data[size - i - 1] = temp;
  }
}

int main() {
  FILE *fp;
  char fileName[50], *data;
  int fileSize, i;

  printf("Enter file name: ");
  scanf("%s", fileName);

  // Open file in binary mode
  fp = fopen(fileName, "rb");

  // Check if file exists
  if(fp == NULL) {
    printf("File does not exist!");
    exit(0);
  }

  // Determine file size
  fseek(fp, 0, SEEK_END);
  fileSize = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  // Allocate memory for data
  data = (char*) malloc(fileSize);

  // Read data from file
  fread(data, 1, fileSize, fp);

  // Shape shift the data
  shapeShift(data, fileSize);

  // Print the recovered data
  for(i = 0; i < fileSize; i++) {
    printf("%c", data[i]);
  }

  // Close file and free memory
  fclose(fp);
  free(data);

  return 0;
}