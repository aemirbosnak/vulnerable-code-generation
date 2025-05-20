//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 4

// Define the virus signature to be detected
char *virus_signature = "virus";

// Structure to hold information about file and thread
typedef struct FileInfo {
    char *filename;
    pthread_t tid;
} FileInfo;

// Find all files with given extension in a directory and return a list
char **file_list(char *path, char *ext) {
    DIR *dir;
    struct dirent *ent;
    int count = 0;
    char **list = NULL;
    char *filename;
    int len;

    // Open the directory
    if ((dir = opendir(path)) != NULL) {
        // Loop through all files in directory
        while ((ent = readdir (dir)) != NULL) {
            // Check if file has the given extension
            len = strlen(ent->d_name);
            if (len > strlen(ext) && strcmp(ent->d_name + len - strlen(ext), ext) == 0) {
                // Allocate memory for filename and add it to the list
                filename = malloc(strlen(path) + strlen(ent->d_name) + 2);
                sprintf(filename, "%s/%s", path, ent->d_name);
                list = realloc(list, (count+1)*sizeof(char *));
                list[count++] = filename;
            }
        }
        closedir(dir);
    }
    return list;
}

// Find if given file has the virus signature
int scan_file(char *filename) {
    FILE *file;
    char buffer[1000];
    int found = 0;

    // Open the file for reading
    if ((file = fopen(filename, "r")) != NULL) {
        // Search for the virus signature in the file
        while (fgets(buffer, sizeof(buffer), file)) {
            if (strstr(buffer, virus_signature) != NULL) {
                found = 1;
                break;
            }
        }
        fclose(file);
    }
    return found;
}

// Thread function to scan a list of files
void *scan_files(void *ptr) {
    FileInfo *info = (FileInfo *)ptr;
    int i, found;

    // Loop through all files in the list and scan for virus signature
    for (i = 0; i < MAX_THREADS; i++) {
        if (info[i].filename != NULL) {
            found = scan_file(info[i].filename);
            if (found)
                printf("Virus found in file: %s\n", info[i].filename);
            free(info[i].filename);
            info[i].filename = NULL;
        }
    }
    return NULL;
}

// Main function to start scanning
int main(int argc, char **argv) {
    char *path;
    char **list;
    int i, count = 0;
    FileInfo info[MAX_THREADS];
    int thread_count = 0;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return 1;
    }

    path = argv[1];

    // Get list of files with .c extension in the given directory
    list = file_list(path, ".c");

    // Loop through all files and create threads to scan them
    for (i = 0; list[i] != NULL; i++) {
        info[count].filename = list[i];
        if (count == MAX_THREADS-1) {
            // Start a new thread to scan a batch of files
            pthread_create(&info[count].tid, NULL, scan_files, info);
            thread_count++;
            count = 0;
        } else {
            count++;
        }
    }

    // Start a new thread for remaining files
    if (count > 0) {
        pthread_create(&info[count].tid, NULL, scan_files, info);
        thread_count++;
    }

    // Wait for all threads to finish
    for (i = 0; i < thread_count; i++) {
        pthread_join(info[count].tid, NULL);
    }

    return 0;
}