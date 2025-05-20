//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: introspective
// The C Building a CSV Reader program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store row data
typedef struct {
    char *name;
    int age;
    char *city;
} RowData;

// Function to read a row from CSV
RowData* readRow(FILE *csvFile, char **row) {
    char *name = NULL;
    int age = 0;
    char *city = NULL;
    
    // Read name from row
    if (fscanf(csvFile, "%s", row)!= 1) {
        fprintf(stderr, "Error reading name from row\n");
        return NULL;
    }
    name = strdup(*row);
    
    // Read age from row
    if (fscanf(csvFile, "%d", &age)!= 1) {
        fprintf(stderr, "Error reading age from row\n");
        free(name);
        return NULL;
    }
    
    // Read city from row
    if (fscanf(csvFile, "%s", row)!= 1) {
        fprintf(stderr, "Error reading city from row\n");
        free(name);
        free(age);
        return NULL;
    }
    city = strdup(*row);
    
    // Create row data and return
    RowData *rowData = malloc(sizeof(RowData));
    rowData->name = name;
    rowData->age = age;
    rowData->city = city;
    return rowData;
}

// Function to print a row data
void printRow(RowData *rowData) {
    printf("Name: %s\n", rowData->name);
    printf("Age: %d\n", rowData->age);
    printf("City: %s\n", rowData->city);
}

// Main function
int main() {
    // Open CSV file
    FILE *csvFile = fopen("data.csv", "r");
    if (csvFile == NULL) {
        fprintf(stderr, "Error opening CSV file\n");
        return 1;
    }
    
    // Create a row buffer
    char *row = malloc(100);
    if (row == NULL) {
        fprintf(stderr, "Error allocating memory for row buffer\n");
        fclose(csvFile);
        return 1;
    }
    
    // Create a row data buffer
    RowData *rowData = NULL;
    while (fscanf(csvFile, "%s,%d,%s", row, &rowData->age, row) == 3) {
        // Read a row from CSV
        rowData = readRow(csvFile, row);
        if (rowData == NULL) {
            free(row);
            fclose(csvFile);
            return 1;
        }
        
        // Print the row data
        printRow(rowData);
        
        // Free the row data
        free(row);
        free(rowData);
        
        // Allocate memory for the next row
        row = malloc(100);
    }
    
    // Free the row data
    free(rowData);
    free(row);
    
    // Close the CSV file
    fclose(csvFile);
    
    return 0;
}