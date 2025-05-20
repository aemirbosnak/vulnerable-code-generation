//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

#define MAX_PATH 1024
#define MAX_SIGNATURES 100
#define SIGNATURE_LENGTH 64

char *virus_signatures[MAX_SIGNATURES] = {
    "6a c0 68 2b ef 68 d1 64",  //Example signature 1
    "b8 1d ab c9 51 57 6a 06",  //Example signature 2
    "f7 47 ab 95 d5 67 a2 9c"   //Example signature 3
};

int signature_count = 3;

void log_alert(const char *filename, const char *virus) {
    FILE *log_file = fopen("virus_scan_log.txt", "a");
    if (log_file) {
        time_t now = time(NULL);
        fprintf(log_file, "ALERT: %s contains %s - detected at %s", filename, virus, ctime(&now));
        fclose(log_file);
    }
}

int check_file(const char *filepath) {
    FILE *file = fopen(filepath, "rb");
    if (!file) {
        return 0;
    }

    unsigned char buffer[16];
    size_t read_bytes;
    while ((read_bytes = fread(buffer, sizeof(unsigned char), sizeof(buffer), file)) > 0) {
        for (int i = 0; i < signature_count; i++) {
            const char *sig = virus_signatures[i];
            if (memmem(buffer, read_bytes, sig, SIGNATURE_LENGTH) != NULL) {
                fclose(file);
                return i + 1;  // Return index of virus signature
            }
        }
    }

    fclose(file);
    return 0;  // No virus found
}

void scan_directory(const char *dir_path) {
    struct dirent *entry;
    DIR *dir = opendir(dir_path);
    if (!dir) {
        fprintf(stderr, "Error opening directory: %s\n", dir_path);
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Check if the entry is a regular file
            char filepath[MAX_PATH];
            snprintf(filepath, sizeof(filepath), "%s/%s", dir_path, entry->d_name);
            int virus_index = check_file(filepath);
            if (virus_index) {
                printf("Virus detected in %s: %s\n", filepath, virus_signatures[virus_index - 1]);
                log_alert(filepath, virus_signatures[virus_index - 1]);
            }
        } else if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char subdir[MAX_PATH];
            snprintf(subdir, sizeof(subdir), "%s/%s", dir_path, entry->d_name);
            scan_directory(subdir);  // Recurse into the subdirectory
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Initializing the Cyberpunk Antivirus Scanner...\n");
    printf("Scanning for digital phantoms and malicious specters in %s...\n", argv[1]);
    scan_directory(argv[1]);
    printf("Scan complete. Repose in the digital shadows...\n");

    return EXIT_SUCCESS;
}