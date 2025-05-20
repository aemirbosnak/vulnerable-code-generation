//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Holy Smokes! A Music Library Management System in C! Prepare for a wild ride!

// Define the good ol' trusty song struct
typedef struct song {
    char *title;
    char *artist;
    int year;
} song_t;

// And now, let's build a library full of groovy tunes
song_t *library;
int num_songs = 0;

// Time to add some bangers to the library!
void add_song(char *title, char *artist, int year) {
    // Say hello to a brand-new song!
    song_t *new_song = malloc(sizeof(song_t));
    new_song->title = strdup(title);
    new_song->artist = strdup(artist);
    new_song->year = year;

    // Oops, we gotta make some room for the new kid on the block!
    library = realloc(library, sizeof(song_t) * (num_songs + 1));

    // Let's give the new song its spot in the library
    library[num_songs++] = *new_song;
    free(new_song); // No more need for the temporary variable
}

// Ready to rock the playlist? Let's list all those sweet tunes!
void list_songs() {
    printf("Get ready for the ultimate playlist! Brace yourself, music lovers:\n");
    for (int i = 0; i < num_songs; i++) {
        printf("%d. %s by %s (%d)\n", i + 1, library[i].title, library[i].artist, library[i].year);
    }
}

// Hold your horses! Let's search for a specific song
void search_song(char *query) {
    int found = 0;
    for (int i = 0; i < num_songs; i++) {
        if (strstr(library[i].title, query) || strstr(library[i].artist, query)) {
            printf("Found it! Check out '%s' by %s (%d).\n", library[i].title, library[i].artist, library[i].year);
            found = 1;
        }
    }
    if (!found) {
        printf("Sorry, couldn't find that one. Better luck next time!\n");
    }
}

// Time to say goodbye to some tunes. Let's delete a song
void delete_song(int index) {
    if (index >= 0 && index < num_songs) {
        // Sayonara, song!
        free(library[index].title);
        free(library[index].artist);
        // Let's shift the library to fill the gap
        for (int i = index; i < num_songs - 1; i++) {
            library[i] = library[i + 1];
        }
        // Resize the library to match the new number of songs
        library = realloc(library, sizeof(song_t) * (num_songs - 1));
        num_songs--;
        printf("Ta-da! The song has been deleted.\n");
    } else {
        printf("Oops, looks like you entered an invalid index. Try again with a valid number!\n");
    }
}

// The grand finale! Let's rock and roll with the main function
int main() {
    // Welcome to the jukebox!
    printf("Welcome to the most epic Music Library Management System ever! Get ready for a musical adventure!\n");

    // Let's add some chart-toppers to our library
    add_song("Bohemian Rhapsody", "Queen", 1975);
    add_song("Stairway to Heaven", "Led Zeppelin", 1971);
    add_song("Imagine", "John Lennon", 1971);
    add_song("Hotel California", "The Eagles", 1976);
    add_song("Billie Jean", "Michael Jackson", 1982);

    // Time to show off our playlist
    list_songs();

    // Let's find a hidden gem
    search_song("Bohemian");

    // Farewell, my friend. Time to bid adieu to a tune
    delete_song(2);

    // Encore! One last glance at the updated playlist
    list_songs();

    // It's been a wild ride!
    printf("Thanks for rocking with us! Stay tuned for more musical adventures.\n");
    return 0;
}