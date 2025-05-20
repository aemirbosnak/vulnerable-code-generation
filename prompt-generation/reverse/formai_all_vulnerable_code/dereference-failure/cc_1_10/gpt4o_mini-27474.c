//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_SIGNATURES 5
#define MAX_PATH_LENGTH 1024
#define NUMBER_OF_FILES 10

// Sample virus signatures
const char* virus_signatures[MAX_SIGNATURES] = {
    "VIRUS1_SIGNATURE",
    "VIRUS2_SIGNATURE",
    "VIRUS3_SIGNATURE",
    "VIRUS4_SIGNATURE",
    "VIRUS5_SIGNATURE"
};

typedef struct {
    char file_path[MAX_PATH_LENGTH];
} file_info;

// Function to check if a file contains any virus signatures
int contains_virus(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (!file) {
        perror("Could not open file");
        return 0;
    }
    
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        for (int i = 0; i < MAX_SIGNATURES; i++) {
            if (strstr(line, virus_signatures[i]) != NULL) {
                fclose(file);
                return 1; // Virus found
            }
        }
    }
    fclose(file);
    return 0; // No virus found
}

// Function to process a file (thread function)
void *scan_file(void *arg) {
    file_info *info = (file_info *)arg;
    if (contains_virus(info->file_path)) {
        printf("Virus detected in file: %s\n", info->file_path);
    } else {
        printf("No virus found in file: %s\n", info->file_path);
    }
    return NULL;
}

// Function to scan files in a given directory
void scan_directory(const char *directory_path) {
    DIR *dir = opendir(directory_path);
    struct dirent *entry;
    pthread_t threads[NUMBER_OF_FILES];
    file_info files[NUMBER_OF_FILES];
    int file_count = 0;

    if (!dir) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL && file_count < NUMBER_OF_FILES) {
        if (entry->d_type == DT_REG) { // Regular file
            snprintf(files[file_count].file_path, sizeof(files[file_count].file_path), "%s/%s", directory_path, entry->d_name);
            pthread_create(&threads[file_count], NULL, scan_file, &files[file_count]);
            file_count++;
        }
    }
    
    closedir(dir);
    
    // Join all threads
    for (int i = 0; i < file_count; i++) {
        pthread_join(threads[i], NULL);
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    scan_directory(argv[1]);
    return EXIT_SUCCESS;
}