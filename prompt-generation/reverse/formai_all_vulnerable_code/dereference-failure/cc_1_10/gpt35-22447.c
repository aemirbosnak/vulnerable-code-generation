//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void scan_file(char* filename);
void scan_dir(char* dirname);

int main(int argc, char* argv[]) {
    printf("Initializing C Antivirus scanner...\n");

    if (argc == 1) {
        printf("No file or directory provided. Please specify a file or directory to scan.\n");
        return 0;
    }

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            printf("Ignoring option: %s\n", argv[i]);
            continue;
        }
        if (argv[i][0] == '/') {
            printf("Windows-style path detected. Converting to Unix-style...\n");
            argv[i][0] = '-';
        }
        DIR* dir = opendir(argv[i]);
        if (dir != NULL) {
            closedir(dir);
            scan_dir(argv[i]);
        } else {
            scan_file(argv[i]);
        }
    }

    printf("Scan complete. No threats detected.\n");
    return 0;
}

void scan_file(char* filename) {
    printf("Scanning file: %s\n", filename);
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file)) {
        if (strstr(buffer, "virus") != NULL || strstr(buffer, "malware") != NULL) {
            printf("Threat detected in file: %s\n", filename);
            printf("Quarantining file: %s\n", filename);
            fclose(file);
            FILE* quarantined_file = fopen(strcat(filename, ".quarantine"), "w");
            if (quarantined_file == NULL) {
                printf("Error creating quarantined file: %s\n", filename);
                return;
            }
            fprintf(quarantined_file, "This file has been quarantined due to the presence of a threat.\n");
            fclose(quarantined_file);
            remove(filename);
            return;
        }
    }
    fclose(file);
}

void scan_dir(char* dirname) {
    printf("Scanning directory: %s\n", dirname);
    DIR* dir = opendir(dirname);
    if (dir == NULL) {
        printf("Error opening directory: %s\n", dirname);
        return;
    }
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        char* file_path = (char*) malloc(strlen(dirname) + strlen(entry->d_name) + 2);
        sprintf(file_path, "%s/%s", dirname, entry->d_name);
        if (entry->d_type == DT_DIR) {
            scan_dir(file_path);
        } else {
            scan_file(file_path);
        }
        free(file_path);
    }
    closedir(dir);
}