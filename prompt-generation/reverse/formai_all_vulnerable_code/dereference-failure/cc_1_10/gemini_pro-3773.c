//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a music track
typedef struct track {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    float price;
} track;

// Function to create a new track
track *create_track(char *title, char *artist, char *album, int year, float price) {
    track *new_track = (track *)malloc(sizeof(track));
    strcpy(new_track->title, title);
    strcpy(new_track->artist, artist);
    strcpy(new_track->album, album);
    new_track->year = year;
    new_track->price = price;
    return new_track;
}

// Function to print a track
void print_track(track *track) {
    printf("Title: %s\n", track->title);
    printf("Artist: %s\n", track->artist);
    printf("Album: %s\n", track->album);
    printf("Year: %d\n", track->year);
    printf("Price: %0.2f\n", track->price);
}

// Function to compare two tracks by title
int compare_tracks_by_title(const void *a, const void *b) {
    track *track1 = (track *)a;
    track *track2 = (track *)b;
    return strcmp(track1->title, track2->title);
}

// Function to compare two tracks by artist
int compare_tracks_by_artist(const void *a, const void *b) {
    track *track1 = (track *)a;
    track *track2 = (track *)b;
    return strcmp(track1->artist, track2->artist);
}

// Function to compare two tracks by album
int compare_tracks_by_album(const void *a, const void *b) {
    track *track1 = (track *)a;
    track *track2 = (track *)b;
    return strcmp(track1->album, track2->album);
}

// Function to compare two tracks by year
int compare_tracks_by_year(const void *a, const void *b) {
    track *track1 = (track *)a;
    track *track2 = (track *)b;
    return track1->year - track2->year;
}

// Function to compare two tracks by price
int compare_tracks_by_price(const void *a, const void *b) {
    track *track1 = (track *)a;
    track *track2 = (track *)b;
    return track1->price - track2->price;
}

// Main function
int main() {
    // Create an array of tracks
    track *tracks[] = {
        create_track("Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 1.99),
        create_track("Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 1.99),
        create_track("Hotel California", "Eagles", "Hotel California", 1976, 1.99),
        create_track("Smells Like Teen Spirit", "Nirvana", "Nevermind", 1991, 1.99),
        create_track("Thriller", "Michael Jackson", "Thriller", 1982, 1.99),
    };

    // Get the number of tracks
    int num_tracks = sizeof(tracks) / sizeof(tracks[0]);

    // Print the original array of tracks
    printf("Original array of tracks:\n");
    for (int i = 0; i < num_tracks; i++) {
        print_track(tracks[i]);
        printf("\n");
    }

    // Sort the array of tracks by title
    qsort(tracks, num_tracks, sizeof(track), compare_tracks_by_title);

    // Print the array of tracks sorted by title
    printf("\nArray of tracks sorted by title:\n");
    for (int i = 0; i < num_tracks; i++) {
        print_track(tracks[i]);
        printf("\n");
    }

    // Sort the array of tracks by artist
    qsort(tracks, num_tracks, sizeof(track), compare_tracks_by_artist);

    // Print the array of tracks sorted by artist
    printf("\nArray of tracks sorted by artist:\n");
    for (int i = 0; i < num_tracks; i++) {
        print_track(tracks[i]);
        printf("\n");
    }

    // Sort the array of tracks by album
    qsort(tracks, num_tracks, sizeof(track), compare_tracks_by_album);

    // Print the array of tracks sorted by album
    printf("\nArray of tracks sorted by album:\n");
    for (int i = 0; i < num_tracks; i++) {
        print_track(tracks[i]);
        printf("\n");
    }

    // Sort the array of tracks by year
    qsort(tracks, num_tracks, sizeof(track), compare_tracks_by_year);

    // Print the array of tracks sorted by year
    printf("\nArray of tracks sorted by year:\n");
    for (int i = 0; i < num_tracks; i++) {
        print_track(tracks[i]);
        printf("\n");
    }

    // Sort the array of tracks by price
    qsort(tracks, num_tracks, sizeof(track), compare_tracks_by_price);

    // Print the array of tracks sorted by price
    printf("\nArray of tracks sorted by price:\n");
    for (int i = 0; i < num_tracks; i++) {
        print_track(tracks[i]);
        printf("\n");
    }

    return 0;
}