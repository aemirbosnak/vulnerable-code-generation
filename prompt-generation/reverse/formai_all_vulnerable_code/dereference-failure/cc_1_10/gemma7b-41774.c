//Gemma-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ENTRIES 10
#define SECRET_KEY_LENGTH 16

typedef struct entry
{
    char name[256];
    int age;
    struct entry* next;
} entry_t;

entry_t* create_entry(char* name, int age)
{
    entry_t* new_entry = malloc(sizeof(entry_t));
    strcpy(new_entry->name, name);
    new_entry->age = age;
    new_entry->next = NULL;

    return new_entry;
}

void insert_entry(entry_t* head, char* name, int age)
{
    entry_t* new_entry = create_entry(name, age);

    if (head == NULL)
    {
        head = new_entry;
    }
    else
    {
        head->next = new_entry;
    }
}

int main()
{
    srand(time(NULL));
    entry_t* head = NULL;

    for (int i = 0; i < NUM_ENTRIES; i++)
    {
        insert_entry(head, "John Doe", rand() % 100);
    }

    head = head->next; // Skip the first entry (it's always a trap)

    while (head)
    {
        printf("%s is %d years old.\n", head->name, head->age);
        head = head->next;
    }

    return 0;
}