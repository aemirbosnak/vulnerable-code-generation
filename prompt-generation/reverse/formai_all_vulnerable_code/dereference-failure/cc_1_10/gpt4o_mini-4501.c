//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

typedef struct {
    char **fields;
    int field_count;
} CSVRow;

typedef struct {
    CSVRow *rows;
    int row_count;
} CSVData;

CSVData* create_csv_data(int initial_size) {
    CSVData *data = (CSVData *)malloc(sizeof(CSVData));
    data->rows = (CSVRow *)malloc(sizeof(CSVRow) * initial_size);
    data->row_count = 0;
    return data;
}

void free_csv_data(CSVData *data) {
    for(int i = 0; i < data->row_count; i++) {
        for(int j = 0; j < data->rows[i].field_count; j++) {
            free(data->rows[i].fields[j]);
        }
        free(data->rows[i].fields);
    }
    free(data->rows);
    free(data);
}

char** split_line(char *line, int *field_count) {
    char **fields = (char **)malloc(sizeof(char *) * MAX_FIELDS);
    char *token = strtok(line, ",");
    *field_count = 0;

    while (token != NULL && *field_count < MAX_FIELDS) {
        fields[*field_count] = (char *)malloc(strlen(token) + 1);
        strcpy(fields[*field_count], token);
        (*field_count)++;
        token = strtok(NULL, ",");
    }
    return fields;
}

void read_csv(const char *filename, CSVData *data) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        CSVRow row;
        row.fields = split_line(line, &row.field_count);
        data->rows[data->row_count++] = row;
    }

    fclose(file);
}

void print_csv_data(const CSVData *data) {
    for (int i = 0; i < data->row_count; i++) {
        for (int j = 0; j < data->rows[i].field_count; j++) {
            printf("%s", data->rows[i].fields[j]);
            if (j < data->rows[i].field_count - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }
}

void write_csv(const char *filename, const CSVData *data) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Cannot open file to write");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < data->row_count; i++) {
        for (int j = 0; j < data->rows[i].field_count; j++) {
            fprintf(file, "%s", data->rows[i].fields[j]);
            if (j < data->rows[i].field_count - 1) {
                fprintf(file, ",");
            }
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

void save_to_csv_file(const char *input_file, const char *output_file) {
    CSVData *data = create_csv_data(10);
    read_csv(input_file, data);
    print_csv_data(data);
    write_csv(output_file, data);
    free_csv_data(data);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.csv> <output.csv>\n", argv[0]);
        return EXIT_FAILURE;
    }

    save_to_csv_file(argv[1], argv[2]);
    printf("CSV data has been read from %s and written to %s successfully.\n", argv[1], argv[2]);

    return EXIT_SUCCESS;
}