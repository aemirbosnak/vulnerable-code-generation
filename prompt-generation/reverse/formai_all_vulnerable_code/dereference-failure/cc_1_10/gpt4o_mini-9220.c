//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define MAX_SIGNATURES 100
#define SIGNATURE_LENGTH 16

typedef struct {
    char name[256];
    char signature[SIGNATURE_LENGTH];
} VirusSignature;

VirusSignature virus_db[MAX_SIGNATURES];
int virus_count = 0;

void load_virus_signatures(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open virus database");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%255s %15s", virus_db[virus_count].name, virus_db[virus_count].signature) == 2) {
        virus_count++;
        if (virus_count >= MAX_SIGNATURES) break;
    }

    fclose(file);
}

int check_file(const char *filename) {
    unsigned char buffer[SIGNATURE_LENGTH];
    FILE *file = fopen(filename, "rb");
    if (!file) return 0;

    fread(buffer, 1, SIGNATURE_LENGTH, file);
    fclose(file);

    for (int i = 0; i < virus_count; i++) {
        if (memcmp(buffer, virus_db[i].signature, SIGNATURE_LENGTH) == 0) {
            printf("Virus detected in file: %s, virus name: %s\n", filename, virus_db[i].name);
            return 1;
        }
    }
    return 0;
}

void scan_directory(const char *path) {
    struct dirent *entry;
    struct stat file_stat;
    DIR *dir = opendir(path);

    if (!dir) {
        perror("Failed to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        char full_path[MAX_PATH];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        if (stat(full_path, &file_stat) == -1) {
            perror("Failed to get file status");
            continue;
        }

        if (S_ISDIR(file_stat.st_mode)) {
            scan_directory(full_path);
        } else if (S_ISREG(file_stat.st_mode)) {
            check_file(full_path);
        }
    }

    closedir(dir);
}

void print_help() {
    printf("Usage: ./antivirus [options]\n");
    printf("Options:\n");
    printf("  -h              Show this help message\n");
    printf("  -d <directory>  Specify the directory to scan\n");
    printf("  -s <file>       Specify the virus signature file\n");
}

int main(int argc, char *argv[]) {
    char *directory = NULL;
    char *signature_file = "viruses.txt"; // default signature file

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0) {
            print_help();
            return 0;
        } else if (strcmp(argv[i], "-d") == 0 && i + 1 < argc) {
            directory = argv[++i];
        } else if (strcmp(argv[i], "-s") == 0 && i + 1 < argc) {
            signature_file = argv[++i];
        }
    }

    if (directory == NULL) {
        fprintf(stderr, "Error: No directory specified. Use -d <directory>.\n");
        return EXIT_FAILURE;
    }

    load_virus_signatures(signature_file);
    scan_directory(directory);

    return EXIT_SUCCESS;
}