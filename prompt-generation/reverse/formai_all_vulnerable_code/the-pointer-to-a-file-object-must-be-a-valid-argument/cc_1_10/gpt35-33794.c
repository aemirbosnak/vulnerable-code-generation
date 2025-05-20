//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: expert-level
#include <stdio.h>
#include <string.h>

// Define a structure to hold metadata information
struct metadata {
    char title[50];
    char artist[50];
    char album[50];
    int year;
};

// Function to extract metadata from file
void extract_metadata(char *filename, struct metadata *data) {
    FILE *fp;
    char line[100];

    // Open the file for reading
    fp = fopen(filename, "r");

    // Read each line of the file
    while (fgets(line, 100, fp)) {
        // Check if line contains metadata
        if (strstr(line, "Title:")) {
            // Copy title information to struct
            strcpy(data->title, line + 7);
        } else if (strstr(line, "Artist:")) {
            // Copy artist information to struct
            strcpy(data->artist, line + 8);
        } else if (strstr(line, "Album:")) {
            // Copy album information to struct
            strcpy(data->album, line + 7);
        } else if (strstr(line, "Year:")) {
            // Copy year information to struct
            sscanf(line + 6, "%d", &data->year);
        }
    }

    // Close the file
    fclose(fp);
}

int main() {
    char filename[50];
    struct metadata song_data;

    // Get file name from user
    printf("Enter file name: ");
    scanf("%s", filename);

    // Call function to extract metadata
    extract_metadata(filename, &song_data);

    // Display extracted metadata
    printf("Title: %s\n", song_data.title);
    printf("Artist: %s\n", song_data.artist);
    printf("Album: %s\n", song_data.album);
    printf("Year: %d\n", song_data.year);

    return 0;
}