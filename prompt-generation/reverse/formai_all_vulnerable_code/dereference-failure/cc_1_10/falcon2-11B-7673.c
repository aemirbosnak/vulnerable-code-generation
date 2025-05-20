//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define MAX_NUM_OF_RECORDS 100

typedef struct {
    char artist[MAX_LENGTH];
    char album[MAX_LENGTH];
    char genre[MAX_LENGTH];
} record_t;

typedef struct {
    record_t *records;
    int num_of_records;
} library_t;

library_t *create_library() {
    library_t *library = malloc(sizeof(library_t));
    library->records = malloc(MAX_NUM_OF_RECORDS * sizeof(record_t));
    library->num_of_records = 0;
    return library;
}

void add_record(library_t *library, const char *artist, const char *album, const char *genre) {
    record_t *record = malloc(sizeof(record_t));
    strcpy(record->artist, artist);
    strcpy(record->album, album);
    strcpy(record->genre, genre);

    if (library->num_of_records >= MAX_NUM_OF_RECORDS) {
        printf("Library is full. Cannot add record.\n");
        return;
    }

    library->records[library->num_of_records] = *record;
    library->num_of_records++;
}

void search_record(library_t *library, const char *artist, const char *album, const char *genre) {
    int i;
    for (i = 0; i < library->num_of_records; i++) {
        if (strcmp(library->records[i].artist, artist) == 0 && 
            strcmp(library->records[i].album, album) == 0 && 
            strcmp(library->records[i].genre, genre) == 0) {
            printf("Record found!\n");
            return;
        }
    }
    printf("Record not found.\n");
}

void display_library(library_t *library) {
    int i;
    printf("Library:\n");
    for (i = 0; i < library->num_of_records; i++) {
        printf("Artist: %s, Album: %s, Genre: %s\n", library->records[i].artist, library->records[i].album, library->records[i].genre);
    }
}

void destroy_library(library_t *library) {
    free(library->records);
    free(library);
}

int main() {
    library_t *library = create_library();

    add_record(library, "John Mayer", "Room for Squares", "Pop");
    add_record(library, "Taylor Swift", "Fearless", "Country");
    add_record(library, "Miles Davis", "Kind of Blue", "Jazz");

    search_record(library, "Taylor Swift", "Fearless", "Country");

    display_library(library);

    destroy_library(library);

    return 0;
}