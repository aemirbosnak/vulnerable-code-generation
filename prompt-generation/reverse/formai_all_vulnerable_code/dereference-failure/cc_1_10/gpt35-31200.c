//FormAI DATASET v1.0 Category: Music Library Management System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for creating a new song node 
struct song
{
    char title[50];
    char artist[50];
    char album[50];
    int year;
    struct song *next;
};

// Function declaration
void menu();
void add_song();
void display_library();
void search_by_title();
void search_by_artist();
void search_by_year();
void delete_song();

// Global variables
struct song *head = NULL;
int size = 0;

// Main function
int main()
{
    menu();
    return 0;
}

// Function to display menu
void menu()
{
    int choice;

    printf("\n--- C Music Library Management System ---\n");
    printf("\n1. Add Song to Library");
    printf("\n2. Display Library");
    printf("\n3. Search Song by Title");
    printf("\n4. Search Song by Artist");
    printf("\n5. Search Song by Year");
    printf("\n6. Delete Song from Library");
    printf("\n7. Exit");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            add_song();
            break;

        case 2:
            display_library();
            break;

        case 3:
            search_by_title();
            break;

        case 4:
            search_by_artist();
            break;

        case 5:
            search_by_year();
            break;

        case 6:
            delete_song();
            break;

        case 7:
            exit(0);
            break;

        default:
            printf("\nInvalid Choice!\n");
            menu();
    }
}

// Function to add a new song to library
void add_song()
{
    struct song *temp, *new_node;
    new_node = (struct song*)malloc(sizeof(struct song));

    printf("\nEnter Song Title: ");
    scanf(" %[^\n]", new_node->title);

    printf("Enter Artist Name: ");
    scanf(" %[^\n]", new_node->artist);

    printf("Enter Album Name: ");
    scanf(" %[^\n]", new_node->album);

    printf("Enter Year of Release: ");
    scanf("%d", &new_node->year);

    new_node->next = NULL;

    if(head == NULL)
    {
        head = new_node;
        size++;
        printf("\nSong added to Library!");
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        size++;
        printf("\nSong added to Library!");
    }
    menu();
}

// Function to display library
void display_library()
{
    struct song *temp = head;

    if(temp == NULL)
    {
        printf("\nLibrary is Empty!");
    }
    else
    {
        printf("\n--- Library Songs ---\n");
        while(temp != NULL)
        {
            printf("Title: %s\n", temp->title);
            printf("Artist: %s\n", temp->artist);
            printf("Album: %s\n", temp->album);
            printf("Year: %d\n", temp->year);
            printf("\n");
            temp = temp->next;
        }
    }
    menu();
}

// Function to search song by title
void search_by_title()
{
    struct song *temp = head;
    char search_title[50];
    int flag = 0;

    printf("\nEnter Song Title: ");
    scanf(" %[^\n]", search_title);

    while(temp != NULL)
    {
        if(strcmp(search_title, temp->title)==0)
        {
            printf("\nSong Found!");
            printf("\nTitle: %s", temp->title);
            printf("\nArtist: %s", temp->artist);
            printf("\nAlbum: %s", temp->album);
            printf("\nYear: %d", temp->year);
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    if(flag == 0)
    {
        printf("\nSong not found in Library!");
    }

    menu();
}

// Function to search song by artist
void search_by_artist()
{
    struct song *temp = head;
    char search_artist[50];
    int flag = 0;

    printf("\nEnter Artist Name: ");
    scanf(" %[^\n]", search_artist);

    while(temp != NULL)
    {
        if(strcmp(search_artist, temp->artist)==0)
        {
            printf("\nSong Found!");
            printf("\nTitle: %s", temp->title);
            printf("\nArtist: %s", temp->artist);
            printf("\nAlbum: %s", temp->album);
            printf("\nYear: %d", temp->year);
            flag = 1;
        }
        temp = temp->next;
    }
    if(flag == 0)
    {
        printf("\nSong not found in Library!");
    }

    menu();
}

// Function to search song by year
void search_by_year()
{
    struct song *temp = head;
    int search_year;
    int flag = 0;

    printf("\nEnter Year of Release: ");
    scanf("%d", &search_year);

    while(temp != NULL)
    {
        if(search_year == temp->year)
        {
            printf("\nSong Found!");
            printf("\nTitle: %s", temp->title);
            printf("\nArtist: %s", temp->artist);
            printf("\nAlbum: %s", temp->album);
            printf("\nYear: %d", temp->year);
            flag = 1;
        }
        temp = temp->next;
    }
    if(flag == 0)
    {
        printf("\nSong not found in Library!");
    }

    menu();
}

// Function to delete a song from library
void delete_song()
{
    struct song *current_node, *prev_node;
    char delete_title[50];
    int flag = 0;

    printf("\nEnter Song Title to be deleted: ");
    scanf(" %[^\n]", delete_title);

    if(head == NULL)
    {
        printf("\nLibrary is Empty!");
    }
    else
    {
        current_node = head;
        prev_node = head;
        while(current_node != NULL)
        {
            if(strcmp(delete_title, current_node->title)==0)
            {
                flag = 1;
                if(current_node == head)
                {
                    head = current_node->next;
                }
                else
                {
                    prev_node->next = current_node->next;
                }
                free(current_node);
                size--;
                printf("\nSong deleted from Library!");
                break;
            }
            prev_node = current_node;
            current_node = current_node->next;
        }
        if(flag == 0)
        {
            printf("\nSong not found in Library!");
        }
    }
    menu();
}