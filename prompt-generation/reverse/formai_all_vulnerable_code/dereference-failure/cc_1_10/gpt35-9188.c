//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CSV_FIELDS 50
#define MAX_CSV_LINE_LENGTH 1024

struct csv_row {
    char **fields;
    int num_fields;
};

struct csv_reader {
    FILE *fp;
    int has_header;
    char *delim;
    char header[MAX_CSV_LINE_LENGTH];
};

void print_csv_row(struct csv_row row) {
    int i;
    for (i = 0; i < row.num_fields; i++) {
        printf("%s ", row.fields[i]);
    }
    printf("\n");
}

void free_csv_row(struct csv_row row) {
    int i;
    for (i = 0; i < row.num_fields; i++) {
        free(row.fields[i]);
    }
    free(row.fields);
}

struct csv_reader create_csv_reader(char *filename, int has_header, char *delim) {
    struct csv_reader reader;
    reader.fp = fopen(filename, "r");
    reader.has_header = has_header;
    reader.delim = delim;
    if (has_header) {
        if (fgets(reader.header, MAX_CSV_LINE_LENGTH, reader.fp) == NULL) {
            fprintf(stderr, "Error: could not read header from CSV file\n");
            exit(1);
        }
    }
    return reader;
}

struct csv_row read_csv_row(struct csv_reader reader) {
    struct csv_row row;
    row.fields = malloc(MAX_CSV_FIELDS * sizeof(char*));
    char line[MAX_CSV_LINE_LENGTH];
    if (fgets(line, MAX_CSV_LINE_LENGTH, reader.fp) == NULL) {
        row.num_fields = 0;
        return row;
    }
    char *ptr = strtok(line, reader.delim);
    int i = 0;
    while (ptr != NULL && i < MAX_CSV_FIELDS) {
        row.fields[i] = malloc((strlen(ptr) + 1) * sizeof(char));
        strcpy(row.fields[i], ptr);
        ptr = strtok(NULL, reader.delim);
        i++;
    }
    row.num_fields = i;
    return row;
}

int main(void) {
    struct csv_reader reader = create_csv_reader("example.csv", 1, ",");
    if (reader.has_header) {
        printf("Header: %s", reader.header);
    }
    struct csv_row row;
    while ((row = read_csv_row(reader)).num_fields > 0) {
        print_csv_row(row);
        free_csv_row(row);
    }
    fclose(reader.fp);
    return 0;
}