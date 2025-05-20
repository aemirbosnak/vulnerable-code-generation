//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: inquisitive
// Intriguing Music Library Management System

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// A captivating structure to represent a melodic masterpiece
typedef struct Song {
    char *title;        // The enticing title of the song
    char *artist;       // The maestro behind the music
    char *genre;        // The rhythmic genre the song resides in
    int release_year;    // The year the song graced the world
    double duration;     // The enchanting length of the song in minutes
} Song;

// A captivating array to hold our enchanting songs
Song *library;

// A counter to keep track of our musical treasures
int song_count = 0;

// An inquisitive function to search for a song by its spellbinding title
void FindSongByTitle(char *title) {
    for (int i = 0; i < song_count; i++) {
        if (strcmp(library[i].title, title) == 0) {
            printf("Your enthralling request has been granted:\n");
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Genre: %s\n", library[i].genre);
            printf("Release Year: %d\n", library[i].release_year);
            printf("Duration: %.2f minutes\n", library[i].duration);
            return;
        }
    }
    printf("Alas, your search has come to naught. No such song resides in our library.\n");
}

// An inquisitive function to add a new song to our captivating collection
void AddSong(char *title, char *artist, char *genre, int release_year, double duration) {
    library = realloc(library, (song_count + 1) * sizeof(Song));
    library[song_count].title = malloc(strlen(title) + 1);
    strcpy(library[song_count].title, title);
    library[song_count].artist = malloc(strlen(artist) + 1);
    strcpy(library[song_count].artist, artist);
    library[song_count].genre = malloc(strlen(genre) + 1);
    strcpy(library[song_count].genre, genre);
    library[song_count].release_year = release_year;
    library[song_count].duration = duration;
    song_count++;
    printf("Your melodious addition has been embraced by our library.\n");
}

// An inquisitive function to list all the enchanting songs in our collection
void ListSongs() {
    printf("Behold, our captivating musical tapestry:\n");
    for (int i = 0; i < song_count; i++) {
        printf("%d. %s\n", i + 1, library[i].title);
    }
}

// An inquisitive function to free the allocated memory from our melodious collection
void FreeLibrary() {
    for (int i = 0; i < song_count; i++) {
        free(library[i].title);
        free(library[i].artist);
        free(library[i].genre);
    }
    free(library);
    song_count = 0;
}

// Our enchanting main function
int main() {
    // Initialize our library with an alluring collection
    library = malloc(sizeof(Song) * 3);
    AddSong("Bohemian Rhapsody", "Queen", "Rock", 1975, 5.54);
    AddSong("Stairway to Heaven", "Led Zeppelin", "Rock", 1971, 8.02);
    AddSong("Strawberry Fields Forever", "The Beatles", "Psychedelic", 1967, 4.05);
    song_count = 3;

    // An interactive loop to guide the user through our musical wonderland
    char input[100];
    while (1) {
        printf("Welcome to your enchanting Music Library, where melody and intrigue intertwine!\n");
        printf("Enter your musical query (search, add, list, exit): ");
        scanf("%s", input);

        if (strcmp(input, "search") == 0) {
            char title[100];
            printf("Enter the title of the song you seek: ");
            scanf(" %[^\n]", title); // Allow spaces in the title
            FindSongByTitle(title);
        } else if (strcmp(input, "add") == 0) {
            char title[100], artist[100], genre[100];
            int release_year;
            double duration;
            printf("Enter the title of the song you wish to add: ");
            scanf(" %[^\n]", title); // Allow spaces in the title
            printf("Enter the artist who serenaded this song: ");
            scanf(" %[^\n]", artist); // Allow spaces in the artist name
            printf("Tell us the enchanting genre that embraces this song: ");
            scanf(" %[^\n]", genre); // Allow spaces in the genre
            printf("In what year did this song grace the world: ");
            scanf("%d", &release_year);
            printf("How long does this musical masterpiece enchant us for (in minutes): ");
            scanf("%lf", &duration);
            AddSong(title, artist, genre, release_year, duration);
        } else if (strcmp(input, "list") == 0) {
            ListSongs();
        } else if (strcmp(input, "exit") == 0) {
            printf("May your musical journey continue to inspire and enchant you!\n");
            FreeLibrary();
            return 0;
        } else {
            printf("Your request confounds us, gentle adventurer. Please try again.\n");
        }
    }
    return 0;
}