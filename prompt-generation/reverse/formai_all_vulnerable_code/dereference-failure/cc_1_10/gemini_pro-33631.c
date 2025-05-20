//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100

// Song struct
typedef struct {
    char title[50];
    char artist[50];
    char album[50];
    int year;
} Song;

// Library array
Song library[MAX_SONGS];

// Current song index
int current_song = -1;

// Get a string from the user
char *get_string(char *prompt) {
    char *input = NULL;
    size_t size = 0;

    printf("%s", prompt);
    getline(&input, &size, stdin);

    // Remove newline character
    input[strcspn(input, "\n")] = '\0';

    return input;
}

// Get an integer from the user
int get_int(char *prompt) {
    int input = 0;

    printf("%s", prompt);
    scanf("%d", &input);

    return input;
}

// Add a song to the library
void add_song() {
    // Get song details
    char *title = get_string("Enter song title: ");
    char *artist = get_string("Enter artist name: ");
    char *album = get_string("Enter album name: ");
    int year = get_int("Enter release year: ");

    // Add song to library
    Song song = { .title = title, .artist = artist, .album = album, .year = year };
    library[current_song++] = song;
}

// Print the library
void print_library() {
    for (int i = 0; i < current_song; i++) {
        Song song = library[i];
        printf("%s by %s (%s, %d)\n", song.title, song.artist, song.album, song.year);
    }
}

// Search the library
void search_library() {
    char *query = get_string("Enter search query: ");

    for (int i = 0; i < current_song; i++) {
        Song song = library[i];
        if (strstr(song.title, query) || strstr(song.artist, query) || strstr(song.album, query)) {
            printf("%s by %s (%s, %d)\n", song.title, song.artist, song.album, song.year);
        }
    }
}

// Delete a song from the library
void delete_song() {
    int index = get_int("Enter song index: ");

    if (index >= 0 && index < current_song) {
        // Shift songs after the deleted song to the left
        for (int i = index; i < current_song - 1; i++) {
            library[i] = library[i + 1];
        }

        // Decrement the current song count
        current_song--;
    } else {
        printf("Invalid song index.\n");
    }
}

// Main menu
void main_menu() {
    int choice = 0;

    while (choice != 6) {
        printf("\nMusic Library Management System\n");
        printf("1. Add Song\n");
        printf("2. Print Library\n");
        printf("3. Search Library\n");
        printf("4. Delete Song\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_song();
                break;
            case 2:
                print_library();
                break;
            case 3:
                search_library();
                break;
            case 4:
                delete_song();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}

// Main function
int main() {
    main_menu();

    return 0;
}