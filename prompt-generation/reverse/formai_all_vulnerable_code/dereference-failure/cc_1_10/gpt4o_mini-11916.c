//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

typedef struct {
    char** fields;
    int field_count;
} CSVRecord;

typedef struct {
    CSVRecord* records;
    int record_count;
} CSVData;

// Function to initialize a CSVRecord
CSVRecord* create_record() {
    CSVRecord* record = malloc(sizeof(CSVRecord));
    record->fields = malloc(MAX_FIELDS * sizeof(char*));
    record->field_count = 0;
    return record;
}

// Function to free a CSVRecord
void free_record(CSVRecord* record) {
    for (int i = 0; i < record->field_count; i++) {
        free(record->fields[i]);
    }
    free(record->fields);
    free(record);
}

// Function to initialize CSVData
CSVData* create_csv_data() {
    CSVData* data = malloc(sizeof(CSVData));
    data->records = malloc(MAX_LINE_LENGTH * sizeof(CSVRecord));
    data->record_count = 0;
    return data;
}

// Function to free CSVData
void free_csv_data(CSVData* data) {
    for (int i = 0; i < data->record_count; i++) {
        free_record(&data->records[i]);
    }
    free(data->records);
    free(data);
}

// Function to trim whitespace from a string
char* trim_whitespace(char* str) {
    char* end;

    // Trim leading space
    while (isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    // Null terminate after the last non-whitespace character
    *(end + 1) = '\0';

    return str;
}

// Function to parse a CSV line into a CSVRecord
CSVRecord* parse_csv_line(char* line) {
    CSVRecord* record = create_record();
    char* token;
    const char* delimiter = ",";

    token = strtok(line, delimiter);
    while (token != NULL) {
        record->fields[record->field_count] = strdup(trim_whitespace(token));
        record->field_count++;
        token = strtok(NULL, delimiter);
    }
    return record;
}

// Function to read a CSV file and return its content as CSVData
CSVData* read_csv_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        return NULL;
    }

    CSVData* data = create_csv_data();
    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file)) {
        // Remove newline character
        line[strcspn(line, "\n")] = 0;
        CSVRecord* record = parse_csv_line(line);
        data->records[data->record_count] = *record; // Copy the record
        data->record_count++;
        free(record); // Free temporary record
    }

    fclose(file);
    return data;
}

// Function to print CSVData to stdout
void print_csv_data(CSVData* data) {
    for (int i = 0; i < data->record_count; i++) {
        CSVRecord record = data->records[i];
        for (int j = 0; j < record.field_count; j++) {
            printf("%s", record.fields[j]);
            if (j < record.field_count - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }
}

// Main function to demonstrate CSV reading and printing
int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char* filename = argv[1];
    CSVData* csv_data = read_csv_file(filename);
    if (!csv_data) {
        return EXIT_FAILURE;
    }

    printf("CSV Data from %s:\n", filename);
    print_csv_data(csv_data);
    free_csv_data(csv_data);
    
    return EXIT_SUCCESS;
}