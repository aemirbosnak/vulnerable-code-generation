//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FIELD_LENGTH 100

typedef struct csvData {
    int numFields;
    char **fields;
} csvData;

int countFields(char *line) {
    int count = 1;
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == ',') {
            count++;
        }
    }
    return count;
}

void readFields(char *line, csvData *data) {
    char *field = strtok(line, ",");
    int i = 0;
    while (field != NULL) {
        data->fields[i] = malloc(sizeof(char) * MAX_FIELD_LENGTH);
        strcpy(data->fields[i], field);
        field = strtok(NULL, ",");
        i++;
    }
}

csvData *readCSV(char *filename) {
    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    csvData *data = malloc(sizeof(csvData));
    char line[MAX_LINE_LENGTH];
    fgets(line, MAX_LINE_LENGTH, file);
    data->numFields = countFields(line);
    data->fields = malloc(sizeof(char*) * data->numFields);
    readFields(line, data);
    int i = 0;
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        data = realloc(data, sizeof(csvData) * (i + 2));
        readFields(line, &data[i + 1]);
        i++;
    }
    fclose(file);
    return data;
}

int main() {
    csvData *data = readCSV("example.csv");
    for (int i = 0; i < data->numFields; i++) {
        printf("%s ", data->fields[i]);
    }
    printf("\n");
    for (int i = 1; i <= 3; i++) {
        for (int j = 0; j < data->numFields; j++) {
            printf("%s ", data[i].fields[j]);
        }
        printf("\n");
    }
    for (int i = 0; i < data->numFields; i++) {
        free(data->fields[i]);
    }
    free(data->fields);
    free(data);
    return 0;
}