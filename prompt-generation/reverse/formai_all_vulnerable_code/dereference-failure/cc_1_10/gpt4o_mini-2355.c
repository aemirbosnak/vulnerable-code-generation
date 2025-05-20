//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 256

void heraldMessage(const char *message);
void gatherTrove(const char *path, char trove[][MAX_PATH], int *count);
void transferFiles(const char *source, const char *destination);
int fileExists(const char *filename);
void summonFile(const char *filename, const char *dest);
void beseechStatus(int status, const char *action);

int main() {
    char source[MAX_PATH], destination[MAX_PATH];

    heraldMessage("Enter the path of the source directory, brave knight:");
    fgets(source, MAX_PATH, stdin);
    source[strcspn(source, "\n")] = 0;  // Remove the newline
    
    heraldMessage("Enter the path of the destination directory, courageous squire:");
    fgets(destination, MAX_PATH, stdin);
    destination[strcspn(destination, "\n")] = 0;  // Remove the newline

    transferFiles(source, destination);
    
    heraldMessage("The synchronization quest hath concluded!");

    return 0;
}

void heraldMessage(const char *message) {
    printf("=== %s ===\n", message);
}

void gatherTrove(const char *path, char trove[][MAX_PATH], int *count) {
    DIR *d;
    struct dirent *dir;
    d = opendir(path);
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0) {
                snprintf(trove[*count], MAX_PATH, "%s/%s", path, dir->d_name);
                (*count)++;
            }
        }
        closedir(d);
    } else {
        heraldMessage("Oh dear! Could not open the directory!");
    }
}

void transferFiles(const char *source, const char *destination) {
    char files[1024][MAX_PATH];  // File trove
    int count = 0;
    gatherTrove(source, files, &count);

    for (int i = 0; i < count; i++) {
        char *file = files[i];
        char *filename = strrchr(file, '/') + 1;
        char destinationFile[MAX_PATH];

        snprintf(destinationFile, MAX_PATH, "%s/%s", destination, filename);

        if (!fileExists(destinationFile)) {
            summonFile(file, destination);
        } else {
            heraldMessage("A file of the same name resides in the distant lands. Skipping...");
        }
    }
}

int fileExists(const char *filename) {
    struct stat buffer;   
    return (stat(filename, &buffer) == 0); 
}

void summonFile(const char *filename, const char *dest) {
    char command[MAX_PATH * 2];
    snprintf(command, sizeof(command), "cp -v '%s' '%s'", filename, dest);
    int status = system(command);
    beseechStatus(status, "Copying");
}

void beseechStatus(int status, const char *action) {
    if (status != 0) {
        heraldMessage("Alas! The operation failed, seek the wise to resolve this plight!");
    } else {
        heraldMessage("The operation hath succeeded, the task is fulfilled!");
    }
}