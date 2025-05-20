//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

// Let's define some magical patterns to search for
#define MALWARE_SIGNATURE "virus123"
#define BUFFER_SIZE 1024

// Behold the function that opens the treasure chest (directory)
void scan_directory(const char *path);

// The grand decoder for checking files
int check_file_for_malware(const char *filename);

// The dazzling display of results
void display_result(const char *filename, int is_malicious);

int main() {
    // Welcome to the quest!
    printf("Welcome to the C Antivirus Scanner!\n");
    char path[BUFFER_SIZE];

    // "Which directory shall we explore?"
    printf("Enter the directory to scan (leave blank for current): ");
    if (fgets(path, sizeof(path), stdin) != NULL) {
        path[strcspn(path, "\n")] = 0; // Remove the newline
    }
    if (strlen(path) == 0) {
        strcpy(path, "."); // Default to current directory if input is empty
    }

    // "Arise and commence the scanning!"
    scan_directory(path);

    printf("Scanning finished!\n");
    return 0;
}

// Function to scan files in a directory
void scan_directory(const char *path) {
    DIR *dir;
    struct dirent *entry;

    // Attempt to open the mystical door (directory)
    if ((dir = opendir(path)) == NULL) {
        perror("Could not open directory");
        return;
    }

    // Loop through the entries inside this treasure trove
    while ((entry = readdir(dir)) != NULL) {
        // Skip the hidden treasures
        if (entry->d_name[0] == '.') {
            continue;
        }
        // Construct the full path to the file
        char filepath[BUFFER_SIZE];
        snprintf(filepath, sizeof(filepath), "%s/%s", path, entry->d_name);

        // "Inspecting the contents of: %s\n" - The adventure begins!
        if (check_file_for_malware(filepath)) {
            display_result(filepath, 1); // Mark as malicious
        } else {
            display_result(filepath, 0); // Mark as clean
        }
    }

    // Close the enchanted portal once we're done
    closedir(dir);
}

// Function to check individual files for malware signatures
int check_file_for_malware(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return 0; // Return as not malicious if file can't be read
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), file)) {
        // Scan for the dark signature of malware
        if (strstr(buffer, MALWARE_SIGNATURE) != NULL) {
            fclose(file);
            return 1; // Found malware
        }
    }

    fclose(file);
    return 0; // No malware found
}

// The grand display of results
void display_result(const char *filename, int is_malicious) {
    // "Unveil the truth!"
    if (is_malicious) {
        printf("[!] Malware detected in: %s\n", filename);
    } else {
        printf("[+] No threats found in: %s\n", filename);
    }
}