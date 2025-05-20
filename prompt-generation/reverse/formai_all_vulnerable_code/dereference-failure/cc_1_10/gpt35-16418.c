//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH_LENGTH 1000
#define MAX_FILE_NAME_LENGTH 256

int isExecutable(char *path) {
    struct stat fileStat;
    if (stat(path, &fileStat) < 0)
        return 0;
    if (S_ISREG(fileStat.st_mode) && (fileStat.st_mode & S_IXUSR))
        return 1;
    return 0;
}

void scanDirectory(char *directoryPath) {
    DIR *directory;
    struct dirent *entry;
    char filePath[MAX_PATH_LENGTH];
    directory = opendir(directoryPath);
    if (directory == NULL) {
        perror("Unable to open directory");
        printf("Please check if %s exists and is accessible.\n", directoryPath);
        return;
    }
    while ((entry = readdir(directory)) != NULL) {
        if (entry->d_type == DT_DIR) { // scanning subdirectory
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue; // ignore current and parent directory links
            sprintf(filePath, "%s/%s", directoryPath, entry->d_name);
            scanDirectory(filePath); // recursively scan subdirectory
        } else {
            sprintf(filePath, "%s/%s", directoryPath, entry->d_name);
            if (isExecutable(filePath)) {
                FILE *file = fopen(filePath, "rb");
                if (file) {
                    char buffer[10];
                    fread(buffer, sizeof(char), 10, file); // checking first 10 bytes
                    if (memcmp(buffer, "C Antivirus", 10) == 0) { // malware found
                        printf("Malware detected: %s\n", filePath);
                    }
                    fclose(file);
                }
            }
        }
    }
    closedir(directory);
}

int main() {
    printf("C Antivirus is scanning your system...\n");
    scanDirectory(".");
    printf("Scanning complete!\n");
    return 0;
}