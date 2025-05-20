//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define SIGNATURE_COUNT 3
#define MAX_PATH_LENGTH 256
#define BUFFER_SIZE 1024

const char *signatures[SIGNATURE_COUNT] = {
    "virus_signature_1",
    "virus_signature_2",
    "virus_signature_3"
};

void log_message(const char *message) {
    FILE *logfile = fopen("scan_log.txt", "a");
    if (logfile) {
        fprintf(logfile, "%s\n", message);
        fclose(logfile);
    } else {
        perror("Could not open log file");
    }
}

int is_virus(const char *buffer) {
    for (int i = 0; i < SIGNATURE_COUNT; i++) {
        if (strstr(buffer, signatures[i]) != NULL) {
            return 1; // Virus found
        }
    }
    return 0; // No virus
}

void scan_file(const char *filepath) {
    FILE *file = fopen(filepath, "rb");
    if (!file) {
        perror("Could not open file");
        return;
    }

    char buffer[BUFFER_SIZE];
    while (fread(buffer, 1, sizeof(buffer), file) > 0) {
        if (is_virus(buffer)) {
            printf("Virus found in: %s\n", filepath);
            log_message(filepath);
            break;
        }
    }

    fclose(file);
}

void scan_directory(const char *dir_path) {
    struct dirent *entry;
    DIR *dp = opendir(dir_path);

    if (dp == NULL) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_type == DT_REG) { // Regular file
            char full_path[MAX_PATH_LENGTH];
            snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);
            scan_file(full_path);
        } else if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                char sub_dir[MAX_PATH_LENGTH];
                snprintf(sub_dir, sizeof(sub_dir), "%s/%s", dir_path, entry->d_name);
                scan_directory(sub_dir);
            }
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Scanning directory: %s\n", argv[1]);
    scan_directory(argv[1]);

    printf("Scan complete.\n");
    return EXIT_SUCCESS;
}