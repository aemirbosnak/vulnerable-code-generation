//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the struct for the CSV data */
typedef struct {
  char *name;
  int age;
  char *occupation;
  float salary;
} CsvData;

/* Function to read the CSV file and store data in an array of CsvData structs */
CsvData* readCsv(char* filename, int* numRecords) {
  int bufferSize = 1024; // maximum buffer size
  char buffer[bufferSize]; // buffer to hold input
  int recordCount = 0; // count of records read in
  CsvData* data = malloc(bufferSize*sizeof(CsvData)); // allocate memory for CsvData array

  /* Attempt to open the CSV file */
  FILE *csvFile = fopen(filename, "r");

  /* Check if the file was opened successfully */
  if (csvFile == NULL) {
    printf("Error: Could not open file '%s'\n", filename);
    exit(1);
  }

  /* Loop through each line in the CSV file */
  while (fgets(buffer, bufferSize, csvFile) != NULL) {
    /* Tokenize the line based on commas */
    char *token = strtok(buffer, ",");
    int i = 0; // index for parsing tokens in line

    /* Create a new CsvData struct */
    CsvData record;

    /* Loop through the tokens */
    while (token != NULL) {
      /* Parse the token based on the column index */
      switch (i) {
        case 0: // name
          record.name = malloc(strlen(token)+1);
          strcpy(record.name, token);
          break;
        case 1: // age
          record.age = atoi(token);
          break;
        case 2: // occupation
          record.occupation = malloc(strlen(token)+1);
          strcpy(record.occupation, token);
          break;
        case 3: // salary
          record.salary = atof(token);
          break;
        default:
          printf("Error: Invalid CSV format\n");
          exit(1);
      }

      /* Move to the next token */
      token = strtok(NULL, ",");
      i++;
    }

    /* Add the record to the data array */
    data[recordCount] = record;
    recordCount++;

    /* Increase the buffer size if necessary */
    if (recordCount == bufferSize) {
      bufferSize *= 2;
      data = realloc(data, bufferSize*sizeof(CsvData));
    }
  }

  /* Close the CSV file */
  fclose(csvFile);

  /* Set the number of records in the output parameter */
  *numRecords = recordCount;

  /* Return the array of CsvData structs */
  return data;
}

int main() {
  /* Read the CSV data from the file */
  int numRecords;
  CsvData* data = readCsv("example.csv", &numRecords);

  /* Print the CsvData records */
  printf("Name\t\tAge\tOccupation\tSalary\n");
  for (int i = 0; i < numRecords; i++) {
    printf("%s\t%d\t%s\t\t%.2f\n", data[i].name, data[i].age, data[i].occupation, data[i].salary);
  }

  /* Free allocated memory */
  for (int i = 0; i < numRecords; i++) {
    free(data[i].name);
    free(data[i].occupation);
  }
  free(data);

  return 0;
}