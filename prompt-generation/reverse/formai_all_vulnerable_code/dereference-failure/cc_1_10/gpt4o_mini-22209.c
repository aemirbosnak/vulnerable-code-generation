//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define BUFFER_SIZE 256
#define SIGNATURE_COUNT 5

// Structure to represent a suspicious signature
typedef struct {
    char *name;
    char *signature;
} Signature;

// The family's dreaded signatures - the scourge of our digital age!
Signature known_signatures[SIGNATURE_COUNT] = {
    {"Trojan.Generic", "ABCD1234"}, // Example signatures
    {"Worm.SelfReplicator", "EFGH5678"},
    {"Malware.Adware", "IJKL9012"},
    {"Rootkit.Hidden", "MNOP3456"},
    {"Spyware.Keylogger", "QRST7890"}
};

// Function to check if a file contains any known signatures
int contains_signature(FILE *file) {
    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (int i = 0; i < SIGNATURE_COUNT; i++) {
            if (strstr(buffer, known_signatures[i].signature) != NULL) {
                printf("Found %s in the file!\n", known_signatures[i].name);
                return 1;
            }
        }
    }
    return 0;
}

// Recursive function to scan directories for files
void scan_directory(const char *directory) {
    DIR *dir;
    struct dirent *entry;

    if (!(dir = opendir(directory))) {
        perror("Unable to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char path[BUFFER_SIZE];
            snprintf(path, sizeof(path), "%s/%s", directory, entry->d_name);

            struct stat entry_info;
            if (stat(path, &entry_info) == 0) {
                if (S_ISDIR(entry_info.st_mode)) {
                    // If it's a directory, scan it recursively
                    scan_directory(path);
                } else {
                    // It's a file, let's examine it
                    printf("Scanning file: %s...\n", path);
                    FILE *file = fopen(path, "rb");
                    if (file) {
                        if (contains_signature(file)) {
                            printf("Suspicious file detected: %s\n", path);
                        }
                        fclose(file);
                    } else {
                        perror("Unable to open file");
                    }
                }
            }
        }
    }
    closedir(dir);
}

// Main function to start the investigation
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    printf("Elementary, my dear Watson. We shall commence the investigation of suspicious files in: %s\n", argv[1]);
    scan_directory(argv[1]);
    printf("Investigation complete.\n");

    return 0;
}