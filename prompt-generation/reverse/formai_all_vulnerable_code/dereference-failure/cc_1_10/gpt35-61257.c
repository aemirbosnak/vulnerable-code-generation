//FormAI DATASET v1.0 Category: Music Library Management System ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char song[100];
    char artist[100];
    int year;
    struct node* next;
};

void print_list(struct node *n)
{
    while(n != NULL)
    {
        printf("%s - %s (%d)\n", n->artist, n->song, n->year);
        n = n->next;
    }
}

struct node* insert_node(struct node* n, char song[], char artist[], int year)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    strcpy(new_node->song, song);
    strcpy(new_node->artist, artist);
    new_node->year = year;
    new_node->next = n;
    return new_node;
}

struct node* delete_node(struct node* n, char song[])
{
    struct node* current_node = n;
    struct node* previous_node = NULL;

    while(current_node != NULL)
    {
        if(strcmp(current_node->song, song) == 0)
        {
            // Found the node to be deleted
            if(previous_node == NULL)
            {
                // It's the first node
                n = current_node->next;
            }
            else
            {
                previous_node->next = current_node->next;
            }

            free(current_node);
            return n;
        }

        previous_node = current_node;
        current_node = current_node->next;
    }

    return n;
}

void search_node(struct node* n, char song[])
{
    while(n != NULL)
    {
        if(strcmp(n->song, song) == 0)
        {
            printf("%s - %s (%d)\n", n->artist, n->song, n->year);
            return;
        }
        n = n->next;
    }

    printf("Sorry, song not found.\n");
}

int main()
{
    struct node* song_library = NULL;

    // Adding some songs to the library
    song_library = insert_node(song_library, "Stairway to Heaven", "Led Zeppelin", 1971);
    song_library = insert_node(song_library, "Bohemian Rhapsody", "Queen", 1975);
    song_library = insert_node(song_library, "Imagine", "John Lennon", 1971);

    // Printing all the songs in the library
    printf("All songs:\n");
    print_list(song_library);

    // Searching for a song
    printf("\nSearching for \"Imagine\"...\n");
    search_node(song_library, "Imagine");

    // Deleting a song
    printf("\nDeleting \"Bohemian Rhapsody\"...\n");
    song_library = delete_node(song_library, "Bohemian Rhapsody");

    // Printing all the songs in the library again
    printf("\nAll songs again:\n");
    print_list(song_library);

    return 0;
}