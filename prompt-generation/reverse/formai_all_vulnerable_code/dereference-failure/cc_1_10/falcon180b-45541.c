//Falcon-180B DATASET v1.0 Category: Data mining ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

// structure to hold data
typedef struct {
    int id;
    char name[50];
    int age;
    float salary;
    char gender[10];
} Data;

// function to compare two data based on their salary
int compare_salary(const void* a, const void* b) {
    Data* data1 = (Data*)a;
    Data* data2 = (Data*)b;

    if (data1->salary > data2->salary)
        return 1;
    else if (data1->salary == data2->salary)
        return 0;
    else
        return -1;
}

// function to print data in a tabular format
void print_data(Data* data, int num_rows) {
    printf("ID\tName\tAge\tSalary\tGender\n");
    for (int i = 0; i < num_rows; i++) {
        printf("%d\t%s\t%d\t%.2f\t%s\n", data[i].id, data[i].name, data[i].age, data[i].salary, data[i].gender);
    }
}

int main() {
    int num_rows, num_cols;
    printf("Enter number of rows: ");
    scanf("%d", &num_rows);
    printf("Enter number of columns: ");
    scanf("%d", &num_cols);

    // initialize data with random values
    Data* data = malloc(num_rows * sizeof(Data));
    srand(time(NULL));
    for (int i = 0; i < num_rows; i++) {
        data[i].id = rand() % MAX_ROWS;
        sprintf(data[i].name, "Name %d", i);
        data[i].age = rand() % 100;
        data[i].salary = rand() % 1000;
        sprintf(data[i].gender, "Gender %d", i);
    }

    // sort data based on salary
    qsort(data, num_rows, sizeof(Data), compare_salary);

    // print data in a tabular format
    printf("Sorted data based on salary:\n");
    print_data(data, num_rows);

    // free memory
    free(data);

    return 0;
}