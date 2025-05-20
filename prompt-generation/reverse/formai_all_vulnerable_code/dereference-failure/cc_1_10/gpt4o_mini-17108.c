//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define BUFFER_SIZE 256
#define MAX_FILE_NAME 256
#define KEYWORDS_COUNT 5

const char *keywords[KEYWORDS_COUNT] = {
    "virus",
    "malware",
    "trojan",
    "worm",
    "ransomware"
};

void checkFile(const char *filePath) {
    FILE *file = fopen(filePath, "r");
    char buffer[BUFFER_SIZE];
    int found = 0;

    if (file == NULL) {
        perror("Couldn't open file");
        return;
    }

    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        for (int i = 0; i < KEYWORDS_COUNT; i++) {
            if (strstr(buffer, keywords[i]) != NULL) {
                printf("Warning! Found keyword '%s' in file: %s\n", keywords[i], filePath);
                found = 1;
                break;
            }
        }
        if (found) break;
    }

    fclose(file);

    if (!found) {
        printf("No threats found in file: %s\n", filePath);
    }
}

void scanDirectory(const char *dirPath) {
    struct dirent *entry;
    struct stat statBuf;
    DIR *dir = opendir(dirPath);

    if (dir == NULL) {
        perror("Couldn't open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char fullPath[MAX_FILE_NAME];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", dirPath, entry->d_name);
        stat(fullPath, &statBuf);

        if (S_ISDIR(statBuf.st_mode)) {
            printf("Entering directory: %s\n", fullPath);
            scanDirectory(fullPath);  // Recur for directories
        } else {
            printf("Scanning file: %s\n", fullPath);
            checkFile(fullPath);  // Check the file for threats
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Initializing antivirus scanner...\n");
    printf("Scanning directory: %s\n", argv[1]);
    
    scanDirectory(argv[1]);

    printf("Scanning completed. Stay safe!\n");
    return EXIT_SUCCESS;
}