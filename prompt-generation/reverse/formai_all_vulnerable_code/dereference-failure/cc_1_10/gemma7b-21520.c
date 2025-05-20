//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: funny
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_ Mailing_LIST_SIZE 100

typedef struct Mailing_List_Entry
{
    char name[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
    struct Mailing_List_Entry* next;
} Mailing_List_Entry;

Mailing_List_Entry* insert_at_tail(Mailing_List_Entry* head, char* name, char* email)
{
    Mailing_List_Entry* new_entry = malloc(sizeof(Mailing_List_Entry));
    new_entry->next = NULL;

    strcpy(new_entry->name, name);
    strcpy(new_entry->email, email);

    if (head == NULL)
    {
        head = new_entry;
    }
    else
    {
        head->next = new_entry;
    }

    return head;
}

int main()
{
    Mailing_List_Entry* head = NULL;

    insert_at_tail(head, "Bob", "bob@example.com");
    insert_at_tail(head, "Alice", "alice@example.com");
    insert_at_tail(head, "Charlie", "charlie@example.com");

    Mailing_List_Entry* current_entry = head;

    while (current_entry)
    {
        printf("Name: %s, Email: %s\n", current_entry->name, current_entry->email);
        current_entry = current_entry->next;
    }

    return 0;
}