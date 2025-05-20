//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: Cryptic
#define _CRYPTIC_ 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Song {
    char title[50];
    char artist[50];
    int length;
    struct _Song* next;
} Song;

typedef struct _Library {
    Song* head;
    Song* tail;
    int count;
} Library;

void _addSong(Library* lib, char* title, char* artist, int len) {
    Song* newSong = (Song*)malloc(sizeof(Song));
    strcpy(newSong->title, title);
    strcpy(newSong->artist, artist);
    newSong->length = len;
    newSong->next = NULL;
    if (lib->head == NULL) {
        lib->head = newSong;
        lib->tail = newSong;
    } else {
        lib->tail->next = newSong;
        lib->tail = newSong;
    }
    lib->count++;
}

void _displayLibrary(Library lib) {
    Song* current = lib.head;
    printf("\n---------------------\n");
    printf("| %-45s | %-45s | %5d |\n", "Title", "Artist", "Length");
    printf("---------------------\n");
    while (current != NULL) {
        printf("| %-45s | %-45s | %5d |\n", current->title, current->artist, current->length);
        current = current->next;
    }
    printf("---------------------\n");
}

int main(void) {
#ifdef _CRYPTIC_
    char crypticLibName[] = "ObfuscatedTunes";
#else
    char libName[] = "MusicLibrary";
#endif
    Library myLib = { NULL, NULL, 0 };

    _addSong(&myLib, "Bohemian Rhapsody", "Queen", 599);
    _addSong(&myLib, "Stairway to Heaven", "Led Zeppelin", 802);
    _addSong(&myLib, "Black Dog", "Led Zeppelin", 402);
    _addSong(&myLib, "Back in Black", "AC/DC", 459);

    _displayLibrary(myLib);

    return 0;
}