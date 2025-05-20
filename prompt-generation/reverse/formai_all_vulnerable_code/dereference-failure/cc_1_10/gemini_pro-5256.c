//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the cyberpunk-themed structure
typedef struct CyberRecord {
    char *name;
    char *artist;
    char *genre;
    int year;
    int times_played;
} CyberRecord;

// Function to create a new cyberpunk record
CyberRecord *create_record(char *name, char *artist, char *genre, int year) {
    CyberRecord *record = malloc(sizeof(CyberRecord));
    record->name = strdup(name);
    record->artist = strdup(artist);
    record->genre = strdup(genre);
    record->year = year;
    record->times_played = 0;
    return record;
}

// Function to free a cyberpunk record
void free_record(CyberRecord *record) {
    free(record->name);
    free(record->artist);
    free(record->genre);
    free(record);
}

// Function to print a cyberpunk record
void print_record(CyberRecord *record) {
    printf("Name: %s\n", record->name);
    printf("Artist: %s\n", record->artist);
    printf("Genre: %s\n", record->genre);
    printf("Year: %d\n", record->year);
    printf("Times played: %d\n", record->times_played);
}

// Function to compare two cyberpunk records by name
int compare_records_by_name(const void *a, const void *b) {
    const CyberRecord *record1 = (const CyberRecord *)a;
    const CyberRecord *record2 = (const CyberRecord *)b;
    return strcmp(record1->name, record2->name);
}

// Function to compare two cyberpunk records by artist
int compare_records_by_artist(const void *a, const void *b) {
    const CyberRecord *record1 = (const CyberRecord *)a;
    const CyberRecord *record2 = (const CyberRecord *)b;
    return strcmp(record1->artist, record2->artist);
}

// Function to compare two cyberpunk records by genre
int compare_records_by_genre(const void *a, const void *b) {
    const CyberRecord *record1 = (const CyberRecord *)a;
    const CyberRecord *record2 = (const CyberRecord *)b;
    return strcmp(record1->genre, record2->genre);
}

// Function to compare two cyberpunk records by year
int compare_records_by_year(const void *a, const void *b) {
    const CyberRecord *record1 = (const CyberRecord *)a;
    const CyberRecord *record2 = (const CyberRecord *)b;
    return record1->year - record2->year;
}

// Function to compare two cyberpunk records by times played
int compare_records_by_times_played(const void *a, const void *b) {
    const CyberRecord *record1 = (const CyberRecord *)a;
    const CyberRecord *record2 = (const CyberRecord *)b;
    return record1->times_played - record2->times_played;
}

// Main function
int main() {
    // Create an array of cyberpunk records
    CyberRecord *records[] = {
        create_record("Neuromancer", "William Gibson", "Science fiction", 1984),
        create_record("Snow Crash", "Neal Stephenson", "Science fiction", 1992),
        create_record("The Diamond Age", "Neal Stephenson", "Science fiction", 1995),
        create_record("Cryptonomicon", "Neal Stephenson", "Science fiction", 1999),
        create_record("The Baroque Cycle", "Neal Stephenson", "Historical fiction", 2003),
        create_record("Seveneves", "Neal Stephenson", "Science fiction", 2015),
        create_record("REAMDE", "Neal Stephenson", "Science fiction", 2011),
        create_record("Fall; or, Dodge in Hell", "Neal Stephenson", "Science fiction", 2019),
        create_record("The Peripheral", "William Gibson", "Science fiction", 2014),
        create_record("Agency", "William Gibson", "Science fiction", 2020),
    };

    // Sort the records by name
    qsort(records, sizeof(records) / sizeof(CyberRecord *), sizeof(CyberRecord *), compare_records_by_name);

    // Print the sorted records
    for (int i = 0; i < sizeof(records) / sizeof(CyberRecord *); i++) {
        print_record(records[i]);
        printf("\n");
    }

    // Free the records
    for (int i = 0; i < sizeof(records) / sizeof(CyberRecord *); i++) {
        free_record(records[i]);
    }

    return 0;
}