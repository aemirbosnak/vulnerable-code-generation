//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024
#define MAX_SIGNATURES 10
#define SIGNATURE_LENGTH 32

// Signature structure
typedef struct {
    char name[SIGNATURE_LENGTH];
    char signature[SIGNATURE_LENGTH];
} VirusSignature;

// List of known virus signatures
VirusSignature signatures[MAX_SIGNATURES] = {
    {"EICAR", "X5O!P%%-"},  // Sample signature representing a known virus
    {"VirusB", "ABCD1234"},
    {"TrojanC", "WXYZ5678"},
    {"WormD", "PQRS9012"},
    {"MalwareE", "LMNOP3456"},
    {"RansomF", "RSTUV7890"},
    {"SpyG", "QWERTY1234"},
    {"AdwareH", "YUIOP5678"},
    {"RootkitI", "ZXCVB1234"},
    {"KeyloggerJ", "ASDFG1234"}
};

// Function to check if a file matches any virus signatures
int is_infected(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Unable to open file");
        return 0;
    }

    char buffer[SIGNATURE_LENGTH];
    fread(buffer, sizeof(char), SIGNATURE_LENGTH, file);
    fclose(file);

    for (int i = 0; i < MAX_SIGNATURES; i++) {
        if (strncmp(buffer, signatures[i].signature, SIGNATURE_LENGTH) == 0) {
            printf("Virus found: %s in file: %s\n", signatures[i].name, filename);
            return 1;
        }
    }
    return 0;
}

// Function to recursively scan a directory
void scan_directory(const char *path) {
    struct dirent *entry;
    struct stat statbuf;
    DIR *dp = opendir(path);

    if (dp == NULL) {
        perror("Unable to open directory");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        char fullpath[MAX_PATH];
        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);

        // Ignore the current and parent directory entries
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            if (stat(fullpath, &statbuf) == -1) {
                perror("Unable to get file status");
                continue;
            }

            if (S_ISDIR(statbuf.st_mode)) {
                scan_directory(fullpath);  // Recur for directories
            } else {
                if (is_infected(fullpath)) {
                    printf("Alert! %s is infected!\n", fullpath);
                }
            }
        }
    }
    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("---- Artistic C Antivirus Scanner ----\n");
    printf("Scanning directory: %s\n\n", argv[1]);

    scan_directory(argv[1]);

    printf("\n---- Scan Completed ----\n");
    
    return EXIT_SUCCESS;
}