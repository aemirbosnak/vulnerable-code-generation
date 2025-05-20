//FormAI DATASET v1.0 Category: File Synchronizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <pthread.h>

#define MAX_FILES 1000
#define MAX_PATH_LENGTH 1024

char* source_dir;
char* destination_dir;

typedef struct {
    char** files;
    int count;
} FileList;

void* syncFile(void* filename) {
    char source[MAX_PATH_LENGTH];
    char destination[MAX_PATH_LENGTH];
    sprintf(source, "%s/%s", source_dir, (char*)filename);
    sprintf(destination, "%s/%s", destination_dir, (char*)filename);
    FILE* source_file = fopen(source, "rb");
    if (source_file == NULL) {
        printf("Error opening source file %s\n", source);
        return NULL;
    }
    FILE* destination_file = fopen(destination, "wb");
    if (destination_file == NULL) {
        printf("Error opening destination file %s\n", destination);
        fclose(source_file);
        return NULL;
    }
    int ch;
    while ((ch = fgetc(source_file)) != EOF) {
        fputc(ch, destination_file);
    }
    fclose(source_file);
    fclose(destination_file);
    printf("Sync complete for file %s\n", (char*)filename);
    return NULL;
}

FileList* getFileList(char* directory) {
    FileList* fileList = (FileList*)malloc(sizeof(FileList));
    fileList->files = (char**)malloc(sizeof(char*)*MAX_FILES);
    fileList->count = 0;
    DIR* dir = opendir(directory);
    if (dir == NULL) {
        printf("Unable to open directory %s", directory);
        return fileList;
    }
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        char* name = entry->d_name;
        if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0)
            continue;
        fileList->files[fileList->count++] = strdup(name);
    }
    closedir(dir);
    return fileList;
}

void freeFileList(FileList* fileList) {
    for (int i = 0; i < fileList->count; i++) {
        free(fileList->files[i]);
    }
    free(fileList->files);
    free(fileList);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <source directory> <destination directory>\n", argv[0]);
        exit(0);
    }
    source_dir = argv[1];
    destination_dir = argv[2];
    printf("Starting file synchronization from %s to %s\n", source_dir, destination_dir);
    pthread_t threads[MAX_FILES];
    int thread_count = 0;
    FileList* fileList = getFileList(source_dir);
    for (int i = 0; i < fileList->count; i++) {
        char* filename = fileList->files[i];
        pthread_create(&threads[thread_count++], NULL, syncFile, (void*)filename);
    }
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }
    freeFileList(fileList);
    printf("Sync complete!\n");
    return 0;
}