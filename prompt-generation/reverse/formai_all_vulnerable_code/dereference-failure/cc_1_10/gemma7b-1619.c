//Gemma-7B DATASET v1.0 Category: Database querying ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORD_SIZE 100

typedef struct Record
{
    char name[MAX_RECORD_SIZE];
    int age;
    float salary;
} Record;

void insertRecord(Record **records, int *recordsCount)
{
    Record *newRecord = (Record *)malloc(sizeof(Record));
    printf("Enter name: ");
    scanf("%s", newRecord->name);

    printf("Enter age: ");
    scanf("%d", &newRecord->age);

    printf("Enter salary: ");
    scanf("%f", &newRecord->salary);

    *records = realloc(*records, (*recordsCount + 1) * sizeof(Record));
    (*recordsCount)++;
    *records = records;
    return;
}

void searchRecords(Record *records, int recordsCount)
{
    char searchName[MAX_RECORD_SIZE];
    printf("Enter name to search for: ");
    scanf("%s", searchName);

    int found = 0;
    for (int i = 0; i < recordsCount; i++)
    {
        if (strcmp(records[i].name, searchName) == 0)
        {
            printf("Name: %s\n", records[i].name);
            printf("Age: %d\n", records[i].age);
            printf("Salary: %.2f\n", records[i].salary);
            found = 1;
        }
    }

    if (!found)
    {
        printf("No record found.\n");
    }
}

int main()
{
    Record *records = NULL;
    int recordsCount = 0;

    insertRecord(&records, &recordsCount);
    insertRecord(&records, &recordsCount);
    insertRecord(&records, &recordsCount);

    searchRecords(records, recordsCount);

    return 0;
}