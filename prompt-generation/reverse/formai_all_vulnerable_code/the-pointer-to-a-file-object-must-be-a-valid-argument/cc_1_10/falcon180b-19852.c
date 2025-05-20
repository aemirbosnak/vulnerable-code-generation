//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for CSV file
typedef struct {
    char *header;
    int num_cols;
    int num_rows;
    char **data;
} CSV;

// Function to read in CSV file
CSV read_csv(char *filename) {
    FILE *file = fopen(filename, "r");
    char line[1024];
    char *token;
    CSV csv = {NULL, 0, 0, NULL};
    int row = 0;
    int col = 0;

    // Read in header row
    if (fgets(line, sizeof(line), file)!= NULL) {
        csv.header = strdup(line);
        token = strtok(csv.header, ",");
        while (token!= NULL) {
            csv.num_cols++;
            col++;
            token = strtok(NULL, ",");
        }
        csv.num_cols++;
        col++;
    } else {
        printf("Error: Invalid CSV file.\n");
        exit(1);
    }

    // Allocate memory for data array
    csv.data = (char **)malloc(csv.num_cols * sizeof(char *));
    for (int i = 0; i < csv.num_cols; i++) {
        csv.data[i] = (char *)malloc(1024 * sizeof(char));
    }

    // Read in data rows
    while (fgets(line, sizeof(line), file)!= NULL) {
        row++;
        token = strtok(line, ",");
        int j = 0;
        while (token!= NULL) {
            strcpy(csv.data[j], token);
            j++;
            token = strtok(NULL, ",");
        }
    }

    csv.num_rows = row;
    return csv;
}

// Function to free memory allocated for CSV file
void free_csv(CSV csv) {
    free(csv.header);
    for (int i = 0; i < csv.num_cols; i++) {
        free(csv.data[i]);
    }
    free(csv.data);
}

// Function to print CSV file
void print_csv(CSV csv) {
    printf("Header: %s\n", csv.header);
    for (int i = 0; i < csv.num_rows; i++) {
        for (int j = 0; j < csv.num_cols; j++) {
            printf("%s ", csv.data[j]);
        }
        printf("\n");
    }
}

int main() {
    CSV csv = read_csv("example.csv");
    print_csv(csv);
    free_csv(csv);
    return 0;
}