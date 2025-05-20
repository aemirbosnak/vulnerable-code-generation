//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

// Function to read data from a file and store it in a 2D array
void readData(char *filePath, double **data) {
  FILE *file = fopen(filePath, "r");
  if (file == NULL) {
    printf("Error: unable to open file %s\n", filePath);
    return;
  }
  
  char line[1024];
  int i = 0;
  int j = 0;
  
  // Read lines from the file and store them in a 2D array
  while (fgets(line, 1024, file) != NULL) {
    // Skip empty lines and comments
    if (strcmp(line, "") != 0 && line[0] != '#') {
      data[i][j] = atof(line);
      j++;
      
      // Check if we reached the end of the line
      if (j >= 1024) {
        i++;
        j = 0;
      }
    }
  }
  
  fclose(file);
}

// Function to write data to a file
void writeData(char *filePath, double *data) {
  FILE *file = fopen(filePath, "w");
  if (file == NULL) {
    printf("Error: unable to open file %s\n", filePath);
    return;
  }
  
  int i = 0;
  for (int j = 0; j < 1024; j++) {
    fprintf(file, "%.8f ", data[i]);
    i++;
  }
  
  fclose(file);
}

int main() {
  // Define file paths and data
  char filePath1[] = "data1.txt";
  char filePath2[] = "data2.txt";
  double data1[] = {1.2, 3.4, 5.6, 7.8, 9.0};
  double data2[] = {10.0, 20.0, 30.0, 40.0, 50.0};
  
  // Read data from file1 and store it in data2
  double **data = (double**)malloc(sizeof(double*) * 2);
  data[0] = data1;
  data[1] = data2;
  readData(filePath1, data);
  
  // Write data to file2
  writeData(filePath2, data[1]);
  
  // Free memory
  free(data);
  
  return 0;
}