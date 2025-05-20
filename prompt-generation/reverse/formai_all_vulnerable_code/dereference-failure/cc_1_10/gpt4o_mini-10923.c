//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_FILES 1000

// Function Prototypes
void scanDirectory(const char *dirPath);
int scanFile(const char *filePath);
void logInfectedFiles(const char *fileName);
void printUsage(const char *progName);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printUsage(argv[0]);
        return EXIT_FAILURE;
    }
    scanDirectory(argv[1]);
    return EXIT_SUCCESS;
}

void printUsage(const char *progName) {
    printf("Usage: %s <directory_path>\n", progName);
    printf("This program scans the specified directory for potential viruses.\n");
}

// Scan a directory for files
void scanDirectory(const char *dirPath) {
    struct dirent *entry;
    struct stat fileStat;
    char filePath[MAX_FILENAME_LENGTH];
    DIR *dir = opendir(dirPath);

    if (dir == NULL) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(filePath, sizeof(filePath), "%s/%s", dirPath, entry->d_name);
        if (stat(filePath, &fileStat) != 0) {
            perror("Could not retrieve file status");
            continue;
        }

        // Check if it's a directory
        if (S_ISDIR(fileStat.st_mode)) {
            scanDirectory(filePath); // Recursive call
        } else {
            // Scan the individual file
            if (scanFile(filePath)) {
                logInfectedFiles(filePath);
            }
        }
    }
    closedir(dir);
}

// Scan a file for known "virus patterns"
int scanFile(const char *filePath) {
    FILE *file = fopen(filePath, "rb");
    if (file == NULL) {
        perror("Could not open file");
        return 0;
    }

    char buffer[512];
    size_t bytesRead;
    char *virusPatterns[] = {
        "VirusPattern1",
        "VirusPattern2",
        "MalwareSignature",
        NULL
    };

    // Scan the file content
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (char **pattern = virusPatterns; *pattern != NULL; pattern++) {
            if (memmem(buffer, bytesRead, *pattern, strlen(*pattern)) != NULL) {
                fclose(file);
                return 1; // Virus found
            }
        }
    }

    fclose(file);
    return 0; // No virus found
}

// Log infected files to a log file
void logInfectedFiles(const char *fileName) {
    FILE *logFile = fopen("infected_log.txt", "a");
    if (logFile == NULL) {
        perror("Could not open log file");
        return;
    }
    
    fprintf(logFile, "Infected File Detected: %s\n", fileName);
    fclose(logFile);
}

// Example of an entry point
void exampleEntryPoint() {
    // Could contain the main virus scanning operations
    printf("Antivirus scanner initialized...\n");
}