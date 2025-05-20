//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Define the file synchronizer structure.
typedef struct {
    FILE *src_file;
    FILE *dst_file;
    char *src_line;
    char *dst_line;
    int src_line_length;
    int dst_line_length;
} file_synchronizer;

// Create a new file synchronizer.
file_synchronizer *new_file_synchronizer(FILE *src_file, FILE *dst_file) {
    file_synchronizer *fs = malloc(sizeof(file_synchronizer));
    fs->src_file = src_file;
    fs->dst_file = dst_file;
    fs->src_line = NULL;
    fs->dst_line = NULL;
    fs->src_line_length = 0;
    fs->dst_line_length = 0;
    return fs;
}

// Free the file synchronizer.
void free_file_synchronizer(file_synchronizer *fs) {
    if (fs->src_line != NULL) {
        free(fs->src_line);
    }
    if (fs->dst_line != NULL) {
        free(fs->dst_line);
    }
    free(fs);
}

// Read a line from the source file.
int read_src_line(file_synchronizer *fs) {
    fs->src_line_length = getline(&fs->src_line, &fs->src_line_length, fs->src_file);
    return fs->src_line_length;
}

// Read a line from the destination file.
int read_dst_line(file_synchronizer *fs) {
    fs->dst_line_length = getline(&fs->dst_line, &fs->dst_line_length, fs->dst_file);
    return fs->dst_line_length;
}

// Synchronize the two files.
void synchronize_files(file_synchronizer *fs) {
    while (read_src_line(fs) != -1) {
        if (read_dst_line(fs) == -1) {
            // The source file has more lines than the destination file.
            fprintf(fs->dst_file, "%s", fs->src_line);
        } else if (strcmp(fs->src_line, fs->dst_line) != 0) {
            // The two lines are different.
            fseek(fs->dst_file, -fs->dst_line_length, SEEK_CUR);
            fprintf(fs->dst_file, "%s", fs->src_line);
        }
    }

    if (read_dst_line(fs) != -1) {
        // The destination file has more lines than the source file.
        fprintf(fs->dst_file, "");
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s src_file dst_file\n", argv[0]);
        return 1;
    }

    FILE *src_file = fopen(argv[1], "r");
    if (src_file == NULL) {
        fprintf(stderr, "Error opening source file: %s\n", argv[1]);
        return 1;
    }

    FILE *dst_file = fopen(argv[2], "w");
    if (dst_file == NULL) {
        fprintf(stderr, "Error opening destination file: %s\n", argv[2]);
        return 1;
    }

    file_synchronizer *fs = new_file_synchronizer(src_file, dst_file);
    synchronize_files(fs);
    free_file_synchronizer(fs);

    fclose(src_file);
    fclose(dst_file);

    return 0;
}