//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum length of string to be parsed
#define MAX_LENGTH 1000

// Define configurable parameters
char* search_key = "artist";
int search_key_len = 6;
char* open_tag = "<";
char* close_tag = ">";

// Struct to hold parsed metadata
typedef struct Metadata {
    char* key;
    char* value;
} Metadata;

// Function to parse metadata from string
Metadata* parseMetadata(char* str) {
    // Allocate memory for metadata object
    Metadata* metadata = malloc(sizeof(Metadata));

    // Find start index of search key
    char* start = strstr(str, search_key);
    if (start == NULL) {
        return NULL;
    }

    // Calculate start index of value
    int value_start = (int)(start - str + search_key_len);

    // Find end index of value
    char* end = strstr(str + value_start, close_tag);
    if (end == NULL) {
        return NULL;
    }

    // Calculate length of value
    int value_len = (int)(end - str - value_start);

    // Allocate memory for key and value strings
    metadata->key = malloc(search_key_len);
    metadata->value = malloc(value_len);

    // Copy key and value strings
    strncpy(metadata->key, search_key, search_key_len);
    strncpy(metadata->value, str + value_start, value_len);

    return metadata;
}

// Function to print metadata object
void printMetadata(Metadata* metadata) {
    printf("%s: %s\n", metadata->key, metadata->value);
}

int main() {
    // Define input string
    char input[MAX_LENGTH] = "<song><title>Crazy Train</title><artist>Ozzy Osbourne</artist></song>";

    // Parse metadata from input string
    Metadata* artist_metadata = parseMetadata(input);

    // Print metadata object
    printMetadata(artist_metadata);

    return 0;
}