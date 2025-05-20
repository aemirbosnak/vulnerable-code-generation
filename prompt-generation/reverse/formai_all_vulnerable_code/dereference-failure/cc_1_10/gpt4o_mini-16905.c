//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024
#define SIGNATURES_FILE "signatures.txt"
#define BUFFER_SIZE 4096

typedef struct {
    char filePath[MAX_PATH_LENGTH];
    unsigned long size;
} FileInfo;

void loadSignatures(char ***signatures, int *count) {
    FILE *file = fopen(SIGNATURES_FILE, "r");
    if (file == NULL) {
        perror("Error opening signatures file");
        exit(EXIT_FAILURE);
    }

    *count = 0;
    *signatures = malloc(BUFFER_SIZE * sizeof(char *));
    if (*signatures == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    char line[MAX_PATH_LENGTH];
    while (fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\n")] = 0; // Remove newline character
        (*signatures)[*count] = malloc((strlen(line) + 1) * sizeof(char));
        strcpy((*signatures)[*count], line);
        (*count)++;
    }

    fclose(file);
}

void freeSignatures(char **signatures, int count) {
    for (int i = 0; i < count; i++) {
        free(signatures[i]);
    }
    free(signatures);
}

int checkFileForSignatures(const char *filePath, char **signatures, int count) {
    FILE *file = fopen(filePath, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return -1; // Error
    }

    unsigned char buffer[BUFFER_SIZE];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (int i = 0; i < count; i++) {
            if (strstr((char *)buffer, signatures[i]) != NULL) {
                fclose(file);
                return 1; // Found a signature
            }
        }
    }

    fclose(file);
    return 0; // No signature found
}

void scanDirectory(const char *dirPath, char **signatures, int count) {
    struct dirent *entry;
    DIR *dp = opendir(dirPath);

    if (dp == NULL) {
        perror("Error opening directory");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char filePath[MAX_PATH_LENGTH];
            snprintf(filePath, sizeof(filePath), "%s/%s", dirPath, entry->d_name);

            struct stat statbuf;
            if (stat(filePath, &statbuf) == -1) {
                perror("Error getting file status");
                continue;
            }

            if (S_ISDIR(statbuf.st_mode)) {
                scanDirectory(filePath, signatures, count); // Recursive call for directories
            } else {
                int result = checkFileForSignatures(filePath, signatures, count);
                if (result == 1) {
                    printf("Malicious file detected: %s\n", filePath);
                }
            }
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char **signatures;
    int signatureCount;

    // Load virus signatures
    loadSignatures(&signatures, &signatureCount);

    // Scan the specified directory
    scanDirectory(argv[1], signatures, signatureCount);

    // Free allocated memory
    freeSignatures(signatures, signatureCount);

    return EXIT_SUCCESS;
}