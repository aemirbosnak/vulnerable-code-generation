//LLAMA2-13B DATASET v1.0 Category: Data mining ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_ROWS 1000
#define MAX_COLUMNS 10

// Structure to represent a data point
typedef struct {
    int age;
    int income;
    char gender;
} data_point;

// Function to generate random data
void generate_data(data_point** data, int* num_rows, int* num_columns) {
    int i, j;
    for (i = 0; i < *num_rows; i++) {
        // Generate random age and income
        data[i][0].age = (int)(18 + (double)rand() / RAND_MAX * 65);
        data[i][0].income = (int)(20000 + (double)rand() / RAND_MAX * 100000);
        
        // Generate random gender
        data[i][1].gender = (char)(rand() % 2 + 'M');
        
        // Print generated data point
        printf("Data point %d: Age %d, Income %d, Gender %c\n", i, data[i][0].age, data[i][0].income, data[i][1].gender);
    }
    *num_columns = 2;
}

// Function to calculate mean and standard deviation
void calculate_stats(data_point** data, int num_rows, int num_columns) {
    int i, j;
    double sum_age = 0, sum_income = 0, sum_squared_age = 0, sum_squared_income = 0;
    for (i = 0; i < num_rows; i++) {
        for (j = 0; j < num_columns; j++) {
            sum_age += data[i][j].age;
            sum_income += data[i][j].income;
            sum_squared_age += data[i][j].age * data[i][j].age;
            sum_squared_income += data[i][j].income * data[i][j].income;
        }
    }
    double mean_age = sum_age / num_rows;
    double mean_income = sum_income / num_rows;
    double std_dev_age = sqrt(sum_squared_age / (num_rows - 1));
    double std_dev_income = sqrt(sum_squared_income / (num_rows - 1));
    
    // Print calculated statistics
    printf("Mean age: %f, Standard deviation age: %f\n", mean_age, std_dev_age);
    printf("Mean income: %f, Standard deviation income: %f\n", mean_income, std_dev_income);
}

int main() {
    int num_rows = 1000;
    int num_columns = 10;
    data_point** data = (data_point**)malloc(num_rows * sizeof(data_point*));
    for (int i = 0; i < num_rows; i++) {
        data[i] = (data_point*)malloc(num_columns * sizeof(data_point));
    }
    
    generate_data(data, &num_rows, &num_columns);
    calculate_stats(data, num_rows, num_columns);
    
    return 0;
}