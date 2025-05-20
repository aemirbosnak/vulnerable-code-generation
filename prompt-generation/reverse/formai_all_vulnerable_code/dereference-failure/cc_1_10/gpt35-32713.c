//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void scan_file(char *filename);
void scan_directory(char *dirname);

char *virus_signature[] = {"virus1", "virus2", "virus3"};

int main() {
    char *file = "test_file.txt";
    char *dir = "test_directory";

    printf("Welcome to C Antivirus Scanner!\n");
    printf("Scanning file: %s\n", file);
    scan_file(file);

    printf("\nScanning directory: %s\n", dir);
    scan_directory(dir);

    printf("Scan complete. No viruses found.\n");

    return 0;
}

void scan_file(char *filename) {
    FILE *file = fopen(filename, "r");
    char line[100];

    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return;
    }

    // Loop through each line in the file
    while (fgets(line, sizeof(line), file)) {
        // Loop through the virus signatures and check for matches
        for (int i = 0; i < sizeof(virus_signature)/sizeof(virus_signature[0]); i++) {
            if (strstr(line, virus_signature[i])) {
                printf("Virus found! Signature: %s in file: %s\n", virus_signature[i], filename);
                return;
            }
        }
    }

    fclose(file);
}

void scan_directory(char *dirname) {
    DIR *dir;
    struct dirent *entry;

    // Open the directory and loop through each entry
    if ((dir = opendir(dirname))) {
        while ((entry = readdir(dir))) {
            // Only scan regular files (not directories)
            if (entry->d_type == DT_REG) {
                char *filename = entry->d_name;
                char filepath[100];
                sprintf(filepath, "%s/%s", dirname, filename);
                scan_file(filepath);
            }
        }
        closedir(dir);
    }
}