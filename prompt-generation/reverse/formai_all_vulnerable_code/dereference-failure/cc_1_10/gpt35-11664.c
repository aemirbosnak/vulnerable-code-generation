//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 10

// Define a struct to store each row of data
typedef struct csv_row {
    char** fields;
    int num_fields;
} csv_row_t;

// Define a struct to store the entire CSV file
typedef struct csv_file {
    csv_row_t* rows;
    int num_rows;
} csv_file_t;

csv_file_t* read_csv_file(char* filename) {
    // Open the file for reading
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: could not open file \"%s\" for reading\n", filename);
        return NULL;
    }

    // Allocate memory for the CSV file struct
    csv_file_t* csv_file = (csv_file_t*)malloc(sizeof(csv_file_t));
    if (!csv_file) {
        printf("Error: could not allocate memory for csv_file\n");
        fclose(fp);
        return NULL;
    }

    csv_file->num_rows = 0;

    // Read and parse each line of the CSV file
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        // Allocate memory for the new row struct
        csv_file->rows = (csv_row_t*)realloc(csv_file->rows, (csv_file->num_rows + 1) * sizeof(csv_row_t));
        if (!csv_file->rows) {
            printf("Error: could not allocate memory for csv_file->rows\n");
            fclose(fp);
            free(csv_file);
            return NULL;
        }

        // Allocate memory for the fields array in the new row struct
        csv_file->rows[csv_file->num_rows].fields = (char**)malloc(MAX_FIELDS * sizeof(char*));
        if (!csv_file->rows[csv_file->num_rows].fields) {
            printf("Error: could not allocate memory for csv_file->rows[%d].fields\n", csv_file->num_rows);
            fclose(fp);
            free(csv_file->rows);
            free(csv_file);
            return NULL;
        }

        // Parse the line into fields
        char* field = strtok(line, ",");
        int field_num = 0;
        while (field) {
            // Remove any trailing newline or carriage return
            int len = strlen(field);
            if (field[len - 1] == '\n' || field[len - 1] == '\r') {
                field[len - 1] = '\0';
            }

            // Store the field in the current row
            csv_file->rows[csv_file->num_rows].fields[field_num] = strdup(field);
            if (!csv_file->rows[csv_file->num_rows].fields[field_num]) {
                printf("Error: could not allocate memory for csv_file->rows[%d].fields[%d]\n", csv_file->num_rows, field_num);
                fclose(fp);
                free(csv_file->rows[csv_file->num_rows].fields);
                free(csv_file->rows);
                free(csv_file);
                return NULL;
            }

            // Move to the next field
            field = strtok(NULL, ",");
            field_num++;
        }

        // Store the number of fields in the current row
        csv_file->rows[csv_file->num_rows].num_fields = field_num;

        // Move to the next row
        csv_file->num_rows++;
    }

    return csv_file;
}

void free_csv_file(csv_file_t* csv_file) {
    // Free the memory allocated for each field in each row
    for (int i = 0; i < csv_file->num_rows; i++) {
        for (int j = 0; j < csv_file->rows[i].num_fields; j++) {
            free(csv_file->rows[i].fields[j]);
        }
        free(csv_file->rows[i].fields);
    }

    // Free the memory allocated for the rows array and the csv_file struct
    free(csv_file->rows);
    free(csv_file);
}

int main() {
    // Read the CSV file
    csv_file_t* csv_file = read_csv_file("example.csv");
    if (!csv_file) {
        return 1;
    }

    // Print out the contents of the CSV file
    for (int i = 0; i < csv_file->num_rows; i++) {
        for (int j = 0; j < csv_file->rows[i].num_fields; j++) {
            printf("%s", csv_file->rows[i].fields[j]);
            if (j < csv_file->rows[i].num_fields - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }

    // Free the memory allocated to the CSV file
    free_csv_file(csv_file);

    return 0;
}