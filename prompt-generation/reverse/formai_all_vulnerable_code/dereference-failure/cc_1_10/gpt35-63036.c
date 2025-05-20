//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct to hold CSV data
struct csv_data {
    char name[50];
    int age;
    float salary;
};

// Define function to parse CSV line and populate struct
void parse_csv(struct csv_data *data, char *line) {
    char *token;
    int index = 0;

    // Split line by comma delimiter
    while ((token = strsep(&line, ",")) != NULL) {
        // Populate struct elements based on index
        if (index == 0) {
            strcpy(data->name, token);
        } else if (index == 1) {
            data->age = atoi(token);
        } else if (index == 2) {
            data->salary = atof(token);
        }
        index++;
    }
}

// Define function to read CSV file and return structs
struct csv_data *read_csv(char *filename, int *n_records) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: CSV file not found\n");
        exit(1);
    }

    // Allocate memory for struct array
    int capacity = 10;
    int n_allocated = 0;
    struct csv_data *records = malloc(capacity * sizeof(struct csv_data));

    // Read each line of CSV file and populate struct array
    char line[100];
    while (fgets(line, sizeof(line), fp)) {
        // Reallocate memory for struct array if necessary
        if (n_allocated == capacity) {
            capacity *= 2;
            records = realloc(records, capacity * sizeof(struct csv_data));
        }

        // Parse CSV line and populate new struct
        struct csv_data *new_data = &records[n_allocated];
        parse_csv(new_data, line);
        n_allocated++;
    }

    // Close file and set number of records
    fclose(fp);
    *n_records = n_allocated;

    return records;
}

int main() {
    // Read CSV file and print data
    int n_records;
    struct csv_data *records = read_csv("data.csv", &n_records);
    for (int i = 0; i < n_records; i++) {
        printf("Name: %s, Age: %d, Salary: %.2f\n", records[i].name, records[i].age, records[i].salary);
    }

    // Free memory and return success
    free(records);
    return 0;
}