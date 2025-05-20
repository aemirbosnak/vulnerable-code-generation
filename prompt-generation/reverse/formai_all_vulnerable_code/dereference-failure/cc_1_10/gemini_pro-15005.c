//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: multi-threaded
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

// Define the library structure
typedef struct {
    char *name;
    int num_tracks;
    char **tracks;
} Library;

// Define the thread data structure
typedef struct {
    Library *library;
    int start_index;
    int end_index;
} ThreadData;

// Function to play a track
void play_track(char *track) {
    // Play the track
    printf("Playing track: %s\n", track);
}

// Function to play all tracks in a library
void *play_tracks(void *data) {
    // Get the thread data
    ThreadData *thread_data = (ThreadData *)data;

    // Play the tracks
    for (int i = thread_data->start_index; i < thread_data->end_index; i++) {
        play_track(thread_data->library->tracks[i]);
    }

    // Return NULL to indicate that the thread has finished
    return NULL;
}

// Function to create a new thread
pthread_t create_thread(Library *library, int start_index, int end_index) {
    // Allocate memory for the thread data
    ThreadData *thread_data = malloc(sizeof(ThreadData));

    // Initialize the thread data
    thread_data->library = library;
    thread_data->start_index = start_index;
    thread_data->end_index = end_index;

    // Create the thread
    pthread_t thread;
    pthread_create(&thread, NULL, play_tracks, thread_data);

    // Return the thread
    return thread;
}

// Function to play all tracks in a library using multiple threads
void play_tracks_multithreaded(Library *library) {
    // Create a thread pool
    pthread_t *threads = malloc(sizeof(pthread_t) * 4);

    // Divide the library into four equal parts
    int num_parts = 4;
    int num_tracks_per_part = library->num_tracks / num_parts;

    // Create a thread for each part
    for (int i = 0; i < num_parts; i++) {
        int start_index = i * num_tracks_per_part;
        int end_index = (i + 1) * num_tracks_per_part;
        threads[i] = create_thread(library, start_index, end_index);
    }

    // Wait for all threads to finish
    for (int i = 0; i < num_parts; i++) {
        pthread_join(threads[i], NULL);
    }

    // Free the thread pool
    free(threads);
}

// Main function
int main() {
    // Create a new library
    Library library = {
        .name = "My Music Library",
        .num_tracks = 10,
        .tracks = {
            "Track 1",
            "Track 2",
            "Track 3",
            "Track 4",
            "Track 5",
            "Track 6",
            "Track 7",
            "Track 8",
            "Track 9",
            "Track 10",
        },
    };

    // Play all tracks in the library using multiple threads
    play_tracks_multithreaded(&library);

    return 0;
}