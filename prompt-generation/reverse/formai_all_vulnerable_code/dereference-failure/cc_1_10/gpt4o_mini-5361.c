//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <signal.h>
#include <time.h>

#define MAX_FILES 100
#define FILE_PATH_LEN 256
#define HASH_LEN 64
#define TIME_BUFFER 26

// Structure to store file details
struct FileInfo {
    char path[FILE_PATH_LEN];
    char lastHash[HASH_LEN]; // Hash of the last known content
};

// Function to compute a simple hash of file contents
void computeFileHash(const char *path, char *hashBuffer) {
    FILE *file = fopen(path, "rb");
    if (file == NULL) {
        snprintf(hashBuffer, HASH_LEN, "ERROR");
        return;
    }

    unsigned long hash = 5381;
    int c;

    while ((c = fgetc(file)) != EOF) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    fclose(file);
    
    snprintf(hashBuffer, HASH_LEN, "%lx", hash);
}

// Function to check for file changes
void checkForIntrusion(struct FileInfo *files, int numFiles) {
    for (int i = 0; i < numFiles; i++) {
        char currentHash[HASH_LEN];
        computeFileHash(files[i].path, currentHash);
        
        if (strcmp(files[i].lastHash, currentHash) != 0) {
            printf("Intrusion detected on file: %s\n", files[i].path);
            printf("Previous Hash: %s | Current Hash: %s\n", files[i].lastHash, currentHash);
            // Log the time of intrusion
            time_t now;
            char timeString[TIME_BUFFER];
            time(&now);
            struct tm *tm_info = localtime(&now);
            strftime(timeString, TIME_BUFFER, "%Y-%m-%d %H:%M:%S", tm_info);
            printf("Timestamp of Intrusion: %s\n", timeString);
        }
    }
}

// Signal handler for graceful shutdown
void handleSigint(int sig) {
    printf("\nExiting Intrusion Detection System... Goodbye!\n");
    exit(0);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file1> <file2> ... <fileN>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    signal(SIGINT, handleSigint);
    
    struct FileInfo files[MAX_FILES];
    int numFiles = argc - 1;

    for (int i = 0; i < numFiles; i++) {
        strncpy(files[i].path, argv[i + 1], FILE_PATH_LEN);
        computeFileHash(files[i].path, files[i].lastHash);
    }

    printf("Intrusion Detection System initialized. Monitoring files...\n");
    
    while (1) {
        sleep(5); // check every 5 seconds
        checkForIntrusion(files, numFiles);
    }

    return 0;
}