//FormAI DATASET v1.0 Category: Music Library Management System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHARS 100

struct song {
    char name[MAX_CHARS];
    char artist[MAX_CHARS];
    int year;
    int rating;
};

struct song_node {
    struct song song;
    struct song_node* next;
};

void print_menu() {
    printf("---------Music Library Management System---------\n");
    printf("1. Add song\n");
    printf("2. Display all songs\n");
    printf("3. Display songs by artist\n");
    printf("4. Delete song\n");
    printf("5. Exit\n");
}

void add_song(struct song_node** head) {
    // create new song
    struct song new_song;
    printf("Enter name of song: ");
    scanf("%s", new_song.name);
    printf("Enter name of artist: ");
    scanf("%s", new_song.artist);
    printf("Enter year of release: ");
    scanf("%d", &new_song.year);
    printf("Enter rating (1-5): ");
    scanf("%d", &new_song.rating);

    // create new song node
    struct song_node* new_node = (struct song_node*)malloc(sizeof(struct song_node));
    new_node->song = new_song;
    new_node->next = NULL;

    // add node to list
    if (*head == NULL) {
        *head = new_node;
    } else {
        struct song_node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    printf("Successfully added song!\n");
}

void display_all_songs(struct song_node* head) {
    if (head == NULL) {
        printf("No songs in the library.\n");
    } else {
        printf("All songs in the library:\n");
        struct song_node* temp = head;
        while (temp != NULL) {
            printf("%s - %s (%d) Rating: %d\n", temp->song.name, temp->song.artist, temp->song.year, temp->song.rating);
            temp = temp->next;
        }
    }
}

void display_songs_by_artist(struct song_node* head) {
    char artist[MAX_CHARS];
    printf("Enter artist name: ");
    scanf("%s", artist);

    struct song_node* temp = head;
    int found = 0;
    printf("Songs by %s:\n", artist);
    while (temp != NULL) {
        if (strcmp(temp->song.artist, artist) == 0) {
            printf("%s - %s (%d) Rating: %d\n", temp->song.name, temp->song.artist, temp->song.year, temp->song.rating);
            found = 1;
        }
        temp = temp->next;
    }

    if (!found) {
        printf("No songs by %s found.\n", artist);
    }
}

void delete_song(struct song_node** head) {
    char name[MAX_CHARS];
    printf("Enter name of song to delete: ");
    scanf("%s", name);

    struct song_node* temp = *head;
    struct song_node* prev = NULL;
    int found = 0;
    while (temp != NULL) {
        if (strcmp(temp->song.name, name) == 0) {
            found = 1;
            if (prev == NULL) {
                *head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("Successfully deleted song!\n");
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    if (!found) {
        printf("Song not found.\n");
    }
}

int main() {
    struct song_node* head = NULL;
    int option;

    do {
        print_menu();
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                add_song(&head);
                break;
            case 2:
                display_all_songs(head);
                break;
            case 3:
                display_songs_by_artist(head);
                break;
            case 4:
                delete_song(&head);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    } while (option != 5);

    return 0;
}