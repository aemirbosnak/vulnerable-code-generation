//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_FILES 100
#define FILE_EXTENSION ".txt"
#define SEARCH_PATH "./lost_files"
#define LOG_FILE "recovery_log.txt"

// Structure to hold file information
typedef struct {
    char *filename;
    int found;
} FileEntry;

// Global array to hold found files
FileEntry foundFiles[MAX_FILES];
int foundCount = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to search for files in the specified directory
void *searchFiles(void *arg) {
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(SEARCH_PATH)) == NULL) {
        perror("opendir failed");
        return NULL;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Only interested in .txt files
        if (strstr(entry->d_name, FILE_EXTENSION) != NULL) {
            pthread_mutex_lock(&mutex);
            if (foundCount < MAX_FILES) {
                foundFiles[foundCount].filename = strdup(entry->d_name);
                foundFiles[foundCount].found = 1;
                foundCount++;
            }
            pthread_mutex_unlock(&mutex);
        }
    }

    closedir(dir);
    return NULL;
}

// Function to log recovered files
void logRecoveredFiles() {
    FILE *logFile = fopen(LOG_FILE, "a");
    if (logFile == NULL) {
        perror("Unable to open log file");
        return;
    }

    fprintf(logFile, "Recovered Files:\n");
    for (int i = 0; i < foundCount; i++) {
        if (foundFiles[i].found) {
            fprintf(logFile, "%s\n", foundFiles[i].filename);
        }
    }
    fprintf(logFile, "Total Recovered: %d\n\n", foundCount);
    fclose(logFile);
}

// Function to free allocated resources
void cleanup() {
    for (int i = 0; i < foundCount; i++) {
        free(foundFiles[i].filename);
    }
}

// Main function
int main() {
    pthread_t thread;

    printf("Starting data recovery process...\n");

    // Create a new thread to search for files
    if (pthread_create(&thread, NULL, searchFiles, NULL) != 0) {
        perror("Failed to create thread");
        return EXIT_FAILURE;
    }

    // Wait for the thread to finish
    pthread_join(thread, NULL);
    
    // Log the recovered files
    logRecoveredFiles();

    printf("Data recovery process completed.\n");
    cleanup();
    
    return EXIT_SUCCESS;
}