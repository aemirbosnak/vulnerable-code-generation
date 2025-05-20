//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_FILES 100
#define BUFFER_SIZE 1024

typedef struct {
    char *sourcePath;
    char *backupPath;
} BackupJob;

void *backup_file(void *arg) {
    BackupJob *job = (BackupJob *)arg;
    char buffer[BUFFER_SIZE];
    FILE *sourceFile;
    FILE *targetFile;
    size_t bytesRead;
    
    // Create the target backup file path
    char *targetFilePath = malloc(strlen(job->backupPath) + strlen(job->sourcePath) + 2);
    sprintf(targetFilePath, "%s/%s", job->backupPath, strrchr(job->sourcePath, '/') + 1);

    // Open the source file for reading
    sourceFile = fopen(job->sourcePath, "rb");
    if (sourceFile == NULL) {
        perror("Failed to open source file");
        free(targetFilePath);
        pthread_exit(NULL);
    }

    // Open the target file for writing
    targetFile = fopen(targetFilePath, "wb");
    if (targetFile == NULL) {
        perror("Failed to create backup file");
        fclose(sourceFile);
        free(targetFilePath);
        pthread_exit(NULL);
    }

    // Copy contents from source to target
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), sourceFile)) > 0) {
        fwrite(buffer, 1, bytesRead, targetFile);
    }

    // Cleanup
    fclose(sourceFile);
    fclose(targetFile);
    printf("Successfully backed up: %s to %s\n", job->sourcePath, targetFilePath);
    
    free(targetFilePath);
    pthread_exit(NULL);
}

void backup_files(const char *sourceDir, const char *backupDir) {
    DIR *dir;
    struct dirent *entry;
    pthread_t threads[MAX_FILES];
    BackupJob jobs[MAX_FILES];
    int threadCount = 0;

    // Open the source directory
    dir = opendir(sourceDir);
    if (dir == NULL) {
        perror("Failed to open source directory");
        return;
    }

    // Read each entry in the directory
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            // Create a new backup job for regular files
            jobs[threadCount].sourcePath = malloc(strlen(sourceDir) + strlen(entry->d_name) + 2);
            sprintf(jobs[threadCount].sourcePath, "%s/%s", sourceDir, entry->d_name);
            jobs[threadCount].backupPath = malloc(strlen(backupDir) + 1);
            strcpy(jobs[threadCount].backupPath, backupDir);

            // Create a new thread to perform the backup
            if (pthread_create(&threads[threadCount], NULL, backup_file, &jobs[threadCount]) != 0) {
                perror("Failed to create thread");
                free(jobs[threadCount].sourcePath);
                free(jobs[threadCount].backupPath);
                continue;
            }

            threadCount++;
            if (threadCount >= MAX_FILES) {
                break;  // Limit the number of threads created
            }
        }
    }

    // Cleanup
    closedir(dir);

    // Wait for all threads to complete
    for (int i = 0; i < threadCount; i++) {
        pthread_join(threads[i], NULL);
        free(jobs[i].sourcePath);
        free(jobs[i].backupPath);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <backup_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    backup_files(argv[1], argv[2]);

    return EXIT_SUCCESS;
}