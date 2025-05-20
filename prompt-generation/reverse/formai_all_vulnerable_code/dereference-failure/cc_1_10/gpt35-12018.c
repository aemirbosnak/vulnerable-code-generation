//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int check_file(char *filename) {
    int virus_detected = 0;
    char buffer[1024];
    // Open the file
    FILE *file = fopen(filename, "r");
    // Check if file is open
    if (file == NULL) {
        printf("%s: Access Denied.\n", filename);
        return virus_detected;
    }
    // Check the file for viruses
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (strstr(buffer, "virus") != NULL) {
            virus_detected = 1;
            break;
        }
    }
    // Close the file
    fclose(file);
    return virus_detected;
}

void scan_folder(char *path) {
    DIR *directory;
    struct dirent *entry;
    // Check if path directory exists
    if ((directory = opendir(path)) != NULL) {
        while ((entry = readdir(directory)) != NULL) {
            // Ignore folders '.' and '..'
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                char full_path[1024];
                sprintf(full_path, "%s/%s", path, entry->d_name);
                // Check if entry is directory
                if (entry->d_type == DT_DIR) {
                    scan_folder(full_path);
                }
                else if (entry->d_type == DT_REG) {
                    if (check_file(full_path) == 1) {
                        printf("%s: Virus Detected!\n", full_path);
                    }
                }
            }
        }
        closedir(directory);
    }
    else {
        printf("%s: Access Denied.\n", path);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }
    scan_folder(argv[1]);
    return 0;
}