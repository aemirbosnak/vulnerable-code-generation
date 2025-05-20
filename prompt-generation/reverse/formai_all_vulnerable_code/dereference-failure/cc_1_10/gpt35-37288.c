//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *header;
    char *datatype;
    int position;
} Column;

typedef struct {
    int num_columns;
    Column *columns;
} CSVSchema;

typedef struct {
    CSVSchema *schema;
    int num_rows;
    char **data;
} CSVData;

// Function to parse the first line of the CSV file and generate the schema
CSVSchema* parse_header(FILE* csv_file) {
    char line[MAX_LINE_LENGTH];
    fgets(line, MAX_LINE_LENGTH, csv_file);

    // Count the number of columns in the CSV file
    int num_columns = 0;
    char *result = strtok(line, ",");
    while (result != NULL) {
        num_columns++;
        result = strtok(NULL, ",");
    }

    // Allocate memory for the schema
    CSVSchema *schema = (CSVSchema*) malloc(sizeof(CSVSchema));
    schema->num_columns = num_columns;
    schema->columns = (Column*) malloc(num_columns * sizeof(Column));

    // Loop through the columns and store their name, data type, and position
    char *token;
    int i = 0;
    token = strtok(line, ",");
    while (token != NULL) {
        char *header = (char*) malloc((strlen(token) + 1) * sizeof(char));
        strcpy(header, token);
        schema->columns[i].header = header;
        schema->columns[i].position = i;

        // Determine the data type of the column
        char *datatype;
        if (isdigit(token[0])) {
            int num_decimals = 0;
            char *ptr = strchr(token, '.');
            if (ptr != NULL) {
                while (*ptr != '\0') {
                    if (*ptr == '.') {
                        num_decimals++;
                    }
                    ptr++;
                }
            }
            datatype = (num_decimals > 0) ? "float" : "integer";
        }
        else {
            datatype = "string";
        }
        schema->columns[i].datatype = datatype;

        token = strtok(NULL, ",");
        i++;
    }

    return schema;
}

// Function to parse the remaining lines of the CSV file and generate the data
CSVData* parse_data(FILE* csv_file, CSVSchema *schema) {
    char line[MAX_LINE_LENGTH];

    // Count the number of rows in the CSV file
    int num_rows = 0;
    while (fgets(line, MAX_LINE_LENGTH, csv_file)) {
        num_rows++;
    }
    rewind(csv_file);

    // Allocate memory for the CSV data
    CSVData *csv_data = (CSVData*) malloc(sizeof(CSVData));
    csv_data->schema = schema;
    csv_data->num_rows = num_rows;
    csv_data->data = (char**) malloc(num_rows * schema->num_columns * sizeof(char*));

    // Loop through the rows of data and store their values
    int i = 0;
    while (fgets(line, MAX_LINE_LENGTH, csv_file)) {
        int j = 0;
        char *token = strtok(line, ",");
        while (token != NULL) {
            char *value = (char*) malloc((strlen(token) + 1) * sizeof(char));
            strcpy(value, token);
            csv_data->data[i*schema->num_columns+j] = value;
            token = strtok(NULL, ",");
            j++;
        }
        i++;
    }

    return csv_data;
}

// Function to free the memory allocated by the CSV schema and data
void free_csv(CSVData *csv_data) {
    int i, j;
    for (i = 0; i < csv_data->schema->num_columns; i++) {
        free(csv_data->schema->columns[i].header);
    }
    free(csv_data->schema->columns);
    free(csv_data->schema);
    for (i = 0; i < csv_data->num_rows; i++) {
        for (j = 0; j < csv_data->schema->num_columns; j++) {
            free(csv_data->data[i*csv_data->schema->num_columns+j]);
        }
    }
    free(csv_data->data);
    free(csv_data);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: csv_reader filename\n");
        return 1;
    }

    FILE *csv_file = fopen(argv[1], "r");
    if (csv_file == NULL) {
        printf("Failed to open file: %s\n", argv[1]);
        return 1;
    }

    CSVSchema *schema = parse_header(csv_file);
    CSVData *csv_data = parse_data(csv_file, schema);

    int i, j;
    printf("CSV File:\n");
    for (i = 0; i < schema->num_columns; i++) {
        printf("%s (%s)", schema->columns[i].header, schema->columns[i].datatype);
        if (i < schema->num_columns-1) {
            printf(", ");
        }
    }
    printf("\n");
    for (i = 0; i < csv_data->num_rows; i++) {
        for (j = 0; j < schema->num_columns; j++) {
            printf("%s", csv_data->data[i*schema->num_columns+j]);
            if (j < schema->num_columns-1) {
                printf(", ");
            }
        }
        printf("\n");
    }

    free_csv(csv_data);

    return 0;
}