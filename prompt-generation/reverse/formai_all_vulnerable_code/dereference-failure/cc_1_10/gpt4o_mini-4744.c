//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_SIGNATURES 10
#define MAX_FILENAME 256
#define MAX_SIGNATURE_LENGTH 64

typedef struct {
    char signature[MAX_SIGNATURE_LENGTH];
} VirusSignature;

VirusSignature signatures[MAX_SIGNATURES] = {
    {"EICAR-STANDARD-ANTIVIRUS-TEST-FILE!"},
    {"VIRUS-SIGNATURE-1"},
    {"VIRUS-SIGNATURE-2"},
    {"VIRUS-SIGNATURE-3"},
    {"VIRUS-SIGNATURE-4"},
    {"VIRUS-SIGNATURE-5"},
    {"VIRUS-SIGNATURE-6"},
    {"VIRUS-SIGNATURE-7"},
    {"VIRUS-SIGNATURE-8"},
    {"VIRUS-SIGNATURE-9"},
};

void scan_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char *buffer = malloc(1024);
    size_t bytesRead;
    int found = 0;

    while ((bytesRead = fread(buffer, 1, 1024, file)) > 0) {
        for (int i = 0; i < MAX_SIGNATURES; i++) {
            if (strstr(buffer, signatures[i].signature) != NULL) {
                printf("Virus found in file %s: %s\n", filename, signatures[i].signature);
                found = 1;
                break;
            }
        }
        if (found) break;
    }

    free(buffer);
    fclose(file);
}

void scan_directory(const char *dirpath) {
    struct dirent *entry;
    DIR *dp = opendir(dirpath);
    if (dp == NULL) {
        perror("Error opening directory");
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) { // If it's a regular file
            char filepath[MAX_FILENAME];
            snprintf(filepath, sizeof(filepath), "%s/%s", dirpath, entry->d_name);
            scan_file(filepath);
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    scan_directory(argv[1]);
    printf("Scanning completed.\n");
    return EXIT_SUCCESS;
}