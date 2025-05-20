//FormAI DATASET v1.0 Category: Music Library Management System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song
{
    char title[50];
    char artist[50];
    char genre[20];
    int year;
};

struct node
{
    struct song data;
    struct node *next;
};

struct node *head = NULL;

void insertSong()
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the song title:");
    scanf("%s", newNode->data.title);
    printf("\nEnter the artist name:");
    scanf("%s", newNode->data.artist);
    printf("\nEnter the genre:");
    scanf("%s", newNode->data.genre);
    printf("\nEnter the year of release:");
    scanf("%d", &newNode->data.year);
    newNode->next = head;
    head = newNode;
    printf("\nSong added successfully!\n");
}

void deleteSong()
{
    char title[50];
    printf("\nEnter the song title to delete:");
    scanf("%s",title);
    struct node *temp = head, *prev;
    if(temp != NULL && strcmp(temp->data.title,title)==0)
    {
        head = temp->next;
        free(temp);
        printf("\nSong '%s' deleted successfully!\n", title);
        return;
    }
    while(temp != NULL && strcmp(temp->data.title,title)!=0)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL)
    {
        printf("\nSong '%s' not found in library!\n", title);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("\nSong '%s' deleted successfully!\n", title);
}

void searchSong()
{
    char title[50];
    printf("\nEnter the song title to search:");
    scanf("%s", title);
    struct node *temp = head;
    while(temp != NULL)
    {
        if(strcmp(temp->data.title, title) == 0)
        {
            printf("\nSong found in library!\nTitle: %s\nArtist: %s\nGenre: %s\nYear of Release: %d\n", 
            temp->data.title, temp->data.artist, temp->data.genre, temp->data.year);
            return;
        }
        temp = temp->next;
    }
    printf("\nSong '%s' not found in library!\n", title);
}

void displayLibrary()
{
    struct node *temp = head;
    printf("\n--- C MUSIC LIBRARY MANAGEMENT SYSTEM ---\n");
    while(temp != NULL)
    {
        printf("\nTitle: %s\nArtist: %s\nGenre: %s\nYear of Release: %d\n", 
        temp->data.title, temp->data.artist, temp->data.genre, temp->data.year);
        temp = temp->next;
    }
    printf("\n--- End of Music Library ---\n");
}

int main()
{
    int choice;
    while(1)
    {
        printf("\n--- C MUSIC LIBRARY MANAGEMENT SYSTEM ---\n");
        printf("\n1. Insert a Song\n2. Delete a Song\n3. Search for a Song\n4. Display the Music Library\n5. Exit\n");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                insertSong();
                break;
            case 2:
                deleteSong();
                break;
            case 3:
                searchSong();
                break;
            case 4:
                displayLibrary();
                break;
            case 5:
                printf("\nThank you for using C Music Library Management System!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }
    return 0;
}