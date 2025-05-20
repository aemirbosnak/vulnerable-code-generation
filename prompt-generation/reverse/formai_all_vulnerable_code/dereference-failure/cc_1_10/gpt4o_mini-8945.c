//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024
#define SIGNATURE_SIZE 64
#define SCAN_LIMIT 1000

// The remnants of the old world, where digital dangers lurked. 
char *malware_signatures[] = {
    "malware_signature_1",
    "virus_signature_2",
    "ransomware_signature_3",
    "trojan_signature_4",
    NULL
};

void log_memory(FILE *logfile, const char *filename) {
    fprintf(logfile, "Scan completed on: %s\n", filename);
}

void scan_file(const char *filename, FILE *logfile) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return;
    }

    char buffer[SIGNATURE_SIZE];
    while (fread(buffer, 1, SIGNATURE_SIZE, file) == SIGNATURE_SIZE) {
        for (int i = 0; malware_signatures[i]; i++) {
            if (memcmp(buffer, malware_signatures[i], SIGNATURE_SIZE) == 0) {
                fprintf(logfile, "Malware detected in file: %s\n", filename);
                fclose(file);
                return;
            }
        }
        // Move the file pointer back by 1 byte to scan for overlapping signatures
        fseek(file, -SIGNATURE_SIZE + 1, SEEK_CUR);
    }

    fclose(file);
}

void traverse_directory(const char *dir_name, FILE *logfile) {
    struct dirent *dir_entry;
    DIR *dir = opendir(dir_name);
    if (!dir) {
        fprintf(stderr, "Could not open directory: %s\n", dir_name);
        return;
    }

    struct stat statbuf;
    char filepath[MAX_PATH_LENGTH];

    while ((dir_entry = readdir(dir)) != NULL) {
        if (strcmp(dir_entry->d_name, ".") == 0 || strcmp(dir_entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(filepath, sizeof(filepath), "%s/%s", dir_name, dir_entry->d_name);
        if (stat(filepath, &statbuf) == -1) {
            fprintf(stderr, "Could not stat file: %s\n", filepath);
            continue;
        }

        if (S_ISREG(statbuf.st_mode)) {
            // Scan the file for signatures
            scan_file(filepath, logfile);
        } else if (S_ISDIR(statbuf.st_mode)) {
            // Recursively traverse subdirectories
            traverse_directory(filepath, logfile);
        }
    }

    closedir(dir);
}

void init_log_file(FILE **logfile) {
    *logfile = fopen("scan_log.txt", "a+");
    if (!*logfile) {
        fprintf(stderr, "Error creating log file.\n");
        exit(1);
    }
}

void shutdown_system(FILE *logfile) {
    fprintf(logfile, "Scan operations have ceased in this wasteland.\n");
    fclose(logfile);
    exit(0);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return 1;
    }

    FILE *logfile;
    init_log_file(&logfile);

    fprintf(logfile, "=== MALWARE SCAN INITIATED ===\n");
    fprintf(logfile, "Scanning directory: %s\n", argv[1]);

    traverse_directory(argv[1], logfile);

    fprintf(logfile, "=== MALWARE SCAN COMPLETED ===\n");
    log_memory(logfile, argv[1]);
    
    shutdown_system(logfile);

    return 0;
}