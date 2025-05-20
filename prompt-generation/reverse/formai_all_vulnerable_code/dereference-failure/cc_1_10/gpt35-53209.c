//FormAI DATASET v1.0 Category: Phone Book ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct phonebook
{
    char name[50];
    char phone_no[20];
    struct phonebook *next;
} Phonebook;

Phonebook *head = NULL;

void insert(Phonebook *p)
{
    if (head == NULL)
    {
        head = p;
        return;
    }

    Phonebook *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = p;
}

void delete (char name[])
{
    if (head == NULL)
    {
        printf("Phonebook is empty\n");
        return;
    }

    Phonebook *prev = NULL;
    Phonebook *curr = head;

    while (curr != NULL)
    {
        if (strcmp(curr->name, name) == 0)
        {
            if (prev == NULL)
            {
                head = curr->next;
            }
            else
            {
                prev->next = curr->next;
            }

            free(curr);
            printf("%s has been deleted from the phonebook\n", name);
            return;
        }

        prev = curr;
        curr = curr->next;
    }

    printf("%s not found in the phonebook\n", name);
}

void search(char name[])
{
    if (head == NULL)
    {
        printf("Phonebook is empty\n");
        return;
    }

    Phonebook *temp = head;
    int found = 0;

    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            printf("%s: %s\n", temp->name, temp->phone_no);
            found = 1;
            break;
        }

        temp = temp->next;
    }

    if (!found)
    {
        printf("%s not found in the phonebook\n", name);
    }
}

void display()
{
    if (head == NULL)
    {
        printf("Phonebook is empty\n");
        return;
    }

    Phonebook *temp = head;

    while (temp != NULL)
    {
        printf("%s: %s\n", temp->name, temp->phone_no);
        temp = temp->next;
    }
}

void save()
{
    if (head == NULL)
    {
        printf("Phonebook is empty\n");
        return;
    }

    FILE *fptr = fopen("phonebook.txt", "w");

    if (fptr == NULL)
    {
        printf("Failed to open file\n");
        return;
    }

    Phonebook *temp = head;

    while (temp != NULL)
    {
        fprintf(fptr, "%s:%s\n", temp->name, temp->phone_no);
        temp = temp->next;
    }

    fclose(fptr);
    printf("Phonebook saved to file\n");
}

void load()
{
    FILE *fptr = fopen("phonebook.txt", "r");

    if (fptr == NULL)
    {
        printf("Failed to open file\n");
        return;
    }

    char line[100];

    while (fgets(line, sizeof(line), fptr))
    {
        char *token = strtok(line, ":");

        Phonebook *p = malloc(sizeof(Phonebook));
        strcpy(p->name, token);

        token = strtok(NULL, "\n");
        strcpy(p->phone_no, token);

        p->next = NULL;
        insert(p);
    }

    fclose(fptr);
    printf("Phonebook loaded from file\n");
}

int main()
{
    int choice;
    char name[50];
    char phone_no[20];

    printf("Welcome to the phonebook!\n");

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Add contact\n");
        printf("2. Delete contact\n");
        printf("3. Search contact\n");
        printf("4. Display contacts\n");
        printf("5. Save phonebook to file\n");
        printf("6. Load phonebook from file\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);

                printf("Enter phone number: ");
                scanf("%s", phone_no);

                Phonebook *p = malloc(sizeof(Phonebook));
                strcpy(p->name, name);
                strcpy(p->phone_no, phone_no);
                p->next = NULL;

                insert(p);

                printf("%s added to the phonebook\n", name);
                break;

            case 2:
                printf("Enter name to delete: ");
                scanf("%s", name);

                delete (name);
                break;

            case 3:
                printf("Enter name to search: ");
                scanf("%s", name);

                search(name);
                break;

            case 4:
                display();
                break;

            case 5:
                save();
                break;

            case 6:
                load();
                break;

            case 7:
                printf("Exiting program\n");
                exit(0);
                break;

            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}