//FormAI DATASET v1.0 Category: Music Library Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song
{
    char title[50];
    char artist[50];
    int year;
    struct song *next;
};

void add_song(struct song **s_head);
void display_songs(struct song *s_head);
void search_song(struct song *s_head, char *t);
void delete_song(struct song **s_head, char *t);
void edit_song(struct song *s_head, char *t);

int main()
{
    struct song *s_head = NULL;
    int choice;
    char title[50];

    do
    {
        printf("Welcome to the Music Library Management System!\n");
        printf("1. Add Song\n");
        printf("2. Display Songs\n");
        printf("3. Search Song\n");
        printf("4. Delete Song\n");
        printf("5. Edit Song\n");
        printf("6. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                add_song(&s_head);
                break;
            case 2:
                display_songs(s_head);
                break;
            case 3:
                printf("Enter title of the song to search: ");
                scanf("%s", title);
                search_song(s_head, title);
                break;
            case 4:
                printf("Enter title of the song to delete: ");
                scanf("%s", title);
                delete_song(&s_head, title);
                break;
            case 5:
                printf("Enter title of the song to edit: ");
                scanf("%s", title);
                edit_song(s_head, title);
                break;
            case 6:
                printf("Exiting program. Goodbye!");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

void add_song(struct song **s_head)
{
    struct song *new_song = malloc(sizeof(struct song));
    printf("Enter title: ");
    scanf("%s", new_song->title);
    printf("Enter artist: ");
    scanf("%s", new_song->artist);
    printf("Enter year: ");
    scanf("%d", &new_song->year);
    new_song->next = *s_head;
    *s_head = new_song;
    printf("Song added!\n");
}

void display_songs(struct song *s_head)
{
    if (s_head == NULL)
    {
        printf("No songs in the library!\n");
        return;
    }

    printf("Title\t\tArtist\t\tYear\n");
    printf("-------------------------------------------------------------\n");

    struct song *temp = s_head;
    while (temp != NULL)
    {
        printf("%s\t\t%s\t\t%d\n", temp->title, temp->artist, temp->year);
        temp = temp->next;
    }
}

void search_song(struct song *s_head, char *t)
{
    if (s_head == NULL)
    {
        printf("No songs in the library!\n");
        return;
    }

    struct song *temp = s_head;
    while (temp != NULL)
    {
        if (strcmp(temp->title, t) == 0)
        {
            printf("Song found!\n");
            printf("Title\t\tArtist\t\tYear\n");
            printf("-------------------------------------------------------------\n");
            printf("%s\t\t%s\t\t%d\n", temp->title, temp->artist, temp->year);
            return;
        }

        temp = temp->next;
    }

    printf("Song not found!\n");
}

void delete_song(struct song **s_head, char *t)
{
    if (*s_head == NULL)
    {
        printf("No songs in the library!\n");
        return;
    }

    struct song *temp = *s_head;
    struct song *prev = NULL;

    while (temp != NULL)
    {
        if (strcmp(temp->title, t) == 0)
        {
            if (prev == NULL)
            {
                *s_head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }

            free(temp);
            printf("Song deleted!\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Song not found!\n");
}

void edit_song(struct song *s_head, char *t)
{
    if (s_head == NULL)
    {
        printf("No songs in the library!\n");
        return;
    }

    struct song *temp = s_head;
    while (temp != NULL)
    {
        if (strcmp(temp->title, t) == 0)
        {
            printf("Enter new title: ");
            scanf("%s", temp->title);
            printf("Enter new artist: ");
            scanf("%s", temp->artist);
            printf("Enter new year: ");
            scanf("%d", &temp->year);
            printf("Song updated!\n");
            return;
        }

        temp = temp->next;
    }

    printf("Song not found!\n");
}