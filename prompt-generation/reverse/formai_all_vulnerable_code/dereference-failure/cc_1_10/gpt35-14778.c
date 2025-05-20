//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256
#define MAX_FIELDS 10

typedef struct {
    char* fields[MAX_FIELDS];
    int num_fields;
} CsvRow;

char* trim(char* token);

CsvRow* read_csv_row(FILE* file) {
    char buffer[MAX_LINE_LENGTH];
    char* token;
    CsvRow* row = NULL;

    if (fgets(buffer, MAX_LINE_LENGTH, file) != NULL) {
        row = (CsvRow*) malloc(sizeof(CsvRow));
        row->num_fields = 0;

        token = strtok(buffer, ",");
        while (token != NULL && row->num_fields < MAX_FIELDS) {
            row->fields[row->num_fields] = trim(token);
            row->num_fields++;
            token = strtok(NULL, ",");
        }
    }

    return row;
}

char* trim(char* token) {
    int len = strlen(token);
    while (len > 0 && (token[len - 1] == '\n' || token[len - 1] == '\r' || token[len - 1] == ' ')) {
        token[--len] = '\0';
    }
    return token;
}

int main() {
    FILE* file = fopen("example.csv", "r");

    if (file == NULL) {
        printf("Error: could not open file\n");
        exit(1);
    }

    CsvRow* row = read_csv_row(file);
    while (row != NULL) {
        printf("Number of fields: %d\n", row->num_fields);
        for (int i = 0; i < row->num_fields; i++) {
            printf("%s\n", row->fields[i]);
        }
        printf("\n");

        free(row);

        row = read_csv_row(file);
    }

    fclose(file);
    return 0;
}