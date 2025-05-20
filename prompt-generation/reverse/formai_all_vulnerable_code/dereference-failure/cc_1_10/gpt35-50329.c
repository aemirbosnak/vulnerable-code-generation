//FormAI DATASET v1.0 Category: File Backup System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_THREADS 100
#define MAX_BACKUPS 10
#define MAX_FILENAME_LEN 100
#define MAX_BUFFER_SIZE 1024

char backups[MAX_BACKUPS][MAX_FILENAME_LEN];
int current_backup = 0;
pthread_mutex_t backup_mutex;

void create_backup(char *filename){
    time_t now;
    char buffer[MAX_BUFFER_SIZE];

    // Get current time and add it to backup filename
    now = time(NULL);
    strftime(buffer, sizeof(buffer), "_%Y-%m-%d_%H:%M:%S", localtime(&now));
    strcat(filename, buffer);

    // Copy file to backup folder
    FILE *source_file = fopen(filename, "r");
    char backup_file[MAX_FILENAME_LEN] = "backup/";
    strcat(backup_file, filename);
    FILE *destination_file = fopen(backup_file, "w");

    char c;
    while ((c = fgetc(source_file)) != EOF) {
        fputc(c, destination_file);
    }

    fclose(source_file);
    fclose(destination_file);

    // Update backups array
    pthread_mutex_lock(&backup_mutex);
    if (current_backup >= MAX_BACKUPS) {
        // Remove oldest backup
        remove(backups[0]);
        for (int i = 0; i < MAX_BACKUPS - 1; i++) {
            strcpy(backups[i], backups[i+1]);
        }
        current_backup--;
    }
    strcpy(backups[current_backup], backup_file);
    current_backup++;
    pthread_mutex_unlock(&backup_mutex);
}

void *backup_file(void *filename) {
    pthread_mutex_lock(&backup_mutex);
    printf("[THREAD %ld] Creating backup for file %s\n", pthread_self(), (char *)filename);
    pthread_mutex_unlock(&backup_mutex);

    create_backup((char *)filename);

    pthread_mutex_lock(&backup_mutex);
    printf("[THREAD %ld] Backup for file %s created\n", pthread_self(), (char *)filename);
    pthread_mutex_unlock(&backup_mutex);

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [filename]\n", argv[0]);  
        exit(1); 
    }

    // Create backup folder if it doesn't exist
    struct stat st = {0};
    if (stat("backup", &st) == -1) {
        mkdir("backup", 0700);
    }

    pthread_t thread_ids[MAX_THREADS];
    int num_threads = 0;

    // Create threads to backup file
    for (int i = 1; i < argc; i++) {
        // Create thread
        if (pthread_create(&thread_ids[num_threads], NULL, backup_file, (void *)argv[i]) != 0) {
            printf("Error creating thread for file %s\n", argv[i]);
        } else {
            num_threads++;
        }

        // Wait for all threads to finish
        if (num_threads >= MAX_THREADS) {
            for (int j = 0; j < num_threads; j++) {
                pthread_join(thread_ids[j], NULL);
            }
            num_threads = 0;
        }
    }

    for (int j = 0; j < num_threads; j++) {
        pthread_join(thread_ids[j], NULL);
    }

    // Print all backups
    pthread_mutex_lock(&backup_mutex);
    printf("\nAll backups:\n");
    for (int i = 0; i < current_backup; i++) {
        printf("%s\n", backups[i]);
    }
    pthread_mutex_unlock(&backup_mutex);

    return 0;
}