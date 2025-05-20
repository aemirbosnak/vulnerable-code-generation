//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024
#define MAX_VIRUS_SIGNATURES 10
#define MAX_SIGNATURE_LENGTH 50

typedef struct {
    char signature[MAX_SIGNATURE_LENGTH];
} VirusSignature;

VirusSignature virusSignatures[MAX_VIRUS_SIGNATURES] = {
    {"MalwareSig1"},
    {"VirusSigA"},
    {"TrojanSigZ"},
    {"SpywareSigX"},
    {"WormSigQ"},
    {"RansomwareSigC"},
    {"RootkitSigD"},
    {"AdwareSigK"},
    {"BotnetSigR"},
    {"PhishingSigL"}
};

void scanFile(const char* filepath) {
    FILE* file = fopen(filepath, "rb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char* buffer;
    size_t size;
    size_t readSize;

    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    buffer = (char*)malloc(size);
    if (buffer == NULL) {
        perror("Memory allocation error");
        fclose(file);
        return;
    }

    readSize = fread(buffer, 1, size, file);
    if (readSize != size) {
        perror("Error reading file");
        free(buffer);
        fclose(file);
        return;
    }
    fclose(file);

    for (int i = 0; i < MAX_VIRUS_SIGNATURES; ++i) {
        if (strstr(buffer, virusSignatures[i].signature) != NULL) {
            printf("Virus found in %s: %s\n", filepath, virusSignatures[i].signature);
            free(buffer);
            return;
        }
    }

    free(buffer);
    printf("No virus found in %s.\n", filepath);
}

void scanDirectory(const char* dirpath) {
    struct dirent* entry;
    DIR* dir = opendir(dirpath);

    if (!dir) {
        perror("Error opening directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char filepath[MAX_PATH_LENGTH];
            snprintf(filepath, sizeof(filepath), "%s/%s", dirpath, entry->d_name);

            struct stat statbuf;
            if (stat(filepath, &statbuf) == -1) {
                perror("Error getting file status");
                continue;
            }

            if (S_ISDIR(statbuf.st_mode)) {
                // It's a directory; recurse into it
                scanDirectory(filepath);
            } else {
                // It's a file; scan it
                scanFile(filepath);
            }
        }
    }

    closedir(dir);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Scanning directory: %s\n", argv[1]);
    scanDirectory(argv[1]);

    printf("Scan completed.\n");
    return EXIT_SUCCESS;
}