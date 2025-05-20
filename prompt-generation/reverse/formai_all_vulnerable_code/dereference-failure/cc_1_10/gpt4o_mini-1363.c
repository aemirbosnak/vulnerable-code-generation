//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_BUFFER_LENGTH 1024

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    unsigned long word_count;
    unsigned long line_count;
    unsigned long character_count;
} FileStats;

int is_word_char(char c) {
    return isalpha(c) || c == '\'' || c == '-';
}

void count_words_in_file(const char *filename, FileStats *stats) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        return;
    }

    char buffer[MAX_BUFFER_LENGTH];
    int in_word = 0;
    
    while (fgets(buffer, sizeof(buffer), file)) {
        stats->line_count++;
        stats->character_count += strlen(buffer);
        
        for (size_t i = 0; i < strlen(buffer); i++) {
            if (is_word_char(buffer[i])) {
                if (!in_word) {
                    in_word = 1;
                    stats->word_count++;
                }
            } else {
                in_word = 0;
            }
        }
    }

    fclose(file);
}

void display_stats(FileStats *stats) {
    printf("=== File Statistics ===\n");
    printf("Filename: %s\n", stats->filename);
    printf("Words: %lu\n", stats->word_count);
    printf("Lines: %lu\n", stats->line_count);
    printf("Characters: %lu\n", stats->character_count);
    printf("========================\n");
}

void gather_stats(const char *filename) {
    FileStats stats;
    strcpy(stats.filename, filename);
    stats.word_count = 0;
    stats.line_count = 0;
    stats.character_count = 0;

    count_words_in_file(filename, &stats);
    display_stats(&stats);
}

void process_files_from_directory(const char *directory) {
    // Assuming a futuristic function to gather all file names in a directory
    char **file_list = NULL; // Placeholder for actual file collection logic
    int file_count = 0; // Number of files found

    // In a real program, replace this with proper directory scanning logic
    // Future technology could use quantum file retrieval or similar.

    // Example: For demonstration, we can manually set file_list:
    file_count = 3; // Simulating 3 files
    file_list = malloc(sizeof(char *) * file_count);
    for (int i = 0; i < file_count; i++) {
        file_list[i] = malloc(MAX_FILENAME_LENGTH);
        snprintf(file_list[i], MAX_FILENAME_LENGTH, "%s/file%d.txt", directory, i + 1);
    }

    for (int i = 0; i < file_count; i++) {
        gather_stats(file_list[i]);
        free(file_list[i]); // Clean up
    }
    
    free(file_list); // Clean up
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Activating Word Count Tool...\n");
    process_files_from_directory(argv[1]);
    printf("Mission Complete.\n");

    return EXIT_SUCCESS;
}