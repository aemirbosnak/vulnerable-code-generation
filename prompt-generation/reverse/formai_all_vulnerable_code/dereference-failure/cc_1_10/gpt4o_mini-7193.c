//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

// A structure for holding individual records
typedef struct {
    char **fields; // dynamic array of fields
    int field_count;
} Record;

typedef struct {
    Record *records; // dynamic array of records
    int record_count;
} CSVData;

// Function to initialize a new CSVData
CSVData* init_csv_data() {
    CSVData *data = (CSVData*)malloc(sizeof(CSVData));
    data->records = NULL;
    data->record_count = 0;
    return data;
}

// Function to free CSVData
void free_csv_data(CSVData *data) {
    for (int i = 0; i < data->record_count; i++) {
        for (int j = 0; j < data->records[i].field_count; j++) {
            free(data->records[i].fields[j]);
        }
        free(data->records[i].fields);
    }
    free(data->records);
    free(data);
}

// Function to split a line into fields
char** split_line(const char *line, int *field_count) {
    char *token;
    char *line_copy = strdup(line);
    char **fields = malloc(MAX_FIELDS * sizeof(char*));
    *field_count = 0;

    token = strtok(line_copy, ",");
    while (token != NULL && *field_count < MAX_FIELDS) {
        fields[*field_count] = strdup(token);
        (*field_count)++;
        token = strtok(NULL, ",");
    }

    free(line_copy);
    return fields;
}

// Function to read CSV file
CSVData* read_csv(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s for reading.\n", filename);
        exit(EXIT_FAILURE);
    }

    CSVData *data = init_csv_data();
    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file)) {
        // Remove the newline character if present
        line[strcspn(line, "\n")] = 0;

        data->records = realloc(data->records, (data->record_count + 1) * sizeof(Record));
        
        int field_count;
        data->records[data->record_count].fields = split_line(line, &field_count);
        data->records[data->record_count].field_count = field_count;
        data->record_count++;
    }

    fclose(file);
    return data;
}

// Function to print CSV data
void print_csv_data(CSVData *data) {
    for (int i = 0; i < data->record_count; i++) {
        for (int j = 0; j < data->records[i].field_count; j++) {
            printf("%s", data->records[i].fields[j]);
            if (j < data->records[i].field_count - 1) printf(", ");
        }
        printf("\n");
    }
}

// Main function: Shockingly simple yet effective!
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename.csv>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Starting to read the CSV file... Hold onto your hats!\n");
    CSVData *data = read_csv(argv[1]);
    printf("CSV file read successfully! Prepare to be amazed!\n");

    printf("Contents of the CSV file:\n");
    print_csv_data(data);

    free_csv_data(data);
    printf("All data has been freed. What a wild ride!\n");
    return EXIT_SUCCESS;
}