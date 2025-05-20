//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: mathematical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Function prototypes
int compare_songs(const void *a, const void *b);
void print_songs(const char *name, const char *artist, int duration);

int main() {
    char name[50], artist[50], duration[50];
    
    // Create the song list
    int num_songs = 10;
    char *song_list[num_songs];
    
    // Populate the song list with random songs
    for (int i = 0; i < num_songs; i++) {
        sprintf(name, "Song %d", i + 1);
        sprintf(artist, "Artist %d", i + 1);
        sprintf(duration, "%d seconds", rand() % 60 + 1);
        song_list[i] = malloc(strlen(name) + strlen(artist) + strlen(duration) + 1);
        strcpy(song_list[i], name);
        strcat(song_list[i], " by ");
        strcat(song_list[i], artist);
        strcat(song_list[i], " - ");
        strcat(song_list[i], duration);
    }
    
    // Sort the song list by song duration
    qsort(song_list, num_songs, sizeof(char*), compare_songs);
    
    // Print the sorted song list
    printf("Sorted Song List:\n");
    for (int i = 0; i < num_songs; i++) {
        print_songs(song_list[i], NULL, 0);
    }
    
    // Free the memory allocated for the song list
    for (int i = 0; i < num_songs; i++) {
        free(song_list[i]);
    }
    
    return 0;
}

// Function to compare song durations
int compare_songs(const void *a, const void *b) {
    const char *song_a = *(const char **)a;
    const char *song_b = *(const char **)b;
    int duration_a = atoi(strchr(song_a, '-') + 1);
    int duration_b = atoi(strchr(song_b, '-') + 1);
    if (duration_a < duration_b) {
        return -1;
    } else if (duration_a > duration_b) {
        return 1;
    } else {
        return 0;
    }
}

// Function to print a single song
void print_songs(const char *name, const char *artist, int duration) {
    printf("%s, %s - %d seconds\n", name, artist, duration);
}