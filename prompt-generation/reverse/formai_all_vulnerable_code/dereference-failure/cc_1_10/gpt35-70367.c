//FormAI DATASET v1.0 Category: File Synchronizer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <pthread.h>

#define MAX_SIZE 10000
#define BUF_SIZE 1024

char* source_dir;
char* dest_dir;
int sync_interval;
int running;

void* sync_files(void* arg){
    while(running){
        // Open the source and destination directories
        DIR* source = opendir(source_dir);
        DIR* dest = opendir(dest_dir);

        if(source == NULL || dest == NULL){
            perror("Could not open directories");
            exit(EXIT_FAILURE);
        }

        struct dirent* source_ent;
        struct dirent* dest_ent;
        char source_path[MAX_SIZE];
        char dest_path[MAX_SIZE];
        struct stat source_stat;
        struct stat dest_stat;

        // Sync all files in the source directory
        while((source_ent = readdir(source)) != NULL){
            if(strcmp(source_ent->d_name, ".") == 0 || strcmp(source_ent->d_name, "..") == 0){
                continue;
            }

            snprintf(source_path, MAX_SIZE, "%s/%s", source_dir, source_ent->d_name);
            snprintf(dest_path, MAX_SIZE, "%s/%s", dest_dir, source_ent->d_name);

            if(stat(source_path, &source_stat) == -1){
                perror("Could not get file info");
                exit(EXIT_FAILURE);
            }

            // Check if the file already exists in the destination directory
            if(stat(dest_path, &dest_stat) != -1){
                // Check if the source file is newer
                if(difftime(source_stat.st_mtime, dest_stat.st_mtime) < 0){
                    continue;
                }
            }

            // Create a new file in the destination directory
            int source_file = open(source_path, O_RDONLY);
            int dest_file = open(dest_path, O_CREAT | O_WRONLY);

            char buf[BUF_SIZE];
            ssize_t bytes_read;

            do {
                bytes_read = read(source_file, buf, BUF_SIZE);
                write(dest_file, buf, bytes_read);
            } while(bytes_read == BUF_SIZE);

            // Set the modification time for the file in the destination directory
            struct timespec times[2];
            times[0] = source_stat.st_atim;
            times[1] = source_stat.st_mtim;

            if(futimens(dest_file, times) == -1){
                perror("Could not set file times");
                exit(EXIT_FAILURE);
            }

            // Close the files
            close(source_file);
            close(dest_file);
        }

        // Close the directories
        closedir(source);
        closedir(dest);

        // Wait for the sync interval
        sleep(sync_interval);
    }

    return NULL;
}

int main(int argc, char** argv){
    if(argc != 4){
        printf("Usage: %s <source directory> <destination directory> <sync interval>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    source_dir = argv[1];
    dest_dir = argv[2];
    sync_interval = atoi(argv[3]);

    // Start the sync thread
    pthread_t sync_thread;
    running = 1;
    pthread_create(&sync_thread, NULL, sync_files, NULL);

    // Wait for user input to stop the program
    getchar();
    running = 0;
    pthread_join(sync_thread, NULL);

    return 0;
}