//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

// Structure to represent a song
typedef struct song {
    char *title;
    char *artist;
    int duration;
} song_t;

// Structure to represent the music library
typedef struct music_library {
    song_t *songs;
    int num_songs;
} music_library_t;

// Mutex to protect the music library
pthread_mutex_t library_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to create a new song
song_t *create_song(char *title, char *artist, int duration) {
    song_t *song = malloc(sizeof(song_t));
    song->title = strdup(title);
    song->artist = strdup(artist);
    song->duration = duration;
    return song;
}

// Function to add a song to the music library
void add_song(music_library_t *library, song_t *song) {
    // Lock the mutex to protect the library
    pthread_mutex_lock(&library_mutex);

    // Add the song to the library
    library->songs = realloc(library->songs, (library->num_songs + 1) * sizeof(song_t));
    library->songs[library->num_songs++] = *song;

    // Unlock the mutex
    pthread_mutex_unlock(&library_mutex);
}

// Function to get a song from the music library
song_t *get_song(music_library_t *library, int index) {
    // Lock the mutex to protect the library
    pthread_mutex_lock(&library_mutex);

    // Get the song from the library
    song_t *song = &library->songs[index];

    // Unlock the mutex
    pthread_mutex_unlock(&library_mutex);

    return song;
}

// Function to remove a song from the music library
void remove_song(music_library_t *library, int index) {
    // Lock the mutex to protect the library
    pthread_mutex_lock(&library_mutex);

    // Remove the song from the library
    free(library->songs[index].title);
    free(library->songs[index].artist);
    for (int i = index + 1; i < library->num_songs; i++) {
        library->songs[i - 1] = library->songs[i];
    }
    library->num_songs--;

    // Unlock the mutex
    pthread_mutex_unlock(&library_mutex);
}

// Function to print the music library
void print_library(music_library_t *library) {
    // Lock the mutex to protect the library
    pthread_mutex_lock(&library_mutex);

    // Print the library
    printf("Music Library:\n");
    for (int i = 0; i < library->num_songs; i++) {
        song_t *song = &library->songs[i];
        printf("%d. %s by %s (%d seconds)\n", i + 1, song->title, song->artist, song->duration);
    }

    // Unlock the mutex
    pthread_mutex_unlock(&library_mutex);
}

// Thread function to add a song to the music library
void *add_song_thread(void *args) {
    // Get the arguments
    music_library_t *library = (music_library_t *)args;
    char *title = "New Song";
    char *artist = "New Artist";
    int duration = 180;

    // Create a new song
    song_t *song = create_song(title, artist, duration);

    // Add the song to the library
    add_song(library, song);

    // Return NULL to indicate success
    return NULL;
}

// Thread function to get a song from the music library
void *get_song_thread(void *args) {
    // Get the arguments
    music_library_t *library = (music_library_t *)args;
    int index = 0;

    // Get the song from the library
    song_t *song = get_song(library, index);

    // Print the song
    printf("Song:\n");
    printf("%s by %s (%d seconds)\n", song->title, song->artist, song->duration);

    // Return NULL to indicate success
    return NULL;
}

// Thread function to remove a song from the music library
void *remove_song_thread(void *args) {
    // Get the arguments
    music_library_t *library = (music_library_t *)args;
    int index = 0;

    // Remove the song from the library
    remove_song(library, index);

    // Return NULL to indicate success
    return NULL;
}

// Main function
int main() {
    // Create a music library
    music_library_t library;
    library.songs = NULL;
    library.num_songs = 0;

    // Create threads to add, get, and remove songs from the library
    pthread_t threads[NUM_THREADS];
    pthread_create(&threads[0], NULL, add_song_thread, &library);
    pthread_create(&threads[1], NULL, get_song_thread, &library);
    pthread_create(&threads[2], NULL, remove_song_thread, &library);

    // Join the threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the library
    print_library(&library);

    // Free the library
    for (int i = 0; i < library.num_songs; i++) {
        free(library.songs[i].title);
        free(library.songs[i].artist);
    }
    free(library.songs);

    return 0;
}