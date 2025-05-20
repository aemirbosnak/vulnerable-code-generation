//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024
#define MAX_FILE_SIZE 1048576 // 1 MB

typedef struct {
    char *name;
    unsigned char *signature;
    size_t sig_length;
} VirusSignature;

typedef struct {
    char path[MAX_PATH_LENGTH];
    int is_infected;
} FileScanResult;

void initializeVirusSignatures(VirusSignature *signatures, size_t *count);
int scanFile(const char *filePath, VirusSignature *signatures, size_t count, FileScanResult *result);
void scanDirectory(const char *directoryPath, VirusSignature *signatures, size_t count);
void reportResults(FileScanResult *results, size_t count);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory to scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    VirusSignature signatures[10];
    size_t signatureCount = 0;

    initializeVirusSignatures(signatures, &signatureCount);
    scanDirectory(argv[1], signatures, signatureCount);

    return EXIT_SUCCESS;
}

void initializeVirusSignatures(VirusSignature *signatures, size_t *count) {
    signatures[0].name = "ExampleVirus";
    signatures[0].signature = (unsigned char *)"\x90\x90\x90"; // NOP instructions
    signatures[0].sig_length = 3;
    
    signatures[1].name = "MalwareX";
    signatures[1].signature = (unsigned char *)"\xC3\xC3"; // RET instructions
    signatures[1].sig_length = 2;

    *count = 2; // Indicates the number of virus signatures initialized
}

int scanFile(const char *filePath, VirusSignature *signatures, size_t count, FileScanResult *result) {
    FILE *file = fopen(filePath, "rb");
    if (!file) {
        perror("Unable to open file");
        return -1;
    }

    unsigned char buffer[MAX_FILE_SIZE];
    size_t bytesRead = fread(buffer, 1, MAX_FILE_SIZE, file);
    fclose(file);

    result->is_infected = 0;
    strcpy(result->path, filePath);

    for (size_t i = 0; i < count; i++) {
        VirusSignature virus = signatures[i];
        for (size_t j = 0; j <= bytesRead - virus.sig_length; j++) {
            if (memcmp(&buffer[j], virus.signature, virus.sig_length) == 0) {
                result->is_infected = 1;
                printf("Infected file found: %s (Virus: %s)\n", filePath, virus.name);
                return 0;
            }
        }
    }

    return 0;
}

void scanDirectory(const char *directoryPath, VirusSignature *signatures, size_t count) {
    DIR *dir;
    struct dirent *entry;
    FileScanResult result;

    dir = opendir(directoryPath);
    if (dir == NULL) {
        perror("Unable to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Check if it is a regular file
            char fullPath[MAX_PATH_LENGTH];
            snprintf(fullPath, sizeof(fullPath), "%s/%s", directoryPath, entry->d_name);
            scanFile(fullPath, signatures, count, &result);
        } else if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char fullPath[MAX_PATH_LENGTH];
            snprintf(fullPath, sizeof(fullPath), "%s/%s", directoryPath, entry->d_name);
            scanDirectory(fullPath, signatures, count);
        }
    }

    closedir(dir);
}

void reportResults(FileScanResult *results, size_t count) {
    // Here we could implement a detailed logging/reporting mechanism.
    // This part is omitted as it is self-contained.
}