//FormAI DATASET v1.0 Category: File Synchronizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>

#define BUF_SIZE 1024

/* Struct to hold file and directory information */
typedef struct {
    char* sourcePath; // path to the source folder
    char* destPath; // path to the destination folder
    pthread_mutex_t lock; // mutex lock
    int threadCount; // number of threads created
} FileSynchronizer;

/* Function to check if a directory exists */
int dirExists(char* path) {
    struct stat s;
    if (stat(path, &s) == 0 && S_ISDIR(s.st_mode)) {
        return 1;
    }
    return 0;
}

/* Function to get the path of a file or folder */
char* getPath(char* folder, char* file) {
    char* path = calloc(1, strlen(folder) + strlen(file) + 2); // +2 is for a slash and a null terminator
    strcat(path, folder);
    if (folder[strlen(folder) - 1] != '/') { // add slash if it is missing
        strcat(path, "/");
    }
    strcat(path, file);
    return path;
}

/* Function to copy files */
void* copyFiles(void* arg) {
    FileSynchronizer* fs = (FileSynchronizer*) arg;
    DIR *dir = opendir(fs->sourcePath);
    if (dir == NULL) {
        fprintf(stderr, "Unable to open directory \"%s\": %s\n", fs->sourcePath, strerror(errno));
        pthread_exit(NULL);
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // if it is a file
            char* sourceFile = entry->d_name;
            char* sourcePath = getPath(fs->sourcePath, sourceFile);
            char* destPath = getPath(fs->destPath, sourceFile);
            pthread_mutex_lock(&fs->lock); // lock before accessing thread count
            fs->threadCount++;
            pthread_mutex_unlock(&fs->lock);
            pid_t pid = fork();
            if (pid == 0) { // child process
                execl("/bin/cp", "cp", sourcePath, destPath, NULL); // copy file using cp command
                perror("Error copying file");
                pthread_exit(NULL);
            }
        }
    }
    closedir(dir);
    pthread_exit(NULL);
}

/* Function to synchronize files */
void synchronize(char* sourcePath, char* destPath, int numThreads) {
    if (!dirExists(sourcePath)) {
        fprintf(stderr, "Source folder \"%s\" does not exist or is not a directory.\n", sourcePath);
        return;
    }
    if (!dirExists(destPath)) {
        fprintf(stderr, "Destination folder \"%s\" does not exist or is not a directory.\n", destPath);
        return;
    }
    pthread_t threads[numThreads];
    pthread_mutex_t lock;
    pthread_mutex_init(&lock, NULL);
    FileSynchronizer fs = {sourcePath, destPath, lock, 0};
    int i;
    for (i = 0; i < numThreads; i++) {
        int rc = pthread_create(&threads[i], NULL, copyFiles, (void*) &fs); // create threads
        if (rc) {
            fprintf(stderr, "Error creating thread: %d\n", rc);
        }
    }
    for (i = 0; i < numThreads; i++) { // wait for all threads to finish
        int rc = pthread_join(threads[i], NULL);
        if (rc) {
            fprintf(stderr, "Error joining thread: %d\n", rc);
        }
    }
    printf("\n%d files copied.\n", fs.threadCount);
    pthread_mutex_destroy(&fs.lock);
}

/* Main function */
int main(int argc, char** argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s source_folder dest_folder num_threads\n", argv[0]);
        return 1;
    }
    char* sourcePath = argv[1];
    char* destPath = argv[2];
    int numThreads = atoi(argv[3]);
    synchronize(sourcePath, destPath, numThreads);
    return 0;
}