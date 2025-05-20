//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_FILE_PATH 256
#define MAX_SIGNATURES 10
#define MAX_SIG_LENGTH 32
#define BUFFER_SIZE 1024

typedef struct {
    char *signature;
} VirusSignature;

VirusSignature virus_signatures[MAX_SIGNATURES];

void load_signatures() {
    // Load common virus signatures (for demonstration)
    virus_signatures[0].signature = "EICAR";
    virus_signatures[1].signature = "Trojan";
    virus_signatures[2].signature = "W32.Downloader";
    // Add more signatures as needed
}

int contains_signature(const char *buffer, const char *signature) {
    return strstr(buffer, signature) != NULL;
}

void scan_file(const char *file_path) {
    FILE *file = fopen(file_path, "rb");
    char buffer[BUFFER_SIZE];
    
    if (!file) {
        perror("Could not open file");
        return;
    }

    printf("Scanning %s...\n", file_path);
    
    while (fread(buffer, 1, BUFFER_SIZE, file) > 0) {
        for (int i = 0; i < MAX_SIGNATURES; i++) {
            if (virus_signatures[i].signature != NULL && 
                contains_signature(buffer, virus_signatures[i].signature)) {
                printf("Warning: Virus signature '%s' found in file: %s\n", 
                       virus_signatures[i].signature, file_path);
            }
        }
    }

    fclose(file);
}

void scan_directory(const char *dir_path) {
    DIR *directory = opendir(dir_path);
    struct dirent *entry;

    if (!directory) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(directory))) {
        char file_path[MAX_FILE_PATH];
        struct stat file_stat;

        // Skip the special entries '.' and '..'
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(file_path, MAX_FILE_PATH, "%s/%s", dir_path, entry->d_name);
        if (stat(file_path, &file_stat) == 0 && S_ISREG(file_stat.st_mode)) {
            scan_file(file_path);
        }
    }

    closedir(directory);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    load_signatures();
    scan_directory(argv[1]);

    return EXIT_SUCCESS;
}