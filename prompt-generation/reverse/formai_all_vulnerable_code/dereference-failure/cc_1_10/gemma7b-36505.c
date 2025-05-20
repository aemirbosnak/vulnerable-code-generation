//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_ENTRIES 100

typedef struct Entry
{
    char name[50];
    double amount;
    struct Entry* next;
} Entry;

Entry* insertEntry(Entry* head, char* name, double amount)
{
    Entry* newEntry = (Entry*)malloc(sizeof(Entry));

    strcpy(newEntry->name, name);
    newEntry->amount = amount;

    if (head == NULL)
    {
        head = newEntry;
    }
    else
    {
        head->next = insertEntry(head->next, name, amount);
    }

    return head;
}

void printEntries(Entry* head)
{
    Entry* currentEntry = head;

    while (currentEntry)
    {
        printf("%s: %.2lf\n", currentEntry->name, currentEntry->amount);
        currentEntry = currentEntry->next;
    }
}

int main()
{
    Entry* head = NULL;

    insertEntry(head, "John Doe", 100);
    insertEntry(head, "Jane Doe", 200);
    insertEntry(head, "Peter Pan", 300);

    printEntries(head);

    return 0;
}