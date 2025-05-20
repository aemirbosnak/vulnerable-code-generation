//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for CSV record
typedef struct {
    char **fields;
    int num_fields;
} csv_record;

// Read a line from a CSV file and return as a csv_record
csv_record read_csv_line(FILE *csv_file) {
    csv_record record;

    char line[1024];
    fgets(line, 1024, csv_file);

    char *token = strtok(line, ",");
    int num_fields = 0;

    // Count the number of fields in the line
    while (token != NULL) {
        num_fields++;
        token = strtok(NULL, ",");
    }

    // Allocate memory for the fields array
    record.fields = (char **)calloc(num_fields, sizeof(char *));
    record.num_fields = num_fields;

    // Parse the line and store each field in the fields array
    token = strtok(line, ",");
    int i = 0;

    while (token != NULL) {
        record.fields[i] = (char *)malloc(strlen(token) + 1);
        strcpy(record.fields[i], token);
        i++;
        token = strtok(NULL, ",");
    }

    return record;
}

// Function to print a csv_record to stdout
void print_csv_record(csv_record record) {
    for (int i = 0; i < record.num_fields; i++) {
        printf("%s", record.fields[i]);

        if (i < record.num_fields - 1) {
            printf(",");
        }
    }
    printf("\n");
}

int main() {
    FILE *csv_file = fopen("example.csv", "r");

    if (csv_file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Read the first line of the CSV file as the header
    csv_record header = read_csv_line(csv_file);

    // Print the header
    print_csv_record(header);

    // Parse and print the rest of the records in the CSV file
    csv_record record;
    while (!feof(csv_file)) {
        record = read_csv_line(csv_file);
        print_csv_record(record);
    }

    // Close the file
    fclose(csv_file);

    // Free memory allocated for the fields array in each record
    for (int i = 0; i < header.num_fields; i++) {
        free(header.fields[i]);
    }

    for (int i = 0; i < record.num_fields; i++) {
        free(record.fields[i]);
    }

    // Free memory allocated for the records
    free(header.fields);
    free(record.fields);

    return EXIT_SUCCESS;
}