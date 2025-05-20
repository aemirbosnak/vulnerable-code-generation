//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Ada Lovelace
/* Ada Lovelace style C Metadata Extractor Example Program */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure to hold metadata variables */
typedef struct metadata {
    char title[100];
    char artist[50];
    char album[50];
    char year[5];
    char genre[20];
} metadata;
 
/* Function to extract metadata from file */
void extract_metadata(char *filename, metadata *data) {
    FILE *fp;
    char buffer[1024];
    char *token;
    
    /* Open the file */
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    
    /* Read file line by line */
    while (fgets(buffer, 1024, fp)) {
        /* Extract metadata from line */
        token = strtok(buffer, ":");
        if (strcmp(token, "Title") == 0) {
            token = strtok(NULL, "\n");
            strcpy(data->title, token);
        } else if (strcmp(token, "Artist") == 0) {
            token = strtok(NULL, "\n");
            strcpy(data->artist, token);
        } else if (strcmp(token, "Album") == 0) {
            token = strtok(NULL, "\n");
            strcpy(data->album, token);
        } else if (strcmp(token, "Year") == 0) {
            token = strtok(NULL, "\n");
            strcpy(data->year, token);
        } else if (strcmp(token, "Genre") == 0) {
            token = strtok(NULL, "\n");
            strcpy(data->genre, token);
        }
    }
    
    /* Close the file */
    fclose(fp);
}

int main() {
    metadata data;
    
    /* Call function to extract metadata */
    extract_metadata("example.mp3", &data);
    
    /* Print the metadata */
    printf("Title: %s\n", data.title);
    printf("Artist: %s\n", data.artist);
    printf("Album: %s\n", data.album);
    printf("Year: %s\n", data.year);
    printf("Genre: %s\n", data.genre);
    
    return 0;
}