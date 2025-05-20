//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum length for each field in the CSV file
#define MAX_FIELD_LEN 100

// Define maximum number of fields in the CSV file
#define MAX_FIELDS 10

// Define struct to store CSV records
typedef struct {
    char **fields;  // array of fields
    int num_fields; // number of fields in record
} csv_record;

// Define function to split a string by delimiter and return array of tokens
char **split_string(char *string, char delimiter, int *num_tokens) {
    char **tokens = malloc(MAX_FIELDS * sizeof(char *));
    char *token;
    int i = 0;
    token = strtok(string, &delimiter);
    
    while (token != NULL && i < MAX_FIELDS) {
        tokens[i] = token;
        i++;
        token = strtok(NULL, &delimiter);
    }
    
    *num_tokens = i;
    return tokens;
}

// Define function to read a CSV file into an array of csv_records
csv_record *read_csv(char *filename, int *num_records) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }
    
    csv_record *records = malloc(1000 * sizeof(csv_record));
    char line[MAX_FIELDS * MAX_FIELD_LEN];
    int i = 0;
    
    while (fgets(line, sizeof(line), file)) {
        int num_fields = 0;
        char **fields = split_string(line, ',', &num_fields);
        
        // Allocate memory for record fields
        records[i].fields = malloc(num_fields * sizeof(char *));
        
        for (int j = 0; j < num_fields; j++) {
            // Allocate memory for field and copy value
            char *field = malloc(MAX_FIELD_LEN * sizeof(char));
            strncpy(field, fields[j], MAX_FIELD_LEN - 1);
            field[MAX_FIELD_LEN - 1] = '\0';
            records[i].fields[j] = field;
        }
        
        records[i].num_fields = num_fields;
        i++;
    }
    
    fclose(file);
    *num_records = i;
    return records;
}

// Define function to print a CSV record
void print_record(csv_record record) {
    for (int i = 0; i < record.num_fields; i++) {
        printf("%s ", record.fields[i]);
    }
    printf("\n");
}

// Define main function
int main() {
    int num_records;
    csv_record *records = read_csv("example.csv", &num_records);
    
    for (int i = 0; i < num_records; i++) {
        print_record(records[i]);
    }
    
    // Free memory allocated for records
    for (int i = 0; i < num_records; i++) {
        for (int j = 0; j < records[i].num_fields; j++) {
            free(records[i].fields[j]);
        }
        free(records[i].fields);
    }
    free(records);
    
    return 0;
}