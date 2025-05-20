//Falcon2-11B DATASET v1.0 Category: Digital Diary ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct diary
{
    char title[100];
    int day;
    char content[1000];
    struct diary *next;
};

struct diary *head = NULL;

void insert(struct diary *new)
{
    struct diary *temp = head;
    while(temp->next!= NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
}

void delete_node(struct diary *node)
{
    if(node == NULL)
        return;
    struct diary *temp = head;
    while(temp->next!= node)
        temp = temp->next;
    if(temp->next == NULL)
    {
        temp->next = NULL;
    }
    else
    {
        temp->next = node->next;
    }
    free(node);
}

void display_diary()
{
    struct diary *temp = head;
    if(temp == NULL)
    {
        printf("No diary entries found.\n");
        return;
    }
    printf("Diary Entries: \n");
    while(temp!= NULL)
    {
        printf("Title: %s\n", temp->title);
        printf("Date: %d\n", temp->day);
        printf("Content: %s\n", temp->content);
        temp = temp->next;
    }
}

int main()
{
    struct diary *new_entry;
    int day, choice;
    char title[100], content[1000];

    printf("1. Add a new diary entry\n");
    printf("2. Delete a diary entry\n");
    printf("3. Display diary entries\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    while(choice!= 4)
    {
        switch(choice)
        {
            case 1:
                printf("Enter the title: ");
                fgets(title, 100, stdin);
                title[strcspn(title, "\n")] = '\0';
                printf("Enter the content: ");
                fgets(content, 1000, stdin);
                content[strcspn(content, "\n")] = '\0';
                printf("Enter the date (in form of day): ");
                scanf("%d", &day);
                new_entry = (struct diary*)malloc(sizeof(struct diary));
                strcpy(new_entry->title, title);
                new_entry->day = day;
                strcpy(new_entry->content, content);
                new_entry->next = NULL;
                insert(new_entry);
                printf("New entry added successfully!\n");
                break;

            case 2:
                printf("Enter the title of the diary entry you want to delete: ");
                fgets(title, 100, stdin);
                title[strcspn(title, "\n")] = '\0';
                delete_node(title);
                printf("Diary entry deleted successfully!\n");
                break;

            case 3:
                display_diary();
                break;

            default:
                printf("Invalid choice. Try again.\n");
                break;
        }

        printf("1. Add a new diary entry\n");
        printf("2. Delete a diary entry\n");
        printf("3. Display diary entries\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    }

    return 0;
}