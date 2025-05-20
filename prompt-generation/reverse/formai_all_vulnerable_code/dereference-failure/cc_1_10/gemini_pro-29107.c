//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the metadata structure
typedef struct {
    char *title;
    char *artist;
    char *album;
    int year;
    int track_number;
    char *genre;
} Metadata;

// Function to extract metadata from a file
Metadata *extract_metadata(char *filename) {
    // Allocate memory for the metadata structure
    Metadata *metadata = malloc(sizeof(Metadata));

    // Open the file
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Read the file contents into a buffer
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *buffer = malloc(file_size);
    fread(buffer, file_size, 1, file);
    fclose(file);

    // Search for the ID3v2 tag
    char *id3v2_tag = strstr(buffer, "ID3");
    if (id3v2_tag == NULL) {
        // No ID3v2 tag found
        return NULL;
    }

    // Parse the ID3v2 tag
    int tag_size = *(id3v2_tag + 4) << 21 | *(id3v2_tag + 5) << 14 | *(id3v2_tag + 6) << 7 | *(id3v2_tag + 7);
    char *tag_end = id3v2_tag + 10 + tag_size;

    // Parse the title frame
    char *title_frame = strstr(id3v2_tag, "TIT2");
    if (title_frame != NULL) {
        int title_length = *(title_frame + 5) << 7 | *(title_frame + 6);
        metadata->title = malloc(title_length + 1);
        strncpy(metadata->title, title_frame + 10, title_length);
        metadata->title[title_length] = '\0';
    }

    // Parse the artist frame
    char *artist_frame = strstr(id3v2_tag, "TPE1");
    if (artist_frame != NULL) {
        int artist_length = *(artist_frame + 5) << 7 | *(artist_frame + 6);
        metadata->artist = malloc(artist_length + 1);
        strncpy(metadata->artist, artist_frame + 10, artist_length);
        metadata->artist[artist_length] = '\0';
    }

    // Parse the album frame
    char *album_frame = strstr(id3v2_tag, "TALB");
    if (album_frame != NULL) {
        int album_length = *(album_frame + 5) << 7 | *(album_frame + 6);
        metadata->album = malloc(album_length + 1);
        strncpy(metadata->album, album_frame + 10, album_length);
        metadata->album[album_length] = '\0';
    }

    // Parse the year frame
    char *year_frame = strstr(id3v2_tag, "TDRC");
    if (year_frame != NULL) {
        int year_length = *(year_frame + 5) << 7 | *(year_frame + 6);
        metadata->year = atoi(year_frame + 10);
    }

    // Parse the track number frame
    char *track_number_frame = strstr(id3v2_tag, "TRCK");
    if (track_number_frame != NULL) {
        int track_number_length = *(track_number_frame + 5) << 7 | *(track_number_frame + 6);
        metadata->track_number = atoi(track_number_frame + 10);
    }

    // Parse the genre frame
    char *genre_frame = strstr(id3v2_tag, "TCON");
    if (genre_frame != NULL) {
        int genre_length = *(genre_frame + 5) << 7 | *(genre_frame + 6);
        metadata->genre = malloc(genre_length + 1);
        strncpy(metadata->genre, genre_frame + 10, genre_length);
        metadata->genre[genre_length] = '\0';
    }

    // Free the buffer
    free(buffer);

    // Return the metadata structure
    return metadata;
}

// Function to print the metadata
void print_metadata(Metadata *metadata) {
    printf("Title: %s\n", metadata->title);
    printf("Artist: %s\n", metadata->artist);
    printf("Album: %s\n", metadata->album);
    printf("Year: %d\n", metadata->year);
    printf("Track Number: %d\n", metadata->track_number);
    printf("Genre: %s\n", metadata->genre);
}

// Main function
int main() {
    // Extract metadata from a file
    Metadata *metadata = extract_metadata("song.mp3");

    // Print the metadata
    print_metadata(metadata);

    // Free the metadata structure
    free(metadata->title);
    free(metadata->artist);
    free(metadata->album);
    free(metadata->genre);
    free(metadata);

    return 0;
}