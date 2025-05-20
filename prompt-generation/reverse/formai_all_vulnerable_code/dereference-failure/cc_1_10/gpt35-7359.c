//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <pthread.h>

#define NUM_THREADS 4 // Number of threads to be used for scanning
#define MAX_PATH_LENGTH 200 // Maximum length of the file path

pthread_mutex_t mutex; // Mutex for shared resources access

char *keywords[] = {"virus", "malware", "dangerous", "hacker", "trojan"}; // List of keywords to scan for

void *scanFiles(void *pathPtr) {
    char *path = (char*) pathPtr; // File path passed as argument
    char buffer[1024]; // Buffer for reading the file contents
    FILE *file = fopen(path, "r"); // Open the file in read mode
    if(file != NULL) {
        while(fgets(buffer, sizeof(buffer), file)) {
            for(int i = 0; i < sizeof(keywords) / sizeof(char*); i++) {
                if(strstr(buffer, keywords[i])) {
                    // Found a keyword, print the file path and exit
                    printf("Infected file found: %s\n", path);
                    fclose(file);
                    pthread_exit(NULL);
                }
            }
        }
        fclose(file);
    }
    pthread_exit(NULL);
}

void scanDirectory(char *dirPath) {
    struct dirent *entry;
    DIR *dir = opendir(dirPath); // Open the directory
    if(dir != NULL) {
        char path[MAX_PATH_LENGTH];
        while((entry = readdir(dir)) != NULL) {
            if(entry->d_type == DT_DIR) {
                if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                    continue;
                }
                sprintf(path, "%s/%s", dirPath, entry->d_name);
                scanDirectory(path);
            } else {
                sprintf(path, "%s/%s", dirPath, entry->d_name);
                // Create a thread to scan the file
                pthread_t tid;
                pthread_create(&tid, NULL, scanFiles, (void*)path);
                pthread_mutex_lock(&mutex);
                pthread_mutex_unlock(&mutex);
            }
        }
        closedir(dir);
    }
}

int main(int argc, char *argv[]) {
    char *dir = argv[1]; // Get the directory path from command-line argument
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&mutex, NULL);
    // Create multiple threads for scanning the files in the directory
    for(int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, scanDirectory, dir);
    }
    // Wait for all threads to finish
    for(int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    printf("Scan complete.\n");
    return 0;
}