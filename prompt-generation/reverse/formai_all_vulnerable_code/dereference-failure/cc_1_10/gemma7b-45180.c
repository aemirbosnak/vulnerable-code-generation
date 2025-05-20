//Gemma-7B DATASET v1.0 Category: Data recovery tool ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECOVERY_SIZE 1024

typedef struct Record
{
    char name[MAX_RECOVERY_SIZE];
    int size;
    struct Record* next;
} Record;

Record* recover_data(char* filename)
{
    FILE* file = fopen(filename, "r");
    if (!file)
    {
        return NULL;
    }

    Record* head = NULL;
    char buffer[MAX_RECOVERY_SIZE];
    int read_size;

    while ((read_size = fread(buffer, 1, MAX_RECOVERY_SIZE, file)) > 0)
    {
        Record* new_record = malloc(sizeof(Record));
        new_record->size = read_size;
        strncpy(new_record->name, buffer, read_size);

        new_record->next = head;
        head = new_record;
    }

    fclose(file);
    return head;
}

int main()
{
    Record* recovered_data = recover_data("data.txt");

    if (recovered_data)
    {
        for (Record* current = recovered_data; current; current = current->next)
        {
            printf("%s\n", current->name);
        }
    }

    return 0;
}