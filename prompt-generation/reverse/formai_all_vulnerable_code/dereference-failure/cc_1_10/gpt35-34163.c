//FormAI DATASET v1.0 Category: File Synchronizer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024
#define MAX_FILES 1000 

/* Define global variables */
char source_path[MAX_PATH_LENGTH];
char dest_path[MAX_PATH_LENGTH];
int file_count = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER; 
pthread_cond_t condition = PTHREAD_COND_INITIALIZER;

/*
 *  Function that synchronizes files from a source directory to a destination directory
 */
void* sync_files(void* arg) {
    DIR* directory;
    struct dirent* entry;
    char* file_list[MAX_FILES]; 
    char source[MAX_PATH_LENGTH];
    char dest[MAX_PATH_LENGTH];

    /* Copy source and destination paths to local variables */
    strcpy(source, source_path);
    strcpy(dest, dest_path);

    /* Open source directory */
    directory = opendir(source);
    if (directory == NULL) {
        printf("ERROR: Could not open directory %s\n", source);
        pthread_exit(NULL);
    }

    /* Traverse the directory and fetch list of files */
    while ((entry = readdir(directory)) != NULL) {
        /* Get file path */
        char* path = malloc(MAX_PATH_LENGTH);
        strcpy(path, source);
        strcat(path, "/");
        strcat(path, entry->d_name);

        /* Check if it's a file */
        if (entry->d_type == DT_REG) {
            /* Lock the mutex and add file to the list */
            pthread_mutex_lock(&lock);
            file_list[file_count++] = path;
            pthread_cond_signal(&condition);
            pthread_mutex_unlock(&lock);
        }
    }

    /* Close directory and free memory */
    closedir(directory);
    free(entry);

    /* Wait for all files to be copied */
    pthread_mutex_lock(&lock);
    while (file_count > 0) {
        pthread_cond_wait(&condition, &lock);
    }
    pthread_mutex_unlock(&lock);

    /* Copy files from source to destination */
    for (int i = 0; i < file_count; i++) {
        char* source_path = file_list[i];
        char* dest_path = malloc(MAX_PATH_LENGTH);
        char* file_name = strrchr(source_path, '/'); 
        strcpy(dest_path, dest); 
        strcat(dest_path, "/");
        strcat(dest_path, file_name + 1);
        if (link(source_path, dest_path) == -1) {
            printf("ERROR: Could not copy the file %s", file_name);
        }
        free(file_list[i]);        
    }
}

/*
 *  Main function
 */
int main(int argc, char* argv[]) {
    pthread_t tid;  /* Thread ID */

    /* Check if the user has supplied the right number of arguments */
    if (argc < 3) {
        printf("Usage: %s <source_path> <dest_path>\n", argv[0]);
        exit(1);
    }

    /* Copy the source and destination paths */
    strcpy(source_path, argv[1]);
    strcpy(dest_path, argv[2]);

    /* Create a new thread to sync files */
    if (pthread_create(&tid, NULL, sync_files, NULL) != 0) {
        printf("ERROR: Could not create new thread.\n");
        exit(1);
    }

    /* Wait for thread to complete execution */
    pthread_join(tid, NULL);

    /* Destroy mutex and condition variable */
    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&condition);
    
    printf("Files synchronized successfully!\n");

    return 0;
}