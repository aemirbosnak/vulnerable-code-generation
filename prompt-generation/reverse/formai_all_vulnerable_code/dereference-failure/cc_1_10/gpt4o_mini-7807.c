//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

#define BUFFER_SIZE 1024
#define MAX_FILENAME_LENGTH 256

void showHelp() {
    printf("File Backup System\n");
    printf("Usage: ./backup_source dest_dir source_file1 source_file2 ...\n");
    printf("This program will create a backup of the specified files in the destination directory.\n\n");
}

int isDirectory(const char *path) {
    struct stat pathStat;
    stat(path, &pathStat);
    return S_ISDIR(pathStat.st_mode);
}

void createBackup(const char *source, const char *destination) {
    char buffer[BUFFER_SIZE];
    int source_fd, dest_fd;
    ssize_t bytesRead, bytesWritten;

    source_fd = open(source, O_RDONLY);
    if (source_fd < 0) {
        perror("Error opening source file");
        return;
    }

    char destPath[MAX_FILENAME_LENGTH];
    snprintf(destPath, sizeof(destPath), "%s/%s.bak", destination, strrchr(source, '/') + 1);
    
    dest_fd = open(destPath, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (dest_fd < 0) {
        perror("Error creating destination file");
        close(source_fd);
        return;
    }

    while ((bytesRead = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        bytesWritten = write(dest_fd, buffer, bytesRead);
        if (bytesWritten < 0) {
            perror("Error writing to destination file");
            break;
        }
    }

    close(source_fd);
    close(dest_fd);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        showHelp();
        return EXIT_FAILURE;
    }
    
    const char *dest = argv[1];
    if (!isDirectory(dest)) {
        fprintf(stderr, "Destination is not a directory: %s\n", dest);
        return EXIT_FAILURE;
    }

    for (int i = 2; i < argc; ++i) {
        const char *source = argv[i];
        createBackup(source, dest);
    }

    printf("Backup completed successfully.\n");
    return EXIT_SUCCESS;
}