//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_SIGNATURES 10
#define MAX_STRING_SIZE 256

const char *known_viruses[MAX_SIGNATURES] = {
    "EICAR-STANDARD-ANTIVIRUS-TEST-FILE",
    "SOME_VIRUS_SIGNATURE_1",
    "SOME_VIRUS_SIGNATURE_2",
    "MALWARE_SIG_1",
    "MALWARE_SIG_2",
    "TROJAN_SIG_1",
    "WORM_SIG_1",
    "RANSOMWARE_SIG_1",
    "SPYWARE_SIG_1",
    "ADWARE_SIG_1"
};

void scan_file(const char *file_path);
void search_directory(const char *directory_path);
bool contains_virus_signature(const char *file_contents);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *directory_to_scan = argv[1];
    search_directory(directory_to_scan);
    
    return EXIT_SUCCESS;
}

void search_directory(const char *directory_path) {
    struct dirent *entry;
    DIR *directory = opendir(directory_path);

    if (directory == NULL) {
        perror("Failed to open directory");
        return;
    }

    while ((entry = readdir(directory)) != NULL) {
        if (entry->d_name[0] == '.') {
            // Skip hidden files/folders
            continue;
        }

        char full_path[MAX_STRING_SIZE];
        snprintf(full_path, sizeof(full_path), "%s/%s", directory_path, entry->d_name);

        struct stat statbuf;
        if (stat(full_path, &statbuf) == -1) {
            perror("Could not access file");
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            // Recursively search directories
            search_directory(full_path);
        } else {
            // Scan the file for viruses
            scan_file(full_path);
        }
    }

    closedir(directory);
}

void scan_file(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        perror("Could not open file");
        return;
    }

    char file_contents[MAX_STRING_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(file_contents, sizeof(char), sizeof(file_contents) - 1, file)) > 0) {
        file_contents[bytes_read] = '\0';  // Null-terminate the string

        if (contains_virus_signature(file_contents)) {
            printf("Virus detected! File: %s\n", file_path);
            fclose(file);
            remove(file_path);  // Remove the infected file
            printf("Removed infected file: %s\n", file_path);
            return;
        }
    }

    fclose(file);
}

bool contains_virus_signature(const char *file_contents) {
    for (int i = 0; i < MAX_SIGNATURES; i++) {
        if (strstr(file_contents, known_viruses[i]) != NULL) {
            return true;  // Virus signature found
        }
    }
    return false;  // No virus signatures found
}