//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define MAX_VIRUS_SIGN 10

// Sample virus signatures (in a real-world scenario, these would be hashes or patterns)
const char *virus_signatures[MAX_VIRUS_SIGN] = {
    "virus_signature_1",
    "malware_signature_2",
    "trojan_signature_3",
    "worm_signature_4",
    "ransomware_signature_5",
    "spyware_signature_6",
    "rootkit_signature_7",
    "adware_signature_8",
    "keylogger_signature_9",
    "backdoor_signature_10"
};

// Function to scan a file for virus signatures
bool scan_file(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (!file) {
        perror("Error opening file");
        return false;
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        for (int i = 0; i < MAX_VIRUS_SIGN; i++) {
            if (strstr(buffer, virus_signatures[i]) != NULL) {
                fclose(file);
                return true; // Virus signature found
            }
        }
    }

    fclose(file);
    return false; // No virus signature found
}

// Function to recursively scan a directory
void scan_directory(const char *dir_path) {
    struct dirent *entry;
    struct stat file_stat;
    char file_path[1024];
    DIR *dir = opendir(dir_path);

    if (!dir) {
        perror("Error opening directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Ignore '.' and '..'
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(file_path, sizeof(file_path), "%s/%s", dir_path, entry->d_name);
        if (stat(file_path, &file_stat) == -1) {
            perror("Error stating file");
            continue;
        }

        // If it's a directory, recurse into it
        if (S_ISDIR(file_stat.st_mode)) {
            scan_directory(file_path);
        } else if (S_ISREG(file_stat.st_mode)) {
            if (scan_file(file_path)) {
                printf("Virus found in file: %s\n", file_path);
            }
        }
    }

    closedir(dir);
}

// Function to display help message
void display_help() {
    printf("Simple C Antivirus Scanner\n");
    printf("Usage: ./antivirus_scanner <directory_path>\n");
    printf("This program scans files in the specified directory for known virus signatures.\n");
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        display_help();
        return 1;
    }

    const char *scan_path = argv[1];
    struct stat path_stat;

    if (stat(scan_path, &path_stat) == -1) {
        perror("Error stating path");
        return 1;
    }

    if (S_ISDIR(path_stat.st_mode)) {
        printf("Scanning directory: %s\n", scan_path);
        scan_directory(scan_path);
    } else if (S_ISREG(path_stat.st_mode)) {
        printf("Scanning file: %s\n", scan_path);
        if (scan_file(scan_path)) {
            printf("Virus found in file: %s\n", scan_path);
        } else {
            printf("No virus found in file: %s\n", scan_path);
        }
    } else {
        printf("Provided path is neither a file nor a directory.\n");
        return 1;
    }

    printf("Scanning completed.\n");
    return 0;
}