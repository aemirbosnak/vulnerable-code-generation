//Gemma-7B DATASET v1.0 Category: Data mining ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100

int main()
{
    // Allocate memory for data storage
    char **data = (char **)malloc(MAX_SIZE * sizeof(char *));
    for(int i = 0; i < MAX_SIZE; i++)
    {
        data[i] = (char *)malloc(MAX_SIZE * sizeof(char));
    }

    // Get the data
    printf("Enter the data (separated by commas): ");
    char input[MAX_SIZE];
    fgets(input, MAX_SIZE, stdin);

    // Split the data into individual records
    char *record = strtok(input, ",");
    int record_num = 0;
    while(record)
    {
        // Store the record
        strcpy(data[record_num], record);
        record_num++;

        // Get the next record
        record = strtok(NULL, ",");
    }

    // Analyze the data
    for(int i = 0; i < record_num; i++)
    {
        // Print the record
        printf("Record %d: %s\n", i + 1, data[i]);

        // Calculate the average of each attribute
        char **attributes = (char **)malloc(MAX_SIZE * sizeof(char *));
        for(int j = 0; j < MAX_SIZE; j++)
        {
            attributes[j] = (char *)malloc(MAX_SIZE * sizeof(char));
        }

        char *attribute = strtok(data[i], ":");
        int attribute_num = 0;
        while(attribute)
        {
            // Store the attribute
            strcpy(attributes[attribute_num], attribute);
            attribute_num++;

            // Get the next attribute
            attribute = strtok(NULL, ":");
        }

        double average = 0.0;
        for(int j = 0; j < attribute_num; j++)
        {
            double value = atof(attributes[j]);
            average += value;
        }

        average /= attribute_num;

        // Print the average
        printf("Average for Record %d: %.2lf\n", i + 1, average);

        // Free memory
        for(int j = 0; j < MAX_SIZE; j++)
        {
            free(attributes[j]);
        }
        free(attributes);
    }

    // Free memory
    for(int i = 0; i < MAX_SIZE; i++)
    {
        free(data[i]);
    }
    free(data);

    return 0;
}