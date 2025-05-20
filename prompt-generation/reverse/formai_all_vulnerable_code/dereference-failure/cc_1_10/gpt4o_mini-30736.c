//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pthread.h>

// Define a structure to hold file analysis details
typedef struct {
    char *filename;
    int is_infected;
} FileCheck;

// Define a threshold for the infection signature
#define INFECTION_SIGNATURE "virus_signature"

// Function to check if a file is infected
void* check_file(void* arg) {
    FileCheck *file_check = (FileCheck*)arg;
    FILE *file = fopen(file_check->filename, "r");
    if (!file) {
        perror("Failed to open file");
        file_check->is_infected = 0; // Cannot determine if it’s infected if the file can't be opened
        return NULL;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (strstr(buffer, INFECTION_SIGNATURE) != NULL) {
            file_check->is_infected = 1;
            fclose(file);
            return NULL;
        }
    }

    file_check->is_infected = 0; // No infection signature found
    fclose(file);
    return NULL;
}

// Function to list files in a directory and check them asynchronously
void scan_directory(const char *directory_name) {
    struct dirent *entry;
    DIR *dp = opendir(directory_name);
    if (dp == NULL) {
        perror("Unable to open directory");
        return;
    }

    pthread_t threads[100]; // Array to hold thread identifiers
    FileCheck file_checks[100]; // Array to hold file check results
    int thread_count = 0;

    // Read entries in the directory
    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) { // Check if it's a regular file
            char full_path[1024];
            snprintf(full_path, sizeof(full_path), "%s/%s", directory_name, entry->d_name);

            file_checks[thread_count].filename = strdup(full_path);
            file_checks[thread_count].is_infected = -1; // Flag it as unprocessed

            // Create a new thread to check the file
            if (pthread_create(&threads[thread_count], NULL, check_file, &file_checks[thread_count]) != 0) {
                perror("Failed to create thread");
                free(file_checks[thread_count].filename);
            } else {
                thread_count++;
            }
        }
    }

    // Close the directory
    closedir(dp);

    // Join all threads and check results
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
        if (file_checks[i].is_infected) {
            printf("Infected file found: %s\n", file_checks[i].filename);
        } else {
            printf("File safe: %s\n", file_checks[i].filename);
        }
        free(file_checks[i].filename); // Free allocated memory
    }
}

// Main entry point of the program
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    scan_directory(argv[1]);
    return EXIT_SUCCESS;
}