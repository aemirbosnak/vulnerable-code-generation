//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 100

typedef struct {
    char **data;
    int num_rows;
    int num_columns;
} CSV;

CSV *csv_create(void) {
    CSV *csv = (CSV *) malloc(sizeof(CSV));
    csv->data = (char **) malloc(MAX_COLUMNS * sizeof(char *));
    csv->num_rows = 0;
    csv->num_columns = 0;
    return csv;
}

void csv_destroy(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_columns; j++) {
            free(csv->data[i]);
        }
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int csv_read_file(CSV *csv, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        return -1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        char *token = strtok(line, ",");
        int num_tokens = 0;

        while (token!= NULL) {
            csv->data[csv->num_rows] = (char *) malloc((strlen(token) + 1) * sizeof(char));
            strcpy(csv->data[csv->num_rows], token);
            csv->num_columns = csv->num_columns > num_tokens? csv->num_columns : num_tokens;
            csv->num_rows++;
            num_tokens++;

            token = strtok(NULL, ",");
        }
    }

    fclose(fp);
    return 0;
}

void csv_print_data(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_columns; j++) {
            printf("%s\t", csv->data[i]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    CSV *csv = csv_create();

    if (csv_read_file(csv, "data.csv")!= 0) {
        csv_destroy(csv);
        return -1;
    }

    csv_print_data(csv);

    csv_destroy(csv);

    return 0;
}