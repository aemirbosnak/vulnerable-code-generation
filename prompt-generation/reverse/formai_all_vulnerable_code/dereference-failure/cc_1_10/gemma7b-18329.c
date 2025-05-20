//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Music_Record
{
    char title[50];
    char artist[50];
    char genre[50];
    int year;
    struct Music_Record* next;
} Music_Record;

void insert(Music_Record**, char*, char*, char*, int);
void search(Music_Record*, char*, char*, int);

int main()
{
    Music_Record* head = NULL;

    insert(&head, "The Darkest Night of the Soul", "The Doors", "Rock", 1967);
    insert(&head, "Like a Rolling Stone", "The Rolling Stones", "Rock", 1965);
    insert(&head, "Another One Bites the Dust", "Queen", "Rock", 1975);

    search(head, "The Doors", "Rock", 1967);

    return 0;
}

void insert(Music_Record** head, char* title, char* artist, char* genre, int year)
{
    Music_Record* new_record = (Music_Record*)malloc(sizeof(Music_Record));

    strcpy(new_record->title, title);
    strcpy(new_record->artist, artist);
    strcpy(new_record->genre, genre);
    new_record->year = year;
    new_record->next = NULL;

    if (*head == NULL)
    {
        *head = new_record;
    }
    else
    {
        (*head)->next = new_record;
        *head = new_record;
    }
}

void search(Music_Record* head, char* artist, char* genre, int year)
{
    while (head)
    {
        if (strcmp(head->artist, artist) == 0 && strcmp(head->genre, genre) == 0 && head->year == year)
        {
            printf("Title: %s\n", head->title);
            printf("Year: %d\n", head->year);
            printf("\n");
        }
        head = head->next;
    }
}