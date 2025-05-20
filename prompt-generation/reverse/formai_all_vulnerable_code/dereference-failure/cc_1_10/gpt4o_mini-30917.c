//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_SIG_LEN 256
#define MAX_PATH_LEN 512
#define MAX_FILES 1024
#define MAX_SIGS 20

typedef struct {
    char *name;
    char *signature;
} VirusSignature;

void loadVirusSignatures(VirusSignature *signatures, int *count) {
    // Just for demonstration, let's use some fake virus signatures
    signatures[0].name = "FakeVirus1";
    signatures[0].signature = "VIRUS1_SIG";

    signatures[1].name = "FakeVirus2";
    signatures[1].signature = "VIRUS2_SIG";

    *count = 2; // Total signatures available
}

int containsSignature(const char *fileData, VirusSignature *signatures, int sigCount) {
    for (int i = 0; i < sigCount; i++) {
        if (strstr(fileData, signatures[i].signature) != NULL) {
            printf("Found virus: %s in %s\n", signatures[i].name, fileData);
            return 1; // Signature found
        }
    }
    return 0; // No signature found
}

void scanFile(const char *filePath, VirusSignature *signatures, int sigCount) {
    FILE *file = fopen(filePath, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    char *fileData = malloc(fileSize + 1);
    if (fileData == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        return;
    }

    fread(fileData, 1, fileSize, file);
    fileData[fileSize] = '\0'; // Null-terminate the string

    if (containsSignature(fileData, signatures, sigCount)) {
        printf("Virus detected in %s\n", filePath);
    } else {
        printf("No virus detected in %s\n", filePath);
    }

    free(fileData);
    fclose(file);
}

void scanDirectory(const char *dirPath, VirusSignature *signatures, int sigCount) {
    DIR *dir = opendir(dirPath);
    struct dirent *entry;
    char fullPath[MAX_PATH_LEN];

    if (dir == NULL) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            // Skip the current and parent directory
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                snprintf(fullPath, sizeof(fullPath), "%s/%s", dirPath, entry->d_name);
                scanDirectory(fullPath, signatures, sigCount); // Recursively scan subdirectories
            }
        } else {
            snprintf(fullPath, sizeof(fullPath), "%s/%s", dirPath, entry->d_name);
            scanFile(fullPath, signatures, sigCount); // Scan the file
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    VirusSignature signatures[MAX_SIGS];
    int sigCount = 0;
    loadVirusSignatures(signatures, &sigCount);

    scanDirectory(argv[1], signatures, sigCount);

    return EXIT_SUCCESS;
}