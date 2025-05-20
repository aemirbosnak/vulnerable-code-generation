//FormAI DATASET v1.0 Category: Music Library Management System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 50
#define MAX_ARTIST_LENGTH 30
#define MAX_ALBUM_LENGTH 30
#define MAX_YEAR_LENGTH 5

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    char album[MAX_ALBUM_LENGTH];
    char year[MAX_YEAR_LENGTH];
} Song;

typedef struct {
    Song* songs;
    int num_songs;
} MusicLibrary;

void addSong(MusicLibrary* lib, Song new_song) {
    // Add the new song to the library
    lib->num_songs++;
    lib->songs = (Song*)realloc(lib->songs, lib->num_songs * sizeof(Song));
    lib->songs[lib->num_songs-1] = new_song;
}

void displayLibrary(MusicLibrary* lib) {
    // Display the entire library
    printf("Music Library:\n");
    for(int i=0; i<lib->num_songs; i++) {
        printf("%d. %s - %s (%s, %s)\n", i+1, lib->songs[i].title, lib->songs[i].artist, lib->songs[i].album, lib->songs[i].year);
    }
}

void searchSongsByArtist(MusicLibrary* lib, char* search_artist) {
    // Search for songs by artist and display results
    int num_results = 0;
    printf("Search Results for Artist: %s\n", search_artist);
    for(int i=0; i<lib->num_songs; i++) {
        if(strcmp(lib->songs[i].artist, search_artist) == 0) {
            printf("%d. %s - %s (%s, %s)\n", num_results+1, lib->songs[i].title, lib->songs[i].artist, lib->songs[i].album, lib->songs[i].year);
            num_results++;
        }
    }
    if(num_results == 0) {
        printf("No results found.\n");
    }
}

int main() {
    MusicLibrary my_library = {.songs = NULL, .num_songs = 0};
    char input_title[MAX_TITLE_LENGTH];
    char input_artist[MAX_ARTIST_LENGTH];
    char input_album[MAX_ALBUM_LENGTH];
    char input_year[MAX_YEAR_LENGTH];
    
    // Add some sample songs to the library
    Song song1 = {.title = "Bohemian Rhapsody", .artist = "Queen", .album = "A Night at the Opera", .year = "1975"};
    Song song2 = {.title = "Stairway to Heaven", .artist = "Led Zeppelin", .album = "Untitled", .year = "1971"};
    Song song3 = {.title = "Hey Jude", .artist = "The Beatles", .album = "Hey Jude", .year = "1968"};
    addSong(&my_library, song1);
    addSong(&my_library, song2);
    addSong(&my_library, song3);
    
    // Display the initial library
    displayLibrary(&my_library);
    
    // Allow the user to add new songs to the library
    char add_song_option;
    do {
        printf("Would you like to add a song to the library? (Y/N) ");
        scanf(" %c", &add_song_option);
        if(add_song_option == 'Y' || add_song_option == 'y') {
            printf("Enter the title of the song: ");
            scanf(" %[^\n]", input_title);
            printf("Enter the artist of the song: ");
            scanf(" %[^\n]", input_artist);
            printf("Enter the album of the song: ");
            scanf(" %[^\n]", input_album);
            printf("Enter the year of the song: ");
            scanf(" %[^\n]", input_year);
            Song new_song = {.title = input_title, .artist = input_artist, .album = input_album, .year = input_year};
            addSong(&my_library, new_song);
            printf("Song added to library.\n");
        }
    } while (add_song_option == 'Y' || add_song_option == 'y');
    
    // Display the updated library
    displayLibrary(&my_library);
    
    // Allow the user to search for songs by artist
    char search_artist[MAX_ARTIST_LENGTH];
    printf("Enter the name of an artist to search for: ");
    scanf(" %[^\n]", search_artist);
    searchSongsByArtist(&my_library, search_artist);
    
    // Free the memory used by the music library
    free(my_library.songs);
    
    return 0;
}