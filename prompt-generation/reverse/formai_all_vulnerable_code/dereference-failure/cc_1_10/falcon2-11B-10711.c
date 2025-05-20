//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Function to add a new song to the library
void add_song(char *artist, char *album, char *title, char *genre) {
    FILE *fp;
    char buffer[255];
    
    // Open the library file for appending
    fp = fopen("library.txt", "a");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }
    
    // Format the song entry
    sprintf(buffer, "%s,%s,%s,%s\n", artist, album, title, genre);
    
    // Write the song entry to the file
    fputs(buffer, fp);
    
    // Close the file
    fclose(fp);
}

// Function to search for a song in the library
void search_song(char *artist, char *album, char *title, char *genre) {
    FILE *fp;
    char buffer[255];
    
    // Open the library file for reading
    fp = fopen("library.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }
    
    // Read the first line of the file
    fgets(buffer, sizeof(buffer), fp);
    
    // Loop through the lines in the file
    while (fgets(buffer, sizeof(buffer), fp)!= NULL) {
        // Split the line into artist, album, title, and genre
        char *artist_split = strtok(buffer, ",");
        char *album_split = strtok(NULL, ",");
        char *title_split = strtok(NULL, ",");
        char *genre_split = strtok(NULL, ",");
        
        // Check if the artist, album, title, and genre match
        if (strcmp(artist, artist_split) == 0 && strcmp(album, album_split) == 0 && strcmp(title, title_split) == 0 && strcmp(genre, genre_split) == 0) {
            printf("Found song: %s by %s\n", title, artist);
            return;
        }
    }
    
    // If no match is found, print a message
    printf("Song not found\n");
}

// Function to delete a song from the library
void delete_song(char *artist, char *album, char *title, char *genre) {
    FILE *fp;
    char buffer[255];
    
    // Open the library file for reading
    fp = fopen("library.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }
    
    // Read the first line of the file
    fgets(buffer, sizeof(buffer), fp);
    
    // Loop through the lines in the file
    while (fgets(buffer, sizeof(buffer), fp)!= NULL) {
        // Split the line into artist, album, title, and genre
        char *artist_split = strtok(buffer, ",");
        char *album_split = strtok(NULL, ",");
        char *title_split = strtok(NULL, ",");
        char *genre_split = strtok(NULL, ",");
        
        // Check if the artist, album, title, and genre match
        if (strcmp(artist, artist_split) == 0 && strcmp(album, album_split) == 0 && strcmp(title, title_split) == 0 && strcmp(genre, genre_split) == 0) {
            // Delete the line from the file
            printf("Deleting song: %s by %s\n", title, artist);
            fputs(buffer, fp);
            fclose(fp);
            return;
        }
    }
    
    // If no match is found, print a message
    printf("Song not found\n");
}

// Main function
int main() {
    char artist[100], album[100], title[100], genre[100];
    int choice;
    
    // Loop until the user chooses to quit
    while (1) {
        printf("1. Add a new song\n");
        printf("2. Search for a song\n");
        printf("3. Delete a song\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter artist, album, title, and genre: ");
                fgets(artist, sizeof(artist), stdin);
                fgets(album, sizeof(album), stdin);
                fgets(title, sizeof(title), stdin);
                fgets(genre, sizeof(genre), stdin);
                add_song(artist, album, title, genre);
                break;
            case 2:
                printf("Enter artist, album, title, and genre: ");
                fgets(artist, sizeof(artist), stdin);
                fgets(album, sizeof(album), stdin);
                fgets(title, sizeof(title), stdin);
                fgets(genre, sizeof(genre), stdin);
                search_song(artist, album, title, genre);
                break;
            case 3:
                printf("Enter artist, album, title, and genre: ");
                fgets(artist, sizeof(artist), stdin);
                fgets(album, sizeof(album), stdin);
                fgets(title, sizeof(title), stdin);
                fgets(genre, sizeof(genre), stdin);
                delete_song(artist, album, title, genre);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    
    return 0;
}