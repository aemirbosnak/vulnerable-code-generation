//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct MusicRecord {
    char title[50];
    char artist[50];
    char genre[50];
    int quantity;
    struct MusicRecord* next;
} MusicRecord;

MusicRecord* insertRecord(MusicRecord* head, char* title, char* artist, char* genre, int quantity) {
    MusicRecord* newRecord = (MusicRecord*)malloc(sizeof(MusicRecord));
    strcpy(newRecord->title, title);
    strcpy(newRecord->artist, artist);
    strcpy(newRecord->genre, genre);
    newRecord->quantity = quantity;
    newRecord->next = NULL;

    if (head == NULL) {
        head = newRecord;
    } else {
        head->next = newRecord;
    }

    return head;
}

void displayRecords(MusicRecord* head) {
    MusicRecord* currentRecord = head;

    while (currentRecord) {
        printf("%s by %s (Genre: %s, Quantity: %d)\n", currentRecord->title, currentRecord->artist, currentRecord->genre, currentRecord->quantity);
        currentRecord = currentRecord->next;
    }
}

int main() {
    MusicRecord* head = NULL;

    // Multiplayer actions
    // - Client 1:
    insertRecord(head, "Song 1", "Artist 1", "Rock", 10);
    insertRecord(head, "Song 2", "Artist 2", "Pop", 5);

    // - Client 2:
    insertRecord(head, "Song 3", "Artist 3", "Electronic", 7);
    insertRecord(head, "Song 4", "Artist 4", "Hip Hop", 8);

    // Display all records
    displayRecords(head);

    return 0;
}