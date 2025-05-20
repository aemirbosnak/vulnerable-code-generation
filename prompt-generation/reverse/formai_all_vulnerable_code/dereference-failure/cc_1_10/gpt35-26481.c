//FormAI DATASET v1.0 Category: Music Library Management System ; Style: futuristic
// C Music Library Management System Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct representing a song.
struct Song {
    char title[100];
    char artist[100];
    char album[100];
    int year;
    int duration;
};

// Struct representing a node in the linked list.
struct Node {
    struct Song song;
    struct Node* next;
};

// Function to add a song to the library.
void addSong(struct Node** head_ref, struct Song song) {

    // Allocate memory for a new node.
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    // Set the song for this node.
    new_node->song = song;

    // Set the next pointer for this node.
    new_node->next = (*head_ref);

    // Set the new head of the linked list.
    (*head_ref) = new_node;
}

// Function to print all songs in the library.
void printLibrary(struct Node* node) {
    printf("Title %20s  |  Artist %20s  |  Album %20s  |  Year  |  Duration (s)\n", "", "", "", "");
    printf("-------------------------------------------------------------------------\n");
    while (node != NULL) {
        printf("%-30s %-30s %-30s %-10d %-10d\n",
            node->song.title,
            node->song.artist,
            node->song.album,
            node->song.year,
            node->song.duration);

        node = node->next;
    }
}

int main() {

    // Initialize an empty linked list.
    struct Node* library = NULL;

    // Add some example songs.
    struct Song song1 = {"Diamonds", "Rihanna", "Unapologetic", 2012, 223};
    struct Song song2 = {"Shape of You", "Ed Sheeran", "÷", 2017, 237};
    struct Song song3 = {"Believer", "Imagine Dragons", "Evolve", 2017, 204};
    struct Song song4 = {"All of Me", "John Legend", "Love in the Future", 2013, 269};
    struct Song song5 = {"Get Lucky", "Daft Punk", "Random Access Memories", 2013, 369};
    struct Song song6 = {"Stressed Out", "Twenty One Pilots", "Blurryface", 2015, 222};

    addSong(&library, song1);
    addSong(&library, song2);
    addSong(&library, song3);
    addSong(&library, song4);
    addSong(&library, song5);
    addSong(&library, song6);

    printf("My Library\n");
    printLibrary(library);

    // Return 0 to indicate successful execution.
    return 0;
}