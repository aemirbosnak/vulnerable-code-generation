//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 1000

// Struct to hold CSV data
typedef struct {
    int num_fields;
    char **fields;
} csv_data_t;

// Function to read CSV file and return data
csv_data_t* read_csv_file(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Failed to open file %s\n", filename);
        exit(1);
    }

    csv_data_t* data = (csv_data_t*)malloc(sizeof(csv_data_t));
    data->num_fields = 0;
    data->fields = (char**)malloc(MAX_FIELDS * sizeof(char*));

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        char* token = strtok(line, ",");
        int field_count = 0;

        while (token!= NULL) {
            if (field_count >= MAX_FIELDS) {
                printf("Error: Too many fields on line %d\n", data->num_fields + 1);
                exit(1);
            }

            data->fields[field_count] = strdup(token);
            token = strtok(NULL, ",");
            field_count++;
        }

        data->num_fields++;
    }

    fclose(fp);
    return data;
}

// Function to print CSV data
void print_csv_data(csv_data_t* data) {
    for (int i = 0; i < data->num_fields; i++) {
        printf("%s\t", data->fields[i]);
    }
    printf("\n");
}

// Function to free CSV data memory
void free_csv_data(csv_data_t* data) {
    for (int i = 0; i < data->num_fields; i++) {
        free(data->fields[i]);
    }
    free(data->fields);
    free(data);
}

int main() {
    csv_data_t* data = read_csv_file("example.csv");
    print_csv_data(data);
    free_csv_data(data);

    return 0;
}