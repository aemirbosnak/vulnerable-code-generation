//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_METADATA 256
#define MAX_FILE_PATH 512

typedef struct {
    char title[MAX_METADATA];
    char artist[MAX_METADATA];
    char album[MAX_METADATA];
    char year[MAX_METADATA];
    char genre[MAX_METADATA];
} Metadata;

void initialize_metadata(Metadata *metadata) {
    memset(metadata, 0, sizeof(Metadata));
}

void print_metadata(const Metadata *metadata) {
    printf("Title: %s\n", metadata->title[0] ? metadata->title : "Unknown");
    printf("Artist: %s\n", metadata->artist[0] ? metadata->artist : "Unknown");
    printf("Album: %s\n", metadata->album[0] ? metadata->album : "Unknown");
    printf("Year: %s\n", metadata->year[0] ? metadata->year : "Unknown");
    printf("Genre: %s\n", metadata->genre[0] ? metadata->genre : "Unknown");
}

int read_metadata_from_file(const char *file_path, Metadata *metadata) {
    FILE *file = fopen(file_path, "rb");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", file_path);
        return -1;
    }

    // Simulating reading metadata from a file, this is where you would parse
    // actual data depending on the file type (e.g. MP3, WAV)
    fread(metadata, sizeof(Metadata), 1, file);
    fclose(file);
    
    return 0;
}

int write_metadata_to_file(const char *file_path, const Metadata *metadata) {
    FILE *file = fopen(file_path, "wb");
    if (!file) {
        fprintf(stderr, "Error: Could not write to file %s\n", file_path);
        return -1;
    }
    
    fwrite(metadata, sizeof(Metadata), 1, file);
    fclose(file);
    
    return 0;
}

void prompt_metadata(Metadata *metadata) {
    printf("Enter Title: ");
    fgets(metadata->title, MAX_METADATA, stdin);
    metadata->title[strcspn(metadata->title, "\n")] = 0;  // Remove newline

    printf("Enter Artist: ");
    fgets(metadata->artist, MAX_METADATA, stdin);
    metadata->artist[strcspn(metadata->artist, "\n")] = 0;  // Remove newline

    printf("Enter Album: ");
    fgets(metadata->album, MAX_METADATA, stdin);
    metadata->album[strcspn(metadata->album, "\n")] = 0;  // Remove newline

    printf("Enter Year: ");
    fgets(metadata->year, MAX_METADATA, stdin);
    metadata->year[strcspn(metadata->year, "\n")] = 0;  // Remove newline

    printf("Enter Genre: ");
    fgets(metadata->genre, MAX_METADATA, stdin);
    metadata->genre[strcspn(metadata->genre, "\n")] = 0;  // Remove newline
}

void display_usage() {
    printf("Usage: metadata_extractor <file_path> <command>\n");
    printf("Commands:\n");
    printf("  read      - Read metadata from file\n");
    printf("  write     - Write new metadata to file\n");
    printf("  display    - Display the metadata\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        display_usage();
        return EXIT_FAILURE;
    }

    const char *file_path = argv[1];
    const char *command = argv[2];
    Metadata metadata;
    initialize_metadata(&metadata);

    if (strcmp(command, "read") == 0) {
        if (read_metadata_from_file(file_path, &metadata) == 0) {
            printf("Metadata read successfully.\n");
        }
    } else if (strcmp(command, "write") == 0) {
        prompt_metadata(&metadata);
        if (write_metadata_to_file(file_path, &metadata) == 0) {
            printf("Metadata written successfully.\n");
        }
    } else if (strcmp(command, "display") == 0) {
        if (read_metadata_from_file(file_path, &metadata) == 0) {
            printf("Displaying Metadata:\n");
            print_metadata(&metadata);
        }
    } else {
        display_usage();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}