//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 100
#define MAX_ROWS 1000

typedef struct CsvFile {
    char *data[MAX_ROWS][MAX_COLUMNS];
    int num_rows, num_cols;
} CsvFile;

void print_file(CsvFile *file) {
    for(int i = 0; i < file->num_rows; i++) {
        for(int j = 0; j < file->num_cols; j++) {
            printf("%s", file->data[i][j]);
            if(j < file->num_cols - 1) {
                printf(",");
            }
        }
        printf("\n");
    }
}

int main(void) {
    FILE *fp = fopen("example.csv", "r");
    if(fp == NULL) {
        printf("Could not open file.\n");
        return 1;
    }

    // read the file line by line and populate the CsvFile struct
    CsvFile file;
    char line[1024];
    int row = 0;
    while(fgets(line, 1024, fp)) {

        // remove the newline character
        line[strcspn(line, "\n")] = 0;
        
        // tokenize the line by comma
        char *value = strtok(line, ",");
        int col = 0;
        while(value != NULL && col < MAX_COLUMNS) {

            // allocate space for the value and copy it
            file.data[row][col] = malloc(sizeof(char) * (strlen(value) + 1));
            strcpy(file.data[row][col], value);

            col++;
            value = strtok(NULL, ",");
        }

        // update the number of columns if necessary
        if(col > file.num_cols) {
            file.num_cols = col;
        }

        row++;
    }
    file.num_rows = row;

    fclose(fp);

    // print the file to stdout
    print_file(&file);

    // free the allocated memory
    for(int i = 0; i < file.num_rows; i++) {
        for(int j = 0; j < file.num_cols; j++) {
            free(file.data[i][j]);
        }
    }

    return 0;
}