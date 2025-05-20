//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 20
#define MAX_COL_NAME_LEN 50
#define MAX_LINE_LEN 1000

typedef enum { INT, FLOAT, STRING } DataType;

typedef struct {
    char colName[MAX_COL_NAME_LEN];
    DataType dataType;
    int index;
} Column;

typedef struct {
    Column* columns;
    int numColumns;
    char* filename;
} Csv;

Csv* readCsvFile(char* filename);
int getColumns(char* line, Csv* csv);
void parseLine(char* line, Csv* csv);
void printCsv(Csv* csv);

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Error: no filename provided\n");
        return -1;
    }
    Csv* csv = readCsvFile(argv[1]);
    if (csv == NULL) {
        printf("Error: could not read file\n");
        return -1;
    }
    printCsv(csv);
}

Csv* readCsvFile(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }
    Csv* csv = (Csv*) malloc(sizeof(Csv));
    csv->filename = filename;
    csv->numColumns = 0;
    csv->columns = (Column*) malloc(MAX_COLS * sizeof(Column));
    char line[MAX_LINE_LEN];
    int isFirstLine = 1;
    while (fgets(line, MAX_LINE_LEN, file) != NULL) {
        if (isFirstLine) {
            isFirstLine = 0;
            getColumns(line, csv);
        } else {
            parseLine(line, csv);
        }
    }
    fclose(file);
    return csv;
}

int getColumns(char* line, Csv* csv) {
    char* tok;
    int i = 0;
    while ((tok = strtok(i == 0 ? line : NULL, ",")) != NULL) {
        if (i >= MAX_COLS) {
            return -1;
        }
        Column col;
        strncpy(col.colName, tok, MAX_COL_NAME_LEN);
        if (strstr(tok, "INT")) {
            col.dataType = INT;
        } else if (strstr(tok, "FLOAT")) {
            col.dataType = FLOAT;
        } else {
            col.dataType = STRING;
        }
        col.index = i;
        csv->columns[i++] = col;
    }
    csv->numColumns = i;
    return i;
}

void parseLine(char* line, Csv* csv) {
    char* tok;
    int i = 0;
    while ((tok = strtok(i == 0 ? line : NULL, ",")) != NULL) {
        switch (csv->columns[i].dataType) {
            case INT:
                printf("%d ", atoi(tok));
                break;
            case FLOAT:
                printf("%.2f ", atof(tok));
                break;
            case STRING:
                printf("%s ", tok);
                break;
        }
        i++;
    }
    printf("\n");
}

void printCsv(Csv* csv) {
    printf("Filename: %s\n", csv->filename);
    for (int i = 0; i < csv->numColumns; i++) {
        printf("%s ", csv->columns[i].colName);
    }
    printf("\n");
    FILE* file = fopen(csv->filename, "r");
    if (file == NULL) {
        return;
    }
    char line[MAX_LINE_LEN];
    int isFirstLine = 1;
    while (fgets(line, MAX_LINE_LEN, file) != NULL) {
        if (!isFirstLine) {
            parseLine(line, csv);
        }
        isFirstLine = 0;
    }
    fclose(file);
}