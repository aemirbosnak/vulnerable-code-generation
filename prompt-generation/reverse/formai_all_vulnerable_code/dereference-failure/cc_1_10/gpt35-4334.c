//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for your CSV data
typedef struct {
    int id;
    char name[50];
    int age;
} CSVData;

// Define a function that takes a line of CSV and returns a CSVData struct
CSVData parseCSVLine(char *line) {
    CSVData data;
    char *field;
    field = strtok(line, ",");
    data.id = atoi(field);
    field = strtok(NULL, ",");
    strcpy(data.name, field);
    field = strtok(NULL, ",");
    data.age = atoi(field);
    return data;
}

// Define a function that reads the CSV file and returns an array of CSVData structs
CSVData* readCSV(char *filename, int *numElements) {
    char line[1024];
    CSVData *data = malloc(100 * sizeof(CSVData));
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file: %s\n", filename);
        exit(1);
    }
    int i = 0;
    fgets(line, 1024, file);
    while (fgets(line, 1024, file) != NULL) {
        data[i++] = parseCSVLine(line);
    }
    *numElements = i;
    fclose(file);
    return data;
}

// Define a function that prints the CSVData array
void printCSVData(CSVData *data, int numElements) {
    for (int i = 0; i < numElements; i++) {
        printf("%d,%s,%d\n", data[i].id, data[i].name, data[i].age);
    }
}

int main(void) {
    int numElements;
    CSVData *data = readCSV("example.csv", &numElements);
    printCSVData(data, numElements);
    free(data);
    return 0;
}