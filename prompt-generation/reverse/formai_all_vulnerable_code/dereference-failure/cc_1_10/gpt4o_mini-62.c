//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 260

void serenade(char *filePath, char *destinationPath) {
    printf("Ah, my dear file: %s, you are destined for a new home: %s\n", filePath, destinationPath);
}

bool file_exists(const char *path) {
    struct stat buffer;
    return (stat(path, &buffer) == 0);
}

void whisper_to_file(char *source, char *dest) {
    FILE *srcFile = fopen(source, "rb");
    FILE *destFile = fopen(dest, "wb");
    
    if (!srcFile || !destFile) {
        perror("Failed to open file");
        return;
    }

    char buffer[1024];
    size_t bytesRead;
    
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), srcFile)) > 0) {
        fwrite(buffer, 1, bytesRead, destFile);
    }

    fclose(srcFile);
    fclose(destFile);
}

void synchronize_files(const char *sourceDir, const char *destDir) {
    DIR *dir;
    struct dirent *entry;

    if (!(dir = opendir(sourceDir))) {
        fprintf(stderr, "Could not open source directory: %s\n", sourceDir);
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') {  // Ignore hidden files and directories
            continue;
        }

        char sourcePath[MAX_PATH];
        char destPath[MAX_PATH];

        snprintf(sourcePath, sizeof(sourcePath), "%s/%s", sourceDir, entry->d_name);
        snprintf(destPath, sizeof(destPath), "%s/%s", destDir, entry->d_name);

        serenade(sourcePath, destPath);

        // Check if the file exists in the destination directory
        if (!file_exists(destPath)) {
            whisper_to_file(sourcePath, destPath);
            printf("Your essence has been copied from %s to %s.\n", sourcePath, destPath);
        } else {
            printf("Oh, %s, you already reside in %s. No need to disturb your peace.\n", entry->d_name, destDir);
        }
    }
    closedir(dir);
}

void heartbeats() {
    printf("\nSynchronizing files...\n");
    printf("With every heartbeat, we bring together what should be together...\n");
    sleep(2);  // Pause for a dramatic effect
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *sourceDir = argv[1];
    const char *destDir = argv[2];

    puts("In the realm of files and dreams, we embark on a journey of synchronization...");
    heartbeats();

    synchronize_files(sourceDir, destDir);

    puts("Our rendezvous is complete. Files have been united, as love should be!");
    return EXIT_SUCCESS;
}