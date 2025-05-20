//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>

#define MAX_FILES 100
#define BUFFER_SIZE 1024
#define BACKUP_DIR "./backup"

typedef struct {
    char *filename;
    int thread_id;
} file_info;

void *backup_file(void *arg) {
    file_info *info = (file_info *)arg;
    char buffer[BUFFER_SIZE];
    char backup_path[512];
    
    // Create backup directory if it doesn't exist
    if (mkdir(BACKUP_DIR, 0777) && errno != EEXIST) {
        perror("Could not create backup directory");
        pthread_exit(NULL);
    }

    // Prepare backup file path
    snprintf(backup_path, sizeof(backup_path), "%s/%s.bak", BACKUP_DIR, info->filename);
    
    FILE *src_file = fopen(info->filename, "rb");
    if (src_file == NULL) {
        perror("Error opening source file");
        pthread_exit(NULL);
    }

    FILE *dest_file = fopen(backup_path, "wb");
    if (dest_file == NULL) {
        perror("Error creating backup file");
        fclose(src_file);
        pthread_exit(NULL);
    }

    size_t bytes;
    while ((bytes = fread(buffer, 1, BUFFER_SIZE, src_file)) > 0) {
        fwrite(buffer, 1, bytes, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);
    
    printf("Thread %d: Backed up %s to %s\n", info->thread_id, info->filename, backup_path);
    pthread_exit(NULL);
}

void list_files(char *path, char *files[], int *file_count) {
    struct dirent *entry;
    DIR *dp = opendir(path);
    
    if (dp == NULL) {
        perror("Error opening directory");
        return;
    }
    
    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) {
            files[*file_count] = strdup(entry->d_name);
            (*file_count)++;
            if (*file_count >= MAX_FILES) break; // Prevent buffer overflow
        }
    }
    
    closedir(dp);
}

int main() {
    char *files[MAX_FILES];
    int file_count = 0;
    int i;
    pthread_t threads[MAX_FILES];
    
    // List files in the current directory
    list_files(".", files, &file_count);

    // Start backup threads
    for (i = 0; i < file_count; i++) {
        file_info *info = malloc(sizeof(file_info));
        info->filename = files[i];
        info->thread_id = i + 1; // Assign thread ID starting from 1

        if (pthread_create(&threads[i], NULL, backup_file, (void *)info) != 0) {
            perror("Failed to create thread");
            free(info);
        }
    }

    // Wait for all threads to complete
    for (i = 0; i < file_count; i++) {
        pthread_join(threads[i], NULL);
        free(files[i]); // Free file name memory
    }

    printf("Backup process completed successfully!\n");
    return 0;
}