//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure to store each row of CSV file
struct CSV_row{
    char **columns; //Pointer to array of string to store each cell value
    int num_columns; //Number of columns in the row
};

//Function to parse a row from CSV file
struct CSV_row* parse_row(char *row, char delimiter){
    struct CSV_row *csv_row = malloc(sizeof(struct CSV_row));
    csv_row->num_columns = 0;
    csv_row->columns = NULL;
    char *tok = strtok(row, &delimiter);
    while(tok != NULL){
        //Add value to row structure
        csv_row->num_columns++;
        csv_row->columns = realloc(csv_row->columns, csv_row->num_columns * sizeof(char *));
        csv_row->columns[csv_row->num_columns-1] = tok;
        tok = strtok(NULL, &delimiter);
    }
    return csv_row;
}

//Function to free memory allocated to a row
void free_row(struct CSV_row *row){
    for(int i=0; i<row->num_columns; i++){
        free(row->columns[i]);
    }
    free(row->columns);
    free(row);
}

//Function to read CSV file
void read_csv(char *file_name, char delimiter){
    FILE *csv_file = fopen(file_name, "r");
    if(csv_file == NULL){
        printf("Error opening file.");
        return;
    }
    char line[1024];
    struct CSV_row *row;
    int row_num = 0, max_columns = 0;
    while(fgets(line, sizeof(line), csv_file)){
        row = parse_row(line, delimiter);
        if(row_num == 0){
            max_columns = row->num_columns;
        }
        else{
            if(row->num_columns != max_columns){
                printf("Row %d has %d columns (expected %d).", row_num, row->num_columns, max_columns);
                exit(1);
            }
        }
        //Printing row data
        printf("Row %d:\n", row_num);
        for(int i=0; i<row->num_columns; i++){
            printf("Column %d : %s\n", i+1, row->columns[i]);
        }
        printf("\n");
        free_row(row);
        row_num++;
    }
    fclose(csv_file);
}

//Main function
int main(){
    read_csv("example.csv", ',');
    return 0;
}