//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store music information
typedef struct Music {
    char title[50];
    char artist[50];
    char genre[50];
    int year;
    struct Music* next;
} Music;

// Create a linked list of music
Music* music_head = NULL;

// Insert a music into the linked list
void insert_music(char* title, char* artist, char* genre, int year) {
    Music* new_music = (Music*)malloc(sizeof(Music));
    strcpy(new_music->title, title);
    strcpy(new_music->artist, artist);
    strcpy(new_music->genre, genre);
    new_music->year = year;
    new_music->next = NULL;

    if (music_head == NULL) {
        music_head = new_music;
    } else {
        Music* current = music_head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_music;
    }
}

// Search for music by title
Music* search_music_by_title(char* title) {
    Music* current = music_head;
    while (current) {
        if (strcmp(current->title, title) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Print music information
void print_music_info(Music* music) {
    printf("Title: %s\n", music->title);
    printf("Artist: %s\n", music->artist);
    printf("Genre: %s\n", music->genre);
    printf("Year: %d\n", music->year);
}

int main() {
    insert_music("The Darkest Hour", "The Beatles", "Rock", 1964);
    insert_music("Let It Be", "The Beatles", "Rock", 1967);
    insert_music("Stairway to Heaven", "Led Zeppelin", "Rock", 1969);
    insert_music("Rock and Roll Hall of Fame", "Elvis Presley", "Rock", 1956);

    Music* music = search_music_by_title("Let It Be");
    print_music_info(music);

    return 0;
}