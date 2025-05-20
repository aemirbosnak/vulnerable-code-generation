//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

int main(int argc, char *argv[]) {

    // open the CSV file for reading
    FILE *fp;
    char *filename = argv[1];
    fp = fopen(filename, "r");
    
    // initialize variables to hold CSV data
    char line[MAX_LINE_SIZE];
    char *field;
    double data[100][100];
    int row = 0, col = 0;
    
    // read through the CSV file, line by line
    while (fgets(line, MAX_LINE_SIZE, fp) != NULL) {
        
        // tokenize the line by commas
        field = strtok(line, ",");
        while (field != NULL) {
            
            // convert the fields to doubles, and store in the data array
            double value = atof(field);
            data[row][col] = value;
            col++;
            field = strtok(NULL, ",");
        }
        row++;
        col = 0;
    }
    
    // print out the CSV data
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%f, ", data[i][j]);
        }
        printf("\n");
    }

    // close the CSV file
    fclose(fp);

    return 0;
}