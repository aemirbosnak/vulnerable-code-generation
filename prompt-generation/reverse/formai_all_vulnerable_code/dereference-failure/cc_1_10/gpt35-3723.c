//FormAI DATASET v1.0 Category: Music Library Management System ; Style: irregular
#include <stdio.h>
#include <stdlib.h> 

typedef struct song_node {
    char *title; 
    char *artist;
    char *album;
    struct song_node *next;
} Song;

Song* createSong(char *title, char *artist, char *album) {
    Song *newSong = malloc(sizeof(Song));
    newSong->title = title;
    newSong->artist = artist;
    newSong->album = album;
    newSong->next = NULL;
    return newSong;
}

Song* addSong(Song *head, char *title, char *artist, char *album) {
    if (head == NULL) {
        return createSong(title, artist, album);
    }
    Song *tmp = head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = createSong(title, artist, album);
    return head;
}

void deleteSong(Song* head, char *title, char *artist) {
    Song *prev = NULL;
    Song *curr = head;
    while (curr != NULL) {
        if (strcmp(curr->title, title) == 0 && strcmp(curr->artist, artist) == 0) {
            if (prev == NULL) {
                head = head->next;
                free(curr);
                return;
            }
            prev->next = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

Song* findSong(Song* head, char* title, char *artist) {
    Song *tmp = head;
    while (tmp != NULL) {
        if (strcmp(tmp->title, title) == 0 && strcmp(tmp->artist, artist) == 0) {
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}

void printSongs(Song* head) {
    Song *tmp = head;
    while (tmp != NULL) {
        printf("Title: %s\nArtist: %s\nAlbum: %s\n\n", tmp->title, tmp->artist, tmp->album);
        tmp = tmp->next;
    }
}

int main() {
    Song *head = NULL;
    head = addSong(head, "Stairway to Heaven", "Led Zeppelin", "IV");
    head = addSong(head, "Smells Like Teen Spirit", "Nirvana", "Nevermind");
    head = addSong(head, "Bohemian Rhapsody", "Queen", "A Night at the Opera");
    head = addSong(head, "Hotel California", "The Eagles", "Hotel California");
    head = addSong(head, "Enter Sandman", "Metallica", "Metallica");

    printSongs(head);

    printf("\n\nDeleting Bohemian Rhapsody by Queen...\n\n");

    deleteSong(head, "Bohemian Rhapsody", "Queen");

    printSongs(head);

    Song *found = findSong(head, "Smells Like Teen Spirit", "Nirvana");
    printf("\n\nFound song: %s by %s\n\n", found->title, found->artist);

    return 0;
}