//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

/* Constant definitions */ 
#define VIRUS_SIGNATURE "I am a virus"
#define MAX_FILE_NAME_LENGTH 256

/* Function declarations */
void scan_directory(const char *dir_path);
int is_infected(char *file_path);

/* Main program */
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [directory path]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *dir_path = argv[1];
    printf("Scanning directory: %s\n\n", dir_path);

    scan_directory(dir_path);

    printf("Scan completed successfully.\n");

    return EXIT_SUCCESS;
}

/* Function definitions */

/* Recursively scan a directory and its subdirectories */
void scan_directory(const char *dir_path) {
    DIR *dir = opendir(dir_path);
    if (dir == NULL) {
        fprintf(stderr, "Error: Unable to open directory %s\n", dir_path);
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        char file_path[MAX_FILE_NAME_LENGTH];
        snprintf(file_path, sizeof(file_path), "%s/%s", dir_path, entry->d_name);

        if (entry->d_type == DT_DIR) {
            /* Skip "." and ".." directories */
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            scan_directory(file_path);
        } else if (entry->d_type == DT_REG) {
            if (is_infected(file_path)) {
                printf("Virus detected in file: %s\n", file_path);
            }
        }
    }

    closedir(dir);
}

/* Check if a file is infected with the virus signature */
int is_infected(char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        return 0; /* Unable to open file, assume it is not infected */
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file)) {
        if (strstr(buffer, VIRUS_SIGNATURE) != NULL) {
            fclose(file);
            return 1; /* Virus signature found, file is infected */
        }
    }

    fclose(file);
    return 0; /* Virus signature not found, file is not infected */
}