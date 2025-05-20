//Gemma-7B DATASET v1.0 Category: Data mining ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a structure to store data
typedef struct data {
    int age;
    float salary;
    char gender;
    char occupation;
} data;

// Function to calculate the average salary of a particular gender
float calculate_average_salary(data *arr, int n, char gender) {
    int i = 0;
    float total_salary = 0.0f;
    for (i = 0; i < n; i++) {
        if (arr[i].gender == gender) {
            total_salary += arr[i].salary;
        }
    }
    return total_salary / (float)n;
}

int main() {
    // Create an array of data structures
    data *arr = (data *)malloc(10 * sizeof(data));

    // Populate the data structures
    arr[0].age = 25;
    arr[0].salary = 50000.0f;
    arr[0].gender = 'f';
    arr[0].occupation = 'Software Engineer';

    arr[1].age = 30;
    arr[1].salary = 60000.0f;
    arr[1].gender = 'm';
    arr[1].occupation = 'Doctor';

    arr[2].age = 28;
    arr[2].salary = 40000.0f;
    arr[2].gender = 'f';
    arr[2].occupation = 'Teacher';

    arr[3].age = 32;
    arr[3].salary = 70000.0f;
    arr[3].gender = 'm';
    arr[3].occupation = 'Lawyer';

    // Calculate the average salary for each gender
    float average_salary_female = calculate_average_salary(arr, 4, 'f');
    float average_salary_male = calculate_average_salary(arr, 4, 'm');

    // Print the average salaries
    printf("The average salary for females is: %.2f\n", average_salary_female);
    printf("The average salary for males is: %.2f\n", average_salary_male);

    return 0;
}