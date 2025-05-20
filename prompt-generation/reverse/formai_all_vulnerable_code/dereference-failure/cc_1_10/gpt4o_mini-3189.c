//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>

#define BUFFER_SIZE 4096

void recover_file(const char *source_path, const char *dest_path) {
    int src_fd, dest_fd;
    ssize_t bytes_read, bytes_written;
    char buffer[BUFFER_SIZE];

    src_fd = open(source_path, O_RDONLY);
    if (src_fd < 0) {
        perror("Cannot open source file for reading");
        return;
    }

    dest_fd = open(dest_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd < 0) {
        perror("Cannot open destination file for writing");
        close(src_fd);
        return;
    }

    while ((bytes_read = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written < 0) {
            perror("Error writing to destination file");
            break;
        }
    }

    if (bytes_read < 0) {
        perror("Error reading source file");
    }

    close(src_fd);
    close(dest_fd);
}

void recover_directory(const char *directory) {
    struct dirent *entry;
    DIR *dp;

    dp = opendir(directory);
    if (dp == NULL) {
        perror("Cannot open directory");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_type == DT_REG) { // Regular file
            char source_path[1024], dest_path[1024];
            snprintf(source_path, sizeof(source_path), "%s/%s", directory, entry->d_name);
            snprintf(dest_path, sizeof(dest_path), "recovered_%s", entry->d_name);
            printf("Recovering file: %s to %s\n", source_path, dest_path);
            recover_file(source_path, dest_path);
        }
    }

    closedir(dp);
}

void display_instructions() {
    printf("Welcome to the Ephemeral Data Recovery Tool!\n");
    printf("Instructions:\n");
    printf("1. Provide a path to the directory containing files you want to recover.\n");
    printf("2. The recovered files will be saved with a 'recovered_' prefix in the same directory.\n");
    printf("3. Ensure you have the necessary permissions to read and write files in the directory.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *directory_path = argv[1];

    display_instructions();
    recover_directory(directory_path);

    printf("Recovery process completed!\n");
    return EXIT_SUCCESS;
}