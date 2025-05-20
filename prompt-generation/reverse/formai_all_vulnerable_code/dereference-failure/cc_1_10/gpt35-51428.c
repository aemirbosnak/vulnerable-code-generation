//FormAI DATASET v1.0 Category: Music Library Management System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>

// struct to represent each song
typedef struct song_t {
    int id;
    char title[100];
    char artist[100];
    char album[100];
    int year;
    struct song_t* next;
} Song;

// struct to represent the music library
typedef struct music_library_t {
    int num_songs;
    Song* head;
    pthread_mutex_t mutex;
} MusicLibrary;

// function to create a new song
Song* create_song(int id, char* title, char* artist, char* album, int year) {
    Song* song = (Song*) malloc(sizeof(Song));
    song->id = id;
    strcpy(song->title, title);
    strcpy(song->artist, artist);
    strcpy(song->album, album);
    song->year = year;
    song->next = NULL;
    return song;
}

// function to add a new song to the music library
void add_song(MusicLibrary* library, Song* song) {
    pthread_mutex_lock(&library->mutex);
    if (library->head == NULL) {
        library->head = song;
    } else {
        Song* current = library->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = song;
    }
    library->num_songs++;
    pthread_mutex_unlock(&library->mutex);
}

// function to remove a song from the music library
void remove_song(MusicLibrary* library, int id) {
    pthread_mutex_lock(&library->mutex);
    if (library->head != NULL) {
        if (library->head->id == id) {
            Song* to_remove = library->head;
            library->head = library->head->next;
            free(to_remove);
            library->num_songs--;
        } else {
            Song* current = library->head;
            while (current->next != NULL) {
                if (current->next->id == id) {
                    Song* to_remove = current->next;
                    current->next = current->next->next;
                    free(to_remove);
                    library->num_songs--;
                    break;
                }
                current = current->next;
            }
        }
    }
    pthread_mutex_unlock(&library->mutex);
}

// function to search for songs based on title or artist
Song* search_songs(MusicLibrary* library, char* query) {
    Song* result = NULL;
    pthread_mutex_lock(&library->mutex);
    if (library->head != NULL) {
        Song* current = library->head;
        while (current != NULL) {
            if (strstr(current->title, query) != NULL || strstr(current->artist, query) != NULL) {
                Song* matching_song = create_song(current->id, current->title, current->artist, current->album, current->year);
                matching_song->next = result;
                result = matching_song;
            }
            current = current->next;
        }
    }
    pthread_mutex_unlock(&library->mutex);
    return result;
}

// function to print a song's details
void print_song(Song* song) {
    printf("ID: %d\n", song->id);
    printf("Title: %s\n", song->title);
    printf("Artist: %s\n", song->artist);
    printf("Album: %s\n", song->album);
    printf("Year: %d\n\n", song->year);
}

// function to print all songs in the music library
void print_library(MusicLibrary* library) {
    pthread_mutex_lock(&library->mutex);
    if (library->head != NULL) {
        Song* current = library->head;
        while (current != NULL) {
            print_song(current);
            current = current->next;
        }
    }
    printf("Total songs: %d\n", library->num_songs);
    pthread_mutex_unlock(&library->mutex);
}

// function to free up memory used by a song and its linked list
void free_song(Song* song) {
    if (song->next != NULL) {
        free_song(song->next);
    }
    free(song);
}

int main() {
    MusicLibrary library = {0, NULL, PTHREAD_MUTEX_INITIALIZER};
    Song* song1 = create_song(1, "Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975);
    Song* song2 = create_song(2, "Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971);
    Song* song3 = create_song(3, "Hotel California", "Eagles", "Hotel California", 1976);
    add_song(&library, song1);
    add_song(&library, song2);
    add_song(&library, song3);
    printf("All songs in library:\n");
    print_library(&library);
    printf("Songs containing 'heaven' or 'eagles' in title or artist:\n");
    Song* matching_songs = search_songs(&library, "heaven");
    while (matching_songs != NULL) {
        print_song(matching_songs);
        Song* to_remove = matching_songs;
        matching_songs = matching_songs->next;
        free(to_remove);
    }
    printf("Removing song with ID 2:\n");
    remove_song(&library, 2);
    printf("All songs in library after removal:\n");
    print_library(&library);
    free_song(song1);
    free_song(song3);
    return 0;
}