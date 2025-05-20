//FormAI DATASET v1.0 Category: Music Library Management System ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100 // Maximum number of songs in the library

// Structure to hold information about a song
typedef struct {
    char title[50];
    char artist[50];
    int duration; // in seconds
} Song;

// Structure to hold information about the library
typedef struct {
    Song songs[MAX_SONGS];
    int num_songs;
} Library;

Library my_library; // global instance of the Library struct

pthread_mutex_t mutex; // mutex to lock the library while updating

// Function to add a new song to the library
void add_song(char* title, char* artist, int duration) {
    pthread_mutex_lock(&mutex); // lock the library
    
    if (my_library.num_songs < MAX_SONGS) {
        Song new_song;
        strcpy(new_song.title, title);
        strcpy(new_song.artist, artist);
        new_song.duration = duration;
        my_library.songs[my_library.num_songs] = new_song;
        my_library.num_songs++;
        printf("Added new song: %s - %s (%d seconds)\n", artist, title, duration);
    } else {
        printf("Library is full. Cannot add song.\n");
    }
    
    pthread_mutex_unlock(&mutex); // unlock the library
}

// Function to remove a song from the library
void remove_song(char* title, char* artist) {
    pthread_mutex_lock(&mutex); // lock the library
    
    int i, found = 0;
    for (i = 0; i < my_library.num_songs; i++) {
        if (strcmp(my_library.songs[i].title, title) == 0 && strcmp(my_library.songs[i].artist, artist) == 0) {
            found = 1;
            break;
        }
    }
    
    if (found) {
        printf("Removed song: %s - %s (%d seconds)\n", artist, title, my_library.songs[i].duration);
        for (; i < my_library.num_songs - 1; i++) {
            my_library.songs[i] = my_library.songs[i+1]; // shift remaining songs left
        }
        my_library.num_songs--;
    } else {
        printf("Song not found in library.\n");
    }
    
    pthread_mutex_unlock(&mutex); // unlock the library
}

// Function to print all songs in the current library
void print_library() {
    pthread_mutex_lock(&mutex); // lock the library
    
    printf("Library Contents:\n");
    if (my_library.num_songs == 0) {
        printf("No songs in library.\n");
    } else {
        int i;
        for (i = 0; i < my_library.num_songs; i++) {
            printf("%d. %s - %s (%d seconds)\n", i+1, my_library.songs[i].artist, my_library.songs[i].title, my_library.songs[i].duration);
        }
    }
    
    pthread_mutex_unlock(&mutex); // unlock the library
}

// Thread function to read input from the user and execute appropriate commands
void* command_thread_function(void* arg) {
    char input[100];
    while (1) {
        printf("> ");
        fgets(input, 100, stdin);
        
        char* command = strtok(input, " \n");
        if (strcmp(command, "add") == 0) {
            char* title = strtok(NULL, " \n");
            char* artist = strtok(NULL, " \n");
            int duration = atoi(strtok(NULL, " \n"));
            add_song(title, artist, duration);
        } else if (strcmp(command, "remove") == 0) {
            char* title = strtok(NULL, " \n");
            char* artist = strtok(NULL, " \n");
            remove_song(title, artist);
        } else if (strcmp(command, "print") == 0) {
            print_library();
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting program.\n");
            exit(0);
        } else {
            printf("Unknown command: %s\n", command);
        }
    }
}

// Main function to create threads and start the program
int main() {
    my_library.num_songs = 0;
    pthread_mutex_init(&mutex, NULL); // initialize the mutex
    
    pthread_t command_thread;
    pthread_create(&command_thread, NULL, &command_thread_function, NULL); // create the command thread
    
    pthread_join(command_thread, NULL); // wait for the command thread to finish
    
    pthread_mutex_destroy(&mutex); // destroy the mutex
    
    return 0;
}