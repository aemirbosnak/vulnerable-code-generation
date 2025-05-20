//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to hold CSV data
typedef struct CSV {
    char **rows;        // An array of rows
    int num_rows;       // Number of rows
    int num_cols;       // Number of columns in the data
} CSV;

// A function to read CSV data from file
CSV* read_csv(char *filename, char delim) {
    CSV *csv = (CSV*) malloc(sizeof(CSV));
    csv->rows = NULL;
    csv->num_rows = 0;
    csv->num_cols = 0;
    
    FILE *fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error: Could not open file '%s'", filename);
        return NULL;
    }
    
    // Get the number of columns
    char buffer[1024];
    fgets(buffer, 1024, fp);
    csv->num_cols = 1;
    for(int i=0; buffer[i]!='\0'; i++) {
        if(buffer[i] == delim) {
            csv->num_cols++;
        }
    }
    rewind(fp);
    
    // Read the data row by row
    while(fgets(buffer, 1024, fp)) {
        csv->rows = (char**) realloc(csv->rows, (csv->num_rows+1)*sizeof(char*));
        csv->rows[csv->num_rows] = (char*) malloc(csv->num_cols*1024);
        char *token;
        int curr_col = 0;
        token = strtok(buffer, &delim);
        while(token != NULL) {
            strcpy(csv->rows[csv->num_rows]+curr_col*1024, token);
            curr_col++;
            token = strtok(NULL, &delim);
        }
        csv->num_rows++;
    }
    fclose(fp);
    return csv;
}

// A function to print the CSV data
void print_csv(CSV *csv) {
    for(int i=0; i<csv->num_rows; i++) {
        for(int j=0; j<csv->num_cols; j++) {
            printf("%s\t", csv->rows[i]+j*1024);
        }
        printf("\n");
    }
}

int main() {
    char *filename = "example.csv";
    char delim = ',';
    CSV *csv = read_csv(filename, delim);
    if(csv != NULL) {
        print_csv(csv);
    }
    return 0;
}