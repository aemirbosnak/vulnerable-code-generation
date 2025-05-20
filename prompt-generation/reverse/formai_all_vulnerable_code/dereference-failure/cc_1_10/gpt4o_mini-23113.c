//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

typedef struct {
    char fields[MAX_FIELDS][MAX_LINE_LENGTH];
    int fieldCount;
} CSVRow;

typedef struct {
    CSVRow* rows;
    int rowCount;
} CSVData;

CSVData* createCSVData() {
    CSVData* data = (CSVData*)malloc(sizeof(CSVData));
    data->rows = NULL;
    data->rowCount = 0;
    return data;
}

void freeCSVData(CSVData* data) {
    if (data) {
        free(data->rows);
        free(data);
    }
}

void parseRow(char* line, CSVRow* row) {
    char* token;
    row->fieldCount = 0;

    token = strtok(line, ",");
    while (token && row->fieldCount < MAX_FIELDS) {
        strncpy(row->fields[row->fieldCount], token, MAX_LINE_LENGTH - 1);
        row->fields[row->fieldCount][MAX_LINE_LENGTH - 1] = '\0'; // Ensure null-terminated
        row->fieldCount++;
        token = strtok(NULL, ",");
    }
}

CSVData* readCSVFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    CSVData* csvData = createCSVData();
    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file)) {
        csvData->rows = realloc(csvData->rows, sizeof(CSVRow) * (csvData->rowCount + 1));
        parseRow(line, &csvData->rows[csvData->rowCount]);
        csvData->rowCount++;
    }

    fclose(file);
    return csvData;
}

void printCSVData(CSVData* data) {
    for (int i = 0; i < data->rowCount; i++) {
        for (int j = 0; j < data->rows[i].fieldCount; j++) {
            printf("%s", data->rows[i].fields[j]);
            if (j < data->rows[i].fieldCount - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }
}

void writeCSVData(const char* filename, CSVData* data) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file for writing");
        return;
    }

    for (int i = 0; i < data->rowCount; i++) {
        for (int j = 0; j < data->rows[i].fieldCount; j++) {
            fprintf(file, "%s", data->rows[i].fields[j]);
            if (j < data->rows[i].fieldCount - 1) {
                fputc(',', file);
            }
        }
        fputc('\n', file);
    }

    fclose(file);
}

void modifyCSVRow(CSVData* data, int rowIndex, int fieldIndex, const char* newValue) {
    if (rowIndex < 0 || rowIndex >= data->rowCount || fieldIndex < 0 || fieldIndex >= data->rows[rowIndex].fieldCount) {
        printf("Invalid row or field index\n");
        return;
    }
    strncpy(data->rows[rowIndex].fields[fieldIndex], newValue, MAX_LINE_LENGTH - 1);
    data->rows[rowIndex].fields[fieldIndex][MAX_LINE_LENGTH - 1] = '\0'; // Ensure null-terminated
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        return 1;
    }

    CSVData* csvData = readCSVFile(argv[1]);
    if (!csvData) {
        return 1;
    }

    printf("Original CSV Data:\n");
    printCSVData(csvData);

    // Modify: Change the first field of the first row if exists
    if (csvData->rowCount > 0 && csvData->rows[0].fieldCount > 0) {
        modifyCSVRow(csvData, 0, 0, "ModifiedValue");
    }

    printf("\nModified CSV Data:\n");
    printCSVData(csvData);

    writeCSVData("output.csv", csvData);

    freeCSVData(csvData);

    return 0;
}