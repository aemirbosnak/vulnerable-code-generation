//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define SIGNATURE_COUNT 5
#define MAX_PATH_LENGTH 1024

typedef struct {
    const char *name;
    const char *signature;
} VirusSignature;

// Sample virus signatures for demonstration purposes
VirusSignature signatures[SIGNATURE_COUNT] = {
    {"Virus1", "DEADBEEF"},
    {"Virus2", "CAFEBABE"},
    {"Trojan1", "FEEDFACE"},
    {"Worm1", "ABADCAFE"},
    {"Spyware1", "BA5BAD00"}
};

void printLogo() {
    printf("#############################################\n");
    printf("#           C Antivirus Scanner            #\n");
    printf("#               Version 1.0                #\n");
    printf("#############################################\n");
}

void scanFile(const char *filePath) {
    FILE *file = fopen(filePath, "rb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    unsigned char *buffer = (unsigned char *)malloc(fileSize);
    if (!buffer) {
        perror("Error allocating memory");
        fclose(file);
        return;
    }
    
    fread(buffer, 1, fileSize, file);
    fclose(file);
    
    for (int i = 0; i < SIGNATURE_COUNT; i++) {
        if (memmem(buffer, fileSize, signatures[i].signature, strlen(signatures[i].signature))) {
            printf("Alert: Potential %s detected in %s\n", signatures[i].name, filePath);
        }
    }
    
    free(buffer);
}

void scanDirectory(const char *directoryPath) {
    struct dirent *entry;
    struct stat statbuf;
    DIR *dp = opendir(directoryPath);
    if (dp == NULL) {
        perror("Error opening directory");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char fullPath[MAX_PATH_LENGTH];
            snprintf(fullPath, sizeof(fullPath), "%s/%s", directoryPath, entry->d_name);
            
            if (stat(fullPath, &statbuf) == -1) {
                perror("Error obtaining file stats");
                continue;
            }

            if (S_ISDIR(statbuf.st_mode)) {
                scanDirectory(fullPath);
            } else if (S_ISREG(statbuf.st_mode)) {
                scanFile(fullPath);
            }
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    printLogo();
    
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Scanning directory: %s\n", argv[1]);
    scanDirectory(argv[1]);
    printf("Scan completed.\n");

    return EXIT_SUCCESS;
}