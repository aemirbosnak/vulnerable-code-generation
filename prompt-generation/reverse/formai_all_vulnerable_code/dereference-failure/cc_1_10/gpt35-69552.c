//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LENGTH 1000 // Max length of each line in CSV file
#define MAX_COLS 100 // Max number of columns in CSV file

int main() 
{
    char filename[20]; 
    printf("Enter CSV file name: ");
    scanf("%s", filename); // get input filename
    
    FILE* fp = fopen(filename, "r"); // open input file for reading
    if (fp == NULL) { // error handling for file IO
        printf("Error: could not open file for reading");
        return 1;
    }

    char line[MAX_LENGTH]; // buffer to store each line
    char* token; // pointer to each element of the CSV row
    int row_num = 0; // keep track of row number

    // 2D array to store the CSV data
    char** data = (char**) malloc(MAX_COLS * sizeof(char*)); 
    for(int i = 0; i < MAX_COLS; i++) {
        data[i] = (char*) malloc(MAX_LENGTH * sizeof(char));
    }

    // read each line of CSV file
    while (fgets(line, MAX_LENGTH, fp)) {
        int col_num = 0;
        token = strtok(line, ","); // tokenize based on delimiter ","
        
        while (token != NULL && col_num < MAX_COLS) {
            strcpy(data[col_num][row_num], token); // copy token to array
            col_num++;
            token = strtok(NULL, ",");
        }
        row_num++;
    }

    // print the CSV data
    for (int i = 0; i < MAX_COLS; i++) {
        for (int j = 0; j < row_num; j++) {
            printf("%s ", data[i][j]);
        }
        printf("\n");
    }

    // clean up allocated memory and close file
    for (int i = 0; i < MAX_COLS; i++) {
        free(data[i]);
    }
    free(data);
    fclose(fp);

    return 0;
}