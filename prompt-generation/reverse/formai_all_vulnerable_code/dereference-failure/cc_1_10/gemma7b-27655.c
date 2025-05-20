//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Music Library Management System (MLMS) structure
typedef struct mlms {
    char title[255];
    char artist[255];
    char genre[255];
    int year;
    struct mlms* next;
} mlms;

// Create a new music library entry
mlms* create_entry(char* title, char* artist, char* genre, int year) {
    mlms* new_entry = (mlms*)malloc(sizeof(mlms));
    strcpy(new_entry->title, title);
    strcpy(new_entry->artist, artist);
    strcpy(new_entry->genre, genre);
    new_entry->year = year;
    new_entry->next = NULL;
    return new_entry;
}

// Insert a new music library entry at the end
void insert_entry(mlms* head, char* title, char* artist, char* genre, int year) {
    mlms* new_entry = create_entry(title, artist, genre, year);
    if (head == NULL) {
        head = new_entry;
    } else {
        head->next = new_entry;
    }
}

// Print all music library entries
void print_entries(mlms* head) {
    mlms* current = head;
    while (current) {
        printf("%s by %s (%d) - %s\n", current->title, current->artist, current->year, current->genre);
        current = current->next;
    }
}

int main() {
    mlms* head = NULL;
    insert_entry(head, "The Dark Side of the Moon", "Pink Floyd", "Rock", 1973);
    insert_entry(head, "Thriller", "Michael Jackson", "Pop", 1987);
    insert_entry(head, "Back in Black", "Led Zeppelin", "Rock", 1969);
    print_entries(head);

    return 0;
}