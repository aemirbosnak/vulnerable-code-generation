//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: accurate
#include <stdio.h>
#include <string.h>

#define MAX_RECORD_SIZE 20

typedef struct Record
{
    char name[MAX_RECORD_SIZE];
    int age;
    char occupation[MAX_RECORD_SIZE];
    struct Record* next;
} Record;

Record* head = NULL;

void addRecord(char* name, int age, char* occupation)
{
    Record* newRecord = (Record*)malloc(sizeof(Record));

    strcpy(newRecord->name, name);
    newRecord->age = age;
    strcpy(newRecord->occupation, occupation);

    if (head == NULL)
    {
        head = newRecord;
    }
    else
    {
        head->next = newRecord;
        head = newRecord;
    }
}

void printRecords()
{
    Record* currentRecord = head;

    while (currentRecord)
    {
        printf("Name: %s, Age: %d, Occupation: %s\n", currentRecord->name, currentRecord->age, currentRecord->occupation);
        currentRecord = currentRecord->next;
    }
}

int main()
{
    addRecord("John Doe", 25, "Software Engineer");
    addRecord("Jane Doe", 30, "Teacher");
    addRecord("Peter Pan", 12, "Student");

    printRecords();

    return 0;
}