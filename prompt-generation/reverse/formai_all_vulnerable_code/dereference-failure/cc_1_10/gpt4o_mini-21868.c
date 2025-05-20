//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define MAX_FILE_PATH 512
#define MAX_SIGNATURES 10

typedef struct {
    char *name;
    char *signature;
} VirusSignature;

VirusSignature signatures[MAX_SIGNATURES] = {
    {"VirusA", "ABCD"},
    {"VirusB", "WXYZ"},
    {"TrojanA", "1234"},
    {"TrojanB", "5678"},
    {"WormA", "9ABC"},
    {"MalwareA", "DEF0"},
    {"RootkitA", "6789"},
    {"SpywareA", "QRST"},
    {"RansomwareA", "UVWX"},
    {"AdwareA", "LMNO"}
};

int load_signatures(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening signature file");
        return -1;
    }
    
    int count = 0;
    while (count < MAX_SIGNATURES && fscanf(file, "%ms %ms", &signatures[count].name, &signatures[count].signature) == 2) {
        count++;
    }
    
    fclose(file);
    return count;
}

int scan_file(const char *file_path) {
    FILE *file = fopen(file_path, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return 0;
    }
    
    char buffer[BUFFER_SIZE];
    while (fread(buffer, 1, BUFFER_SIZE, file) > 0) {
        for (int i = 0; i < MAX_SIGNATURES; i++) {
            if (signatures[i].signature && strstr(buffer, signatures[i].signature)) {
                printf("Virus found: %s in file: %s\n", signatures[i].name, file_path);
                fclose(file);
                return 1; // Virus found
            }
        }
    }

    fclose(file);
    return 0; // No virus found
}

void scan_directory(const char *dir_path) {
    struct dirent *entry;
    struct stat info;
    DIR *dir = opendir(dir_path);

    if (dir == NULL) {
        perror("Error opening directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip current and parent directory
        }
        
        char full_path[MAX_FILE_PATH];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);
        
        if (stat(full_path, &info) == 0) {
            if (S_ISDIR(info.st_mode)) {
                scan_directory(full_path); // Recursively scan subdirectories
            } else if (S_ISREG(info.st_mode)) {
                scan_file(full_path); // Scan files
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Load signatures from file (optional enhancement)
    // load_signatures("signatures.txt");

    printf("Scanning directory: %s\n", argv[1]);
    
    scan_directory(argv[1]);
    
    printf("Scan completed.\n");
    return EXIT_SUCCESS;
}