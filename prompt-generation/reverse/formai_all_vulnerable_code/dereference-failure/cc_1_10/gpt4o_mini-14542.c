//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH_LENGTH 1024
#define SIGNATURE_FILE "signatures.txt"

void listFilesRecursively(const char *basePath);
void checkFileForVirus(const char *filePath);
int isVirusDetected(const char *filePath);
void logDetectedVirus(const char *filePath);
void scanDirectory(const char *path);

int main() {
    printf("Welcome to the Mind-Bending C Antivirus Scanner!\n");
    char path[MAX_PATH_LENGTH];

    printf("Enter the directory path to scan (e.g., /home/user): ");
    scanf("%s", path);

    scanDirectory(path);
    printf("Scanning completed. Have a secure day!\n");

    return 0;
}

// Scans the specified directory for files and directories recursively
void scanDirectory(const char *path) {
    listFilesRecursively(path);
}

// Lists files recursively
void listFilesRecursively(const char *basePath) {
    struct dirent *dp;
    DIR *dir = opendir(basePath);

    if (dir == NULL) {
        perror("Unable to open directory");
        return;
    }

    while ((dp = readdir(dir)) != NULL) {
        char path[MAX_PATH_LENGTH];
        // Skip the '.' and '..' directories
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0) {
            snprintf(path, sizeof(path), "%s/%s", basePath, dp->d_name);
            struct stat pathStat;
            stat(path, &pathStat);

            if (S_ISDIR(pathStat.st_mode)) {
                // Recursive call for directories
                scanDirectory(path);
            } else {
                // Check file for viruses
                checkFileForVirus(path);
            }
        }
    }
    closedir(dir);
}

// Check the given file for potential viruses
void checkFileForVirus(const char *filePath) {
    if (isVirusDetected(filePath)) {
        logDetectedVirus(filePath);
    }
}

// Check if the file contains a virus signature
int isVirusDetected(const char *filePath) {
    FILE *sigFile = fopen(SIGNATURE_FILE, "r");
    if (sigFile == NULL) {
        perror("Unable to open signature file");
        return 0;
    }

    char signature[256];
    while (fgets(signature, sizeof(signature), sigFile) != NULL) {
        // Remove newline characters from signature
        signature[strcspn(signature, "\n")] = 0;

        // Check for the signature in the file
        FILE *file = fopen(filePath, "r");
        if (file != NULL) {
            char line[256];
            while (fgets(line, sizeof(line), file) != NULL) {
                if (strstr(line, signature) != NULL) {
                    fclose(file);
                    fclose(sigFile);
                    return 1; // Virus found
                }
            }
            fclose(file);
        }
    }
    
    fclose(sigFile);
    return 0; // No virus found
}

// Log the detected virus to a log file
void logDetectedVirus(const char *filePath) {
    FILE *logFile = fopen("virus_log.txt", "a");
    if (logFile == NULL) {
        perror("Unable to open log file");
        return;
    }

    fprintf(logFile, "Virus detected in: %s\n", filePath);
    fclose(logFile);

    printf("ALERT! Virus detected at: %s\n", filePath);
}