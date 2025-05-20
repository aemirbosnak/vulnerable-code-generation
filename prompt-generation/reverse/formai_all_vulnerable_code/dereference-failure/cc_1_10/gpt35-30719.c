//FormAI DATASET v1.0 Category: Music Library Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

struct song {
    int id;
    char title[MAX_LEN];
    char artist[MAX_LEN];
    char album[MAX_LEN];
    float duration;
    struct song *next_song;
};

int length = 0;

void display_menu();
void add_song(struct song **head);
void remove_song(struct song **head, int id);
void search_song(struct song *head, char *title);
void display_songs(struct song *head);
void clear_library(struct song **head);

int main() {
    struct song *head = NULL;
    int choice, id;
    char title[MAX_LEN];

    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_song(&head);
                break;

            case 2:
                printf("Enter the ID of the song to remove: ");
                scanf("%d", &id);
                remove_song(&head, id);
                break;

            case 3:
                printf("Enter the title of the song to search: ");
                scanf("%s", title);
                search_song(head, title);
                break;

            case 4:
                display_songs(head);
                break;

            case 5:
                clear_library(&head);
                break;

            case 6:
                printf("Exiting the program...\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void display_menu() {
    printf("\n");
    printf("1. Add a song\n");
    printf("2. Remove a song\n");
    printf("3. Search for a song\n");
    printf("4. Display all songs\n");
    printf("5. Clear the music library\n");
    printf("6. Exit\n");
}

void add_song(struct song **head) {
    struct song *new_song = (struct song *) malloc(sizeof(struct song));
    new_song->next_song = NULL;

    printf("Enter the details of the song:\n");
    printf("ID: ");
    scanf("%d", &new_song->id);
    printf("Title: ");
    scanf("%s", new_song->title);
    printf("Artist: ");
    scanf("%s", new_song->artist);
    printf("Album: ");
    scanf("%s", new_song->album);
    printf("Duration: ");
    scanf("%f", &new_song->duration);

    if (*head == NULL) {
        *head = new_song;
    } else {
        struct song *current_song = *head;
        while (current_song->next_song != NULL) {
            current_song = current_song->next_song;
        }
        current_song->next_song = new_song;
    }

    length++;
    printf("Song added successfully!\n");
}

void remove_song(struct song **head, int id) {
    if (*head == NULL) {
        printf("The music library is empty.\n");
        return;
    }

    struct song *current_song = *head;
    struct song *previous_song = NULL;

    while (current_song != NULL) {
        if (current_song->id == id) {
            if (previous_song == NULL) {
                *head = current_song->next_song;
            } else {
                previous_song->next_song = current_song->next_song;
            }
            free(current_song);
            length--;
            printf("Song removed successfully!\n");
            return;
        }
        previous_song = current_song;
        current_song = current_song->next_song;
    }
    printf("Song not found in the music library.\n");
}

void search_song(struct song *head, char *title) {
    if (head == NULL) {
        printf("The music library is empty.\n");
        return;
    }

    struct song *current_song = head;
    int count = 1;

    while (current_song != NULL) {
        if (strcmp(current_song->title, title) == 0) {
            printf("Song #%d:\n", count);
            printf("ID: %d\n", current_song->id);
            printf("Title: %s\n", current_song->title);
            printf("Artist: %s\n", current_song->artist);
            printf("Album: %s\n", current_song->album);
            printf("Duration: %.2f\n", current_song->duration);
            return;
        }
        current_song = current_song->next_song;
        count++;
    }

    printf("Song not found in the music library.\n");
}

void display_songs(struct song *head) {
    if (head == NULL) {
        printf("The music library is empty.\n");
        return;
    }

    struct song *current_song = head;
    int count = 1;

    printf("Displaying all songs in the music library:\n");
    while (current_song != NULL) {
        printf("Song #%d:\n", count);
        printf("ID: %d\n", current_song->id);
        printf("Title: %s\n", current_song->title);
        printf("Artist: %s\n", current_song->artist);
        printf("Album: %s\n", current_song->album);
        printf("Duration: %.2f\n", current_song->duration);
        printf("\n");
        current_song = current_song->next_song;
        count++;
    }
}

void clear_library(struct song **head) {
    struct song *current_song = *head;
    struct song *next_song;

    while (current_song != NULL) {
        next_song = current_song->next_song;
        free(current_song);
        current_song = next_song;
    }

    *head = NULL;
    length = 0;

    printf("The music library has been cleared.\n");
}