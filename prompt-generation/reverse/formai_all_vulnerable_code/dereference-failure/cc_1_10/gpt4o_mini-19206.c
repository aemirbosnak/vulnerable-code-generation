//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <pthread.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_THREADS 4
#define MAX_PATH 1024

typedef struct {
    char *sourceFilePath;
    char *backupFilePath;
} FileBackupInfo;

void* backupFile(void* arg) {
    FileBackupInfo *fileInfo = (FileBackupInfo *)arg;
    
    int sourceFD = open(fileInfo->sourceFilePath, O_RDONLY);
    if (sourceFD < 0) {
        perror("Could not open source file");
        free(fileInfo);
        return NULL;
    }

    int backupFD = open(fileInfo->backupFilePath, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    if (backupFD < 0) {
        perror("Could not open backup file");
        close(sourceFD);
        free(fileInfo);
        return NULL;
    }

    char buffer[4096];
    ssize_t bytesRead;
    while ((bytesRead = read(sourceFD, buffer, sizeof(buffer))) > 0) {
        write(backupFD, buffer, bytesRead);
    }

    close(sourceFD);
    close(backupFD);
    printf("Backup completed for: %s to %s\n", fileInfo->sourceFilePath, fileInfo->backupFilePath);
    free(fileInfo);
    return NULL;
}

void backupDirectory(const char *sourceDir, const char *backupDir) {
    struct dirent *entry;
    DIR *dp = opendir(sourceDir);
    if (dp == NULL) {
        perror("Could not open source directory");
        return;
    }
    
    pthread_t threads[MAX_THREADS];
    int threadCount = 0;

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_name[0] == '.') { // Skip hidden files
            continue;
        }
        
        char sourceFilePath[MAX_PATH];
        char backupFilePath[MAX_PATH];

        snprintf(sourceFilePath, sizeof(sourceFilePath), "%s/%s", sourceDir, entry->d_name);
        snprintf(backupFilePath, sizeof(backupFilePath), "%s/%s", backupDir, entry->d_name);

        FileBackupInfo *fileInfo = malloc(sizeof(FileBackupInfo));
        fileInfo->sourceFilePath = strdup(sourceFilePath);
        fileInfo->backupFilePath = strdup(backupFilePath);

        if (threadCount < MAX_THREADS) {
            pthread_create(&threads[threadCount], NULL, backupFile, fileInfo);
            threadCount++;
        } else {
            // wait for threads to finish before starting new ones
            for (int i = 0; i < MAX_THREADS; i++) {
                pthread_join(threads[i], NULL);
                threadCount--;
            }
            pthread_create(&threads[threadCount], NULL, backupFile, fileInfo);
            threadCount++;
        }
    }
    
    // Wait for any remaining threads
    for (int i = 0; i < threadCount; i++) {
        pthread_join(threads[i], NULL);
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <backup_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *sourceDir = argv[1];
    const char *backupDir = argv[2];

    struct stat st = {0};
    if (stat(backupDir, &st) == -1) {
        mkdir(backupDir, 0700); // Create backup directory if it does not exist
    }

    backupDirectory(sourceDir, backupDir);
    
    return EXIT_SUCCESS;
}