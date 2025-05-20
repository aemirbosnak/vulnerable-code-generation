//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 512
#define MAX_SIG_LENGTH 256
#define MAX_FILE_SIZE 1024 * 1024 // 1MB
#define MAX_SIGNATURES 100

typedef struct {
    char *signature; // String pattern to detect virus
} VirusSignature;

typedef struct {
    VirusSignature signatures[MAX_SIGNATURES];
    int count;
} SignatureDatabase;

void init_signature_database(SignatureDatabase *db) {
    db->count = 0;
    db->signatures[db->count++] = (VirusSignature){"VIRUS_SIGNATURE_1"};
    db->signatures[db->count++] = (VirusSignature){"VIRUS_SIGNATURE_2"};
    db->signatures[db->count++] = (VirusSignature){"MALWARE_PATTERN_XYZ"};
}

void scan_file(const char *filepath, SignatureDatabase *db) {
    FILE *file = fopen(filepath, "rb");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    char *buffer = (char *)malloc(MAX_FILE_SIZE);
    if (!buffer) {
        perror("Memory allocation failed");
        fclose(file);
        return;
    }

    size_t bytesRead = fread(buffer, 1, MAX_FILE_SIZE, file);
    fclose(file);

    for (int i = 0; i < db->count; i++) {
        if (strstr(buffer, db->signatures[i].signature)) {
            printf("Virus detected in file: %s\n", filepath);
            printf("Signature: %s\n", db->signatures[i].signature);
            break;
        }
    }

    free(buffer);
}

void scan_directory(const char *path, SignatureDatabase *db) {
    struct dirent *entry;
    DIR *dp = opendir(path);
    if (!dp) {
        perror("Unable to open directory");
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                char newPath[MAX_PATH_LENGTH];
                snprintf(newPath, sizeof(newPath), "%s/%s", path, entry->d_name);
                scan_directory(newPath, db); // Recursive scanning of subdirectory
            }
        } else if (entry->d_type == DT_REG) {
            char filePath[MAX_PATH_LENGTH];
            snprintf(filePath, sizeof(filePath), "%s/%s", path, entry->d_name);
            scan_file(filePath, db);
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    SignatureDatabase db;
    init_signature_database(&db);

    printf("Scanning directory: %s\n", argv[1]);
    scan_directory(argv[1], &db);
    printf("Scan complete.\n");

    return EXIT_SUCCESS;
}