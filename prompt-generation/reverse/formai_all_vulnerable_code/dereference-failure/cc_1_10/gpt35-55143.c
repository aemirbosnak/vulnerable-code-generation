//FormAI DATASET v1.0 Category: Data mining ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100
#define MAX_NUM_RECORDS 1000

typedef struct
{
    char name[MAX_STRING_LENGTH];
    int age;
    float height;
} Record;

int main()
{
    Record records[MAX_NUM_RECORDS];
    char filename[MAX_STRING_LENGTH];
    int num_records = 0;

    printf("Enter filename: ");
    scanf("%s", filename);

    FILE* fp = fopen(filename, "r");

    if(fp == NULL)
    {
        printf("Error: File not found!\n");
        exit(1);
    }

    char line[MAX_STRING_LENGTH];

    while(fgets(line, MAX_STRING_LENGTH, fp) != NULL)
    {
        char* token = strtok(line, ",");
        strcpy(records[num_records].name, token);

        token = strtok(NULL, ",");
        records[num_records].age = atoi(token);

        token = strtok(NULL, ",");
        records[num_records].height = atof(token);

        num_records++;
    }

    fclose(fp);

    printf("Total number of records: %d\n", num_records);

    // Data mining starts here

    float total_height = 0.0;

    for(int i = 0; i < num_records; i++)
    {
        total_height += records[i].height;
    }

    float average_height = total_height / num_records;

    printf("Average height: %f\n", average_height);

    int num_teenagers = 0;

    for(int i = 0; i < num_records; i++)
    {
        if(records[i].age >= 13 && records[i].age <= 19)
        {
            num_teenagers++;
        }
    }

    printf("Number of teenagers: %d\n", num_teenagers);

    return 0;
}