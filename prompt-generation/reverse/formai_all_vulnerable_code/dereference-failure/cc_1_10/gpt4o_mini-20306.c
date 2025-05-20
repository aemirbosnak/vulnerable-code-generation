//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024
#define MAX_FILES 2048
#define SUSPICIOUS_PATTERNS 3

const char *patterns[SUSPICIOUS_PATTERNS] = {
    " virus ",
    " malware ",
    " trojan "
};

void scan_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    char buffer[BUFFER_SIZE];
    int line_number = 0;
    int found = 0;

    while (fgets(buffer, BUFFER_SIZE, file)) {
        line_number++;
        for (int i = 0; i < SUSPICIOUS_PATTERNS; i++) {
            if (strstr(buffer, patterns[i])) {
                printf("Suspicious pattern found in file: %s on line %d: %s", filename, line_number, buffer);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("No suspicious patterns found in file: %s\n", filename);
    }

    fclose(file);
}

void scan_directory(const char *dir_name) {
    struct dirent *entry;
    DIR *dp = opendir(dir_name);

    if (!dp) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) { // regular file
            char full_path[PATH_MAX];
            snprintf(full_path, sizeof(full_path), "%s/%s", dir_name, entry->d_name);
            scan_file(full_path);
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Scanning directory: %s\n", argv[1]);
    scan_directory(argv[1]);

    return EXIT_SUCCESS;
}