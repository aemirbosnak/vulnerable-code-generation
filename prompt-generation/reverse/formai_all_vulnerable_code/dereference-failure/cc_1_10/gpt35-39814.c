//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// function to get the number of rows in the csv file
int get_num_rows(FILE *file) {
  int count = 0; // initialize count
  char c;
  // loop through the file and count the new lines
  do {
    c = fgetc(file);
    if (c == '\n') count++;
  } while (c != EOF);
  // rewind the file pointer to the beginning
  rewind(file);
  return count;
}

// function to get the number of columns in the csv file
int get_num_cols(char *line) {
  int count = 0; // initialize count
  char *token = strtok(line, ",");
  // loop through the line and count the commas
  while (token != NULL) {
    count++;
    token = strtok(NULL, ",");
  }
  return count;
}

int main() {
  FILE *file = fopen("example.csv", "r"); // open the csv file for reading
  if (file == NULL) { // check for errors opening the file
    printf("Error: could not open file!\n");
    return 1;
  }

  int num_rows = get_num_rows(file); // get the number of rows in the csv file
  char line[1024]; // initialize a buffer for reading lines
  fgets(line, 1024, file); // read the first line to get the number of columns
  int num_cols = get_num_cols(line); // get the number of columns in the csv file

  char ***data = (char ***)malloc(sizeof(char **) * num_rows); // allocate memory for the data array
  for (int i = 0; i < num_rows; i++) {
    data[i] = (char **)malloc(sizeof(char *) * num_cols);
    for (int j = 0; j < num_cols; j++) {
      data[i][j] = (char *)malloc(sizeof(char) * 256);
    }
  }

  // loop through the file and store the csv data in the data array
  for (int i = 0; i < num_rows; i++) {
    fgets(line, 1024, file); // read a line from the file
    char *token = strtok(line, ",");
    for (int j = 0; j < num_cols; j++) {
      if (token == NULL) {
        strcpy(data[i][j], "");
      } else {
        strcpy(data[i][j], token);
        token = strtok(NULL, ",");
      }
    }
  }

  // print out the data array
  for (int i = 0; i < num_rows; i++) {
    for (int j = 0; j < num_cols; j++) {
      printf("%s,", data[i][j]);
    }
    printf("\n");
  }

  // free the memory used by the data array
  for (int i = 0; i < num_rows; i++) {
    for (int j = 0; j < num_cols; j++) {
      free(data[i][j]);
    }
    free(data[i]);
  }
  free(data);

  fclose(file); // close the file
  return 0; // exit the program
}