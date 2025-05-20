//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_EMAIL_LENGTH 50

typedef struct MailListEntry
{
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    struct MailListEntry* next;
} MailListEntry;

void add_entry(MailListEntry** head, char* name, char* email)
{
    MailListEntry* new_entry = malloc(sizeof(MailListEntry));
    strcpy(new_entry->name, name);
    strcpy(new_entry->email, email);
    new_entry->next = NULL;

    if (*head == NULL)
    {
        *head = new_entry;
    }
    else
    {
        (*head)->next = new_entry;
    }
}

void print_entries(MailListEntry* head)
{
    while (head)
    {
        printf("%s - %s\n", head->name, head->email);
        head = head->next;
    }
}

int main()
{
    MailListEntry* head = NULL;

    add_entry(&head, "John Doe", "john.doe@example.com");
    add_entry(&head, "Jane Doe", "jane.doe@example.com");
    add_entry(&head, "Bob Smith", "bob.smith@example.com");

    print_entries(head);

    return 0;
}