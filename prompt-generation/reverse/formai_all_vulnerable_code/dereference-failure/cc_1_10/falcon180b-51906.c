//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

typedef struct {
    char *data;
    int length;
} Field;

typedef struct {
    int num_fields;
    Field fields[MAX_FIELDS];
} Row;

typedef struct {
    int num_rows;
    Row rows[MAX_FIELDS];
} CSV;

void csv_init(CSV *csv) {
    csv->num_rows = 0;
}

void csv_add_row(CSV *csv, Row row) {
    csv->rows[csv->num_rows++] = row;
}

CSV *csv_read_file(FILE *fp) {
    CSV *csv = malloc(sizeof(CSV));
    csv_init(csv);

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        char *token = strtok(line, ",");
        int num_fields = 0;
        while (token!= NULL) {
            if (num_fields >= MAX_FIELDS) {
                break;
            }
            Field field = {
               .data = token,
               .length = strlen(token)
            };
            csv->rows[csv->num_rows - 1].fields[num_fields++] = field;
            token = strtok(NULL, ",");
        }
        csv->rows[csv->num_rows - 1].num_fields = num_fields;
    }

    return csv;
}

void csv_print_header(CSV *csv) {
    for (int i = 0; i < csv->rows[0].num_fields; i++) {
        printf("%s\t", csv->rows[0].fields[i].data);
    }
    printf("\n");
}

void csv_print_row(CSV *csv, int row_num) {
    for (int i = 0; i < csv->rows[row_num].num_fields; i++) {
        printf("%s\t", csv->rows[row_num].fields[i].data);
    }
    printf("\n");
}

int main() {
    FILE *fp = fopen("data.csv", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    CSV *csv = csv_read_file(fp);
    fclose(fp);

    csv_print_header(csv);
    for (int i = 0; i < csv->num_rows; i++) {
        csv_print_row(csv, i);
    }

    return 0;
}