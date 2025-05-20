//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 20
#define DELIMITER ","

typedef struct {
    char *fields[MAX_FIELDS];
    int num_fields;
} Row;

typedef struct {
    Row *rows;
    int num_rows;
    int num_fields;
} CsvData;

CsvData read_csv(char *filename) {
    CsvData csv_data;
    csv_data.num_rows = 0;
    csv_data.num_fields = 0;
    csv_data.rows = NULL;

    FILE *fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Could not open file: %s\n", filename);
        return csv_data;
    }

    char line[MAX_LINE_LENGTH];
    int line_num = 0;
    while(fgets(line, MAX_LINE_LENGTH, fp)) {
        line_num++;
        line[strcspn(line, "\n")] = 0;   // remove newline character

        char *token = strtok(line, DELIMITER);
        int field_num = 0;
        Row row;
        row.num_fields = 0;
        row.fields[row.num_fields++] = strdup(token);

        while(token != NULL) {
            token = strtok(NULL, DELIMITER);
            if (token != NULL) {
                row.fields[row.num_fields++] = strdup(token);
            }
            field_num++;
        }

        if(line_num == 1) {     // header row
            csv_data.num_fields = row.num_fields;
        }
        else if(row.num_fields != csv_data.num_fields) {  // check for inconsistent row lengths
            printf("Error on line %d: Inconsistent row length\n", line_num);
            free(csv_data.rows);
            csv_data.num_rows = 0;
            csv_data.num_fields = 0;
            csv_data.rows = NULL;
            return csv_data;
        }
        else {  // add row to csv data
            csv_data.num_rows++;
            csv_data.rows = realloc(csv_data.rows, csv_data.num_rows * sizeof(Row));
            csv_data.rows[csv_data.num_rows - 1] = row;
        }
    }

    fclose(fp);
    return csv_data;
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: csv_reader <filename>\n");
        return 1;
    }

    CsvData csv_data = read_csv(argv[1]);

    if(csv_data.num_rows == 0) {
        return 1;
    }

    printf("%d rows, %d fields\n", csv_data.num_rows, csv_data.num_fields);

    // print header row
    for(int i = 0; i < csv_data.num_fields; i++) {
        printf("%s\t", csv_data.rows[0].fields[i]);
    }
    printf("\n");

    // print data rows
    for(int i = 1; i < csv_data.num_rows; i++) {
        for(int j = 0; j < csv_data.num_fields; j++) {
            printf("%s\t", csv_data.rows[i].fields[j]);
        }
        printf("\n");
    }

    // free memory
    for(int i = 0; i < csv_data.num_rows; i++) {
        for(int j = 0; j < csv_data.rows[i].num_fields; j++) {
            free(csv_data.rows[i].fields[j]);
        }
    }
    free(csv_data.rows);

    return 0;
}