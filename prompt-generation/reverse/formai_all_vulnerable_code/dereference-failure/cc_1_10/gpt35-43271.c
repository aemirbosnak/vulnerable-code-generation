//FormAI DATASET v1.0 Category: File Synchronizer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pthread.h>

// Structure for storing file information
typedef struct {
    char path[255];
    long int size;
    time_t modified;
} File;

// Global variables for file lists and synchronization
File* fileList1[1000];
File* fileList2[1000];
int fileCount1 = 0;
int fileCount2 = 0;
pthread_mutex_t lock;

// Recursive function to add files to the list
void walkDirectory(char* directory, File** fileList, int* fileCount) {
    DIR* dir;
    struct dirent* entry;
    struct stat statbuf;
    char path[255];
    
    // Open the directory and loop through the entries
    if ((dir = opendir(directory)) != NULL) {
        while ((entry = readdir(dir)) != NULL) {
            sprintf(path, "%s/%s", directory, entry->d_name);
            
            // Get the file's stat information
            if (stat(path, &statbuf) == -1) {
                continue;
            }
            
            // Add regular files to the list
            if (S_ISREG(statbuf.st_mode)) {
                File* file = malloc(sizeof(File));
                strcpy(file->path, path);
                file->size = statbuf.st_size;
                file->modified = statbuf.st_mtime;
                fileList[(*fileCount)++] = file;
            }
            
            // Recurse on subdirectories
            if (S_ISDIR(statbuf.st_mode) && strcmp(".", entry->d_name) != 0 && strcmp("..", entry->d_name) != 0) {
                walkDirectory(path, fileList, fileCount);
            }
        }
        closedir(dir);
    }
}

// Thread function for synchronizing files from list 1 to list 2
void* syncFiles1to2(void* arg) {
    int* numCopied = (int*) arg;
    for (int i = 0; i < fileCount1; i++) {
        pthread_mutex_lock(&lock);
        int alreadySynced = 0;
        for (int j = 0; j < fileCount2; j++) {
            if (strcmp(fileList1[i]->path, fileList2[j]->path) == 0) {
                alreadySynced = 1;
                if (fileList1[i]->modified > fileList2[j]->modified) {
                    FILE* src = fopen(fileList1[i]->path, "rb");
                    FILE* dest = fopen(fileList2[j]->path, "wb");
                    char buffer[1024];
                    size_t n;
                    while ((n = fread(buffer, 1, sizeof(buffer), src)) > 0) {
                        fwrite(buffer, 1, n, dest);
                    }
                    fclose(src);
                    fclose(dest);
                    (*numCopied)++;
                }
                break;
            }
        }
        if (!alreadySynced) {
            char destPath[255];
            sprintf(destPath, "%s/%s", "./dir2", strstr(fileList1[i]->path, "/")+1);
            FILE* src = fopen(fileList1[i]->path, "rb");
            FILE* dest = fopen(destPath, "wb");
            char buffer[1024];
            size_t n;
            while ((n = fread(buffer, 1, sizeof(buffer), src)) > 0) {
                fwrite(buffer, 1, n, dest);
            }
            fclose(src);
            fclose(dest);
            (*numCopied)++;
        }
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

// Thread function for synchronizing files from list 2 to list 1
void* syncFiles2to1(void* arg) {
    int* numCopied = (int*) arg;
    for (int i = 0; i < fileCount2; i++) {
        pthread_mutex_lock(&lock);
        int alreadySynced = 0;
        for (int j = 0; j < fileCount1; j++) {
            if (strcmp(fileList2[i]->path, fileList1[j]->path) == 0) {
                alreadySynced = 1;
                if (fileList2[i]->modified > fileList1[j]->modified) {
                    FILE* src = fopen(fileList2[i]->path, "rb");
                    FILE* dest = fopen(fileList1[j]->path, "wb");
                    char buffer[1024];
                    size_t n;
                    while ((n = fread(buffer, 1, sizeof(buffer), src)) > 0) {
                        fwrite(buffer, 1, n, dest);
                    }
                    fclose(src);
                    fclose(dest);
                    (*numCopied)++;
                }
                break;
            }
        }
        if (!alreadySynced) {
            char destPath[255];
            sprintf(destPath, "%s/%s", "./dir1", strstr(fileList2[i]->path, "/")+1);
            FILE* src = fopen(fileList2[i]->path, "rb");
            FILE* dest = fopen(destPath, "wb");
            char buffer[1024];
            size_t n;
            while ((n = fread(buffer, 1, sizeof(buffer), src)) > 0) {
                fwrite(buffer, 1, n, dest);
            }
            fclose(src);
            fclose(dest);
            (*numCopied)++;
        }
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    // Get the file lists for dir1 and dir2
    walkDirectory("./dir1", fileList1, &fileCount1);
    walkDirectory("./dir2", fileList2, &fileCount2);
    
    // Create threads for synchronization
    int numCopied = 0;
    pthread_t threads[2];
    pthread_mutex_init(&lock, NULL);
    pthread_create(&threads[0], NULL, syncFiles1to2, &numCopied);
    pthread_create(&threads[1], NULL, syncFiles2to1, &numCopied);
    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("Synced %d files.\n", numCopied);
    
    return 0;
}