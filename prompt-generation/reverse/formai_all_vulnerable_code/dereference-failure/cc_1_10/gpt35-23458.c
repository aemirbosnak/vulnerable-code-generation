//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

typedef struct csv_record {
    char **fields;
    int num_fields;
} csv_record;

typedef struct csv_reader {
    FILE *file;
    char *delim;
    int num_cols;
} csv_reader;

csv_reader* csv_reader_create(const char *filename, const char *delim, int num_cols) {
    csv_reader *reader = malloc(sizeof(csv_reader));
    reader->file = fopen(filename, "r");
    reader->delim = strdup(delim);
    reader->num_cols = num_cols;
    return reader;
}

void csv_reader_destroy(csv_reader *reader) {
    fclose(reader->file);
    free(reader->delim);
    free(reader);
}

int csv_reader_read_record(csv_reader *reader, csv_record **record) {
    char buffer[MAX_LINE_LEN];
    if (fgets(buffer, MAX_LINE_LEN, reader->file) == NULL) {
        return 0;
    }

    // Count number of delimiters in line
    int num_delims = 0;
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == reader->delim[0]) {
            num_delims++;
        }
    }

    // Check if number of delimiters matches expected number of columns
    if (num_delims + 1 != reader->num_cols) {
        return -1;
    }

    // Split line by delimiter
    char **fields = malloc(sizeof(char*) * (num_delims + 1));
    fields[0] = strtok(buffer, reader->delim);
    for (int i = 1; i < num_delims + 1; i++) {
        fields[i] = strtok(NULL, reader->delim);
    }

    // Create new record object
    *record = malloc(sizeof(csv_record));
    (*record)->num_fields = num_delims + 1;
    (*record)->fields = fields;

    return 1;
}

int main() {
    csv_reader *reader = csv_reader_create("data.csv", ",", 3);

    csv_record *record;
    while (csv_reader_read_record(reader, &record) == 1) {
        printf("Record: ");
        for (int i = 0; i < record->num_fields; i++) {
            printf("%s ", record->fields[i]);
        }
        printf("\n");
        free(record->fields);
        free(record);
    }

    csv_reader_destroy(reader);

    return 0;
}