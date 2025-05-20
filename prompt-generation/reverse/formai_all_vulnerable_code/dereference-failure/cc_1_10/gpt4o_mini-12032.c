//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define BUFFSIZE 1024
#define SIGNATURE "MALWARE_SIGNATURE"

void scan_file(const char *filepath);
void scan_directory(const char *dirpath);
int contains_signature(const char *filepath);
void log_alert(const char *filepath);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    scan_directory(argv[1]);
    return EXIT_SUCCESS;
}

void scan_directory(const char *dirpath) {
    struct dirent *entry;
    DIR *dp = opendir(dirpath);
    if (dp == NULL) {
        fprintf(stderr, "Cannot open directory: %s\n", dirpath);
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                char subdirpath[BUFFSIZE];
                snprintf(subdirpath, sizeof(subdirpath), "%s/%s", dirpath, entry->d_name);
                scan_directory(subdirpath);
            }
        } else if (entry->d_type == DT_REG) {
            char filepath[BUFFSIZE];
            snprintf(filepath, sizeof(filepath), "%s/%s", dirpath, entry->d_name);
            scan_file(filepath);
        }
    }

    closedir(dp);
}

void scan_file(const char *filepath) {
    if (contains_signature(filepath)) {
        log_alert(filepath);
    }
}

int contains_signature(const char *filepath) {
    FILE *file = fopen(filepath, "rb");
    if (file == NULL) {
        fprintf(stderr, "Could not open file: %s\n", filepath);
        return 0;
    }

    char buffer[BUFFSIZE];
    while (fread(buffer, sizeof(char), sizeof(buffer), file)) {
        if (memmem(buffer, sizeof(buffer), SIGNATURE, strlen(SIGNATURE)) != NULL) {
            fclose(file);
            return 1; // Found the signature
        }
    }

    fclose(file);
    return 0; // Signature not found
}

void log_alert(const char *filepath) {
    FILE *logfile = fopen("alert.log", "a");
    if (logfile == NULL) {
        fprintf(stderr, "Could not open log file.\n");
        return;
    }
    
    fprintf(logfile, "ALERT: Infected file found: %s\n", filepath);
    fclose(logfile);
    printf("ALERT: Infected file found: %s\n", filepath);
}