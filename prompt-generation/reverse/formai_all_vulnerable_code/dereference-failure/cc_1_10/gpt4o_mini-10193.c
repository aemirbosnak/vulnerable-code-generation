//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

// Structure representing a futuristic metadata entry
typedef struct {
    char filename[256];
    char type[50];
    float size; // Size in kilobytes
    char date[20]; // Creation date
} Metadata;

// Function prototypes
void extract_metadata(const char *directory);
void print_metadata(Metadata *data, int count);
char *get_file_type(const char *filename);
void format_size(float size, char *buffer);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    char *input_directory = argv[1];
    extract_metadata(input_directory);

    return 0;
}

// Function to extract metadata from files in the specified directory
void extract_metadata(const char *directory) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;
    Metadata *metadata_list = malloc(100 * sizeof(Metadata)); // Dynamic array for metadata entries
    int count = 0;

    // Open the specified directory
    if (!(dir = opendir(directory))) {
        fprintf(stderr, "Cannot open directory: %s\n", directory);
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip hidden files
        if (entry->d_name[0] == '.') continue;

        char filepath[512];
        snprintf(filepath, sizeof(filepath), "%s/%s", directory, entry->d_name);

        // Get file status
        if (stat(filepath, &file_stat) == -1) {
            perror("stat");
            continue;
        }

        // Populate metadata
        strcpy(metadata_list[count].filename, entry->d_name);
        strcpy(metadata_list[count].type, get_file_type(entry->d_name));
        metadata_list[count].size = file_stat.st_size / 1024.0; // Convert to KB
        strftime(metadata_list[count].date, sizeof(metadata_list[count].date), "%Y-%m-%d %H:%M:%S", localtime(&file_stat.st_ctime));
        
        count++;
    }

    closedir(dir);
    print_metadata(metadata_list, count);
    free(metadata_list);
}

// Print the collected metadata in a sleek, sci-fi format
void print_metadata(Metadata *data, int count) {
    printf("==== Cybernetic Metadata Extractor ====\n");
    printf("| %-30s | %-10s | %-8s | %-19s |\n", "File Name", "Type", "Size (KB)", "Creation Date");
    printf("=========================================\n");

    for (int i = 0; i < count; i++) {
        char size_buffer[16];
        format_size(data[i].size, size_buffer);
        printf("| %-30s | %-10s | %-8s | %-19s |\n", data[i].filename, data[i].type, size_buffer, data[i].date);
    }

    printf("=========================================\n");
}

// Function to determine file type based on its extension
char *get_file_type(const char *filename) {
    const char *dot = strrchr(filename, '.');
    if (!dot || dot == filename) return "Unknown";

    if (strcmp(dot, ".txt") == 0) return "Text";
    else if (strcmp(dot, ".jpg") == 0 || strcmp(dot, ".png") == 0) return "Image";
    else if (strcmp(dot, ".exe") == 0) return "Executable";
    else if (strcmp(dot, ".mp3") == 0 || strcmp(dot, ".wav") == 0) return "Audio";
    else if (strcmp(dot, ".mp4") == 0 || strcmp(dot, ".mkv") == 0) return "Video";
    else return "Binary";
}

// Format size to display nicely
void format_size(float size, char *buffer) {
    snprintf(buffer, 16, "%.2f", size);
}