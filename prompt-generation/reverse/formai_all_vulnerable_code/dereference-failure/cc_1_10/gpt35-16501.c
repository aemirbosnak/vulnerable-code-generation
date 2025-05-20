//FormAI DATASET v1.0 Category: Music Library Management System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song {
    char title[50];
    char artist[50];
    char album[50];
    float duration;  // in minutes
    int year;
} Song;

typedef struct node {
    Song data;
    struct node *next;
} Node;

Node *head = NULL;

Song create_song(char *title, char *artist, char *album, float duration, int year) {
    Song new_song;
    strcpy(new_song.title, title);
    strcpy(new_song.artist, artist);
    strcpy(new_song.album, album);
    new_song.duration = duration;
    new_song.year = year;
    return new_song;
}

void print_song(Song song) {
    printf("Title: %s\n", song.title);
    printf("Artist: %s\n", song.artist);
    printf("Album: %s\n", song.album);
    printf("Duration: %.2f minutes\n", song.duration);
    printf("Year: %d\n", song.year);
}

void add_song(Song song) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->data = song;
    new_node->next = head;
    head = new_node;
}

void display_songs() {
    if (head == NULL) {
        printf("No songs found.\n");
    } else {
        Node *curr = head;
        while (curr != NULL) {
            print_song(curr->data);
            printf("------------------------\n");
            curr = curr->next;
        }
    }
}

void search_by_title(char *title) {
    int count = 0;
    Node *curr = head;
    while (curr != NULL) {
        if (strcmp(curr->data.title, title) == 0) {
            print_song(curr->data);
            printf("------------------------\n");
            count += 1;
        }
        curr = curr->next;
    }
    if (count == 0) {
        printf("No song found with title: %s\n", title);
    } else {
        printf("Total %d songs found with title: %s\n", count, title);
    }
}

void search_by_artist(char *artist) {
    int count = 0;
    Node *curr = head;
    while (curr != NULL) {
        if (strcmp(curr->data.artist, artist) == 0) {
            print_song(curr->data);
            printf("------------------------\n");
            count += 1;
        }
        curr = curr->next;
    }
    if (count == 0) {
        printf("No song found with artist: %s\n", artist);
    } else {
        printf("Total %d songs found with artist: %s\n", count, artist);
    }
}

void search_by_album(char *album) {
    int count = 0;
    Node *curr = head;
    while (curr != NULL) {
        if (strcmp(curr->data.album, album) == 0) {
            print_song(curr->data);
            printf("------------------------\n");
            count += 1;
        }
        curr = curr->next;
    }
    if (count == 0) {
        printf("No song found in album: %s\n", album);
    } else {
        printf("Total %d songs found in album: %s\n", count, album);
    }
}

int count_songs() {
    int count = 0;
    Node *curr = head;
    while (curr != NULL) {
        count += 1;
        curr = curr->next;
    }
    return count;
}

void delete_song(char *title) {
    Node *curr = head;
    Node *prev = NULL;
    while (curr != NULL) {
        if (strcmp(curr->data.title, title) == 0) {
            if (prev == NULL) {
                head = curr->next;
                free(curr);
            } else {
                prev->next = curr->next;
                free(curr);
            }
            printf("Song with title '%s' has been deleted.\n", title);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("No song found with title: %s. Nothing has been deleted.\n", title);
}

void save_songs(char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Failed to create/update file %s.\n", filename);
    } else {
        Node *curr = head;
        while (curr != NULL) {
            fprintf(fp, "%s,%s,%s,%.2f,%d\n",
                curr->data.title, curr->data.artist, curr->data.album,
                curr->data.duration, curr->data.year);
            curr = curr->next;
        }
        fclose(fp);
        printf("Successfully saved %d songs into file %s.\n", count_songs(), filename);
    }
}

void load_songs(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file %s.\n", filename);
    } else {
        char line[200];
        while (fgets(line, sizeof(line), fp)) {
            char *title = strtok(line, ",");
            char *artist = strtok(NULL, ",");
            char *album = strtok(NULL, ",");
            float duration = atof(strtok(NULL, ","));
            int year = atoi(strtok(NULL, ",\n"));
            Song new_song = create_song(title, artist, album, duration, year);
            add_song(new_song);
        }
        fclose(fp);
        printf("Successfully loaded %d songs from file %s.\n", count_songs(), filename);
    }
}

int main() {
    printf("Welcome to the C Music Library Management System\n");
    printf("------------------------------------------------\n");

    // load songs from file
    load_songs("songs.csv");

    // program loop
    while (1) {
        printf("1. Display all songs\n");
        printf("2. Search for a song by title\n");
        printf("3. Search for songs by artist\n");
        printf("4. Search for songs in an album\n");
        printf("5. Count the number of songs in the library\n");
        printf("6. Add a song to the library\n");
        printf("7. Delete a song from the library\n");
        printf("8. Save the library to a file\n");
        printf("9. Exit program\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nAll songs in the library:\n");
                display_songs();
                break;
            case 2:
                printf("\nEnter the title to search for: ");
                char title[50];
                scanf("%s", title);
                search_by_title(title);
                break;
            case 3:
                printf("\nEnter the artist to search for: ");
                char artist[50];
                scanf("%s", artist);
                search_by_artist(artist);
                break;
            case 4:
                printf("\nEnter the album to search for: ");
                char album[50];
                scanf("%s", album);
                search_by_album(album);
                break;
            case 5:
                printf("\nTotal %d songs in the library.\n", count_songs());
                break;
            case 6:
                printf("\nEnter the song details:");
                printf("\nTitle: ");
                char new_title[50];
                scanf("%s", new_title);
                printf("Artist: ");
                char new_artist[50];
                scanf("%s", new_artist);
                printf("Album: ");
                char new_album[50];
                scanf("%s", new_album);
                printf("Duration (in minutes): ");
                float new_duration;
                scanf("%f", &new_duration);
                printf("Year: ");
                int new_year;
                scanf("%d", &new_year);
                Song new_song = create_song(new_title, new_artist, new_album, new_duration, new_year);
                add_song(new_song);
                printf("\nSuccessfully added the song:\n");
                print_song(new_song);
                break;
            case 7:
                printf("\nEnter the title of the song to delete: ");
                char del_title[50];
                scanf("%s", del_title);
                delete_song(del_title);
                break;
            case 8:
                save_songs("songs.csv");
                break;
            case 9:
                printf("\nThank you for using C Music Library Management System!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
        printf("\n");
    }

    return 0;
}