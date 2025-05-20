//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_COLUMNS 100
#define MAX_ROWS 1000
#define MAX_CELL_SIZE 100
#define DELIMITER ','
#define QUOTE_CHAR '"'

typedef struct{
    char **data;
    int num_rows;
    int num_columns;
} CSVData;

CSVData *readCSV(FILE *fp){
    CSVData *csvData = (CSVData*)malloc(sizeof(CSVData));
    csvData->data = (char**)malloc(MAX_ROWS*sizeof(char*));
    csvData->num_rows = 0;
    csvData->num_columns = 0;

    char line[MAX_CELL_SIZE];
    while(fgets(line, MAX_CELL_SIZE, fp)!= NULL){
        if(csvData->num_rows >= MAX_ROWS){
            printf("Maximum number of rows exceeded.\n");
            break;
        }
        char *token = strtok(line, DELIMITER);
        while(token!= NULL){
            if(csvData->num_columns >= MAX_COLUMNS){
                printf("Maximum number of columns exceeded.\n");
                break;
            }
            csvData->data[csvData->num_rows] = (char*)malloc((strlen(token)+1)*sizeof(char));
            strcpy(csvData->data[csvData->num_rows], token);
            csvData->num_columns++;
            csvData->num_rows++;
            token = strtok(NULL, DELIMITER);
        }
    }
    return csvData;
}

void printCSV(CSVData *csvData){
    for(int i=0; i<csvData->num_rows; i++){
        for(int j=0; j<csvData->num_columns; j++){
            printf("%s ", csvData->data[i]);
        }
        printf("\n");
    }
}

int main(){
    FILE *fp = fopen("example.csv", "r");
    if(fp == NULL){
        printf("File not found.\n");
        return 1;
    }
    CSVData *csvData = readCSV(fp);
    fclose(fp);
    printCSV(csvData);
    for(int i=0; i<csvData->num_rows; i++){
        for(int j=0; j<csvData->num_columns; j++){
            free(csvData->data[i]);
        }
        free(csvData->data[i]);
    }
    free(csvData->data);
    free(csvData);
    return 0;
}