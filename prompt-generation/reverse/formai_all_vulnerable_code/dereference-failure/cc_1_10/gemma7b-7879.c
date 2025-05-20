//Gemma-7B DATASET v1.0 Category: Data mining ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 100

int main()
{
    // Declare variables
    char **data = NULL;
    int num_records = 0, i, j, k, l, record_length, target_column = 3;
    float average_salary = 0.0f;

    // Allocate memory for data
    data = (char **)malloc(MAX * sizeof(char *));

    // Read data from file
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }

    // Count the number of records
    while (!feof(fp))
    {
        getline(fp, data[num_records], MAX);
        num_records++;
    }

    // Calculate the average salary
    for (i = 0; i < num_records; i++)
    {
        record_length = strlen(data[i]);
        for (j = 0; j < record_length; j++)
        {
            if (data[i][j] == '$')
            {
                k = j + 1;
                l = record_length;
                while (data[i][k] != ',')
                {
                    k++;
                }
                average_salary += atof(data[i] + k) / num_records;
            }
        }
    }

    // Print the average salary
    printf("The average salary is: $%.2f\n", average_salary);

    // Free memory
    free(data);

    return 0;
}