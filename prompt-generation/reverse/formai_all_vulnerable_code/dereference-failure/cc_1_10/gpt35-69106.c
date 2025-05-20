//FormAI DATASET v1.0 Category: Music Library Management System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *title;
    char *artist;
    int year;
    char *genre;
} Song;

typedef struct node{
    Song song;
    struct node *next;
} Node;

Node *head = NULL;

void add_song(char *title, char *artist, int year, char *genre) {
    Node *new_node = (Node*) malloc(sizeof(Node));

    Song new_song = {title, artist, year, genre};

    new_node->song = new_song;
    new_node->next = head;
    head = new_node;
}

void display_songs() {
    Node *current_node = head;
    while(current_node != NULL) {
        printf("Title: %s\n", current_node->song.title);
        printf("Artist: %s\n", current_node->song.artist);
        printf("Year: %d\n", current_node->song.year);
        printf("Genre: %s\n", current_node->song.genre);
        printf("---------------\n");

        current_node = current_node->next;
    }
}

void search_songs(char *artist) {
    Node *current_node = head;

    while(current_node != NULL) {
        if(strcmp(current_node->song.artist, artist) == 0) {
            printf("Title: %s\n", current_node->song.title);
            printf("Artist: %s\n", current_node->song.artist);
            printf("Year: %d\n", current_node->song.year);
            printf("Genre: %s\n", current_node->song.genre);
            printf("---------------\n");
        }

        current_node = current_node->next;
    }
}

void delete_song(char *title) {
    Node *current_node = head;
    Node *prev_node = NULL;

    while(current_node != NULL) {
        if(strcmp(current_node->song.title, title) == 0) {
            if(prev_node == NULL) {
                head = current_node->next;
            } else {
                prev_node->next = current_node->next;
            }

            free(current_node->song.title);
            free(current_node->song.artist);
            free(current_node->song.genre);
            free(current_node);
            return;
        }

        prev_node = current_node;
        current_node = current_node->next;
    }
}

int main() {
    add_song("Bohemian Rhapsody", "Queen", 1975, "Rock");
    add_song("Stairway to Heaven", "Led Zeppelin", 1971, "Rock");
    add_song("Thriller", "Michael Jackson", 1982, "Pop");
    add_song("Hotel California", "The Eagles", 1976, "Rock");

    printf("All songs:\n");
    display_songs();

    printf("\nSearching for all songs by Queen:\n");
    search_songs("Queen");

    delete_song("Thriller");

    printf("\nAll songs after deleting 'Thriller':\n");
    display_songs();

    return 0;
}