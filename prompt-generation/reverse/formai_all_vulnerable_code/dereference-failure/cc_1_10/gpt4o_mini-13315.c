//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_PATH 256
#define MAX_FILES 100
#define SIGNATURE_COUNT 4

const char *malicious_signatures[SIGNATURE_COUNT] = {
    "malware_signature_1",
    "malware_signature_2",
    "virus_signature_3",
    "trojan_signature_4"
};

void scan_file(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        printf("Could not open file: %s\n", file_path);
        return;
    }

    char buffer[1024];
    int found = 0;
    
    while (fgets(buffer, sizeof(buffer), file)) {
        for (int i = 0; i < SIGNATURE_COUNT; i++) {
            if (strstr(buffer, malicious_signatures[i]) != NULL) {
                printf("Warning! Malware signature '%s' found in: %s\n", malicious_signatures[i], file_path);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("No threats found in: %s\n", file_path);
    }
    
    fclose(file);
}

void scan_directory(const char *dir_path) {
    struct dirent *entry;
    DIR *dir = opendir(dir_path);
    
    if (dir == NULL) {
        printf("Could not open directory: %s\n", dir_path);
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Regular file
            char file_path[MAX_PATH];
            snprintf(file_path, sizeof(file_path), "%s/%s", dir_path, entry->d_name);
            scan_file(file_path);
        }
    }

    closedir(dir);
}

void display_welcome_message() {
    printf("========================================\n");
    printf("          Welcome to C Antivirus       \n");
    printf("     Scanning for potential threats... \n");
    printf("========================================\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *directory = argv[1];

    display_welcome_message();
    scan_directory(directory);

    printf("Scanning completed. Stay safe!\n");

    return EXIT_SUCCESS;
}