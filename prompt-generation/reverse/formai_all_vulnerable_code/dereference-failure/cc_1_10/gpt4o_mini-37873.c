//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <pthread.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_PATH 1024
#define CHUNK_SIZE 4096
#define SIGNATURES_FILE "signatures.txt"

typedef struct {
    char *file_path;
} file_scan_t;

// Function to check if the file contains any signatures
int contains_signature(const char *file_path, const char **signatures, int num_signatures) {
    int fd = open(file_path, O_RDONLY);
    if (fd < 0) {
        perror("Failed to open file");
        return -1;
    }

    char buffer[CHUNK_SIZE];
    ssize_t bytes_read;

    while ((bytes_read = read(fd, buffer, CHUNK_SIZE)) > 0) {
        for (int i = 0; i < num_signatures; i++) {
            if (strstr(buffer, signatures[i]) != NULL) {
                close(fd);
                return 1; // Signature found
            }
        }
    }
    close(fd);
    return 0; // No signatures found
}

// Thread function to scan a file
void *scan_file(void *arg) {
    file_scan_t *scan_info = (file_scan_t *)arg;
    const char *signatures[] = {"EICAR", "virus_signature_2", "malware_signature_3"}; // Example signatures
    int num_signatures = sizeof(signatures) / sizeof(signatures[0]);

    printf("Scanning file: %s\n", scan_info->file_path);
    int result = contains_signature(scan_info->file_path, signatures, num_signatures);
    
    if (result == 1) {
        printf("Virus found in %s!\n", scan_info->file_path);
    } else if (result == 0) {
        printf("No virus found in %s.\n", scan_info->file_path);
    }

    free(scan_info->file_path);
    free(scan_info);
    return NULL;
}

// Function to scan a directory
void scan_directory(const char *dir_path) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(dir_path);
    if (dir == NULL) {
        perror("Failed to open directory");
        return;
    }

    pthread_t threads[100];
    int thread_count = 0;

    // Read entries in the directory
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Regular file
            file_scan_t *scan_info = malloc(sizeof(file_scan_t));
            scan_info->file_path = malloc(MAX_PATH);
            snprintf(scan_info->file_path, MAX_PATH, "%s/%s", dir_path, entry->d_name);

            // Create a new thread to scan the file
            if (pthread_create(&threads[thread_count], NULL, scan_file, (void *)scan_info) != 0) {
                perror("Failed to create thread");
                free(scan_info->file_path);
                free(scan_info);
            } else {
                thread_count++;
            }

            // Limit the number of concurrent threads
            if (thread_count >= 100) {
                for (int i = 0; i < thread_count; i++) {
                    pthread_join(threads[i], NULL);
                }
                thread_count = 0;
            }
        }
    }

    closedir(dir);

    // Join remaining threads
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return 1;
    }

    scan_directory(argv[1]);

    return 0;
}