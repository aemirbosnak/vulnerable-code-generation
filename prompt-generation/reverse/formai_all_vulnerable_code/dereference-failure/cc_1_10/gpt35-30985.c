//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DataRow{
    int id;
    char name[20];
    int age;
    float salary;
} DataRow;

DataRow* read_csv_file(char* filename, int* rows){
    DataRow* data_arr = NULL;
    FILE* fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Error: Could not open file %s", filename);
        exit(EXIT_FAILURE);
    }
    char line[1024];
    int count = 0;
    while (fgets(line, 1024, fp)){
        strtok(line, "\n"); //Removing newline character from the line
        if(count == 0){
            count++; //skipping first row since it contains column names
            continue;
        }
        data_arr = (DataRow*)realloc(data_arr, count * sizeof(DataRow));
        char *tmp;
        tmp = strtok(line, ",");
        data_arr[count-1].id = atoi(tmp);
        tmp = strtok(NULL, ",");
        strcpy(data_arr[count-1].name, tmp);
        tmp = strtok(NULL, ",");
        data_arr[count-1].age = atoi(tmp);
        tmp = strtok(NULL, ",");
        data_arr[count-1].salary = atof(tmp);
        count++;
    }
    fclose(fp);
    *rows = count - 1;
    return data_arr;
}

void print_data(DataRow* data_arr, int rows){
    printf("%-5s %-20s %-10s %-10s\n", "ID", "Name", "Age", "Salary");
    for(int i=0; i<rows; i++){
        printf("%-5d %-20s %-10d %-10.2f\n", data_arr[i].id, data_arr[i].name, data_arr[i].age, data_arr[i].salary);
    }
}

int main(){
    //Reading CSV file
    int rows;
    DataRow* data_arr = read_csv_file("data.csv", &rows);

    //Printing data
    printf("\nData read from CSV file:\n");
    print_data(data_arr, rows);

    free(data_arr);
    return 0;
}