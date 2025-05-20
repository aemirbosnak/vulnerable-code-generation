//FormAI DATASET v1.0 Category: Data recovery tool ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// This function extracts the file name from a given path.
// It returns a new string with the file name (without the path).
// If the path is invalid or the file name cannot be extracted, returns NULL.
char* get_file_name(char* path) {
    char* file_name = NULL;
    char* last_slash = strrchr(path, '/');
    if (last_slash != NULL) {
        file_name = last_slash + 1;
    } else {
        file_name = path;
    }
    if (strlen(file_name) == 0) {
        return NULL;
    }
    return strdup(file_name);
}

// This function searches for a file with a given name in the directory specified by path.
// If the file is found, it returns a FILE* to the opened file.
// If the file is not found or cannot be opened, returns NULL.
FILE* find_file(char* path, char* file_name, char mode) {
    char file_path[BUFFER_SIZE];
    snprintf(file_path, BUFFER_SIZE, "%s/%s", path, file_name);
    FILE* file = fopen(file_path, (mode == 'r') ? "rb" : "wb");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }
    return file;
}

// This function recovers the data of a file from two partial files in the directory specified by path.
// The partial files must have the form "filename.part1" and "filename.part2".
// If the recovery is successful, the recovered data is saved in a new file with the original name.
void recover_file_data(char* path, char* file_name) {
    FILE* part1_file = find_file(path, strcat(file_name, ".part1"), 'r');
    FILE* part2_file = find_file(path, strcat(file_name, ".part2"), 'r');
    char* output_file_name = get_file_name(file_name);
    if (part1_file == NULL || part2_file == NULL || output_file_name == NULL) {
        return;
    }
    FILE* output_file = find_file(path, output_file_name, 'w');
    if (output_file == NULL) {
        return;
    }
    char buffer[BUFFER_SIZE];
    int bytes_read = 0;
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, part1_file)) > 0) {
        fwrite(buffer, 1, bytes_read, output_file);
    }
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, part2_file)) > 0) {
        fwrite(buffer, 1, bytes_read, output_file);
    }
    fclose(part1_file);
    fclose(part2_file);
    fclose(output_file);
    printf("File %s recovered successfully!\n", output_file_name);
    free(output_file_name);
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s <directory path> <file name>\n", argv[0]);
        return EXIT_FAILURE;
    }
    char* path = argv[1];
    char* file_name = argv[2];
    recover_file_data(path, file_name);
    return EXIT_SUCCESS;
}