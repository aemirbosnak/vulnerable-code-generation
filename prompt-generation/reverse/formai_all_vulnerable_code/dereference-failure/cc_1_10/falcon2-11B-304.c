//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read the header row from the CSV file
char** readHeader(const char* filename, int numColumns) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return NULL;
    }
    
    fseek(file, 0, SEEK_SET);
    char** header = malloc(numColumns * sizeof(char*));
    int column = 0;
    
    while (fgets(header[column], sizeof(char) * 100, file)!= NULL) {
        column++;
    }
    
    fclose(file);
    return header;
}

// Function to read and process each line of the CSV file
void readRow(const char* filename, const char** header, int numColumns, char** data) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }
    
    fseek(file, 0, SEEK_SET);
    int column = 0;
    
    while (fgets(data[column], sizeof(char) * 100, file)!= NULL) {
        column++;
    }
    
    fclose(file);
}

// Function to print the header row of the CSV file
void printHeader(const char** header) {
    printf("CSV Header:\n");
    
    for (int i = 0; i < 10; i++) {
        printf("%s\n", header[i]);
    }
}

// Function to print the data from a single line of the CSV file
void printData(const char** data, int numColumns) {
    printf("CSV Data:\n");
    
    for (int i = 0; i < numColumns; i++) {
        printf("%s\n", data[i]);
    }
}

// Function to print the data from all lines of the CSV file
void printDataAll(const char** header, const char** data, int numColumns) {
    printf("CSV Data:\n");
    
    for (int i = 0; i < 10; i++) {
        printf("Column %d:\n", i);
        
        for (int j = 0; j < numColumns; j++) {
            printf("%s\n", data[j][i]);
        }
    }
}

int main() {
    const char* filename = "example.csv";
    int numColumns = 5;
    
    char** header = readHeader(filename, numColumns);
    if (header == NULL) {
        return 1;
    }
    
    char** data = malloc(numColumns * sizeof(char*));
    for (int i = 0; i < numColumns; i++) {
        data[i] = malloc(100 * sizeof(char));
    }
    
    readRow(filename, header, numColumns, data);
    
    printHeader(header);
    printDataAll(header, data, numColumns);
    
    free(header);
    for (int i = 0; i < numColumns; i++) {
        free(data[i]);
    }
    free(data);
    
    return 0;
}