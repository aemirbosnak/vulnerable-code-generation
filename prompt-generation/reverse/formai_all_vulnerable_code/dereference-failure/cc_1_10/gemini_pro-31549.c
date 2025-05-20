//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    size_t len;
} CSVRow;

typedef struct {
    FILE *fp;
    char delim;
    CSVRow row;
} CSVReader;

CSVReader *csv_reader_new(FILE *fp, char delim) {
    CSVReader *reader = malloc(sizeof(CSVReader));
    if (!reader) return NULL;
    reader->fp = fp;
    reader->delim = delim;
    reader->row.data = NULL;
    reader->row.len = 0;
    return reader;
}

void csv_reader_free(CSVReader *reader) {
    free(reader->row.data);
    free(reader);
}

int csv_reader_next(CSVReader *reader) {
    int c;
    size_t i = 0;

    // Free the old row data
    free(reader->row.data);

    // Read until the end of the line or the end of the file
    while ((c = fgetc(reader->fp)) != EOF && c != '\n') {
        // Reallocate the row data if necessary
        if (i >= reader->row.len) {
            reader->row.len *= 2;
            reader->row.data = realloc(reader->row.data, reader->row.len);
            if (!reader->row.data) return -1;
        }

        // Store the character in the row data
        reader->row.data[i++] = c;
    }

    // Add the null terminator
    reader->row.data[i++] = '\0';

    // Return the number of characters read
    return i;
}

char *csv_reader_get_field(CSVReader *reader, int field) {
    char *start = reader->row.data;
    char *end = start;

    // Iterate over the row data until we reach the end or the desired field
    while (*end && field--) {
        start = end + 1;
        while (*end && *end != reader->delim) end++;
    }

    // Return the field data or NULL if the field does not exist
    if (*end) {
        *end = '\0';
        return start;
    } else {
        return NULL;
    }
}

int main(int argc, char **argv) {
    // Open the CSV file
    FILE *fp = fopen("data.csv", "r");
    if (!fp) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Create the CSV reader
    CSVReader *reader = csv_reader_new(fp, ',');
    if (!reader) {
        perror("csv_reader_new");
        return EXIT_FAILURE;
    }

    // Read the CSV file and print the first 10 rows
    int row_count = 0;
    while (csv_reader_next(reader) != EOF) {
        printf("Row %d:\n", ++row_count);
        printf("  Field 1: %s\n", csv_reader_get_field(reader, 0));
        printf("  Field 2: %s\n", csv_reader_get_field(reader, 1));
        printf("  Field 3: %s\n", csv_reader_get_field(reader, 2));
        printf("\n");
        if (row_count >= 10) break;
    }

    // Free the CSV reader and close the file
    csv_reader_free(reader);
    fclose(fp);

    return EXIT_SUCCESS;
}