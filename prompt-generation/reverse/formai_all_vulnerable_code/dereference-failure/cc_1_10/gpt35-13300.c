//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100000
#define MAX_COLS 100

typedef struct {
    char* data[MAX_COLS];
    int num_cols;
} csv_row;

typedef struct {
    csv_row rows[MAX_ROWS];
    int num_rows;
} csv_data;

int read_csv(char* filename, csv_data* data);
void parse_csv_row(char* row, csv_row* parsed_row);

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        exit(1);
    }

    csv_data data;
    int num_rows = read_csv(argv[1], &data);

    printf("%d rows read from file %s:\n", num_rows, argv[1]);
    for (int i = 0; i < data.num_rows; i++) {
        csv_row row = data.rows[i];
        for (int j = 0; j < row.num_cols; j++) {
            printf("%s,", row.data[j]);
        }
        printf("\n");
    }

    return 0;
}

int read_csv(char* filename, csv_data* data) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(1);
    }

    int num_rows = 0;
    char buffer[1024];
    while (fgets(buffer, 1024, file) != NULL) {
        csv_row row;
        parse_csv_row(buffer, &row);
        data->rows[num_rows] = row;
        num_rows++;
    }

    data->num_rows = num_rows;

    fclose(file);
    return num_rows;
}

void parse_csv_row(char* row, csv_row* parsed_row) {
    char* saveptr;
    char* token = strtok_r(row, ",", &saveptr);
    int num_cols = 0;
    while (token != NULL) {
        parsed_row->data[num_cols] = malloc(strlen(token) + 1);
        strcpy(parsed_row->data[num_cols], token);
        num_cols++;
        token = strtok_r(NULL, ",", &saveptr);
    }
    parsed_row->num_cols = num_cols;
}