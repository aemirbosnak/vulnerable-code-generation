//Gemma-7B DATASET v1.0 Category: Data mining ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_RECORD_SIZE 1024

typedef struct Record {
    char *name;
    char *address;
    char *phone_number;
    char *email;
    struct Record *next;
} Record;

Record *record_head = NULL;

void add_record(char *name, char *address, char *phone_number, char *email)
{
    Record *new_record = malloc(sizeof(Record));

    new_record->name = strdup(name);
    new_record->address = strdup(address);
    new_record->phone_number = strdup(phone_number);
    new_record->email = strdup(email);
    new_record->next = NULL;

    if (record_head == NULL)
    {
        record_head = new_record;
    }
    else
    {
        record_head->next = new_record;
        record_head = new_record;
    }
}

void search_record(char *name)
{
    Record *current_record = record_head;

    while (current_record)
    {
        if (strcmp(current_record->name, name) == 0)
        {
            printf("Name: %s\n", current_record->name);
            printf("Address: %s\n", current_record->address);
            printf("Phone Number: %s\n", current_record->phone_number);
            printf("Email: %s\n", current_record->email);
            break;
        }
        current_record = current_record->next;
    }

    if (current_record == NULL)
    {
        printf("Record not found.\n");
    }
}

int main()
{
    add_record("John Doe", "123 Main St.", "555-123-4567", "john.doe@example.com");
    add_record("Jane Doe", "456 Oak Ave.", "555-456-7890", "jane.doe@example.com");
    add_record("Bob Smith", "789 Oak St.", "555-987-6234", "bob.smith@example.com");

    search_record("John Doe");

    return 0;
}