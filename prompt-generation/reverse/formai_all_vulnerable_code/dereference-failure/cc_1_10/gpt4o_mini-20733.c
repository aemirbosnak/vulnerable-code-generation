//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 512

void print_error(const char *msg) {
    perror(msg);
}

void recover_file(const char *file_path, const char *output_directory) {
    FILE *input_file = fopen(file_path, "rb");
    if (!input_file) {
        print_error("Failed to open input file");
        return;
    }

    char *buffer = malloc(BUFFER_SIZE);
    if (!buffer) {
        print_error("Failed to allocate memory for buffer");
        fclose(input_file);
        return;
    }

    snprintf(buffer, BUFFER_SIZE, "%s/%s_recovered", output_directory, strrchr(file_path, '/') + 1);
    FILE *output_file = fopen(buffer, "wb");
    if (!output_file) {
        print_error("Failed to open output file");
        free(buffer);
        fclose(input_file);
        return;
    }

    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, input_file)) > 0) {
        fwrite(buffer, 1, bytesRead, output_file);
    }

    free(buffer);
    fclose(output_file);
    fclose(input_file);
}

void scan_directory(const char *dir_name, const char *output_directory) {
    struct dirent *entry;
    DIR *dp = opendir(dir_name);
    if (dp == NULL) {
        print_error("Failed to open directory");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_type == DT_REG) { // Regular file
            char file_path[PATH_MAX];
            snprintf(file_path, sizeof(file_path), "%s/%s", dir_name, entry->d_name);
            recover_file(file_path, output_directory);
        }
    }

    closedir(dp);
}

void usage() {
    printf("Usage: data_recovery_tool <directory_to_scan> <output_directory>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        usage();
        return EXIT_FAILURE;
    }

    const char *directory_to_scan = argv[1];
    const char *output_directory = argv[2];

    // Create output directory if it doesn't exist
    if (mkdir(output_directory, 0777) && errno != EEXIST) {
        print_error("Failed to create output directory");
        return EXIT_FAILURE;
    }

    printf("Scanning for files in: %s\n", directory_to_scan);
    scan_directory(directory_to_scan, output_directory);
    printf("Recovery process completed. Files are saved in: %s\n", output_directory);

    return EXIT_SUCCESS;
}