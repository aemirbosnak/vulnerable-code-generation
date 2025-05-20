//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CSVData {
    char** headers;
    char*** values;
    int numHeaders;
    int numRows;
} CSVData;

CSVData* readCSV(char* filename);

int main() {
    // Reading in the CSV file and storing the data into a CSVData struct
    CSVData* data = readCSV("example.csv");

    // Printing out the headers
    printf("CSV Headers: ");
    for (int i = 0; i < data->numHeaders; i++) {
        printf("%s | ", data->headers[i]);
    }
    printf("\n");

    // Printing out the values
    for (int i = 0; i < data->numRows; i++) {
        for (int j = 0; j < data->numHeaders; j++) {
            printf("%s | ", data->values[i][j]);
        }
        printf("\n");
    }

    // Freeing up memory
    for (int i = 0; i < data->numRows; i++) {
        free(data->values[i]);
    }
    free(data->values);
    for (int i = 0; i < data->numHeaders; i++) {
        free(data->headers[i]);
    }
    free(data->headers);
    free(data);

    return 0;
}

CSVData* readCSV(char* filename) {
    CSVData* data = (CSVData*) malloc(sizeof(CSVData));

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file.\n");
        exit(1);
    }

    // Reading in the headers
    char line[1024];
    fgets(line, 1024, file);
    char* token = strtok(line, ",");
    int numHeaders = 0;
    while (token != NULL) {
        data->headers[numHeaders] = (char*) malloc(strlen(token) + 1);
        strcpy(data->headers[numHeaders], token);
        numHeaders++;
        token = strtok(NULL, ",");
    }
    data->numHeaders = numHeaders;

    // Reading in the values
    char*** values = (char***) malloc(sizeof(char**) * 1024);
    char buffer[1024];
    int numRows = 0;
    while (fgets(buffer, 1024, file)) {
        char** fields = (char**) malloc(sizeof(char*) * numHeaders);
        token = strtok(buffer, ",");
        int fieldNum = 0;
        while (token != NULL) {
            fields[fieldNum] = (char*) malloc(strlen(token) + 1);
            strcpy(fields[fieldNum], token);
            fieldNum++;
            token = strtok(NULL, ",");
        }
        values[numRows] = fields;
        numRows++;
    }
    data->values = values;
    data->numRows = numRows;

    fclose(file);

    return data;
}