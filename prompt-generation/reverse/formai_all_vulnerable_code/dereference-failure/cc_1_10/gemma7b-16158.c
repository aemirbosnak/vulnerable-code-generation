//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void initializeDatabase(int **arr, int size);
void insertRecord(int **arr, int size, int data);
void searchRecord(int **arr, int size, int data);

int main()
{
    int **database = NULL;
    int size = 0;

    initializeDatabase(&database, size);

    insertRecord(database, size, 10);
    insertRecord(database, size, 20);
    insertRecord(database, size, 30);

    searchRecord(database, size, 20);

    free(database);

    return 0;
}

void initializeDatabase(int **arr, int size)
{
    *arr = (int *)malloc(size * MAX_SIZE * sizeof(int));
    size = MAX_SIZE;
}

void insertRecord(int **arr, int size, int data)
{
    if (size == MAX_SIZE)
    {
        printf("Database is full!\n");
        return;
    }

    arr[size++] = data;
}

void searchRecord(int **arr, int size, int data)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == data)
        {
            printf("Record found: %d\n", arr[i]);
            return;
        }
    }

    printf("Record not found.\n");
}